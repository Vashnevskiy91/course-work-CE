#include "student.h"

Student::Student(int age, int growth, string fio, int ClassNomer) : Human(age, growth, fio)
{
	this->ClassNomer = ClassNomer;
}

void Student::Add_Eval(subject sub, evalType type, int eval)
{
	evaluations.push_back(Evaluation{ eval,type,sub });
}

void Student::PrintAverage(subject sub)
{
	double averEval = 0;
	int av = 0;
	int l = evaluations.size();
	for (int i = 0; i < l; i++)
	{
		if (evaluations[i].sub == sub)
		{
			string type;
			switch (evaluations[i].type)
			{
				case evalType::Solo: type = "Solo work: ";
					break;
				case evalType::Control:type = "Test work: ";
					break;
				case evalType::Exam:type = "Exam: ";
					break;
				case evalType::Home:type = "Home work: ";
					break;
			}
			int eval = evaluations[i].Eval;
			cout << type << eval << endl;
			av++;
			averEval += eval;
		}
	}
	averEval /= av;
	cout << "Final: " << averEval << endl;
}

void Student::Random_Eval(int count_of_evals)
{

	for (int i = 0; i < count_of_evals; i++)
	{
		int type = rand() % 4;
		evalType etype;
		switch (type)
		{
			case 0: etype = evalType::Solo;
				break;
			case 1: etype = evalType::Control;
				break;
			case 2: etype = evalType::Exam;
				break;
			case 3: etype = evalType::Home;
				break;
		}
		int bal = rand() % 12 + 1;
		subject s;
		type = rand() % 4;
		switch (type)
		{
			case 0: s = subject::Math;
				break;
			case 1: s = subject::Language;
				break;
			case 2: s = subject::Physics;
				break;
			case 3: s = subject::Programming;
				break;
		}
		evaluations.push_back(Evaluation{ bal, etype, s });
	}
}