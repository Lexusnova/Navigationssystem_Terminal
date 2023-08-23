#ifndef POINTOFINTEREST_H
#define POINTOFINTEREST_H
#include "Ort.h"

#include <iostream>

using namespace std;

class PointOfInterest : public Ort
{
private:
    string kategorie;
    string bemerkung; //kommentar
public:
    PointOfInterest();
    PointOfInterest(double lGrad, double bGrad, string kategorie, string bemerkung);
    PointOfInterest(int id, double laengeGrad, double breiteGrad, string kategorie, string bemerkung);

    void show();
    void poiAnlegen();
    string getKategorie() const;
    void setKategorie(const string &value);
    string getBemerkung() const;
    void setBemerkung(const string &value);
};

#endif // POINTOFINTEREST_H
