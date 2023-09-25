//
//  statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 24/08/2023.
//

#include "statement.hpp"

Statement::Statement() {
};

int Statement::getTokenNumber() {
    exit(ERR_UNDEFINED_STATEMENT);
};

void Statement::execute() {
    exit(ERR_UNDEFINED_STATEMENT);
};
