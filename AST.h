#include <iostream>
using namespace std;

enum ASTNodeType
{
	Undefined,
	OperatorPlus,
	OperatorMinus,
	OperatorMul,
	OperatorDiv,
	UnaryMinus,
	NumberValue,
	Variables, //need code
	BoolValue,
	OperatorEqual,
	OpLessThan,
	OperatorNot,
	OperatorConj,
	OperatorDisj,
	OperatorSkip,
	OperatorStore,
	OperatorCommands,
	OpIfStatement,
	OpWhileStatement
};

class ASTNode
{
public:
	ASTNodeType Type;
	double Value;
	ASTNode *Left;
	ASTNode *Right;
	ASTNode *Center;
	ASTNode();
	~ASTNode();
};