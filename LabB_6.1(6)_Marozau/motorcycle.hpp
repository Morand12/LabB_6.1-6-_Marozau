#include <iostream>
#pragma once
#include"object.hpp";

class Motorcycle : public Object
{
protected:

    double colour;
    char* number;

public:
    Motorcycle(int& xmin, int& xmax, int& ymin, int& ymax, double& colour, char& number) :Object(xmin, xmax, ymin, ymax) {
        this->colour = colour;
        this->number = &number;
    }
    Motorcycle(Motorcycle& moto) :Object(moto.xmin, moto.xmax, moto.ymin, moto.ymax) {
        this->colour = moto.colour;
        this->number = moto.number;
    }
    Motorcycle(Motorcycle&& moto) :Object(moto.xmin, moto.xmax, moto.ymin, moto.ymax) {
        this->colour = moto.colour;
        this->number = moto.number;
        moto.~Motorcycle();
    }
    Motorcycle& operator=(const Motorcycle& moto)
    {
        this->xmax = moto.xmax;
        this->xmin = moto.xmin;
        this->ymax = moto.ymax;
        this->ymin = moto.ymin;
        this->colour = moto.colour;
        this->number = moto.number;
    }
    //Motorcycle& operator>>(const Motorcycle& moto)
    Motorcycle& operator = (Motorcycle&& moto)
    {
        this->xmax = moto.xmax;
        this->xmin = moto.xmin;
        this->ymax = moto.ymax;
        this->ymin = moto.ymin;
        this->colour = moto.colour;
        this->number = moto.number;
        moto.~Motorcycle();
    }
    ~Motorcycle() {
        delete[] number;
        cout << "destr";
    };

    virtual const void Print() {
        cout << "Motorcycle" << endl;
        cout << "xmin : " << this->xmin << " , xmax : " << this->xmax << endl;
        cout << "ymin : " << this->ymin << " , ymax : " << this->ymax << endl;
        cout << "colour : " << this->colour << " , number : " << this->number << endl;
    }

    void set_colour(double colour) {
        this->colour = colour;
    }
    double get_colour() {
        return this->colour;
    }
    void set_number(char& number) {
        this->number = &number;
    }
    char* get_number() {
        return this->number;
    }
    bool colour_validator(double colour) {
        return colour >= 0;
    }
    bool number_validator(char& number) {
        return strlen(&number) > 0;
    }
};