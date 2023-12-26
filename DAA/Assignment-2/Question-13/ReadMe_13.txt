#############################################
System Reqruirements
    --> Compiler : g++ compiler
    --> Hardware : sufficient main memory
    --> OS       : Windows
#############################################

Program File : Question13.cpp
How to run the program: Open Command Prompt/Powershell
                        Go to the folder using cd
                        Run the following command to compile the cpp file
Command to compile and run the program : Command to run program : g++ -o Question13 Question13.cpp&Question13.exe
----------------------------------------------------------------------------
Input Parameters.
----------------------------------------------------------------------------
Number of sticks

-----------------------------------------------------------------------------
Program Explanation and Analysis:-
-----------------------------------------------------------------------------

1. Define 'compareSticks' function to determine the relationship between two sticks.

	1.1 Algorithm:

	Function compareSticks(a, b):
    	01. If a is above b in all dimensions (x, y, z), return "Above"
        02. If b is above a in all dimensions (x, y, z), return "Below"
    	03. Otherwise, return "Unrelated"
        
	1.2 Time Complexity: O(1)

	Explanation: This function compares two sticks by checking if one is entirely above the other in all three dimensions. The comparisons are performed in constant time.

2. Define 'pickStick' function to mark a stick as picked.

	2.1 Algorithm:

	Function pickStick(stick):
    	01. Mark the stick as picked by setting its 'isPicked' attribute to true

	2.2 Time Complexity: O(1)

    	Explanation: This function marks a stick as picked by updating a Boolean attribute, which is done in constant time.

3. Define 'canPickAllSticks' function to determine if all sticks can be picked up and provide a sequence.

	3.1 Algorithm:

	Function canPickAllSticks(sticks, sequence):
    	01. Clear the sequence vector
    	02. Initialize remainingSticks to the number of sticks
    	03. While there are remaining sticks:
        04. 	Initialize a flag 'picked' to false
        05. 	For each stick in the sticks:
        06. 	    If the stick is not picked:
        07.	        Initialize a flag 'canPick' to true
        08.	        For each other stick in the sticks:
        09.	            If the other stick is not picked:
        10.	                Compare the current stick with the other stick
        11.	                If the current stick is "Above" the other stick:
        12.	                    Set 'canPick' to false
        13.	                    Break
        14.             If 'canPick' is true:
        15.           		Mark the current stick as picked
        16.           		Add it to the sequence
        17.           		Decrement remainingSticks
        18.           		Set 'picked' to true
        19.   	If 'picked' is false:
        20.    	    Return false as it's impossible to pick up all sticks
    	21. Return true as it's possible to pick up all sticks

    	3.2 Time Complexity: O(N^3), where N is the number of sticks

    	Explanation: This function attempts to find a sequence to pick up all sticks. It involves nested loops and stick comparisons, leading to a cubic time complexity.

The empirical time complexity of the canPickAllSticks function is O(N^3), where N is the number of sticks. This is due to the presence of nested loops and stick comparisons, resulting in cubic time complexity.

Here, for n=10
      Time taken by function: 10970 microseconds
	

