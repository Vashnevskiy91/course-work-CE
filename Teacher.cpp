#include "Teacher.h"

Teacher::Teacher(int age, int growth, string fio, subject s) : Human(age, growth, fio)
{
	sub = s;
}

void Teacher::Add_student(Student* s)
{
	students.push_back(s);
}

double Teacher::Average(int clas)
{
	double averEval = 0;
	int c = 0;
	int l = students.size();
	for (int i = 0; i < l; i++)
	{
		Student* stud = students[i];
		if (stud->ClassNomer != clas)
			continue;

		int l1 = stud->evaluations.size();
		for (int j = 0; j < l1; j++)
		{
			if (stud->evaluations[j].sub == sub)
			{
				c++;
				averEval += stud->evaluations[j].Eval;
			}
		}
	}
	if (c == 0)
		return -1;
	return averEval / c;
}
