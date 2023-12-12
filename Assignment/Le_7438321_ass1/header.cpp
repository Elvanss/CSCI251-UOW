// #include "header.h"
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <random>

// using namespace std;

// void convertTask(const string &file, Tasks tasks[], int &task_num) {
//     fstream input(file);
//     string line;
//     task_num =0;
    
//     while(getline(input, line) && task_num <10) {
//         stringstream ss(line);
//         Tasks task;
//         //get the id task 
//         getline(ss, line, ',');
//         task.taskId = stoi(line);

//         //get the description 
//         getline(ss, line, ',');
//         task.description = line;

//         //get the uncertainty 
//         getline(ss, line, ',');
//         task.uncertainty = stoi(line);

//         //get the difficulty 
//         getline(ss, line, ',');
//         task.difficulty = stoi(line);

//         //get the Workers List 
//         getline(ss, line, ':');
//         while (getline(ss, line, ',') && task.t_num < 10) {
//             task.Workers[task.t_num++] = stoi(line);
//         }

//         // an forward element of the array "tasks" save the each new task as the object
//         tasks[task_num++] = task;
//     }   
// }

// void convertWorker(const string &file, Workers workers[], int &worker_num) {
//     fstream input(file);
//     string line;
//     worker_num =0;
    
//     while(getline(input, line) && worker_num <10) {
//         stringstream ss(line);
//         Workers worker;
//         getline(ss, line, ',');
//         worker.workerID = stoi(line);

//         getline(ss, line, ',');
//         worker.name = line;

//         getline(ss, line, ',');
//         worker.variability = stoi(line);

//         getline(ss, line, ',');
//         worker.ability = stoi(line);

//         // an forward element of the array "tasks" save the each new task as the object
//         workers[worker_num++] = worker;
//     }   
// }

// double workerPerformance(double mean, double standardDev) {
//     default_random_engine generator;
//     normal_distribution<double> distribution(mean, standardDev);
//     double sum;
//     //check the random 5 times
//     for (int i = 0; i<5; i++) {
//         sum = sum + distribution(generator);
//     }
//     //get the average from 5 times testing
//     double final = sum/5;
//     return final;
// }

// void fileInput(string taskFile, string workerFile, string outputFile) {
    
//     Tasks tasks[total_tasks];
//     int taskCount;
//     Workers workers[total_workers];
//     int workerCount;
//     string line;
//     // Read all tasks from the file
//     convertTask(taskFile, tasks, taskCount);
//     convertWorker(workerFile, workers, workerCount);
    
//     // Display the tasks and workers
//     cout<<"\n===================================== The lists of given tasks and workers ====================================="<<endl;                                                                                                                        
//     for (int i = 0; i < taskCount; i++) {
//         cout <<"("<< i <<"): "<< "Task ID: " << tasks[i].taskId<<", ";
//         cout << "Description: " << tasks[i].description<<", ";
//         cout << "Uncertainty: " << tasks[i].uncertainty<<", ";
//         cout << "Difficulty: " << tasks[i].difficulty<<", ";
//         cout << "Workers: ";
//         for(int j = 0; j < tasks[i].t_num; j++) {
//             cout << tasks[i].Workers[j];
//             if(j != tasks[i].t_num - 1) {
//                 cout << ", ";
//             }
//         }
//         cout << "\n";
//     }
//     cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
//     for (int i =0; i<workerCount; i++) {
//         cout <<"("<< i <<"): "<< "Worker ID: " << workers[i].workerID<<", ";
//         cout << "Worker name: " << workers[i].name<<", ";
//         cout << "Variability: " << workers[i].variability<<", ";
//         cout << "Ability: " << workers[i].ability;
//         cout << "\n";
//     }
//     cout<<"\n================================================================================================================"<<endl;

//     cout<<"Performance Test:"<<endl;
//     //for loop with each task
//     for (int i = 0; i< taskCount; i++) {
//         cout<<"================================================================================================================"<<endl;
//         cout << "Task ID: " << tasks[i].taskId<<endl;
//         cout << "Description: " << tasks[i].description<<endl;
//         cout << "Uncertainty: " << tasks[i].uncertainty<<endl;
//         cout << "Difficulty: " << tasks[i].difficulty<<endl;
//         cout << "Workers: ";
//         for(int j = 0; j < tasks[i].t_num; j++) {
//             cout << tasks[i].Workers[j];
//             if(j != tasks[i].t_num - 1) {
//                 cout << ", ";
//             }
//         }
//         cout<<"\n"<<endl;
//         //For each task, generate the list of workers with performance (fail/succeed)
//         for (int j = 0; j< tasks[i].t_num; j++) {
//             int workerId = tasks[i].Workers[j];
//             Workers worker = workers[workerId];

//             int mean = worker.ability - tasks[i].difficulty;
//             int standardDev = tasks[i].uncertainty + worker.variability; 
        
//             double average = workerPerformance(mean, standardDev);
//             cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
//             cout << "Trial:" << " workers : " << workerId << std::endl;
//             cout<<"----------------------------------------------------------------------------------------------------------------\n"<<endl;
//             std::cout << "The average performance is " << average << std::endl;

//             if (average > 50) {
//                 cout << "Assignment of Task " << tasks[i].taskId << " to worker " << workerId << " succeeds\n" << std::endl;
//                 //stop the task and assign the work for that task
//                 break;
//             } else {
//                 cout << "Assignment of Task " << tasks[i].taskId << " to worker " << workerId << " fails \n" << std::endl;
//             }     
//         }
        

