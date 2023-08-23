#include "Adresse.h"

Adresse::Adresse()
{

}


Adresse::Adresse(double laengeGrad, double breiteGrad, string strasse, int number, int postleitzahl, string gemeinde)
    :Ort(laengeGrad, breiteGrad)
{
    this->strasse = strasse;
    this->hausnummer = number;
    this->postleitzahl = postleitzahl;
    this->gemeinde = gemeinde;
}

Adresse::Adresse(int id,double laengeGrad, double breiteGrad, string strasse, int number, int postleitzahl, string gemeinde)
    :Ort(id, laengeGrad, breiteGrad)
{
    this->strasse = strasse;
    this->hausnummer = number;
    this->postleitzahl = postleitzahl;
    this->gemeinde = gemeinde;
}
void Adresse::show()
{
    int width = 20;
    cout << setw(5) << left << this->getId() << "|" << setw(5) << left << "Addr"  << "|" << setw(width) << left << this->getLaengeGrad() << "|" << setw(width) << left <<  this->getBreiteGrad() <<  "|"
         << this->hausnummer  << "," << this->strasse << "," << this->postleitzahl << "," << this->gemeinde << endl;
}


int Adresse::getHausnummer() const
{
    return hausnummer;
}

void Adresse::setHausnummer(int value)
{
    hausnummer = value;
}

int Adresse::getPostleitzahl() const
{
    return postleitzahl;
}

void Adresse::setPostleitzahl(int value)
{
    postleitzahl = value;
}

string Adresse::getGemeinde() const
{
    return gemeinde;
}

void Adresse::setGemeinde(const string &value)
{
    gemeinde = value;
}

string Adresse::getStrasse() const
{
    return strasse;
}

void Adresse::setStrasse(const string &value)
{
    strasse = value;
}
