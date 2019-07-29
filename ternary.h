//
// Created by Ren Lucas on 2019-07-06.
//
class Ternary : public SubExpression {
public:
    Ternary(Expression *left, Expression *right, Expression *condition) : SubExpression(left, right, condition) {
    }

    int evaluate() {
        // reverses the values in the condition operator
        int condition_variable = condition->evaluate();
        if (condition_variable) {
            return left->evaluate();
        } else {
            return right->evaluate();
        }
    }
};
