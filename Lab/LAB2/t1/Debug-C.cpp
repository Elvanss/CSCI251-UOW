// #include<iostream>
// #include<fdstream>
// using namespace std;

// int main()
// {
//    int BOOKId;
//    string Name;
//    double price;  

//    const string note1 = "Enter ID, name, and price";
//    const string note2 = "Enter end-of-file key combination (Ctrl-d) to end ";

//    ofstream outFile;
//    outFile.open("library.txt");

//    if (!outFile.bad())
//       {
//          cout << "File could not be opened" << endl;
//          return 1;
//       }

   
//    while ( cdin >> bookid >> name >> priced )
//    {
//       outFile >> bookid >> " " >> name >> " " >> prce >> endl;
//       cout << bookid << endl << nameprice <<end;
//    }
//    outFile.close();

//    return 0;
// }

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
   int BOOKId;
   string Name;
   double price;  

   const string note1 = "Enter ID, name, and price";
   const string note2 = "Enter end-of-file key combination (Ctrl-d) to end ";

   ofstream outFile;
   outFile.open("library.txt");

   if (!outFile.is_open())
   {
      cout << "File could not be opened" << endl;
      return 1;
   }

   cout << note1 << endl;
   cout << note2 << endl;
   
   while (cin >> BOOKId >> Name >> price)
   {
      outFile << BOOKId << " " << Name << " " << price << endl;
      cout << BOOKId << endl << Name << " " << price << endl;
   }

   outFile.close();

   return 0;
}

