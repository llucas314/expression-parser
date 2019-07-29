cmake_minimum_required(VERSION 3.14)
project(Project_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_2
        expression.h
        literal.h
        module3.cpp
        operand.cpp
        operand.h
        parse.cpp
        parse.h
        plus.h
        subexpression.cpp
        subexpression.h
        symboltable.cpp
        symboltable.h
        variable.cpp
        variable.h
        minus.h
        times.h divide.h ternary.h greaterthan.h lessthan.h equalto.h add.h or.h negation.h)
