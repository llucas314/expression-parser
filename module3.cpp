#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(stringstream &iss);

int main() {


    Expression *expression;
    char paren, comma;
    string line;
    int number = 1;
    string fileName = "input.txt";

    // creates input stream to read from file
    ifstream fileInput(fileName);

    if (!fileInput.is_open()) {
        cerr << "Error Opening File" << endl;
        exit(1);
    }

    // adds a title to the output
    string title = "Expression Results Of " + fileName;

    for (int i = 0; title[i]!='\0'; i++) {
        cout << "*";
    }
    cout << endl << title << endl;

    for (int i = 0; title[i]!='\0'; i++) {
        cout << "*";
    }

    cout << endl << endl;

    // parses the file by line and evaluates the expression
    while (getline(fileInput, line)) {
        symbolTable.clear();
        if (!fileInput)
            break;
        stringstream iss(line, ios_base::in);
        iss >> paren;
        cout << "Expression #" << number << " " << line << endl;
        number++;
        expression = SubExpression::parse(iss);
        iss >> comma;
        parseAssignments(iss);
        int result = expression->evaluate();
        cout << "\t" << "Value = " << result << endl << endl;

    }
    fileInput.close();
    return 0;
}

void parseAssignments(stringstream &iss) {
    char assignop, delimiter;
    string variable;
    double value;
    symbolTable.clear();
    do {
        variable = parseName(iss);
        iss >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    } while (delimiter == ',');
}