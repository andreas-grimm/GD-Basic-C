//
//  expression.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 30/08/2023.
//

#include "expression.hpp"

/**
 * Expression classes implement this to evaluate the expression and
 * return the value.
 *
 * @return The value of the calculated expression.
 * @throws Exception - Any Exception generated in a lower part of the program.
 */
Value* Expression::evaluate() {
    mpoLogger->error("Expression::evaluate","Non-covered mandatory class used");
    exit(ERR_UNCOVERED_MANDATORY_CLASS);
};
 
/**
 * Get the content in human readable form.
 *
 * @return Content in readable form
 */
string Expression::content() {
    mpoLogger->error("Expression::content","Non-covered mandatory class used");
    exit(ERR_UNCOVERED_MANDATORY_CLASS);
}

