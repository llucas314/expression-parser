#include <iostream>
#include <regex>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greaterthan.h"
#include "lessthan.h"
#include "equalto.h"
#include "add.h"
#include "or.h"
#include "ternary.h"
#include "negation.h"

SubExpression::SubExpression(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}

SubExpression::SubExpression(Expression *left, Expression *right, Expression *condition) {
    this->left = left;
    this->right = right;
    this->condition = condition;
}

SubExpression::SubExpression(Expression *left) {
    this->left = left;
}

Expression *SubExpression::parse(stringstream& iss) {
    Expression *left;
    Expression *right;
    Expression *condition;
    char operation, paren, question;

    left = Operand::parse(iss);
    iss >> operation;
    // checks to see if expression is a negation
    if (operation == '!') {
        iss >> paren;
        return new Negation(left);
    }
    right = Operand::parse(iss);
    iss >> ws;
    // checks for conditional operator
    if (iss.peek() == '?') {
        iss >> question;
        condition = Operand::parse(iss);
        iss >> paren;
        return new Ternary(left, right, condition);
    }
    iss >> paren;
    switch (operation) {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
        case '>':
            return new Greaterthan(left, right);
        case '<':
            return new Lessthan(left, right);
        case '=':
            return new Equalto(left, right);
        case '&':
            return new Add(left, right);
        case '|':
            return new Or(left, right);
    }
    return 0;
}
