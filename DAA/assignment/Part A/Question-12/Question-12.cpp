#include<iostream>
#include<fstream>
#include<chrono>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int d) {
    Node* temp = new Node;
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int d) {
    if (root == NULL)
        return newNode(d);

    if (d < root->data) {
        root->left = insert(root->left, d);
    }
    else if (d > root->data) {
        root->right = insert(root->right, d);
    }
    else
        return root;

    return root;
}

Node* bst(Node* root, vector<int> v, int size) {
    for (int i = 0; i < size; i++) {
        root = insert(root, v[i]);
    }
    return root;
}

vector<int> load_vector(fstream& f, int* s) {
    vector<int> v;
    int d;

    while (f >> d) {
        v.push_back(d);
        (*s)++;
    }

    return v;
}

void inorder(Node* n) {
    if (n != NULL) {
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
}

void show(Node* root) {
    if (root != NULL)
        inorder(root);
    else
        cout << "Tree is Empty." << endl;
}

Node* concatenate(Node* root1, Node* root2) {
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;

    Node* curr = root1;
    while (curr->right != NULL)
        curr = curr->right;

    curr->right = root2;
    return root1;
}

void small() {
    fstream f1, f2;
    vector<int> v1, v2;
    int s1, s2;
    Node* n1, * n2, * n3;

    s1 = 0;
    s2 = 0;

    n1 = NULL;
    n2 = NULL;
    n3 = NULL;

    f1.open("problem_12_1_a.txt", ios::in);
    f2.open("problem_12_2_a.txt", ios::in);

    v1 = load_vector(f1, &s1);
    cout << "Size 1: " << s1 << endl;

    v2 = load_vector(f2, &s2);
    cout << "Size 2: " << s2 << endl;

    n1 = bst(n1, v1, s1);
    n2 = bst(n2, v2, s2);

    auto start = chrono::high_resolution_clock::now();
    n3 = concatenate(n1, n2);
    auto end = chrono::high_resolution_clock::now();

    auto time = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << endl << endl << "Time taken to concatenate 2 trees with " << s1 << " elements: " << time.count() << " microseconds" << endl;

    f1.close();
    f2.close();
}

void large() {
    fstream f1, f2;
    vector<int> v1, v2;
    int s1, s2;
    Node* n1, * n2, * n3;

    s1 = 0;
    s2 = 0;

    n1 = NULL;
    n2 = NULL;
    n3 = NULL;

    f1.open("problem_12_1.txt", ios::in);
    f2.open("problem_12_2.txt", ios::in);

    v1 = load_vector(f1, &s1);
    cout << "Size 1: " << s1 << endl;

    v2 = load_vector(f2, &s2);
    cout << "Size 2: " << s2 << endl;

    n1 = bst(n1, v1, s1);
    n2 = bst(n2, v2, s2);

    auto start = chrono::high_resolution_clock::now();
    n3 = concatenate(n1, n2);
    auto end = chrono::high_resolution_clock::now();

    auto time = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << endl << endl << "Time taken to concatenate 2 trees with " << s1 << " elements: " << time.count() << " microseconds" << endl;

    f1.close();
    f2.close();
}

int main() {
    small();
    large();
    return -1;
}
