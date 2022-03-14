#include <iostream>
using namespace std;
#include "interpreter.h"
#include "parser.h"
#include "AST.h"

void Test(const char* text)
{
    Parser parse;
    ASTNode* ast = parse.Parse(text);
}

int main()
{
    //easy
    Test("x := 1");
    Test("skip");
    Test("if true then x := 1 else x := 0");
    Test("while false do x := 3");
    Test("while x = 0 do x := 3");
    Test("x := 1 * 9 ; if 5 < x then x := 2 - 2 else y := 9");
    Test("if x = 0 ∧ y < 4 then x := 1 else x := 3");
    Test("if x = 0 ∧ 4 < 4 then x := 1 else x := 3");
    Test("if 0 < x ∧ 4 = 4 then x := 1 else x := 3");
    Test("if 0 < x ∧ 4 < y then x := 1 else x := 3");
    Test("if x = 0 ∨ y < 4 then x := 1 else x := 3");
    Test("if x = 0 ∨ 4 < 4 then x := 1 else x := 3");
    Test("if 0 < x ∨ 4 = 4 then x := 1 else x := 3");
    Test("if 0 < x ∨ 4 < y then x := 1 else x := 3");
    Test("while ¬ true do x := 1");
    Test("while ¬ ( x < 0 ) do x := -1");
    Test("TRUE := 1");
    Test("FALSE := 1");
    return 0;
}