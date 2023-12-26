#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getRandomValue(int min, int max) {
    return rand() % (max - min + 1) + min;
}

TreeNode* generateRandomBinaryTree(int numNodes) {
    if (numNodes <= 0) {
        return nullptr;
    }

    int value = getRandomValue(1, 100);
    TreeNode* newNode = new TreeNode(value);

    // Calculate the number of nodes for left and right subtrees
    int leftNodes = numNodes / 2;
    int rightNodes = numNodes - leftNodes - 1;

    newNode->left = generateRandomBinaryTree(leftNodes);
    newNode->right = generateRandomBinaryTree(rightNodes);

    return newNode;
}

int getHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int numNodes ;
    cout<<"Enter the No. of Nodes in tree : ";
    cin>>numNodes; // Adjust the number of nodes as needed
    TreeNode* root = generateRandomBinaryTree(numNodes);

    // Measure the execution time of the getHeight function
    auto start = std::chrono::high_resolution_clock::now();
    int levels = getHeight(root);
    auto end = std::chrono::high_resolution_clock::now();

    // Output the result and execution time
    std::cout << "Number of levels in the binary tree: " << levels << std::endl;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    // Free the memory allocated for the tree
    delete root;

    return 0;
}

