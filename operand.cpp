#include <cctype>
#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(stringstream& iss)
{
    char paren;
    double value;

    iss >> ws;
    if (isdigit(iss.peek()))
    {
        iss >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (iss.peek() == '(')
    {
        iss >> paren;
        return SubExpression::parse(iss);
    }
    else
        return new Variable(parseName(iss));
    return 0;
}