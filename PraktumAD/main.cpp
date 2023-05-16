#include <iostream>
#include "Myclasses.h"
using namespace std;

int main()
{
    POINT* p = new POINT(1.0,0.0);
    POINT* p2 = new POINT(5.0,4.0);
    LINE* L = new LINE(p,p2);

    POINT* Lp = new POINT(1.0,4.0);
    POINT* Lp2 = new POINT(5.0,5.0);
    LINE* L2 = new LINE(Lp,Lp2);

    POINT * SchnittPunkt = L->meets(L2);
    SchnittPunkt->show();
}
