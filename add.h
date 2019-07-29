//
// Created by Ren Lucas on 2019-07-06.
//
class Add: public SubExpression
{
public:
    Add(Expression* left, Expression* right): SubExpression(left, right)
    {
    }

    int evaluate()
    {
        return left->evaluate() && right->evaluate();
    }
};