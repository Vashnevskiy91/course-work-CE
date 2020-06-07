#include <iostream>
#include <vector>
#include <windows.h>
#include "Teacher.h"
using namespace std;

vector<Teacher*> teachers;
vector<Student*> students;

void fill()
{	
	Student* s11 = new Student(16, 170, "Eugesha Batikov Alexandr", 11);
	s11->Random_Eval(30);

	Student* s12 = new Student(17, 180, "Eugen Bazhenov Ahmedov", 11);
	s12->Random_Eval(30);

	Student* s13 = new Student(16, 192, "Alexey Sheucov Sipulkovich", 11);
	s13->Random_Eval(30);

	Student* s21 = new Student(15, 156, "Jolly Golf Anatolievich", 10);
	s21->Random_Eval(30);

	Student* s22 = new Student(15, 174, "Jolly Bell Mihailovich", 10);
	s22->Random_Eval(30);

	Student* s23 = new Student(16, 199, "Alexey Pridko Ploykovich", 10);
	s13->Random_Eval(30);

	students.push_back(s11);
	students.push_back(s12);
	students.push_back(s13);
	students.push_back(s21);
	students.push_back(s22);
	students.push_back(s23);
	Teacher* math = new Teacher(59, 179, "Eugeniy Alexandrov Alexandrovich", subject::Math);
	Teacher* lang = new Teacher(42, 189, "Eugeniy Makarey Makarevich", subject::Language);
	Teacher* phys = new Teacher(23, 155, "Eugeniy Evgen Evgenich", subject::Physics);
	Teacher* prog = new Teacher(60, 187, "Eugeniy Neevgen Neevgeneevich", subject::Programming);
	teachers.clear();
	teachers.push_back(math);
	teachers.push_back(lang);
	teachers.push_back(phys);
	teachers.push_back(prog);
	
	math->Add_student(s11);
	math->Add_student(s12);
	math->Add_student(s13);
	math->Add_student(s21);
	math->Add_student(s22);
	math->Add_student(s23);

	lang->Add_student(s11);
	lang->Add_student(s12);
	lang->Add_student(s13);
	lang->Add_student(s21);
	lang->Add_student(s22);
	lang->Add_student(s23);
	
	phys->Add_student(s11);
	phys->Add_student(s12);
	phys->Add_student(s13);
	phys->Add_student(s21);
	phys->Add_student(s22);
	phys->Add_student(s23);
	
	prog->Add_student(s11);
	prog->Add_student(s12);
	prog->Add_student(s13);
	prog->Add_student(s21);
	prog->Add_student(s22);
	prog->Add_student(s23);
}

