#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "parse.h"

string parseName(stringstream& iss)
{
    char alnum;
    string name = "";

    iss >> ws;
    while (isalnum(iss.peek()))
    {
        iss >> alnum;
        name += alnum;
    }
    return name;
}