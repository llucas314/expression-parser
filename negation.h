//
// Created by Ren Lucas on 2019-07-07.
//
class Negation: public SubExpression
{
public:
    Negation(Expression* left): SubExpression(left)
    {
    }

    int evaluate()
    {
        return !left->evaluate();
    }
};