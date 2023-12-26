#############################################
System Reqruirements
    --> Compiler : g++ compiler
    --> Hardware : sufficient main memory
    --> OS       : Windows
#############################################

Program File : Question5.cpp
How to run the program: Open Command Prompt/Powershell
                        Go to the folder using cd
                        Run the following command to compile the cpp file
Command to compile and run the program : Command to run program : g++ -o Question-5 Question-5.cpp&Question-5.exe

1. Algorithm :

	function countingSort(arr):
		maxElement = findMaximum(arr) -----------------O(n)
		count = createArray(maxElement + 1, 0) -----------------O(n)

		for num in arr: -----------------O(n)
			count[num]++

		for i = 1 to maxElement + 1:  -----------------O(k)
			count[i] += count[i - 1]

		output = createArray(arr.size())  -----------------O(n)

		for i = arr.size() - 1 to 0: -----------------O(n)
			output[count[arr[i]] - 1] = arr[i]
			count[arr[i]]--

		for i = 0 to arr.size() - 1: -----------------O(n)
			arr[i] = output[i]


2. Asymptotic Analysis:

	Time complexity of the Counting sort algorithm is O(n+k)
	

3. Empirical Analysis:
					(time)		
	Execution time for 10 :       8 microsecond         
	Execution time for 100  :     48 microsecond        
	Execution time for 1000  :    548 microsecond       
	Execution time for 10000  :   2521 microsecond      
	

4. Observation:

	The countingSort algorithm is an efficient sorting algorithm that is particularly well-suited for arrays with small ranges. 
	Its time complexity of O(n + k) makes it a good choice for many practical applications.

