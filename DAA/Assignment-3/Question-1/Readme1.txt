#############################################
System Reqruirements
    --> Compiler : g++ compiler
    --> Hardware : sufficient main memory
    --> OS       : Windows
#############################################

Program File : Question1.cpp
How to run the program: Open Command Prompt/Powershell
                        Go to the folder using cd
                        Run the following command to compile the cpp file
Command to compile and run the program : Command to run program : g++ -o Question-1 Question-1.cpp&Question-1.exe

Introduction: 
        
This program creates a random binary tree with a specified number of nodes and then calculates the number of levels in the tree.
The main purpose is to demonstrate the generation of a binary tree and measure the execution time of the height calculation function.

1. Algorithm : 	

	function generateRandomBinaryTree(numNodes): --------------------O(n)
		if numNodes <= 0:
			return null
		value = getRandomValue(1, 100)
		newNode = new TreeNode(value)
		leftNodes = numNodes / 2
		rightNodes = numNodes - leftNodes - 1
		newNode->left = generateRandomBinaryTree(leftNodes)
		newNode->right = generateRandomBinaryTree(rightNodes)
		return newNode
	  
	function getHeight(root): --------------------------O(n)
		if root == null:
			return 0
		leftHeight = getHeight(root->left)
		rightHeight = getHeight(root->right)
		return 1 + max(leftHeight, rightHeight)
		

2. Asymptotic Analysis:

	Time complexity of the algorithm is O(n).

3. Empirical Analysis:

	Execution time for 10 : 1 microsecond
	Execution time for 100  : 5 microsecond
	Execution time for 1000  : 39 microsecond
	Execution time for 10000  : 373 microsecond
	Execution time for 100000  : 4380 microsecond

4. Observation:

	The algorithm runs with time complexity of O(n) as per the asymptotic analysis as ni increased by 10 then time is also incresed in
	multiple of 10. 

