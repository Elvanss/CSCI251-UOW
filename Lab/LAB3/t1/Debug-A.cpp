#include<iostream>
//error
#include<string>
using namespace std;

class Worker
{
  private:
   int idNum;
   string lastName;
   //error
   string firstName;
   double celery;
   public:
   void setIdNum(int id);
   void setLastName(string last);
   void setFirstName(string first);
   void setSalary(double payRate);
   //error
   void displayWorker();
};
//error
void Worker::setIdNum(int id)
{
   const int LOWID = 0;
   const int HIGHID = 999;
   if(id < LOWID && id > HIGHID)
     idNum = LOWID;
   else
     idNum = id;
}
//error
void Worker::setLastName(string last)
{
   lastName = last;
}
void Worker::setFirstName(string first)
{
   firstName = first;
}

//error
void Worker::setSalary(double payRate)
{
   const double LOWPAY = 5.75;
   const double HIGHPAY = 99.99;
   if (payRate < LOWPAY || payRate < HIGHPAY)
     celery = LOWPAY;
   else
     celery = payRate;
 }

void Worker::displayWorker()
{
   //error
   cout<<"ID # "<<idNum<<"\nName: "<<firstName<<" "<<lastName
   	<<"\nSalary: $"<<celery<<endl;
}

int main() 
{
     Worker aWorker;
     //(Error)
     aWorker.setIdNum(111);
     //error
     aWorker.setLastName("Anteater");
     aWorker.setFirstName("Alice");
     aWorker.setSalary(23.45);
     aWorker.displayWorker();

     return 0;
}

