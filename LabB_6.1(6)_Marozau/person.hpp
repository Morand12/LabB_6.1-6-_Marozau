#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "object.hpp";
class Person : public Object
{
public:
    enum class TypeOfPerson { human , cyclist };
    enum class Sex { male , female , not_identified };
    enum class Baby { yes , no , not_identified };
    enum class Glasses { yes , no , not_identified };
    enum class Beard { yes, no, not_identified };

    Person(int& xmin, int& xmax, int& ymin, int& ymax, TypeOfPerson& typeOfPerson, Sex& sex, Baby& baby, Glasses& glasses, Beard& beard) : Object(xmin, xmax, ymin, ymax) {
        this->TypeOfPerson = typeOfPerson;
        this->Sex = sex;
        this->Baby = baby;
        this->Glasses = glasses;
        this->Beard = beard;
    }

    const char* getTextForEnum(TypeOfPerson& typeofperson)
    {
        switch (typeofperson)
        {
        case TypeOfPerson::cyclist:
            return "cyclist";
        case TypeOfPerson::human:
            return "human";
        default:
            return "Not recognized..";
        }
    }

    const char* getTextForEnum(Sex&sex)
    {
        switch (sex)
        {
        case Sex::male:
            return "male";
        case Sex::female:
            return "female";
        case Sex::not_identified:
            return "not_identified";

        default:
            return "Not recognized..";
        }
    }

    const char* getTextForEnum(Baby&baby)
    {
        switch (baby)
        {
        case Baby::yes:
            return "yes";
        case Baby::no:
            return "no";
        case Baby::not_identified:
            return "not_identified";

        default:
            return "Not recognized..";
        }
    }

    const char* getTextForEnum(Glasses&glasses)
    {
        switch (glasses)
        {
        case Glasses::yes:
            return "yes";
        case Glasses::no:
            return "no";
        case Glasses::not_identified:
            return "not_identified";

        default:
            return "Not recognized..";
        }
    }

    const char* getTextForEnum(Beard&beard)
    {
        switch (beard)
        {
        case Beard::yes:
            return "yes";
        case Beard::no:
            return "no";
        case Beard::not_identified:
            return "not_identified";

        default:
            return "Not recognized..";
        }
    }

    virtual const void Print() {
        cout << "Person" << endl;
        cout << "xmin : " << this->xmin << " , xmax : " << this->xmax << endl;
        cout << "ymin : " << this->ymin << " , ymax : " << this->ymax << endl;
        cout << "type of person : " << getTextForEnum(this->TypeOfPerson) << " , sex : " << getTextForEnum(this->Sex) << endl;
        cout << "baby : " << getTextForEnum(this->Baby) << " , Glasses : " << getTextForEnum(this->Glasses) << endl;
        cout << "beard : " << getTextForEnum(this->Beard);
    }

    void set_TypeOfPerson(TypeOfPerson& TypeOfPerson) {
        this->TypeOfPerson = TypeOfPerson;
    }
    TypeOfPerson get_TypeOfPerson(void) {
        return this->TypeOfPerson;
    }

    void set_Sex(Sex& Sex) {
        this->Sex = Sex;
    }
    Sex get_Sex(void) {
        return Sex;
    }

    void set_Baby(Baby& Baby) {
        this->Baby = Baby;
    }
    Baby get_Baby(void) {
        return this->Baby;
    }

    void set_Glasses(Glasses& Glasses) {
        this->Glasses = Glasses;
    }
    Glasses get_Glasses(void) {
        return this->Glasses;
    }

    void set_Beard(Beard& Beard) {
        this->Beard = Beard;
    }
    Beard get_Beard(void) {
        return this->Beard;
    }
    bool TypeOfPerson_validator() {
        return (static_cast<int>(this->TypeOfPerson) >= 0 && static_cast<int>(this->TypeOfPerson) <= 1);
    }
    bool Sex_validator() {
        return(static_cast<int>(this->Sex) >= 0 && static_cast<int>(this->Sex) <= 2);
    }
    bool Baby_validator() {
        return(static_cast<int>(this->Baby) >= 0 && static_cast<int>(this->Baby) <= 2);
    }
    bool Glasses_validator() {
        return(static_cast<int>(this->Glasses) >= 0 && static_cast<int>(this->Glasses) <= 2);
    }
    bool Beard_validator() {
        return(static_cast<int>(this->Beard) >= 0 && static_cast<int>(this->Beard) <= 2);
    }

private:

    Person::TypeOfPerson TypeOfPerson;
    Person::Sex Sex;
    Person::Baby Baby;
    Person::Glasses Glasses;
    Person::Beard Beard;

};