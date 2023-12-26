#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <random>
#include <fstream>
#include <bitset>
using namespace std;

#define EMPTY_STRING ""

// A Tree node
struct Node
{
    char ch;
    int freq;
    Node* left, *right;
};

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
        return l->freq > r->freq;
    }
};

// Utility function to check if Huffman Tree contains only a single node
bool isLeaf(Node* root) {
    return root->left == nullptr && root->right == nullptr;
}

// Traverse the Huffman Tree and store Huffman Codes in a map
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (root == nullptr) {
        return;
    }
    if (isLeaf(root)) {
        huffmanCode[root->ch] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Build Huffman Tree and encode the given input text
Node* buildHuffmanTree(string text)
{
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, comp> pq;

    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    return pq.top();
}

// Encode the input file and save the compressed data to an output file
void compressFile(string inputFileName, string outputFileName)
{
    ifstream inputFile(inputFileName, ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the input file." << endl;
        return;
    }

    // Read the contents of the input file
    string text;
    char ch;
    while (inputFile.get(ch)) {
        text += ch;
    }
    inputFile.close();

    // Build Huffman Tree
    Node* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCode;
    encode(root, EMPTY_STRING, huffmanCode);

    // Encode the input text
    string encodedString;
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }

    // Convert the binary string to bytes and write to the output file
    ofstream outputFile(outputFileName, ios::binary);
    if (outputFile.is_open()) {
        bitset<8> bits;
        for (char bit : encodedString) {
            bits[7] = (bit == '1');
            if (bits[7]) {
                outputFile.put(static_cast<char>(bits.to_ulong()));
            }
        }
        outputFile.close();
        cout << "File compressed and saved to " << outputFileName << endl;
    }
    else {
        cerr << "Error: Unable to open the output file." << endl;
    }
}

int main()
{
    string inputFileName = "input.txt";  // Replace with the name of your input file
    string outputFileName = "output.bin"; // Output file to save compressed data

    // Generate random text and save it to the input file
    string randomText = generateRandomText(1000);  // Change the length as needed
    ofstream inputFile(inputFileName);
    if (inputFile.is_open()) {
        inputFile << randomText;
        inputFile.close();
        cout << "Input file generated: " << inputFileName << endl;
    } else {
        cerr << "Error: Unable to create the input file." << endl;
    }

    // Compress the input file and save the result to the output file
    compressFile(inputFileName, outputFileName);

    return 0;
}
