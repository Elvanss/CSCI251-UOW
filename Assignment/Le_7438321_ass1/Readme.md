List of /imports/functions/structs that are mentioned in program:

(*)import:
    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <string>
    #include <random>

(*) main.cpp:
    1. int main()

(*) header.cpp:
    1. void convertTask(const string &file, Tasks tasks[], int &task_num)
        - This method generate the fstream import to interact with array of tasks and the number of task (parameter)
        - Using while loop to assign each string/number to variable by spliting the "," and ":"
    2. void convertWorker(const string &file, Workers workers[], int &worker_num)
        - This method generate the fstream import to interact with each variable of the workers
        - Using while loop to assign each string/number to variable by spliting the ","
    3. double workerPerformance(double mean, double standardDev)
        - Generating the random import and normal distribution to calculate by using mean and standard deviation (values)
        - calculate the sum of calculation and get the average from the given sum divided by 5
    4. void fileInput()
        - Print the tasks and workers to check the converting txt file to each variable functions
        - Print the loop of each task and workers which are assigned by each task until successfully in the new text file 

(*) header.h;
    1. Constant variables: total_tasks and total_workers with values are 10 and 10 respectively
    2. Structure Task (int taskId; string description; double uncertainty; double difficulty; int Workers[20]; int t_num =0;)
    3. Structure Workers (int workerID; string name; int variability; int ability;)


