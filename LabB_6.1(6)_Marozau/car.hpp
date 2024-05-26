#pragma once
#include"motorcycle.hpp";
class Car : public Motorcycle
{

public:

    enum Is_taxi { yes, no, not_identified };

    Car(int& xmin, int& xmax, int& ymin, int& ymax, double& colour, char& number, Is_taxi& taxi) : Motorcycle(xmin, xmax, ymin, ymax, colour, number){
        this->Is_taxi = taxi;
    };
    Car(Car& car) : Motorcycle(car.xmin, car.xmax, car.ymin, car.ymax,car.colour,*car.number) {
        this->Is_taxi = Is_taxi;
    }
    Car(Car&& car) : Motorcycle(car.xmin, car.xmax, car.ymin, car.ymax, car.colour, *car.number) {
        car.~Car();
    }
    Car& operator=(const Car& car)
    {
        this->xmax = car.xmax;
        this->xmin = car.xmin;
        this->ymax = car.ymax;
        this->ymin = car.ymin;
        this->colour = car.colour;
        this->number = car.number;
    }
    //Motorcycle& operator>>(const Motorcycle& moto)
    Car& operator = (Car&& car)
    {
        this->xmax = car.xmax;
        this->xmin = car.xmin;
        this->ymax = car.ymax;
        this->ymin = car.ymin;
        this->colour = car.colour;
        this->number = car.number;
        car.~Car();
    }
    ~Car() {
        delete[] number;
        cout << "destr";
    };
    const char* getTextForEnum(Is_taxi& is_taxi)
    {
        switch (is_taxi)
        {
        case Is_taxi::yes:
            return "yes";
        case Is_taxi::no:
            return "no";
        case Is_taxi::not_identified:
            return "not_identified";

        default:
            return "Not recognized..";
        }
    }
    virtual const void Print() {
        cout << "Car" << endl;
        cout << "xmin : " << this->xmin << " , xmax : " << this->xmax << endl;
        cout << "ymin : " << this->ymin << " , ymax : " << this->ymax << endl;
        cout << "colour : " << this->colour << " , number : " << this->number << endl;
        cout << "is taxi : " << getTextForEnum(this->Is_taxi);
    }

    void set_Is_taxi(Is_taxi& Is_taxi) {
        this->Is_taxi = Is_taxi;
    }
    Is_taxi get_Is_taxi(void) {
        return this->Is_taxi;
    }
    bool Is_taxi_validator() {
        return ( this->Is_taxi >= 0 && this->Is_taxi <= 2);
    }
    private:
    
    Car::Is_taxi Is_taxi;

    

};