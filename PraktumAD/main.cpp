#include <iostream>
#include "Myclasses.h"
using namespace std;

int main()
{
    POINT* p = new POINT(3,8);
    CIRCLE * c = new CIRCLE(p,15);


    POINT* p2 = new POINT(6,5);
    CIRCLE* c2 = new CIRCLE(p2,1);

    POINT** s1 = new POINT*;
    POINT** s2 = new POINT*;
    int anzahl = 0;
    c->meetsOther(c2,anzahl,s1,s2);

    cout << " Die Kreise haben: " << anzahl <<" Schnittpunkte"<< endl;

    if(anzahl != 0){
        (*s1)->show();
        if(anzahl == 2)
        (*s2)->show();
    }

  }
