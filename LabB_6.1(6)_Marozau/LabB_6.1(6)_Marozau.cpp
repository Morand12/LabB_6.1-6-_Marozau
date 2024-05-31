#include <iostream>
#include <string>
#include "person.hpp"
#include "bag.hpp"
#include "car.hpp"
#include "motorcycle.hpp"

int main(){

	// class Object
	Object Test(3, 4, 5, 6);
	Test.Print();
	// class Bag
	Bag Test1(1, 2, 3, 4, 5);
	Test1.Print();
	Test1.set_secondsAfterMidnight(7);
	cout << Test1.get_secondsAfterMidnight() << endl;
	cout << Test1.secondsAfterMidnight_validator(Test1.get_secondsAfterMidnight())<<endl;
	// class Motorcycle
	int size = 7;
	char* number = new char[size];
	cout << "enter the number of motorcycle, 7 symbols: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> number[i];
	}
	Motorcycle Test2(9, 8, 7, 6, 3.43, number, size);
	Test2.Print();
	Motorcycle Test3(Test2);
	Test3.Print();
	Motorcycle Test4 = move(Test2);
	Test4.Print();
	// class Car
	Is_taxi taxi = (Is_taxi)1;
	Car Test6(1,2,3,4,5.5, number, size, taxi);
	Test6.Print();
	Car Test7(Test6);
	Test7.Print();
	Car Test8 = move(Test6);
	Test8.Print();
	Car Test9 = Test7;
	Test9.Print();
	//class Person
	TypeOfPerson typeOfPerson = TypeOfPerson(1);
	Sex sex = (Sex)1;
	Baby baby = (Baby)0;
	Glasses glasses = (Glasses)2;
	Beard beard = (Beard)1;
	Person TestP1(3,4,5,1, typeOfPerson, sex,  baby, glasses, beard);
	TestP1.Print();
	TestP1.set_Glasses((Glasses)1);
	TestP1.set_Sex((Sex)0);
	cout << "beard:";
	cout << TestP1.getTextForEnum(TestP1.get_Beard());
	TestP1.Print();
}

