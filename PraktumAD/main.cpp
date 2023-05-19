#include <iostream>
#include <limits>
#include "Myclasses.h"
using namespace std;

int main()
{
    int auswahl = 0;
    CIRCLE *c1,*c2;
    POINT *s1,*s2;
    int anzahl;
    while(auswahl != 2){

        cout<<"geben Sie 2 Kreise um das verhaeltnis zu ihnen angezeigt zu bekommen"<<endl;
        c1 = readCIRCLE();
        cout << "Kreis eins :";
        c1->show();

        c2 = readCIRCLE();
        cout<<endl<<"Kreis zwei:";
        c2->show();
        cout<<endl;

        c1->meetsOther(c2,anzahl,&s1,&s2);

        switch(anzahl){
            case 0:{
                cout<<"Die Kreise schneiden sich nicht"<<endl;
                break;
                }
            case 1:{
                cout<< " Die Kreise schneiden sich in dem Punkt";
                s1->show();
                cout<<endl;
                break;
                }
            case 2:{
                cout<< "Die Kreise schneiden sich in den Punkten";
                s1->show();
                s2->show();
                cout<<endl;
                }
        }
        cout<<endl<<"Wählen Sie eine der Möglichkeiten:"<<endl<<"\t1) Weitere Kreise eingeben"<<endl<<"\t2) das Programm beenden"<<endl;
        auswahl = readInt(1,2);
        cout<<endl;
     }
  }

POINT * readPOINT(){
        double x,y;
        cout << "Geben Sie Die X Koordinate des punktes ein: "<<endl;
        cin >> x;
        cout << "Geben Sie Die Y Koordinate des punktes ein: "<<endl;
        cin >> y;

        return new POINT(x,y);
}

CIRCLE * readCIRCLE(){
    int auswahl;
    cout<< "Wie möchten Sie den Kreis Einlesen:" << endl <<"\t1) Mit Mittelpunkt und Radius"<<endl<<"\t2) Konstruktion aus 3 Punkten"<<endl;
    auswahl = readInt(1,2);
    CIRCLE *outPut;

    switch(auswahl){
        case 1:{
                POINT * mittelpunkt = readPOINT();
                cout<<"geben Sie den Radius des Kreises an"<<endl;
                double radius = readDouble(numeric_limits<double>::min(),numeric_limits<double>::max());
                 outPut = new CIRCLE(mittelpunkt,radius);
                delete mittelpunkt;
                return outPut;
            }
        case 2:{
            POINT* pointArray[3];
            bool pointsRight = false;
            while(!pointsRight){ // solange punkte einlesen bis diese legitim sind
                for(int i = 0; i<3;i++){
                    pointArray[i] = readPOINT();
                }
                int testResult;
                CIRCLE::testPOINTS(testResult,pointArray[0],pointArray[1],pointArray[2]);
                if(testResult == 0){
                    pointsRight = true;
                }else if(testResult == 1){
                    cout<<"Bitte geben Sie 3 unterschiedliche Punkte an"<<endl<<endl;
                }else if(testResult == 2){
                    cout <<"Die Punkte dürfen sich nicht auf einer Linie befinden"<<endl<<endl;
                }
            }
            outPut = new CIRCLE(pointArray[0],pointArray[1],pointArray[2]);
            for (int i = 0; i < 3; i++) {
                delete pointArray[i];
            }
            // Das Array löschen
            delete[] pointArray;
            return outPut;
        }
    }

}

int readInt(int min,int max){
    int outPut;
    cin >> outPut;
    if(outPut >=min && outPut <= max)
        return outPut;
    else{
        cout<<"geben Sie einen wert zwischen" << min << " und "<<max<<" ein!"<<endl;
        return readInt(min,max);
    }
}

double readDouble(double min, double max){
    double outPut;
    cin >> outPut;
    if(outPut >=min && outPut <= max)
        return outPut;
    else{
        cout<<"geben Sie einen wert zwischen" << min << " und "<<max<<" ein!"<<endl;
        return readDouble(min,max);
    }
}
