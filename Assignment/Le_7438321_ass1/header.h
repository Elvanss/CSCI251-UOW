#define HEADER_H
#include <string>
using namespace std;

const int total_tasks = 10;
const int total_workers = 10;

struct Tasks {
    int taskId;
    string description;
    double uncertainty;
    double difficulty;
    int Workers[20];
    int t_num =0;
};

struct Workers {
    int workerID;
    string name;
    int variability;
    int ability;
};

void convertTask(const string &file, Tasks tasks[], int &task_num);
void convertWorker(const string &file, Workers workers[], int &worker_num);
double workerPerformance(double mean, double standardDev);
void fileInput(string taskFile, string workerFile, string outputFile);


