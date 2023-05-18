
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
    return *(new POINT(newX,newY));
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
CIRCLE::CIRCLE (POINT *M, double R): POINT(*M),Radius(R){} //Initialisierungskonstruktor 1
CIRCLE::CIRCLE (POINT *A,POINT *B,POINT *C){} //Initialisierungskonstruktor 2
CIRCLE::POINT* getMiddle(){}
double CIRCLE::skPro(POINT & a,POINT &b){
    return a.getX()*b.getX()+a.getY()*b.getY();
}
double CIRCLE::getRadius(){return Radius;}
POINT* CIRCLE::getMiddle(){
    return new POINT(getX(),getY());
}
void CIRCLE::show(){} //Überschriebene Methode show, verwendet show von POINT: Ausgabe des Mittelpunktes und des Radius
bool CIRCLE::isInCircle(const POINT & P){
 return distanceTo(P) < Radius;
}
void CIRCLE::meetsOther(CIRCLE *C, int &Anzahl, POINT **S1, POINT **S2){

    //Anzahl schnittpunkte berechnen
    double distance =distanceTo(*C);

    if(isInCircle(*C)){
        double temp = distance+C->Radius;
        if(temp < Radius || distance < Epsilon){//kein schnittPunkt
            Anzahl = 0;
        }else if(temp == Radius){
            Anzahl = 1;
        }else{
            Anzahl = 2;
        }
    }else{
        if(distance > Radius + C->getRadius() ){//Es gibt keinen Schnittpunkt
            Anzahl = 0;
        }else if(distance == Radius + C->getRadius()){//ein schittpunkt
                Anzahl = 1;
        }else{
            Anzahl = 2;
        }
    }



    //Berechnung
        if(Anzahl > 0){
            double c = (skPro(*C,*C)-skPro(*this,*this))-(C->getRadius()*C->getRadius()-Radius*Radius);
        POINT n1 = *this-*C;
        n1 = n1*2;
        POINT n2(n1.getY()*-1,n1.getX());
        double n1Betrag = n1.distanceTo(POINT(0,0));
        double ls = -((c)/(pow(n1Betrag,2)));

        double p = (skPro(n2,*this)); //Teil vor der wurzel
        p = p/(n1Betrag*n1Betrag);

        double a = ((c*c)/(pow(n1Betrag,4)));//erster Bruch des subtrahenten in der wurzel
        a += ((2*c*skPro(n1,*this))/pow(n1Betrag,4));//zweiter Bruch des subtrahenten in der wurzel
        a += ((skPro(*this,*this)-pow(Radius,2))/(pow(n1Betrag,2)));

        double Ms1 = p + sqrt(pow(p,2)-a);
        double Ms2 = p - sqrt(pow(p,2)-a);

        *S1 = new POINT(n1*ls + n2*Ms1);
        *S2 = new POINT(n1*ls + n2*Ms2);
        }
   } //C wird übergeben, Anzahl, S1 und S2 kommen zurück
