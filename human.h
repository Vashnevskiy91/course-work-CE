#pragma once
#include <string>
using namespace std;

class Human
{
protected:
	int Age;
	int Growth;
public:
	string FIO;
	Human(int age, int growth, string fio)
	{
		Age = age;
		Growth = growth;
		FIO = fio;
	}
	string data()
	{
		return FIO + ". " + to_string(Age) + " - age. Growth: " + to_string(Growth);
	}
};
