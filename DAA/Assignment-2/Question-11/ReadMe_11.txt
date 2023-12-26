#############################################
System Reqruirements
    --> Compiler : g++ compiler
    --> Hardware : sufficient main memory
    --> OS       : Windows
#############################################

Program File : Question11.cpp
How to run the program: Open Command Prompt/Powershell
                        Go to the folder using cd
                        Run the following command to compile the cpp file
Command to compile and run the program : Command to run program : g++ -o Question11 Question11.cpp&Question11.exe

----------------------------------------------------------------------------
Input Parameters.
----------------------------------------------------------------------------
The number of licenses
-----------------------------------------------------------------------------
Program Explanation and Analysis:-
-----------------------------------------------------------------------------

1. Define 'compareLicenses' function to compare licenses based on their growth rates.

	1.1 Algorithm:

	Function compareLicenses(a, b):
    	01. Compare two licenses a and b based on their growth rates
    	02. Return true if a's growth rate is greater than b's, false otherwise

    	1.2 Time Complexity: O(1)

    	Explanation: This function simply compares two licenses based on their growth rates and has constant time complexity.

2. Define 'minimizeCostOrder' function to calculate the optimal order to minimize cost.

	2.1 Algorithm:

	Function minimizeCostOrder(growthRates):
    	01. Initialize an empty vector of licenses
    	02. For each growth rate in growthRates:
        03. 	Create a License object with the index and growth rate
        04. 	Add the License object to the vector of licenses
    	05. Sort the vector of licenses in descending order of growth rate
    	06. Initialize an empty vector of order
    	07. For each License in the sorted vector of licenses:
        08.	Add the License's index to the vector of order
    	09. Return the vector of order

    	2.2 Time Complexity: O(n*log(n)), where n is the number of growth rates

    	Explanation: This function creates License objects for each growth rate and sorts them based on their growth rate in descending order. The sorting operation takes O(n*log(n)) time, and the subsequent loop has a linear time complexity.

3. Define 'random' function for generating random numbers.

	3.1 Algorithm:
	
	Function random():
    	01. Generate a random float value in a specified range
    	02. Return the random value

    	3.2 Time Complexity: O(1)

    	Explanation: This function generates a random float value within a specified range in constant time.

The empirical time complexity of the minimizeCostOrder function is O(nlog(n)), where n is the number of growth rates. This is due to the sorting operation that has a time complexity of O(nlog(n)).

Here, for n=100,
      It took 92516 microsecond.






