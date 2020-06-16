#pragma once
#include "vector"
#include "student.h"
using namespace std;


class Teacher : public Human
{
private:
	vector<Student*> students;
public:
	subject sub;
	Teacher(int age, int growth, string fio, subject s) : Human(age, growth, fio)
	{
		sub = s;
	}
	
	void Add_student(Student* s)
	{
		students.push_back(s);
	}

	double Average(int clas)
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
};
