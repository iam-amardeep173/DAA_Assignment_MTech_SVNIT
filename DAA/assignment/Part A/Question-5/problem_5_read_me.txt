Some of the factors that affect the speed of program execution:

1. Input Size: Larger is the input size, Logner it will take for the program to execute.

2. No. of Threads: The number of threads a program can work on has an effect on the time. 

3. CPU and memory Utilization: The time of execution of a program also depends on how much of the CPU and the memory is free.

4. System Specifications: Similar to the above point, having better specifications will lead to faster execution.

5. Disk Access: The configuration of the disk space can have an effect on the disk fetches.

6. Cache Memory: The size of cache will also have an effect on speed of program.

7. Programming Language: Different languages have different ways to run on the machines, this also effects the time.


We can clearly see that multiple of the above things are not constant things like the CPU usage can be different during the execution of 2 instances of the same program due to some other program that was also being run at the same time of one instances. 
Maybe the cache memory of the system has another data when running a program. But when the same program is run again, the cache might have the data which can be used in this instance from the previous instance used.

There are multiple things more than the ones listed here which are ever changing variables, that can effect the execution of the program. So doing empirical analysis is not so feasible when comparing two algorithms.