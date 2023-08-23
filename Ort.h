#ifndef ORT_H
#define ORT_H

#include <iostream>
#include <iomanip>

class Ort
{
private:
    double laengeGrad;
    double breiteGrad;
    int id;
    int static counter;
public:
    Ort();
    Ort(double laengeGrad, double breiteGrad);
    Ort(int id , double laengeGrad, double breiteGrad);
    virtual void show();
    void entfernungBerechnen();
        
    double getLaengeGrad () const;
    void setLaengeGrad(double value);
    double getBreiteGrad() const;
    void setBreiteGrad(double value);
    int getId() const;
    void setId(int value);
    static void setCounter(int value);
};

#endif // ORT_H
