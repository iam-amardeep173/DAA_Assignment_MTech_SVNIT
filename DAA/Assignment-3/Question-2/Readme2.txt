#############################################
System Reqruirements
    --> Compiler : g++ compiler
    --> Hardware : sufficient main memory
    --> OS       : Windows
#############################################

Program File : Question-4.cpp
How to run the program: Open Command Prompt/Powershell
                        Go to the folder using cd
                        Run the following command to compile the cpp file
Command to compile and run the program : Command to run program : g++ -o Question-2 Question-2.cpp&Question-2.ex

1. Inversion Counting Algorithms

This C++ program demonstrates two different approaches for counting inversions in an array:

 1. **Brute Force Approach**: This approach iterates through all pairs of elements in the array and counts the number of inversions. It has a time complexity of O(n^2).

 2. **Merge and Count Approach (Using Merge Sort)**: This approach utilizes the merge-sort algorithm to efficiently count inversions. It has a time complexity of O(n log n).


2. Algorithm :

	function countInversions_brute(arr, n): ----------------O(n^2)
		inversionCount = 0
		for i = 0 to n - 1:
			for j = i + 1 to n:
				if arr[i] > arr[j]:
					inversionCount++
		return inversionCount

  
	function mergeAndCount(arr, temp, left, mid, right): ---------------------O(n log n)
		i = left
		j = mid + 1
		k = left
		inversionCount = 0
		while i <= mid and j <= right:
			if arr[i] <= arr[j]:
			  	temp[k++] = arr[i++]
			else:
			  	temp[k++] = arr[j++]
		  	inversionCount += (mid - i + 1)
		while i <= mid:
			temp[k++] = arr[i++]
		while j <= right:
			temp[k++] = arr[j++]
		for i = left to right:
			arr[i] = temp[i]
		return inversionCount
	  

	function mergeSortAndCount(arr, temp, left, right):
		inversionCount = 0
		if left < right:
			mid = (left + right) / 2
			inversionCount += mergeSortAndCount(arr, temp, left, mid)--------------O(n log n)
			inversionCount += mergeSortAndCount(arr, temp, mid + 1, right)--------------O(n log n)
			inversionCount += mergeAndCount(arr, temp, left, mid, right) --------------O(n log n)

		return inversionCount  
		

3. Asymptotic Analysis:

	Time complexity of the Bruteforce algorithm is O(n^2).
	Time complexity of the merge and count algorithm is O(n log n).

4. Empirical Analysis:
				     Brute force(time)	   mergeandcount(time)
	Execution time for 10 :       2 microsecond         16 microsecond
	Execution time for 100  :     34 microsecond        19 microsecond
	Execution time for 1000  :    6239 microsecond      205 microsecond
	Execution time for 10000  :   217837 microsecond    1280 microsecond

5. Observation:

	The brute force algorithm has a time complexity of O(N^2), which means that its execution time grows quadratically with the size of 
	the input. This makes it inefficient for large arrays. The merge sort algorithm has a time complexity of O(N log N), which means that 
	its execution time grows logarithmically with the size of the input. This makes it much more efficient for large arrays.

	The merge sort algorithm is a more efficient algorithm for counting inversions in an array than the brute force algorithm. It has a 
	better asymptotic time complexity and is much faster in practice for large arrays. Therefore, the merge sort algorithm is the 
	preferred algorithm for this task.

