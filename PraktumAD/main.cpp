#include <iostream>
#include "Myclasses.h"
using namespace std;

int main()
{
    POINT* p = new POINT(2.0,4.0);
    POINT* p2 = new POINT(2.0,6.0);
    cout << p->distanceTo(*p2)<< endl;
}
