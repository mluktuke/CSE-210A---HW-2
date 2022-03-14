#include <iostream>
#include <sstream>
using namespace std;
#include "interpreter.h"

double Evaluator::eval(ASTNode* ast)
{
	/*if (ast == NULL)
	{
		stringstream str;
		str << "Invalid input!";
		throw EvaluatorException(str.str());
	}*/
	if (ast->Type == NumberValue)
		return ast->Value;
	else if (ast->Type == UnaryMinus)
		return -eval(ast->Left);
	else if (ast->Type == OpWhileStatement)
	{
		bool c1 = eval(ast->Left);
		bool c2 = eval(ast->Right);
		while (c1)
		{
			return c2;
		}
	}
	else
	{
		double e1 = eval(ast->Left);
		double e2 = eval(ast->Right);
		switch (ast->Type)
		{
		case OperatorPlus:
			return e1 + e2;
		case OperatorMinus:
			return e1 - e2;
		case OperatorMul:
			return e1 * e2;
		case OperatorDiv:
			return e1 / e2;
		}
	}
	stringstream str1;
	str1 << "Invalid syntax tree!";
	//throw EvaluatorException(str1.str());
}

void Evaluator::evalWhile(ASTNode* ast)
{
    bool c1 = evalBool(ast->Left);
	bool c2 = evalBool(ast->Right);
    while (c1)
    {
        cout << c2;
    }
}

void Evaluator::evalIfElse(ASTNode* ast)
{
    bool b1 = evalBool(ast->Center);
    bool b2 = eval(ast->Left);
    bool b3 = eval(ast->Right);
    if (b1)
        cout << b2;
    else
        cout << b3;
}

bool Evaluator::evalBool(ASTNode* ast)
{
	if (ast->Type == BoolValue)
		return ast->Value;
	else if (ast->Type == OperatorNot)
		return !(ast->Value);
	else
	{
		double e1 = eval(ast->Left);
		double e2 = eval(ast->Right);
		switch (ast->Type)
		{
		case OperatorEqual:
			if (e1 == e2)
				return true;
			else
				return false;
		case OpLessThan:
			if (e1 < e2)
				return true;
			else
				return false;
		case OperatorConj:
			bool conj = e1 && e2;
			if (conj == 1)
				return true;
			else 
				return false;
		case OperatorDisj:
			return e1 || e2;
		}
	}
}

double Evaluator::Eval(ASTNode* ast)
{
	if (ast == NULL)
	{
		stringstream str2;
		str2 << "Invalid abstract syntax tree!";
		//throw EvaluatorException(str2.str());
	}

	return eval(ast);
}