How to run code:
    - Open terminal on any IDE and compile editor [(Visual Studio (Studio/Code), CodeBlock, Net bean, etc]
    - Run this command: "g++ driver.cpp header.cpp -std=c++17 -o run"
        ~With "run" can be changed as your own name~
    - After running that command, run this one: "./run Tasks.txt Workers.txt Output.txt" or "./your own created name Tasks.txt Workers.txt Output.txt"
    - And now then the output will be shown in the terminal tab

OUTPUT: 
===================================== The lists of given tasks and workers =====================================
(0): Task ID: 1, Description: image processing, Uncertainty: 6, Difficulty: 10, Workers: 7, 0, 8
(1): Task ID: 2, Description: natural language processing, Uncertainty: 7, Difficulty: 15, Workers: 8, 1, 3
(2): Task ID: 3, Description: computer vision, Uncertainty: 5, Difficulty: 10, Workers: 0, 1
(3): Task ID: 4, Description: friend recommendation, Uncertainty: 1, Difficulty: 19, Workers: 2, 8, 5
(4): Task ID: 5, Description: knowledge discovery, Uncertainty: 9, Difficulty: 12, Workers: 0, 1, 6
(5): Task ID: 6, Description: data analytics, Uncertainty: 8, Difficulty: 11, Workers: 3, 9
(6): Task ID: 7, Description: seed selection, Uncertainty: 6, Difficulty: 14, Workers: 9, 5, 6, 3
(7): Task ID: 8, Description: data mining, Uncertainty: 7, Difficulty: 15, Workers: 1, 2, 4
(8): Task ID: 9, Description: pattern recognition, Uncertainty: 5, Difficulty: 20, Workers: 0, 3, 4
(9): Task ID: 10, Description: clustering, Uncertainty: 2, Difficulty: 12, Workers: 2, 1, 7, 5
----------------------------------------------------------------------------------------------------------------
(0): Worker ID: 0, Worker name: Peter, Variability: -3, Ability: 53
(1): Worker ID: 1, Worker name: Sam, Variability: -2, Ability: 82
(2): Worker ID: 2, Worker name: Tommy, Variability: -7, Ability: 61
(3): Worker ID: 3, Worker name: James, Variability: -4, Ability: 72
(4): Worker ID: 4, Worker name: Amanda, Variability: -5, Ability: 62
(5): Worker ID: 5, Worker name: Hellen, Variability: -8, Ability: 46
(6): Worker ID: 6, Worker name: Kim, Variability: -3, Ability: 71
(7): Worker ID: 7, Worker name: Young, Variability: -4, Ability: 62
(8): Worker ID: 8, Worker name: Linda, Variability: -5, Ability: 44
(9): Worker ID: 9, Worker name: Ryan, Variability: -2, Ability: 82

================================================================================================================
Performance Test:
================================================================================================================
Task ID: 1
Description: image processing
Uncertainty: 6
Difficulty: 10
Workers: 7, 0, 8

----------------------------------------------------------------------------------------------------------------
Trial: workers : 7
----------------------------------------------------------------------------------------------------------------

The average performance is 52.6989
Assignment of Task 1 to worker 7 succeeds

================================================================================================================
Task ID: 2
Description: natural language processing
Uncertainty: 7
Difficulty: 15
Workers: 8, 1, 3

----------------------------------------------------------------------------------------------------------------
Trial: workers : 8
----------------------------------------------------------------------------------------------------------------

The average performance is 29.6989
Assignment of Task 2 to worker 8 fails 

----------------------------------------------------------------------------------------------------------------
Trial: workers : 1
----------------------------------------------------------------------------------------------------------------

The average performance is 68.7474
Assignment of Task 2 to worker 1 succeeds

================================================================================================================
Task ID: 3
Description: computer vision
Uncertainty: 5
Difficulty: 10
Workers: 0, 1

----------------------------------------------------------------------------------------------------------------
Trial: workers : 0
----------------------------------------------------------------------------------------------------------------

The average performance is 43.6989
Assignment of Task 3 to worker 0 fails 

----------------------------------------------------------------------------------------------------------------
Trial: workers : 1
----------------------------------------------------------------------------------------------------------------

The average performance is 73.0484
Assignment of Task 3 to worker 1 succeeds

================================================================================================================
Task ID: 4
Description: friend recommendation
Uncertainty: 1
Difficulty: 19
Workers: 2, 8, 5

----------------------------------------------------------------------------------------------------------------
Trial: workers : 2
----------------------------------------------------------------------------------------------------------------

The average performance is 39.9032
Assignment of Task 4 to worker 2 fails 

----------------------------------------------------------------------------------------------------------------
Trial: workers : 8
----------------------------------------------------------------------------------------------------------------

The average performance is 23.6021
Assignment of Task 4 to worker 8 fails 

----------------------------------------------------------------------------------------------------------------
Trial: workers : 5
----------------------------------------------------------------------------------------------------------------

The average performance is 24.5537
Assignment of Task 4 to worker 5 fails 

================================================================================================================
Task ID: 5
Description: knowledge discovery
Uncertainty: 9
Difficulty: 12
Workers: 0, 1, 6

----------------------------------------------------------------------------------------------------------------
Trial: workers : 0
----------------------------------------------------------------------------------------------------------------

The average performance is 43.0968
Assignment of Task 5 to worker 0 fails 

----------------------------------------------------------------------------------------------------------------
Trial: workers : 1
----------------------------------------------------------------------------------------------------------------

The average performance is 72.4463
Assignment of Task 5 to worker 1 succeeds

================================================================================================================
Task ID: 6
Description: data analytics
Uncertainty: 8
Difficulty: 11
Workers: 3, 9

----------------------------------------------------------------------------------------------------------------
Trial: workers : 3
----------------------------------------------------------------------------------------------------------------

The average performance is 62.3979
Assignment of Task 6 to worker 3 succeeds

================================================================================================================
Task ID: 7
Description: seed selection
Uncertainty: 6
Difficulty: 14
Workers: 9, 5, 6, 3

----------------------------------------------------------------------------------------------------------------
Trial: workers : 9
----------------------------------------------------------------------------------------------------------------

The average performance is 69.3979
Assignment of Task 7 to worker 9 succeeds

================================================================================================================
Task ID: 8
Description: data mining
Uncertainty: 7
Difficulty: 15
Workers: 1, 2, 4

----------------------------------------------------------------------------------------------------------------
Trial: workers : 1
----------------------------------------------------------------------------------------------------------------

The average performance is 68.7474
Assignment of Task 8 to worker 1 succeeds

================================================================================================================
Task ID: 9
Description: pattern recognition
Uncertainty: 5
Difficulty: 20
Workers: 0, 3, 4

----------------------------------------------------------------------------------------------------------------
Trial: workers : 0
----------------------------------------------------------------------------------------------------------------

The average performance is 33.6989
Assignment of Task 9 to worker 0 fails 

----------------------------------------------------------------------------------------------------------------
Trial: workers : 3
----------------------------------------------------------------------------------------------------------------

The average performance is 52.3495
Assignment of Task 9 to worker 3 succeeds

================================================================================================================
Task ID: 10
Description: clustering
Uncertainty: 2
Difficulty: 12
Workers: 2, 1, 7, 5

----------------------------------------------------------------------------------------------------------------
Trial: workers : 2
----------------------------------------------------------------------------------------------------------------

The average performance is 47.2526
Assignment of Task 10 to worker 2 fails 

----------------------------------------------------------------------------------------------------------------
Trial: workers : 1
----------------------------------------------------------------------------------------------------------------

The average performance is 70
Assignment of Task 10 to worker 1 succeeds
    