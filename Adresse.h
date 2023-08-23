#ifndef ADRESSE_H
#define ADRESSE_H

#include "Ort.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Adresse : public Ort
{
private:
    string strasse;
    int hausnummer;
    int postleitzahl;
    string gemeinde;

public:
    Adresse();
    Adresse(double lGrad, double bGrad, string strasse, int number, int postleitzahl, string gemeinde);
    Adresse(int id,double laengeGrad, double breiteGrad, string strasse, int number, int postleitzahl, string gemeinde);

    void show();
    string getStrasse() const;
    void setStrasse(const string &value);
    int getHausnummer() const;
    void setHausnummer(int value);
    int getPostleitzahl() const;
    void setPostleitzahl(int value);
    string getGemeinde() const;
    void setGemeinde(const string &value);
};

#endif // ADRESSE_H
