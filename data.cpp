#include "Data.h"

#include <typeinfo>
#define pi 3.14159265358979323846


Data::Data()
{
    
}

Data::~Data()
{
    storage.clear();
}

void Data::menueAusgabe()
{
    cout <<  "(1) Ort Anlegen " << endl
          << "(2) Karte Anzeigen" << endl
          << "(3) Karte Berechnen"  << endl
          << "(4) Karte Expotieren" << endl
          << "(5) Importieren" << endl
          << "(0) Navigationssystem verlassen" << endl;
}

void Data::ortAnlegen()
{
    cout << "- (1) Adresse "
         << "- (2) Point of Interest " << endl;
    cout << "Geben sie ein was sie erstellen möchten" << endl;
    int userInput;
    cin >> userInput;

    if (userInput == 1) {
        int hausnummer, postleitzahl;
        double laengenGrad, breitenGrad;
        string strasse, gemeide;

        cout << "Geben sie bitte die LÄNGENGRAD, BREITENGRAD,STRASSE, HAUSNUMMER, POSTLEITZAHL, GEMEIDE ein" << endl;
        cout << "Geben sie die LÄNGENGRAD, BREITENGRAD ein " << endl;
        cin >> laengenGrad >> breitenGrad;
        cout << "Geben sie die HAUSNUMMER, POSTLEIZZAHL ein" << endl;
        cin >> hausnummer >> postleitzahl;
        cout << "Geben sie die STRASSE, GEMEIDE ein " << endl;
        cin >> strasse >> gemeide;
        Adresse* adresse = new Adresse(laengenGrad, breitenGrad, strasse, hausnummer, postleitzahl, gemeide);
        storage.push_back(adresse);
    } else {
        double laengenGrad, breitenGrad;
        string kategorie, bemerkung;

        cout << "Geben sie bitte die LÄNGENGRAD, BREITENGRAD, KATEGORIE, BEMERKUNG ein " << endl;
        cout << "Geben sie die LÄGENGRAD, BREITENGRAD ein" << endl;
        cin >> laengenGrad >> breitenGrad;
        cout << "Geben sie die KATEGORIE, BEMERKUNG ein" << endl;
        cin >> kategorie >> bemerkung;
        PointOfInterest* user = new PointOfInterest(laengenGrad, breitenGrad, kategorie, bemerkung);
        storage.push_back(user);
    }
    
}

void Data::karteAnzeigen()
{
    system("clear");
    vector<PointOfInterest*> info;
    vector<Adresse*> stats;
    const int size = storage.size();
    for (int i = 0; i < size; i++) {
        //Dynamic Cast funktioniert nur mit Klassen
        if (PointOfInterest *temp = dynamic_cast<PointOfInterest*>(storage[i])) {
            info.push_back(temp);
        } else if (Adresse *adresse = dynamic_cast<Adresse*>(storage[i])) {
            stats.push_back(adresse);
        }
    }
    sortInformation();
    int width = 20;
    cout  << "ID   " << setw(6) << left <<  "|Type " << setw(22) << left << "|Längengrad" << setw(21) << left << "|Breitengrad " << setw(width) << left << "|Information" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < storage.size(); i++)
    {
        storage[i]->show();
    }
}

void Data::sortInformation()
{
    for (size_t i = 1; i < storage.size(); i++)
    {
        for (size_t j = 0;j < storage.size()-1; j++)
        {
            if (storage[j]->getId() > storage[j+1]->getId())
            {
                swap(storage[j], storage[j+1]);
            }
        }
    }
}
double Data::toRad(double degree) {
    return degree/180 * pi;
}

double Data::entfernungBerechnen(Ort* medien, Ort* medien2)
{
    double radius  = 6372.795477598;
    double ergebnis = sin(toRad(medien->getLaengeGrad())) * sin(toRad(medien2->getLaengeGrad()))
            + cos(toRad(medien->getLaengeGrad())) * cos(toRad(medien2->getLaengeGrad())) * cos(toRad(medien->getBreiteGrad() - medien2->getBreiteGrad()));
    ergebnis = acos (ergebnis);
    ergebnis = ergebnis * radius;
    return ergebnis;
    //(A, B) = R * arccos (sin (lata) * sin (latB) + cos (lata) * cos (latB) * cos (LonA-LonB))
}

