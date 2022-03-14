#include <iostream>
#include <sstream>
using namespace std;
#include "AST.h"

enum TokenType
{
	Error,
	Plus,
	Minus,
	Mul,
	Div,
	EndOfText,
	OpenParenthesis,
	ClosedParenthesis,
	OpenCurly,
	CloseCurly,
	Var,
	Bool,
	Equal,
	LessThan,
	Not,
	Conj,
	Disj,
	Skip,
	Store,
	Commands,
	IfStatement,
	WhileStatement,
	Number
};

struct Token
{
	TokenType Type;
	double Value;
	bool tfValue;
	string Variable;
	char Symbol;

	Token() :Type(Error), Value(0), Symbol(0)
	{}
};

/*class ParserException : public exception
{
	int m_Pos;

public:
	ParserException(const string& message, int pos) :
		exception(message.c_str()),
		m_Pos(pos)
	{
	}
};*/

class Parser
{
	Token m_crtToken;
	const char* m_Text;
	size_t m_Index;

private:
	ASTNode* Expression();
	ASTNode* Expression1();
	ASTNode* Term();
	ASTNode* Term1();
	ASTNode* Factor();
	ASTNode* CreateNode(ASTNodeType type, ASTNode* left, ASTNode* right);
	ASTNode* CreateIfNode(ASTNodeType type, ASTNode* left, ASTNode* right, ASTNode* center);
	ASTNode* CreateUnaryNode(ASTNode* left);
	ASTNode* CreateNodeNumber(double value);
	void Match(char expected);
	void SkipWhitespaces();
	void GetNextToken();
	double GetNumber();
public:
	ASTNode* Parse(const char* text);
};