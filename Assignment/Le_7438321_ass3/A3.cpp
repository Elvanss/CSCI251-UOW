#include "collect.h"
#include <iostream>
#include <string>
#include <map>
#include <random>

using namespace std;

class Knapsack {
private:
    int maxSize;
    int currentSize = 0;
    int resetVal = 0;
    vector<char> objList; //the vector that store the list of words 
    map<char, int> knapSize; //the size of class
    map<char, int> knapCount; //the count of bag collection that can be stored in the knapsack
    int durability; //durability of condition

public:
    Knapsack(int s, int d) : maxSize(s), durability(d) {}

    template <typename T>
    //add bags
    bool addObject(T &obj, char type)
    {
        int objSize = sizeof(obj);
        switch (type)
        {
        case 'R':
        {
            cout << "Condition 2: Attempt to add an R object which triggers a reset. The number of used resets: " << resetVal + 1 << " out of " << durability << endl;
            print();
            reset();
            return false;
        }
        case 'S':
        {
            cout << "Condition 3: Attempt to add an S object which triggers early termination." << endl;
            print();
            exit(4);
        }
        default:
        {
            if (currentSize + objSize <= maxSize)
            {
                currentSize += objSize;
                objList.push_back(obj.getName());
                knapSize[obj.getName()] = objSize;
                knapCount[obj.getName()]++;

                return true;
            }
            else
            {
                cout << "Condition 1 is triggered because the size of the next object is too large: " << objSize << endl;
                print();
                return false;
            }
        }
        }
    }
//reset the bag (condition 2)
    void reset()
    {
        currentSize = 0;
        objList.clear();
        knapSize.clear();
        knapCount.clear();
        resetVal++;
    }
//stop the loop while it smaller than user's durability input
    bool canReset()
    {
        return resetVal < durability;
    }

    void print()
    {
        //print the report 
        cout << "==============================================================================\n";
        cout << "Knapsack size: " << maxSize << "\n";
        cout << "Added object size: " << currentSize << "\n";
        for (char obj : objList)
        {
            cout << obj;
        }
        cout << endl;
        cout << "\n==============================================================================\n";
        for (auto &[key, size] : knapSize)
        {
            cout << key << ", " << size << ", " << knapCount[key] << "\n";
        }

        cout << "==============================================================================\n";
    }
};

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Invalid command, please try: ./KAP x y z" << endl;
        return 1;
    }

    int size = stoi(argv[1]);
    int seed = stoi(argv[2]);
    int durability = stoi(argv[3]);

    Knapsack knapsack(size, durability);

    bool stop;

    while (true)
    {
        char type = generate(seed);
        switch (type)
        {
        case 'A':
        {
            A a;
            stop = knapsack.addObject(a, type);
            if (!stop)
            {
                return 0;
            }
            break;
        }
        case 'B':
        {
            B b;
            stop = knapsack.addObject(b, type);
            if (!stop)
            {
                return 0;
            }
            break;
        }
        case 'C':
        {
            C c;
            stop = knapsack.addObject(c, type);
            if (!stop)
            {
                return 0;
            }
            break;
        }
        case 'D':
        {
            D d;
            stop = knapsack.addObject(d, type);
            if (!stop)
            {
                return 0;
            }
            break;
        }
        case 'E':
        {
            E e;
            stop = knapsack.addObject(e, type);
            if (!stop)
            {
                return 0;
            }
            break;
        }
        case 'F':
        {
            F f;
            stop = knapsack.addObject(f, type);
            if (!stop)
            {
                return 0;
            }
            break;
        }
        case 'G':
        {
            G g;
            stop = knapsack.addObject(g, type);
            if (!stop)
            {
                return 0;
            }
            break;
        }
        case 'R':
        {
            R r;
            knapsack.addObject(r, type);
            break;
        }
        case 'S':
        {
            S s;
            knapsack.addObject(s, type);
            break;
        }
        default:
        {
            cerr << "The objects should be an alphabet from A-G, R and S: " << type << endl;
            return 2;
        }
        }
    //stop the condition
        if (!knapsack.canReset())
        {
            return 0;
        }
    }

    return 0;
}