#include <iostream>
#include "Myclasses.h"
using namespace std;

int main()
{
    POINT* p = new POINT(0.0,4.0);
    POINT* p2 = new POINT(5.0,4.0);
    LINE* L = new LINE(p,p2);

    POINT* Lp = new POINT(0.0,5.0);
    POINT* Lp2 = new POINT(05.0,5.0);
    LINE* L2 = new LINE(Lp,Lp2);

    cout <<L->parallelTo(L2);


}
