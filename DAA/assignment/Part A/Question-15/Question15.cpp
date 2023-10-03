#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;
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

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int d)
{
    Node *temp = new Node;
    temp -> data = d;
	temp -> left = NULL;
	temp -> right = NULL;

	return temp;
}

Node* insert(Node *n, int d)
{
	if(n == NULL)
		return newNode(d);

	if(d < n -> data)
	{
		n -> left = insert(n -> left, d);
	}
	else if(d > n -> data)
	{
		n -> right = insert(n -> right, d);
	}
	else
		return n;
	
	return n;
}

bool identical(Node *n1, Node *n2)
{
    if(n1 == NULL && n2 == NULL)
        return true;
    else if(n1 == NULL || n2 == NULL)
        return false;
    else
    {
        if((n1 -> data) != (n2 -> data))
            return false;
        else
        {
            bool l = identical(n1 -> left, n2 -> left);
            bool r = identical(n1 -> right, n2 -> right);

            return (l && r);
        }
    }
}

void inorder(Node *n)
{
	if(n != NULL)
	{
		inorder(n -> left);
		cout << n -> data << " ";
		inorder(n -> right);
	}
}

Node* bst(Node *root, vector<int> v, int size)
{
    for(int i = 0; i < size; i++)
    {
        root = insert(root, v[i]);
    }

    return root;
}

vector<int> load_vector(fstream &f, int *s)
{
    vector<int> v;
    int d;

    while(f >> d)
    {
        v.push_back(d);
        (*s)++;
    }

    return v;
}

void show(Node *root)
{
	if(root != NULL)
		inorder(root);
	else
		cout << "Tree is Empty." << endl;
}

int main()
{
     vector<int> dataset = generateDataset(1000000);
    fstream f1,f2;
    f1.open("problem_15_1_a.txt",ios_base::out);
 
    for(int i=0;i<1000;i++)
    {
        f1<<dataset[i]<<endl;
    }
 
    

     
    f2.open("problem_15_2_a.txt",ios_base::out);
 
    for(int i=0;i<1000;i++)
    {
        f2<<dataset[i]<<endl;
    }
     f1.close();
    f2.close();
    
	

	vector<int> v1,v2;
	int s1,s2;
	Node *n1,*n2;
    bool i;

	s1 = 0;
	s2 = 0;

	n1 = NULL;
	n2 = NULL;


    /* 
    a as suffix means bigger data set
    1 and 3 are same, therefore worst case
    1 and 2 are different
    1 and 4 are same except largest element
    */
   
	f1.open("problem_15_1_a.txt", ios::in);
	f2.open("problem_15_2_a.txt", ios::in);

	v1 = load_vector(f1, &s1);
	cout << "Size 1: " << s1 << endl;

	v2 = load_vector(f2, &s2);
	cout << "Size 2: " << s2 << endl;

	n1 = bst(n1, v1, s1);
	n2 = bst(n2, v2, s2);

	// cout << "Tree 1: " << endl;
	// show(n1);
	
	// cout << endl << "Tree 2: " << endl;
	// show(n2);

	auto start = chrono::high_resolution_clock::now();
	i = identical(n1, n2);
	auto end = chrono::high_resolution_clock::now();

    if(i)
        cout << "The trees are identical." << endl;
    else
        cout << "The trees are not identical." << endl;

	auto time = chrono::duration_cast<chrono::microseconds>(end - start);

	cout << endl << endl << "Time taken to find out if the trees are identical or not: " << time.count() << " microseconds" << endl;

	f1.close();
	f2.close();


     
}