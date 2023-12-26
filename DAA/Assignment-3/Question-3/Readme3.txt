#############################################
System Reqruirements
    --> Compiler : g++ compiler
    --> Hardware : sufficient main memory
    --> OS       : Windows
#############################################

Program File : Question-3.cpp
How to run the program: Open Command Prompt/Powershell
                        Go to the folder using cd
                        Run the following command to compile the cpp file
Command to compile and run the program : Command to run program : g++ -o Question-3 Question-3.cpp&Question-3.exe

# Quicksort Algorithms Comparison

This C++ program demonstrates two versions of the Quicksort algorithm: Lomuto partition scheme and a standard partition scheme. 
It generates a random array, sorts it using both versions of the Quicksort algorithm, and compares the execution times.

1. Algorithm :

	function lomutoQuicksort(arr, low, high): ----------------------------O(N)
		if low < high:
			pivotIndex = lomutoPartition(arr, low, high)
			lomutoQuicksort(arr, low, pivotIndex - 1)
			lomutoQuicksort(arr, pivotIndex + 1, high)

	function lomutoPartition(arr, low, high): ----------------------------O(N log N)
		pivot = arr[high]
		i = low - 1
		for j = low to high - 1:
			if arr[j] < pivot:
				i++
				swap(arr[i], arr[j])
		swap(arr[i + 1], arr[high])
		return i + 1
	  

	function quicksort(arr, low, high): ----------------------------O(N)
  		if low < high:
			pivotIndex = partition(arr, low, high)
			quicksort(arr, low, pivotIndex - 1)
			quicksort(arr, pivotIndex + 1, high)
    
    function partition(arr, low, high): ----------------------------O(N log N)
		pivot = arr[high]
		i = low - 1
		for j = low to high - 1:
			if arr[j] <= pivot:
				i++
				swap(arr[i], arr[j])
		swap(arr[i + 1], arr[high])
		return i + 1  
		

2. Asymptotic Analysis:

	Time complexity of the Quicksort (original partition) algorithm is O(N)+O(N log N)= O(N log N).
	Time complexity of the Quicksort (lomuto partition) algorithm is O(N)+O(N log N)= O(N log N).
	

3. Empirical Analysis:
				     Brute force(time)	   mergeandcount(time)
	Execution time for 10 :       5 microsecond         5 microsecond
	Execution time for 100  :     63 microsecond        73 microsecond
	Execution time for 1000  :    548 microsecond       819 microsecond
	Execution time for 10000  :   2723 microsecond      3589 microsecond
	

4. Observation:

	Based on both asymptotic and empirical analysis, both the lomutoQuicksort and quicksort algorithms are excellent choices for sorting
	large arrays. The lomutoQuicksort algorithm is typically slightly faster, but the difference is not significant for most practical 
	applications. i.e both have same time complexity.