void Data::display()
{
    int userInput, userInput2;
    cin >> userInput >> userInput2;
    int size = storage.size();

    Ort* temp;
    Ort* temp2;
    for (int i = 0; i < size ;i++ ) {
        if (userInput == storage[i]->getId()) {
            temp = storage[i];
        }
        if (userInput2 == storage[i]->getId()) {
            temp2 = storage[i];
        }
    }
    double ergebnis = entfernungBerechnen(temp, temp2);
    cout << "Der Abstand zwischen den zwei Punkten beträgt: " << ergebnis  << "km" << endl;
}

void Data::exportData()
{
    system("clear");
    ofstream save;
    string line;
    const int size = storage.size();
    save.open("saveData.csv", ios::out);
    if (save) {
        for (int i = 0; i < size;i++) {
            if (PointOfInterest *temp = dynamic_cast<PointOfInterest*>(storage[i])) {
                save << temp->getId() << ";" << temp->getLaengeGrad() << ";" << temp->getBreiteGrad() << ";"
                     << "Pot" << ";"
                     << temp->getKategorie() << ";" << temp->getBemerkung()
                     << endl;
            } else if (Adresse *adresse = dynamic_cast<Adresse*>(storage[i])) {
                save << adresse->getId() << ";" << adresse->getLaengeGrad() << ";" << adresse->getBreiteGrad() << ";"
                     << "Adr" << ";"
                     << adresse->getHausnummer() << ";" << adresse->getStrasse() << ";" << adresse->getPostleitzahl() << ";" << adresse->getGemeinde()
                     << endl;
            }
        }
        cout << "Die Daten wurden erfolgreich gespeichert " << endl;
    } else {
        cerr << "Die Datei konnte nicht geöffnet werden" << endl;
    }

}

void Data::importData()
{
    storage.clear();
    fstream load;
    string line;
    string type;
    string id, längengrad,breitengrad;
    string kategorie, bemerkung;
    string hausnummer, strasse, postleitzahl, gemeinde;

    int id1;
    double längengrad1, breitengrad1;
    int hausnummer1, postleitzahl1;

    int biggestNumber = 0;
    string split = ";";
    load.open("saveData.csv", ios::in);
    if (load)
    {
        while (getline(load, line)) {
            id = line.substr(0, line.find(split));
            id1 = stoi(id);

            string temp = line.substr(line.find(split)+1, line.length());
            längengrad = temp.substr(0, temp.find(split));
            längengrad1 = stod(längengrad);

            string temp2 = temp.substr(temp.find(split)+1, temp.length());
            breitengrad = temp2.substr(0, temp2.find(split));
            breitengrad1 = stod(breitengrad);

            string temp3 = temp2.substr(temp2.find(split)+1, temp2.length());
            type = temp3.substr(0, temp3.find(split));
            PointOfInterest *pot;
            Adresse *adresse;
            if (type == "Pot") {
                string temp4 = temp3.substr(temp3.find(split)+1, temp3.length());
                kategorie = temp4.substr(0, temp4.find(split));

                string temp5 = temp4.substr(temp4.find(split)+1, temp4.length());
                bemerkung = temp5.substr(0, temp5.length());
                pot = new PointOfInterest(id1, längengrad1, breitengrad1, kategorie, bemerkung);
                storage.push_back(pot);
            } else {
                string temp4 = temp3.substr(temp3.find(split)+1, temp3.length());
                hausnummer = temp4.substr(0, temp4.find(split));
                hausnummer1 = stoi(hausnummer);

                string temp5 = temp4.substr(temp4.find(split)+1, temp4.length());
                strasse = temp5.substr(0, temp5.length());

                string temp6 = temp5.substr(temp5.find(split)+1, temp5.length());
                postleitzahl = temp6.substr(0, temp6.find(split));
                postleitzahl1 = stoi(postleitzahl);

                string temp7 = temp6.substr(temp6.find(split)+1, temp6.length());
                gemeinde = temp7.substr(0, temp7.length());

                adresse = new Adresse(id1, längengrad1, breitengrad1, strasse, hausnummer1, postleitzahl1, gemeinde);
                storage.push_back(adresse);
            }
            if (biggestNumber < id1) {
                biggestNumber = id1;
            }
        }
        {
            Ort *ort = new Ort;
            ort->setCounter(biggestNumber+1);
        }
        cout << "Die Karten wurden erfolgreich geladen" << endl;
        load.close();
    } else  {
        cerr << "Die Datei konnte nicht geöffnet werden" << endl;
    }

}
