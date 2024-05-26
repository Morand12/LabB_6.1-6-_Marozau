#pragma once
#include"object.hpp";
class Bag : public Object
{
private:

    int secondsAfterMidnight;

public:

    Bag(int& xmin, int& xmax, int& ymin, int& ymax, int& secondsAfterMidnight) :Object(xmin, xmax, ymin, ymax) {
        this->secondsAfterMidnight = secondsAfterMidnight;
    };
    
    virtual const void Print() {
        cout << "Bag" << endl;
        cout << "xmin : " << this->xmin << " , xmax : " << this->xmax << endl;
        cout << "ymin : " << this->ymin << " , ymax : " << this->ymax << endl;
        cout << "seconds after midnight: " << this->secondsAfterMidnight;
    }

    void set_secondsAfterMidnight(int& secondsAfterMidnight) {
        this->secondsAfterMidnight = secondsAfterMidnight;
    }
    int get_secondsAfterMidnight() {
        return this->secondsAfterMidnight;
    }
    bool secondsAfterMidnight_validator() {
        return this->secondsAfterMidnight > 0;
    }
};