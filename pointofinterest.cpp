#include "Pointofinterest.h"

PointOfInterest::PointOfInterest()
{

}

PointOfInterest::PointOfInterest(double laengeGrad, double breiteGrad, string kategorie, string bemerkung)
    :Ort(laengeGrad, breiteGrad)
{
    this->kategorie = kategorie;
    this->bemerkung = bemerkung;
}

PointOfInterest::PointOfInterest(int id, double laengeGrad, double breiteGrad, string kategorie, string bemerkung)
    :Ort(id,laengeGrad, breiteGrad)
{
    this->kategorie = kategorie;
    this->bemerkung = bemerkung;
}

void PointOfInterest::show()
{
    int width = 20;
    cout << setw(5) << left << this->getId()  << "|" << setw(5) << left << "Pot"  << "|" << setw(width) << left  << this->getLaengeGrad() << "|" << setw(width) << left << this->getBreiteGrad() <<  "|"
         << this->kategorie << "," << this->bemerkung << endl;
}

string PointOfInterest::getBemerkung() const
{
    return bemerkung;
}

void PointOfInterest::setBemerkung(const string &value)
{
    bemerkung = value;
}

string PointOfInterest::getKategorie() const
{
    return kategorie;
}

void PointOfInterest::setKategorie(const string &value)
{
    kategorie = value;
}
