//
// Created by Ren Lucas on 2019-07-06.
//

class Times : public SubExpression {
public:
    Times(Expression *left, Expression *right) : SubExpression(left, right) {}

    int evaluate() {
        return left->evaluate() * right->evaluate();
    }
};