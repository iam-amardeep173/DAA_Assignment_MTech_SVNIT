#############################################
System Reqruirements
    --> Compiler : g++ compiler
    --> Hardware : sufficient main memory
    --> OS       : Windows
#############################################

Program File : Question-17.cpp
How to run the program: Open Command Prompt/Powershell
                        Go to the folder using cd
                        Run the following command to compile the cpp file
Command to compile and run the program : Command to run program : g++ -o Question-17 Question-17.cpp&Question-17.exe


Program Explanation and Analysis:-


1) As the array is sorted, we can perform the given task in O(n) by checking and storing the difference between the adjacent elements.

2) The pair of adjacent elements with smallest difference will be our pair of elemets that we need to find.


Algoirithm:

1.	int findPair(int arr[])
2.	    int diff = arr[1]-arr[0];
3.	    int index = 0;
4.	    int length = sizeof(arr)/sizeof(arr[0]);
5.	    for(int ind = 1; ind<length-1; ind++)
6.	        int newDiff = arr[ind+1] - arr[ind];
7.	        if(newDiff<diff)
8.	            diff = newDiff;
9.	            index = ind;
10.	    return index;



Asymptotic analysis:
Line number 5 will execute for n-1 time(where n is array size) and all other statements will run in O(1) time => Total time complexity = O(n-1) i.e. O(n)


Empirical analysis:
Time taken for 10000 input: 39 micro sec Using Chrono
Time taken for 100000 input:  346 micro sec Using Chrono

Conclusion: Thus we can see that as we increase input size by 10 times the time complexity is increasing by around 10 times which justifies the asymptotic complexity O(n)