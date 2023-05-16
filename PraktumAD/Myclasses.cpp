
/* Dateiname: Myclasses.cpp:

Programmkopf mit Programmname, Autor(en)...
Beschreibung, usw.
Enthält den Code der Methoden der Klassen POINT, LINE und CIRCLE

*/
#include "Myclasses.h"
#include <iostream>
#include <cmath>
using namespace std;

//POINT

POINT::POINT(){}
POINT::POINT (double X, double Y): X(X), Y(Y){}
POINT::POINT (POINT & other){}
double POINT::distanceTo(const POINT & other){
    return sqrt(pow(X-other.getX(),2)+pow(Y-other.getY(),2));
}  // Abstand zweier POINT-Objekte
double POINT::getX()const {return X;}
double POINT::getY() const {return Y;}
POINT & POINT::operator = (const POINT &other){} // Überladener Zuweisungsoperator
POINT & POINT::operator + (const POINT &other){} // Überladener Additionsoperator
POINT & POINT::operator - (const POINT &other){} // Überladener Subtraktionsoperator
POINT & POINT::operator * (double scalar){}  // Überladener Multiplikationsoperator, POINT * SkalarerWert
void POINT::show(){
    cout << "( "<<X<<" | " <<Y<<" )"<< endl;
} // Ausgabe der Koordinaten in der Form ( x | y )
POINT::~POINT(){}


//LINE
LINE::LINE (POINT *P1, POINT *P2){}
POINT * LINE::meets (const LINE *L){}  //Schnittpunkt für zwei Geraden
bool LINE::parallelTo(const LINE *L){} //Feststellen, ob zwei Geraden parallel sind
void LINE::show(){}


//CIRCLE
CIRCLE::CIRCLE (POINT *M, double R){} //Initialisierungskonstruktor 1
CIRCLE::CIRCLE (POINT *A,POINT *B,POINT *C){} //Initialisierungskonstruktor 2
CIRCLE::POINT* getMiddle(){}
void CIRCLE::show(){} //Überschriebene Methode show, verwendet show von POINT: Ausgabe des Mittelpunktes und des Radius
bool CIRCLE::isInCircle(const POINT &){}
void CIRCLE::meetsOther(CIRCLE *C, int &Anzahl, POINT **S1, POINT **S2){} //C wird übergeben, Anzahl, S1 und S2 kommen zurück
