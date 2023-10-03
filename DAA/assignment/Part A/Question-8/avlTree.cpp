#include <iostream>
#include <stack>
#include <stack>
#include <vector>
#include <unordered_set>
#include <random>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> generateDataset(int size) {
    vector<int> dataset;
    random_device rd;
    mt19937 rng(rd());

    for (int i = 0; i < size; i++) {
        int randValue = uniform_int_distribution<int>(1, INT_MAX)(rng);
        dataset.push_back(randValue);
    }

    return dataset;
}

class node
{
public:
    int data;
    int height;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

int max(int a, int b);
int height(node *N);
int getBalance(node *N);
node *rightRotate(node *y);
node *leftRotate(node *x);
void inOrder(node *root);
node *minValueNode(node *root);
node *insert(node *root, int key);
node *deleteNodeWithKey(node *root, int key);
bool searchInAVL(node *root, int key);

int main()
{
    node *root = NULL;
    vector<int> vect1;
    long long int exchangeCount = 0;

    vector<int> dataset = generateDataset(1000000);

    fstream file;
    file.open("data.txt",ios_base::out);
 
    for(int i=0;i<10000;i++)
    {
        file<<dataset[i]<<endl;
    }
 
    file.close();

   
   file.open("data.txt", ios_base::in); // Change the open mode to ios_base::in

if (!file)
{
    cerr << "File can not open.";
    exit(1);
}

string line;
while (getline(file, line))
    vect1.push_back(stoi(line));

file.close();

    // cout << endl<< "No. of element to insert in Tree : " << vect1.size() << endl<< endl;
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto elapsed_time = duration_cast<microseconds>(end - start).count();
    for (int i = 0; i <= 20; i++)
    {
        start = high_resolution_clock::now();
        root = insert(root, vect1[i]);
        end = high_resolution_clock::now();
        elapsed_time = duration_cast<microseconds>(end - start).count();
        cout << "Insert time: " << i << " element " << elapsed_time << " microseconds" << endl;
    }

    cout << "Inorder traversal of the tree : ";
    start = high_resolution_clock::now();
    ;
    inOrder(root);
    cout << endl
         << endl;
    end = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(end - start).count();
    cout << "Inorder Traversal time: " << elapsed_time << " microseconds" << endl;

    int elementToBeDeleted = 60;
    start = high_resolution_clock::now();
    ;
    root = deleteNodeWithKey(root, elementToBeDeleted);
    cout << endl
         << endl;
    end = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(end - start).count();
    cout << "Deletion of Node time: " << elapsed_time << " microseconds" << endl;

    cout << "Inorder traversal of the tree after deleting " << elementToBeDeleted << " : ";
    start = high_resolution_clock::now();
    ;
    inOrder(root);
    cout << endl
         << endl;
    end = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(end - start).count();
    cout << "Inorder Traversal time: " << elapsed_time << " microseconds" << endl;

    start = high_resolution_clock::now();
    ;
    cout << elementToBeDeleted << " is present in tree? " << searchInAVL(root, elementToBeDeleted) << endl
         << endl;
    cout
        << endl;
    end = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(end - start).count();
    cout << "Inorder Traversal time: " << elapsed_time << " microseconds" << endl;

    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

node *insert(node *root, int key)
{
    // Perform normal BST insertion.
    if (root == NULL)
    {
        node *tmp = new node(key);
        return (tmp);
    }

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    // Update height of this ancestor node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(root);

    // LL Case
    if ((balance > 1) && (key < root->left->data))
        return rightRotate(root);

    // RR Case
    if ((balance < -1) && (key > root->right->data))
        return leftRotate(root);

    // LR Case
    if ((balance > 1) && (key > root->left->data))
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case --> right rotate
    if ((balance < -1) && (key < root->right->data))
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

node *deleteNodeWithKey(node *root, int key)
{
    // STEP 1 : DELETE AS BST.
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNodeWithKey(root->left, key);

    else if (key > root->data)
        root->right = deleteNodeWithKey(root->right, key);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            node *tmp = root->left ? root->left : root->right;

            if (tmp == NULL)
            {
                tmp = root;
                root = NULL;
            }
            else
            {
                *root = *tmp;
            }
            free(tmp);
        }
        else
        {
            node *tmp = minValueNode(root->right);
            root->data = tmp->data;
            root->right = deleteNodeWithKey(root->right, tmp->data);
        }
    }

    if (root == NULL)
        return root;

    // STEP 1.1 : UPDATE HEIGHT.
    root->height = max(height(root->left), height(root->right)) + 1;

    // STEP 2 : GET BALANCE FACTOR.
    int balance = getBalance(root);

    // STEP 3 : MAINTAIN BALANCE FACTOR

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

node *minValueNode(node *root)
{
    node *tmp = root;

    while (tmp->left)
    {
        tmp = tmp->left;
    }

    return tmp;
}

bool searchInAVL(node *root, int key)
{
    if (root == NULL)
        return false;

    if (key == root->data)
        return true;
    else if (key < root->data)
        return searchInAVL(root->left, key);
    else
        return searchInAVL(root->right, key);
}
