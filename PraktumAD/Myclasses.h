

/* Dateiname: Myclasses.h:
Author: Tim Heinsberg
Beschreibung, usw.

Achtung: Signaturen d�rfen nicht ge�ndert werden!

*/

#ifndef MYCLASSES_H_INCLUDED
#define MYCLASSES_H_INCLUDED
#define Epsilon 0.00001

using namespace std;

class POINT{
   private:
       double X;
       double Y;

   protected:
      void setX(double);
      void setY(double);

   public :
      POINT ();  //Standardkonstruktor, Nutzung eventuell nicht erforderlich!
      POINT (double X, double Y); //Initialisierungskonstruktor
      POINT (POINT &); //Copy-Konstruktor
      double distanceTo(const POINT &);  // Abstand zweier POINT-Objekte
      double getX() const;// musste auf const ge�ndert werden da ich die Mehtode sonst in distance to nicht aufrufen kann
      double getY() const;// musste auf const ge�ndert werden da ich die Mehtode sonst in distance to nicht aufrufen kann
      POINT & operator = (const POINT &); // �berladener Zuweisungsoperator
      POINT & operator + (const POINT &); // �berladener Additionsoperator
      POINT & operator - (const POINT &); // �berladener Subtraktionsoperator
      POINT & operator * (double );  // �berladener Multiplikationsoperator, POINT * SkalarerWert
      virtual void show(); // Ausgabe der Koordinaten in der Form ( x | y )
      virtual ~POINT(); // Virtueller Destruktor, wird automatisch aufgerufen durch die Destruktoren von LINE und CIRCLE

};  //Ende class POINT

class LINE: public POINT{
   private:
      POINT * P2;   //pointer auf zweites POINT-Objekt f�r die Gerade
      double A,B,C; //Werte f�r die Parameterdarstellung der  Geraden
      void normalize(void); //Normalisierung nach Euklid, Verwendung im Konstruktor, kann weggelassen werden
   public :
      LINE (POINT *P1, POINT *P2); //Initialisierungskonstruktor
      POINT * meets (const LINE *L);  //Schnittpunkt f�r zwei Geraden
      bool parallelTo(const LINE *L); //Feststellen, ob zwei Geraden parallel sind
      void show(); //�berschriebene Methode show, verwendet show von POINT: Ausgabe der Koordinaten in der Form ( x1 | y1 ), ( x2 | y2 )

}; //class LINE

class CIRCLE: public POINT{
   private:
      double Radius;
      double skPro(POINT&, POINT &); //Hilfsfunktion um das Skalarprodukt zweier Vektoren zu bestimmen
   public:
      CIRCLE (POINT *M, double R); //Initialisierungskonstruktor 1
      CIRCLE (POINT *,POINT *,POINT *); //Initialisierungskonstruktor 2
      POINT* getMiddle();
      void show(); //�berschriebene Methode show, verwendet show von POINT: Ausgabe des Mittelpunktes und des Radius
      bool isInCircle(const POINT &);
      void meetsOther(CIRCLE *C, int &Anzahl, POINT **S1, POINT **S2); //C wird �bergeben, Anzahl, S1 und S2 kommen zur�ck
};  //class CIRCLE

#endif // MYCLASSES_H_INCLUDED:"
