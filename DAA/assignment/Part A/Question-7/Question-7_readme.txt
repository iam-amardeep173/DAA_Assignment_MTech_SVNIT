#############################################
System Requirements
    --> Compiler : g++ compiler
    --> Hardware : sufficient main memory
    --> OS : Windows
#############################################

This program calculates the time for the functions to run for two different inputs, sh and la.

How to run the program: Open Command Prompt/Powershell
                        Go to the folder using cd
                        Run the command to compile the cpp file

1. Part a

    Program File : question-7.cpp
    Command to compile and run the program : g++ -o question-7 question-7.cpp&question-7.exe

    1.1 Algorithm:
        func(n)
        1. x = 0                   --------------- O(1)
        2. for i = 1 to n          --------------- O(n)
        3.     for j = 1 to i      --------------- O(~ n) * n
        4.         x = x + 1       --------------- O(1) * ~ n * n
        5. return x                --------------- O(1)       

    1.2 Asymptotic Analysis of Time Complexity
        Total time complexity = O(2n^2 + n + 2) = O(n^2)

    1.3 Empirical Analysis of Time Complexity
        Time Taken for input size 10 : 6 microsecond
        Time Taken for input size 100 : 3 microsecond

        Here, we increased input size by factor of 10 and as time complexity is O(n^2), increment in time should by factor of 100.
        And that is that we are approximately getting.
        Hence our asymptotic analysis of time complexity is proved by empirical analysis.

2. Part b


    2.1 Algorithm:
        func(n)
        1. x = 0                   --------------- O(1)
        2. j = n                   --------------- O(1)
        3. while (j >= 1)          --------------- O(infinity)
        4.     for i = 1 to j      --------------- O(~ n/2) * infinity
        5.         x = x + 1       --------------- O(1) * ~ n/2 * infinity 
        6.     j = n/2             --------------- O(1)
        7. return x                --------------- O(1)       

    2.2 Asymptotic Analysis of Time Complexity
        Total time complexity = O(infinity)

    2.3 Empirical Analysis of Time Complexity
        Cannot be done as there is an infinite loop, so the program will not terminate.

        Here we can see that Asymptotic and Empirical Analysis come to similar conclusions.

3. Part f


    3.1 Algorithm:
        func(n)
        1. x = 0                   --------------- O(1)
        2. for i = 1 to n          --------------- O(n)
        3.     for j = 1 to i      --------------- O(~ n) * n
        4.         for k = 1 to i  --------------- O(~ n) * ~ n * n
        5.             x = x + 1   --------------- O(1) * ~ n * ~ n * n
        6. return x                --------------- O(1)       

    3.2 Asymptotic Analysis of Time Complexity
        Total time complexity = O(2n^3 + n^2 + n + 2) = O(n^3)

    3.3 Empirical Analysis of Time Complexity
        Time Taken for input size 10 : 3 microsecond
        Time Taken for input size 100 : 1893 microsecond

        Here, we increased input size by factor of 2 and as time complexity is O(n^3), increment in time should by factor of 8.
        And that is that we are approximately getting.
        Hence our asymptotic analysis of time complexity is proved by empirical analysis.

4. Part d


    4.1 Algorithm:
        func(n)
        1. x = 0                   --------------- O(1)
        2. i = n                   --------------- O(1)
        3.     while i >= 1        --------------- O(log n)
        4.         for j = 1 to n  --------------- O(n) * log n
        5.             x = x + 1   --------------- O(1) * n * log n
        6.             i = i / 2   --------------- O(1) * n * log n
        6. return x                --------------- O(1)       

    4.2 Asymptotic Analysis of Time Complexity
        Total time complexity = O(3 n log n + log n + 3) = O(n log n)

    4.3 Empirical Analysis of Time Complexity
        Time Taken for input size 10 : 0 microsecond
        Time Taken for input size 100 : 1 microsecond

        Here, we increased input size by factor of 2 and as time complexity is O(n log n), increment in time should by factor of 2 log 2 = 2.
        And that is that we are approximately getting.
        Hence our asymptotic analysis of time complexity is proved by empirical analysis.