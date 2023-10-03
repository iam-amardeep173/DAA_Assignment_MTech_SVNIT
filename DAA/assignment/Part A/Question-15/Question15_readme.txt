#############################################
System Reqruirements
    --> Compiler : g++ compiler
    --> Hardware : sufficient main memory
    --> OS       : Windows
#############################################

Program File : Question15.cpp
How to run the program: Open Command Prompt/Powershell
                        Go to the folder using cd
                        Run the following command to compile the cpp file
Command to compile and run the program : Command to run program : g++ -o Question15 Question15.cpp&Question15.exe

    1.# Binary Search Tree Comparison Program
        This program generates two binary search trees (BSTs) from datasets stored in text files and checks if they are identical.
        It measures the time taken to perform this comparison.
           ## Program Description
              The program performs the following steps:
		1. Generates two datasets of random integers and stores them in separate text files.
		2. Reads the datasets from the text files and constructs two binary search trees (BSTs).
		3. Compares the two BSTs to determine if they are identical.
		4. Measures the time taken to perform the comparison.


    2. Time Complexity
        Generating the random dataset: O(size)
	Constructing a binary search tree (BST) from a dataset of size N: O(N * log(N)) in the average case (if the data is randomly distributed). 
	However, in the worst case (if the data is sorted), it can be O(N^2).
	Comparing two BSTs for identity: O(N) in the worst case (when both trees are balanced).
    
     3. Empirical Analysis of Time Complexity
        Size 1: 10000
	Size 2: 100000
	The trees are not identical.
	Time taken to find out if the trees are identical or not: 792 microseconds
        Size 1: 1000
        Size 2: 100
        The trees are not identical.
        Time taken to find out if the trees are identical or not: 10 microseconds
        Size 1: 1000
        Size 2: 1000
        The trees are identical.
        Time taken to find out if the trees are identical or not: 45 microseconds

      4. Files
	main.cpp: The main C++ source code file.
	problem_15_1_a.txt: Text file containing the first dataset.
	problem_15_4_a.txt: Text file containing the second dataset.
    

