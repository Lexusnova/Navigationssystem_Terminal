#include "Ort.h"

Ort::Ort()
{

}

int Ort::counter = 1;

Ort::Ort(double laengeGrad, double breiteGrad)
{
    this->laengeGrad = laengeGrad;
    this->breiteGrad = breiteGrad;
    this->id = counter;
    counter++;
}

Ort::Ort(int id, double laengeGrad, double breiteGrad)
{
    this->laengeGrad = laengeGrad;
    this->id= id;
    this->breiteGrad = breiteGrad;
}

void Ort::entfernungBerechnen()
{

}

void Ort::show()
{
    std::cout << this->laengeGrad;
    std::cout << this->breiteGrad;
    std::cout << this->id;
}


double Ort::getBreiteGrad() const
{
    return breiteGrad;
}

void Ort::setBreiteGrad(double value)
{
    breiteGrad = value;
}

double Ort::getLaengeGrad() const
{
    return laengeGrad;
}

void Ort::setLaengeGrad(double value)
{
    laengeGrad = value;
}


int Ort::getId() const
{
    return id;
}

void Ort::setId(int value)
{
    id = value;
}


void Ort::setCounter(int value)
{
    counter = value;
}
