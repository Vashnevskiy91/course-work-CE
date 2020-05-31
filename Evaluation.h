#pragma once
#include "string"
using namespace std;
enum class subject
{
	Language,
	Programming,
	Math,
	Physics
};
enum class evalType
{
	Home,
	Control,
	Solo,
	Exam
};

struct Evaluation
{
	int Eval;
	evalType type;
	subject sub;
};