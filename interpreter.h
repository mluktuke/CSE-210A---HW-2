#include <iostream>
#include <sstream>
using namespace std;
#include "AST.h"
#include "parser.h"

/*class EvaluatorException : public exception
{
public:
	EvaluatorException(const string& message) :
		exception(message.c_str())
	{
	}
};*/

class Evaluator
{
	double eval(ASTNode* ast);
	bool evalBool(ASTNode* ast);
	void evalWhile(ASTNode* ast);
    void evalIfElse(ASTNode* ast);
public:
	double Eval(ASTNode* ast);
};