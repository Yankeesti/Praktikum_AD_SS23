
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
POINT::POINT (POINT & other): X(other.getX()), Y(other.getY()){}

double POINT::distanceTo(const POINT & other){// Abstand zweier POINT-Objekte
    return sqrt(pow(X-other.getX(),2)+pow(Y-other.getY(),2));
}

double POINT::getX()const {return X;}
double POINT::getY() const {return Y;}

POINT & POINT::operator = (const POINT &other){// Überladener Zuweisungsoperator
    X = other.getX();
    Y = other.getY();
    return *this;
}
POINT & POINT::operator + (const POINT &other){// Überladener Additionsoperator
    double newX = X+other.getX();
    double newY = Y+other.getY();
    POINT* newPoint = new POINT(newX,newY);
    return *newPoint;
}
POINT & POINT::operator - (const POINT &other){// Überladener Subtraktionsoperator
    double newX = X-other.getX();
    double newY = Y-other.getY();
    POINT* newPoint = new POINT(newX,newY);
    return *newPoint;
}
POINT & POINT::operator * (double scalar){// Überladener Multiplikationsoperator, POINT * SkalarerWert
    double newX = X*scalar;
    double newY = Y*scalar;
    POINT* newPoint = new POINT(newX,newY);
    return *newPoint;
}
void POINT::show(){
    cout << "( "<<X<<" | " <<Y<<" )";
} // Ausgabe der Koordinaten in der Form ( x | y )
POINT::~POINT(){}


//LINE
LINE::LINE (POINT *P1, POINT *P2): POINT(*P1),P2(P2){
//Werte für Parameter darstellung berechnen
A = getY()-P2->getY();
B = P2->getX() - getX();
C = getX()*P2->getY() - P2->getX()*getY();
}
void LINE::getParmDarstellung(double &pA,double &pB,double &pC) const { //Methode wurde hinzugefuegt weil sonst der zugriff auf A,B und C unmöglich wäre
    pA = A;
    pB = B;
    pC = C;
}
POINT * LINE::meets (const LINE *L){
    if(parallelTo(L)){
        return nullptr;
    }else{
        double A2,B2,C2;
        L->getParmDarstellung(A2,B2,C2);
        double nenner = A2*B-A*B2;
        double newX = (B2*C-C2*B)/nenner;
        double newY = (C2*A-A2*C)/nenner;
        POINT * outPut = new POINT(newX,newY);
        return outPut;}
}  //Schnittpunkt für zwei Geraden
bool LINE::parallelTo(const LINE *L){//Feststellen, ob zwei Geraden parallel sind
    double A2,B2,C2;
    L->getParmDarstellung(A2,B2,C2);
    double temp = abs(A2*B - A * B2);
    return temp < Epsilon;
}
void LINE::show(){
    POINT::show();
    cout << ",";
    P2->show();
    }


//CIRCLE
CIRCLE::CIRCLE (POINT *M, double R){} //Initialisierungskonstruktor 1
CIRCLE::CIRCLE (POINT *A,POINT *B,POINT *C){} //Initialisierungskonstruktor 2
CIRCLE::POINT* getMiddle(){}
void CIRCLE::show(){} //Überschriebene Methode show, verwendet show von POINT: Ausgabe des Mittelpunktes und des Radius
bool CIRCLE::isInCircle(const POINT &){}
void CIRCLE::meetsOther(CIRCLE *C, int &Anzahl, POINT **S1, POINT **S2){} //C wird übergeben, Anzahl, S1 und S2 kommen zurück
