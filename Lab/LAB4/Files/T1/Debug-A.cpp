#include<iostream>
#include<string>
using namespace std;
class Painting
{
   protected:
      string title;
      string artist;
      int value;
   public:
       Painting();
       Painting(string, string);
       void showPainting();
       void setData();
       string getArtist();
       string getTitle();
};
//default constructor
Painting::Painting() {}
Painting::Painting(string name, string painter)
{
    name = title;
    artist = painter;
    value = 400;
}
void Painting::setData()
{
     cout<<"Enter painting's title ";
     cin>>title;
     cout<<"Enter artist ";
     cin>>artist;
     value = 40;
}
void Painting::showPainting()
{
   cout<<title <<artist<<" value $40";
}

string Painting::getArtist()
{
  return artist;
}

string Painting::getTitle()
{
  return title;
}

class FamousPainting: public Painting
{
 public:
   FamousPainting(string, string);
};

FamousPainting::FamousPainting(string name, string painter) :
   Painting(name, painter)
{
   value = 25;
}

bool isPaintingFamous(Painting& p)
{  
   bool isFamous = true;
    const int NUM = 4;
    string artists[NUM] = { "Degas", "Monet", "Picasso", "Rembrandt" };
    for (int x = 0; x < NUM; ++x) {
        if (p.getArtist() == artists[x]) {
            isFamous =  true;
            return isFamous;
        }
}
    return false;
}

//main function in Debug-A program
int main()
{
    const int NUM = 6;
    Painting pictures[NUM];

    for (int x = 0; x < NUM; ++x)
    {
        Painting temp;
        temp.setData();

        if (isPaintingFamous(temp))
        {
            FamousPainting tempF(temp.getTitle(), temp.getArtist());
            pictures[x] = tempF;
        }
        else
        {
            pictures[x] = temp;
        }
    }

    for(int x = 0; x< NUM; x++) {
      pictures[x].showPainting();
    }
    return 0;
}


