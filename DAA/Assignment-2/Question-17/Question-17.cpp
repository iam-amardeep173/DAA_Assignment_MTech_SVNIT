#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <limits>
#include <string>
#include <functional>

class Edge {
public:
    std::string src;
    std::string dst;
    int travelTime;

    Edge(std::string source, std::string destination, int time) : src(source), dst(destination), travelTime(time) {}

    bool operator<(const Edge& other) const {
        return travelTime > other.travelTime;
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge) {
        os << "[" << edge.src << "-" << edge.dst << "](" << edge.travelTime << " minutes)";
        return os;
    }
};

class Vertex {
public:
    std::string id;
    std::map<Vertex*, int> adjacent;
    int totalTime;
    bool visited;

    Vertex(const std::string& node) : id(node), totalTime(std::numeric_limits<int>::max()), visited(false) {}

    int operator[](Vertex* key) const {
        return adjacent.at(key);
    }

    int& operator[](Vertex* key) {
        return adjacent[key];
    }
      // It's used for sorting edges based on their travel time.
    bool operator<(const Vertex& other) const {
        return totalTime > other.totalTime;
    }
           //This function overloads the output stream operator (<<) to allow easy printing of Edge objects
    friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex) {
        os << "{";
        for (const auto& neighbor : vertex.adjacent) {
            os << neighbor.first->id << " (" << neighbor.second << " minutes), ";
        }
        os << "}";
        return os;
    }
};

class Graph {
public:
    std::map<std::string, Vertex*> graph;

    void addVertex(const std::string& vertex) {
        graph[vertex] = new Vertex(vertex);
    }

    void addEdge(const std::vector<Edge>& edges) {
        for (const Edge& edge : edges) {
            if (graph.find(edge.src) == graph.end()) {
                addVertex(edge.src);
            }
            if (graph.find(edge.dst) == graph.end()) {
                addVertex(edge.dst);
            }

            graph[edge.src]->adjacent[graph[edge.dst]] = edge.travelTime;
            graph[edge.dst]->adjacent[graph[edge.src]] = edge.travelTime;
        }
    }

    Vertex* getVertex(const std::string& node) {
        if (graph.find(node) != graph.end()) {
            return graph[node];
        } else {
            return nullptr;
        }
    }
        //This function returns a set of all the vertex IDs in the graph.
    std::set<std::string> getVertices() const {
        std::set<std::string> vertices;
        for (const auto& pair : graph) {
            vertices.insert(pair.first);
        }
        return vertices;
    }
      //This function calculates and returns the travel time between two vertices using the travel times stored 
    int travelTime(const Vertex* vertex1, const Vertex* vertex2) const {
        return (*vertex1)[const_cast<Vertex*>(vertex2)];
    }
//This function resets the visited and totalTime values for all vertices in the graph, preparing it for a new shortest path calculation.
    void reset() {
        for (const auto& pair : graph) {
            Vertex* v = pair.second;
            v->visited = false;
            v->totalTime = std::numeric_limits<int>::max();
        }
    }
};

void dijkstraAlgorithm(Graph& graph, const std::string& startVertex, const std::string& targetVertex) {
    graph.getVertex(startVertex)->totalTime = 0;

    std::priority_queue<Vertex*> unvisitedQueue;
    unvisitedQueue.push(graph.getVertex(startVertex));

    std::map<std::string, int> shortestTime;
    for (const auto& pair : graph.graph) {
        shortestTime[pair.first] = std::numeric_limits<int>::max();
    }
    shortestTime[startVertex] = 0;

    std::map<std::string, std::string> previousVertices;

    while (!unvisitedQueue.empty()) {
        Vertex* current = unvisitedQueue.top();
        unvisitedQueue.pop();
        current->visited = true;

        for (const auto& neighbor : current->adjacent) {
            Vertex* next = neighbor.first;
            if (next->visited) {
                continue;
            }
            int newTime = current->totalTime + current->adjacent[next];
            if (newTime < next->totalTime) {
                next->totalTime = newTime;
                shortestTime[next->id] = newTime;
                previousVertices[next->id] = current->id;
                unvisitedQueue.push(next);
            }
        }
    }

    if (!targetVertex.empty()) {
        std::vector<std::string> path;
        std::string vertex = targetVertex;
        while (vertex != startVertex) {
            path.push_back(vertex);
            vertex = previousVertices[vertex];
        }
        path.push_back(startVertex);

        std::cout << "The shortest travel time from " << startVertex << " to " << targetVertex << " is " << shortestTime[targetVertex] << " minutes.\n";
        std::cout << "Route: ";
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            std::cout << *it;
            if (it + 1 != path.rend()) {
                std::cout << " -> ";
            }
        }
    }
}

int main() {
    Graph g;
    g.addVertex("Balrampur");
    g.addVertex("Gonda");
    g.addVertex("Bahraich");
    g.addVertex("Barabanki");
    g.addVertex("Lucknow");
    g.addVertex("Kanpur");
    g.addVertex("Lakhimpur");
    g.addVertex("Shahjahanpur");
    g.addVertex("GolaGokarannath");

    std::vector<Edge> edges = {{"Balrampur", "Gonda", 42}, {"Balrampur", "Bahraich", 63}, {"Gonda", "Barabanki", 88}, {"Gonda", "Lakhimpur", 181},
                              {"Gonda", "Bahraich", 64}, {"Lucknow", "Barabanki", 28}, {"Lakhimpur", "Kanpur", 225}, {"Lakhimpur", "Barabanki", 131},
                              {"Bahraich", "Lakhimpur", 121}, {"Bahraich", "Barabanki", 99}, {"Bahraich", "Kanpur", 224}, {"Lakhimpur", "GolaGokarannath", 35}, 
                              {"Lakhimpur", "Shahjahanpur", 110}, {"GolaGokarannath", "Shahjahanpur", 60}};

    g.addEdge(edges);

    dijkstraAlgorithm(g, "Lakhimpur", "Shahjahanpur");

    return 0;
}
