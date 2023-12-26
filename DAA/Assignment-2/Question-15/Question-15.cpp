#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

#define EMPTY_STRING ""

// A Tree node
struct Node
{
    char ch;
    int freq;
    Node* left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node* l, const Node* r) const
    {
        // the highest priority item has the lowest frequency
        return l->freq > r->freq;
    }
};

// Utility function to check if Huffman Tree contains only a single node
bool isLeaf(Node* root) {
    return root->left == nullptr && root->right == nullptr;
}

// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (root == nullptr) {
        return;
    }

    // found a leaf node
    if (isLeaf(root)) {
        huffmanCode[root->ch] = (str != EMPTY_STRING) ? str : "1";
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Builds Huffman Tree and encodes the given input text
void buildHuffmanTree(string text, string outputFileName)
{
    // base case: empty string
    if (text == EMPTY_STRING) {
        return;
    }

    // Count the frequency of appearance of each character
    // and store it in a map
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Create a leaf node for each character and add it
    // to the priority queue.
    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    // Do until there is more than one node in the queue
    while (pq.size() != 1)
    {
        // Remove the two nodes of the highest priority
        // (the lowest frequency) from the queue

        Node* left = pq.top(); pq.pop();
        Node* right = pq.top();    pq.pop();

        // Create a new internal node with these two nodes as children and
        // with a frequency equal to the sum of the two nodes' frequencies.
        // Add the new node to the priority queue.

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // `root` stores a pointer to the root of the Huffman Tree
    Node* root = pq.top();

    // Traverse the Huffman Tree and store Huffman Codes
    // in a map. Also, print them
    unordered_map<char, string> huffmanCode;
    encode(root, EMPTY_STRING, huffmanCode);

    // Encode the input string
    string encodedString;
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }

    // Write the encoded string to an output file
    ofstream outputFile(outputFileName, ios::binary);
    if (outputFile.is_open()) {
        outputFile << encodedString;
        outputFile.close();
        cout << "Huffman Codes are saved to an output file." << endl;
    }
    else {
        cerr << "Error: Unable to open the output file." << endl;
    }
}

// Generate random text
string generateRandomText(int length)
{
    string text;
    const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";
    int charsetSize = charset.size();
    srand(time(0));

    for (int i = 0; i < length; ++i) {
        text += charset[rand() % charsetSize];
    }

    return text;
}

int main()
{
    string inputFileName = "C:/Users/Amar Deep/OneDrive/Desktop/M Tech/DAA/Assignment-2/Question-15/random_output.bin";



    string outputFileName = "output.bin";

    auto start = chrono::high_resolution_clock::now(); // Record the start time

    // Read the input text from a file
    ifstream inputFile(inputFileName);
    if (inputFile.is_open()) {
        string text((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
        inputFile.close();

        buildHuffmanTree(text, outputFileName);

        auto end = chrono::high_resolution_clock::now(); // Record the end time
        chrono::duration<double, std::micro> duration = end - start; // Calculate the duration in microseconds

        cout << "Time taken: " << duration.count() << " microseconds" << endl;
    }
    else {
        cerr << "Error: Unable to open the input file." << endl;
    }

    // Generate random text and save it to another output file
    string randomText = generateRandomText(1000);  // Change the length as needed
    string randomOutputFileName = "random_output.bin";
    buildHuffmanTree(randomText, randomOutputFileName);

    return 0;
}
