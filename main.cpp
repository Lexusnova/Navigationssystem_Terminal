#include <iostream>

#include "Data.h"


using namespace std;

int main()
{
    Data* data = new Data;
    
    int userInput;
    bool start = true;
    while (start) {
        data->menueAusgabe();
        cin >> userInput;
        switch (userInput) {
        case 1:
            data->ortAnlegen();
            break;
        case 2:
            data->karteAnzeigen();
            break;
        case 3:
            data->display();
            break;
        case 4:
            data->exportData();
            break;
        case 5:
            data->importData();
            break;
        case 0:
            exit(-1);
            break;
        default:
            cerr << "Wrong Input, Try it Again " << endl;
        }
    }
    return 0;
}
