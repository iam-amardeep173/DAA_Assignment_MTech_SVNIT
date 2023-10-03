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

void inOrder(node *root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  }
}

// Inserts a new node into the tree.
node *insert(node *root, int key)
{
  if (root == NULL)
  {
    return new node(key);
  }

  if (key < root->data)
  {
    root->left = insert(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = insert(root->right, key);
  }

  return root;
}

// Finds the minimum value node in the tree.
node *minValueNode(node *root)
{
  node *temp = root;

  while (temp->left)
  {
    temp = temp->left;
  }

  return temp;
}

// Searches for a node in the tree.
bool search(node *root, int key)
{
  if (root == NULL)
  {
    return false;
  }

  if (key == root->data)
  {
    return true;
  }
  else if (key < root->data)
  {
    return search(root->left, key);
  }
  else
  {
    return search(root->right, key);
  }
}

// Deletes a node from the tree.
node *deleteNode(node *root, int key)
{
  if (root == NULL)
  {
    return NULL;
  }

  if (key < root->data)
  {
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = deleteNode(root->right, key);
  }
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }
    else if (root->left == NULL)
    {
      node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL)
    {
      node *temp = root->left;
      delete root;
      return temp;
    }
    else
    {
      node *temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }

  return root;
}

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
    
    inOrder(root);
    cout << endl
         << endl;
    end = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(end - start).count();
    cout << "Inorder Traversal time: " << elapsed_time << " microseconds" << endl;

    int elementToBeDeleted = 60;
    start = high_resolution_clock::now();
    
    root = deleteNode(root, elementToBeDeleted);
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
    cout << elementToBeDeleted << " is present in tree? " << search(root, elementToBeDeleted) << endl
         << endl;
    cout
        << endl;
    end = high_resolution_clock::now();
    elapsed_time = duration_cast<microseconds>(end - start).count();
    cout << "Inorder Traversal time: " << elapsed_time << " microseconds" << endl;

    return 0;
}
