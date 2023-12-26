#############################################
System Reqruirements
    --> Compiler : g++ compiler
    --> Hardware : sufficient main memory
    --> OS       : Windows
#############################################

Program File : Question20.cpp
How to run the program: Open Command Prompt/Powershell
                        Go to the folder using cd
                        Run the following command to compile the cpp file
Command to compile and run the program : Command to run program : g++ -o Question20 Question20.cpp&Question20.exe
----------------------------------------------------------------------------
Input Parameters.
----------------------------------------------------------------------------
Number of villages

-----------------------------------------------------------------------------
Program Explanation and Analysis:-
-----------------------------------------------------------------------------

1. Define 'distance' function

	1.1 Algorithm:

	Function distance(v1, v2):
    	01. Calculate the difference in x and y coordinates (dx and dy)
    	02. Calculate the square of dx and dy
    	03. Calculate the sum of squared differences
    	04. Calculate the square root of the sum
    	05. Return the square root as the distance

    	1.2 Time Complexity: O(1)

    	Explanation: This function calculates the Euclidean distance between two villages using mathematical operations that have constant time complexity.

2. Define 'findMinimumSpanningTree' function

	2.1 Algorithm:

	Function findMinimumSpanningTree(villages):
    	01. Initialize n as the number of villages
    	02. Initialize visited as a boolean array of size n, all set to false
    	03. Initialize minDistance as an array of size n, all set to positive infinity
    	04. Set minDistance[0] to 0
    	05. Initialize totalDistance as 0
   	06. For i from 0 to n - 1:
        07. 	Initialize u as -1
        08. 	For j from 0 to n - 1:
        09.	    If village j is not visited and (u is -1 or minDistance[j] < minDistance[u]):
        10.         Set u to j
        11. Mark village u as visited
        12. Add minDistance[u] to totalDistance
        13. For each village v from 0 to n - 1:
        14.    If village v is not visited:
        15.         Calculate the distance from village u to v
        16.         Update minDistance[v] to the minimum of its current value and the calculated distance
	17. Return totalDistance

    	2.2 Time Complexity: O(n^2)

    	Explanation: This function constructs the Minimum Spanning Tree using Prim's algorithm. It involves two nested loops where the outer loop iterates over the villages and the inner loop searches for the minimum distance vertex. The time complexity is O(n^2).

3. Define 'generateRandomVillages' function

	3.1 Algorithm:

	Function generateRandomVillages(n):
    	01. Initialize an empty vector of villages (villages)
    	02. Initialize a random number generator
    	03. Create n random villages with coordinates (x, y) in the range [0.0, 1.0]
    	04. Add each village to the villages vector
    	05. Return the villages vector

    	3.2 Time Complexity: O(n)

    	Explanation: This function generates random village coordinates and creates a vector of villages. The time complexity is linear in the number of villages, which is O(n).


The empirical time complexity of the findMinimumSpanningTree function is O(n^2), where n is the number of villages. This is due to the nested loops, where the outer loop iterates over the villages, and the inner loop searches for the minimum distance vertex.

