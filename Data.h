#ifndef DATA_H
#define DATA_H

#include "Ort.h"

#include "Adresse.h"
#include "Pointofinterest.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <ostream>

using namespace std;

class Data
{
private:
    vector<Ort*> storage;
public:
    Data();
    ~Data();
    void exportData();
    void importData();

    double toRad(double degree);
    double entfernungBerechnen(Ort* medien, Ort* medien2);
    void display();
    void sortInformation();
    void menueAusgabe();
    void ortAnlegen();
    void karteAnzeigen();

};

#endif // DATA_H
