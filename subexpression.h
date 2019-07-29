class SubExpression : public Expression {
public:
    SubExpression(Expression *left, Expression *right);

    //constructor for conditional expression
    SubExpression(Expression *left, Expression *right, Expression *condition);

    //constructor for negation expression
    SubExpression(Expression *left);

    static Expression *parse(stringstream& iss);

protected:
    Expression *left;
    Expression *right;
    Expression *condition;
};