int main()
{
	while (true)
	{
		int command;
		cout << "Commands:" << endl;
		cout << "0: Fill 10 and 11 classes" << endl;
		cout << "1: List of students" << endl;
		cout << "2: List of teachers" << endl;
		cout << "3: Average student's evaluation" << endl;
		cout << "4: Average teacher's evaluation" << endl;
		cout << "5: Add student" << endl;
		cout << "6: Kick out student" << endl;
		cout << "7: Add(update) teacher" << endl;
		cout << "8: Rate student" << endl;
		cout << "9: Exit" << endl;
		cin >> command;
		int s;
		cout << endl;
		switch (command)
		{
			case 0:
			{
				fill();
				break;
			}
			case 1:// Список учеников
			{
				s = students.size();
				for (int i = 0; i < s; i++)
				{
					int clas = students[i]->ClassNomer;
					cout << i << ": " << students[i]->data() << ". " << clas << " class" << endl;
				}
				break;
			}
			case 2: // список учителей 
			{
				s = teachers.size();
					
				for (int i = 0; i < s; i++)
				{
					string s;
					switch (teachers[i]->sub)
					{
						case subject::Programming: s = "Programming"; break;
						case subject::Math: s = "Math"; break;
						case subject::Physics: s = "Physics"; break;
						case subject::Language: s = "Language"; break;
					}
					cout << i << ": " << teachers[i]->data() << ". Subject: " << s << endl;
				}
				break;
			}
			case 3: // средний балл ученика
			{
				cout << "Student's number: ";
				cin >> s;
				cout << endl;
				int sub;
				cout << "Which subject?" << endl;
				cout << "1: Language" << endl;
				cout << "2: Math" << endl;
				cout << "3: Physics" << endl;
				cout << "4: Programming" << endl;
				cin >> sub;
				subject subj;
				switch (sub)
				{
					case 1: subj = subject::Language;
						break;
					case 2:subj = subject::Math;
						break;
					case 3:subj = subject::Physics;
						break;
					case 4:subj = subject::Programming;
						break;
					default:
						cout << "As default was chosen language";
						subj = subject::Language;
						break;
				}
				students[s]->PrintAverage(subj);
				break;
			}
			case 4: // средний балл учителя
			{
				cout << "Teacher's number: ";
				cin >> s;
				cout << endl;
				cout << "Which class? ";
				int clas;
				cin >> clas;
				cout << endl;
				double aver = teachers[s]->Average(clas);
				cout << "Average teacher's evaluation in this class: " << aver << endl;
				break;
			}
			case 5: // + ученик
			{
				cout << "Input Full name, class, age and growth" << endl;
				string F;
				string I;
				string O;
				int clas;
				int gr;
				int age;
				cin >> F >> I >> O >> clas >> age >> gr;
				Student* s = new Student(age, gr, F + " " + I + " " + O, clas);
				int l = teachers.size();
				for (int i = 0; i < l; i++)
				{
					teachers[i]->Add_student(s);
				}
				students.push_back(s);
				break;
			}
			case 6:
			{
				cout << "Number? ";
				int ws;
				cin >> ws;
				cout << endl;
				students.erase(students.begin() + ws);
				break;
			}
			case 7: // добавить(заменить) учителя
			{
				cout << "Input Full name, age and growth" << endl;
				string F;
				string I;
				string O;
				int gr;
				int age;
				int sub;
				cin >> F >> I >> O >> age >> gr;
				cout << "Which subject?" << endl;
				cout << "1: Language" << endl;
				cout << "2: Math" << endl;
				cout << "3: Physics" << endl;
				cout << "4: Programming" << endl;
				cin >> sub;
				subject subj;
				switch (sub)
				{
					case 1: subj = subject::Language;
						break;
					case 2:subj = subject::Math;
						break;
					case 3:subj = subject::Physics;
						break;
					case 4:subj = subject::Programming;
						break;
					default:
					{
						cout << "As default was chosen language";
						subj = subject::Language;
						break;
					}
				}
				Teacher* t = new Teacher(age, gr, F + " " + I + " " + O, subj);
				int ts = teachers.size();
				for (int i = 0; i < ts; i++)
				{
					if (teachers[i]->sub == subj)
					{
						teachers.erase(teachers.begin() + i);
						break;
					}
				}
				ts = students.size();
				for (int i = 0; i < ts; i++)
				{
					t->Add_student(students[i]);
				}
				teachers.push_back(t);
				break;
			}
			case 8: // Поставить оценку 
			{
				cout << "Which student? ";
				int ws;
				cin >> ws;
				cout << endl << "Rate? ";
				int eval;
				cin >> eval;
					
				cout << endl << "Which subject?" << endl;
				cout << "1: Language" << endl;
				cout << "2: Math" << endl;
				cout << "3: Physics" << endl;
				cout << "4: Programming" << endl;
				int sub;
				subject subj;
				cin >> sub;
				switch (sub)
				{
					case 1: subj = subject::Math;
						break;
					case 2: subj = subject::Language;
						break;
					case 3: subj = subject::Physics;
						break;
					case 4: subj = subject::Programming;
						break;
					default:
					{
						cout << "As default was chosen language";
						subj = subject::Language;
					}
				}
				cout << endl << "Which type of the work?" << endl;
				cout << "1: Home" << endl;
				cout << "2: Test" << endl;
				cout << "3: Solo" << endl;
				cout << "4: Exam" << endl;
				int t;
				evalType type;
				cin >> t;
				switch (t)
				{
					case 1: type = evalType::Home;
						break;
					case 2: type = evalType::Control;
						break;
					case 3: type = evalType::Solo;
						break;
					case 4: type = evalType::Exam;
						break;
					default:
					{
						cout << "As default was chosen solo" << endl;
						type = evalType::Solo;
					}
				}
				students[ws]->Add_Eval(subj, type, eval);
				break;
			}

			case 9: return 0;
		}
		cout << endl;
	}	
}