//     }

// }

#include "header.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>

using namespace std;

void convertTask(const string &file, Tasks tasks[], int &task_num) {
    fstream input(file);
    string line;
    task_num =0;
    
    while(getline(input, line) && task_num <10) {
        stringstream ss(line);
        Tasks task;
        //get the id task 
        getline(ss, line, ',');
        task.taskId = stoi(line);

        //get the description 
        getline(ss, line, ',');
        task.description = line;

        //get the uncertainty 
        getline(ss, line, ',');
        task.uncertainty = stoi(line);

        //get the difficulty 
        getline(ss, line, ',');
        task.difficulty = stoi(line);

        //get the Workers List 
        getline(ss, line, ':');
        while (getline(ss, line, ',') && task.t_num < 10) {
            task.Workers[task.t_num++] = stoi(line);
        }

        // an forward element of the array "tasks" save the each new task as the object
        tasks[task_num++] = task;
    }   
}

void convertWorker(const string &file, Workers workers[], int &worker_num) {
    fstream input(file);
    string line;
    worker_num =0;
    
    while(getline(input, line) && worker_num <10) {
        stringstream ss(line);
        Workers worker;
        getline(ss, line, ',');
        worker.workerID = stoi(line);

        getline(ss, line, ',');
        worker.name = line;

        getline(ss, line, ',');
        worker.variability = stoi(line);

        getline(ss, line, ',');
        worker.ability = stoi(line);

        // an forward element of the array "tasks" save the each new task as the object
        workers[worker_num++] = worker;
    }   
}

double workerPerformance(double mean, double standardDev) {
    default_random_engine generator;
    normal_distribution<double> distribution(mean, standardDev);
    double sum;
    //check the random 5 times
    for (int i = 0; i<5; i++) {
        sum = sum + distribution(generator);
    }
    //get the average from 5 times testing
    double final = sum/5;
    return final;
}

void fileInput(string taskFile, string workerFile, string outputFile) {
    ofstream output;
    Tasks tasks[total_tasks];
    int taskCount;
    Workers workers[total_workers];
    int workerCount;
    string line;
    // Read all tasks from the file
    convertTask(taskFile, tasks, taskCount);
    convertWorker(workerFile, workers, workerCount);
    output.open(outputFile);
    // Display the tasks and workers
    output<<"===================================== The lists of given tasks and workers ====================================="<<endl;                                                                                                                        
    for (int i = 0; i < taskCount; i++) {
        output <<"("<< i <<"): "<< "Task ID: " << tasks[i].taskId<<", ";
        output << "Description: " << tasks[i].description<<", ";
        output << "Uncertainty: " << tasks[i].uncertainty<<", ";
        output << "Difficulty: " << tasks[i].difficulty<<", ";
        output << "Workers: ";
        for(int j = 0; j < tasks[i].t_num; j++) {
            output << tasks[i].Workers[j];
            if(j != tasks[i].t_num - 1) {
                output << ", ";
            }
        }
        output << "\n";
    }
    output<<"----------------------------------------------------------------------------------------------------------------"<<endl;
    for (int i =0; i<workerCount; i++) {
        output <<"("<< i <<"): "<< "Worker ID: " << workers[i].workerID<<", ";
        output << "Worker name: " << workers[i].name<<", ";
        output << "Variability: " << workers[i].variability<<", ";
        output << "Ability: " << workers[i].ability;
        output << "\n";
    }
    output<<"\n================================================================================================================"<<endl;

    output<<"Performance Test:"<<endl;
    //for loop with each task
    for (int i = 0; i< taskCount; i++) {
        output<<"================================================================================================================"<<endl;
        output << "Task ID: " << tasks[i].taskId<<endl;
        output << "Description: " << tasks[i].description<<endl;
        output << "Uncertainty: " << tasks[i].uncertainty<<endl;
        output << "Difficulty: " << tasks[i].difficulty<<endl;
        output << "Workers: ";
        for(int j = 0; j < tasks[i].t_num; j++) {
            output << tasks[i].Workers[j];
            if(j != tasks[i].t_num - 1) {
                output << ", ";
            }
        }
        output<<"\n"<<endl;
        //For each task, generate the list of workers with performance (fail/succeed)
        for (int j = 0; j< tasks[i].t_num; j++) {
            int workerId = tasks[i].Workers[j];
            Workers worker = workers[workerId];

            int mean = worker.ability - tasks[i].difficulty;
            int standardDev = tasks[i].uncertainty + worker.variability; 
        
            double average = workerPerformance(mean, standardDev);
            output<<"----------------------------------------------------------------------------------------------------------------"<<endl;
            output << "Trial:" << " workers : " << workerId << std::endl;
            output<<"----------------------------------------------------------------------------------------------------------------\n"<<endl;
            output << "The average performance is " << average << std::endl;

            if (average > 50) {
                output << "Assignment of Task " << tasks[i].taskId << " to worker " << workerId << " succeeds\n" << std::endl;
                //stop the task and assign the work for that task
                break;
            } else {
                output << "Assignment of Task " << tasks[i].taskId << " to worker " << workerId << " fails \n" << std::endl;
            }     
        }

    }
    output.close();

}



