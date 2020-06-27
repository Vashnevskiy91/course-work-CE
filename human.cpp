#include "human.h"

Human::Human(int age, int growth, string fio)
{
	Age = age;
	Growth = growth;
	FIO = fio;
}

string Human::data()
{
	return FIO + ". " + to_string(Age) + " - age. Growth: " + to_string(Growth);
}

