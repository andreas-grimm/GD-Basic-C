//
//  function.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 25/09/2023.
//

#include "function.hpp"

/**
 * Contructor for functions without parameter.
 *
 * @param oToken token to be executed.
 */
Function::Function(Token oToken) {
    moToken = oToken;
    mpoFirstParam = NULL;
    mpoSecondParam = NULL;
    mpoThirdParam = NULL;
}

/**
 * Contructor for functions with one parameter.
 *
 * @param oToken      token to be executed
 * @param poExpression parameter of the function
 */
Function::Function(Token oToken, Expression* poExpression) {
    moToken = oToken;
    mpoFirstParam = poExpression;
    mpoSecondParam = NULL;
    mpoThirdParam = NULL;
}

/**
 * Contructor for functions with one parameter.
 *
 * @param oToken      token to be executed
 * @param poFirstParam parameter of the function
 * @param poSecondParam parameter of the function
 */
Function::Function(Token oToken, Expression* poFirstParam, Expression* poSecondParam) {
    moToken = oToken;
    mpoFirstParam = poFirstParam;
    mpoSecondParam = poSecondParam;
    mpoThirdParam = NULL;
}

/**
 * Contructor for functions with three parameter.
 *
 * @param oToken      token to be executed
 * @param poFirstParam parameter of the function
 * @param poSecondParam parameter of the function
 * @param poThirdParam parameter of the function
 */
Function::Function(Token oToken, Expression* poFirstParam, Expression* poSecondParam, Expression* poThirdParam) {
    moToken = oToken;
    mpoFirstParam = poFirstParam;
    mpoSecondParam = poSecondParam;
    mpoThirdParam = poThirdParam;
}

/**
 * This method is used to trigger the function selected.
 *
 * @return - value containing the result of the function
 * @throws Exception - when the processing is running into a problem
 */
Value* Function::evaluate() {

    switch (moToken.getType()) {
        // ABS Token: Return the absolute value of the parameter
        case BasicTokenType::ABS: {
            return Abs::execute(mpoFirstParam->evaluate());
        }
        // ASC Token: Return the ASCII value of the parameter
        case BasicTokenType::ASC: {
            return Asc.execute(mpoFirstParam->evaluate());
        }
        // ATN Token: Return the arch tangents of the parameter
        case BasicTokenType::ATN: {
            return Atn.execute(mpoFirstParam->evaluate());
        }
        // CDBL Token: Convert to a DBL (Real)
        case BasicTokenType::CDBL: {
            return Cdbl.execute(mpoFirstParam->evaluate());
        }
        // CHR Token: Return the character of the ASCII value parameter
        case BasicTokenType::CHR: {
            return Chr.execute(mpoFirstParam->evaluate());
        }
        // CINT Token: Convert to a INT (Integer)
        case BasicTokenType::CINT: {
            return Cint.execute(mpoFirstParam->evaluate());
        }
        // COS Token: Return the CoSinus of the value parameter
        case BasicTokenType::COS: {
            return Cos.execute(mpoFirstParam->evaluate());
        }
        // EXP Token: Return the Exponent to the base e of the value parameter
        case BasicTokenType::EXP: {
            return Exp.execute(mpoFirstParam->evaluate());
        }
        // INSTR Token: Return the Index of the location of the second parameter in the first parameter
        case BasicTokenType::INSTR: {
            return Instr.execute(mpoFirstParam->evaluate(), mpoSecondParam->evaluate());
        }
        // LEFT Token: Return the first number of characters from the input string. The first parameter needs
        // to be a type String, the second parameter has to be part Integer.
        case BasicTokenType::LEFT: {
            return Left.execute(mpoFirstParam->evaluate(), mpoSecondParam->evaluate());
        }
        // LEN Token: Returns the Length of the String in the first parameter
        case BasicTokenType::LEN: {
            return Len.execute(mpoFirstParam->evaluate());
        }
        // LOG10 Token: Return the Logarithm Decimalis of the value parameter
        case BasicTokenType::LOG10: {
            return Log10.execute(mpoFirstParam->evaluate());
        }
        // MEM Token: Return size of available memory
        case BasicTokenType::MEM: {
            return Mem.execute();
        }
        // MID Token: Returns a substring of an input string with start and end position
        case BasicTokenType::MID: {
            return Mid.execute(mpoFirstParam->evaluate(), mpoSecondParam->evaluate(), mpoThirdParam->evaluate());
        }
        // RIGHT Token: Return the last number of characters from the input string. The first parameter needs
        // to be a type String, the second parameter has to be part Integer.
        case BasicTokenType::RIGHT: {
            return Right.execute(mpoFirstParam->evaluate(), mpoSecondParam->evaluate());
        }
        // RND Token: Return a pseudo random number between 0 and 1
        case BasicTokenType::RND: {
            return Rnd.execute();
        }
        // SIN Token: Return the Sinus of the value parameter
        case BasicTokenType::SIN: {
            return Sin.execute(mpoFirstParam->evaluate());
        }
        // SQR Token: Return the Square Root of the value parameter
        case BasicTokenType::SQR: {
            return Sqr.execute(mpoFirstParam->evaluate());
        }
        // STR Token: Return the String value to a numeric parameter
        case BasicTokenType::STR: {
            return Str.execute(mpoFirstParam->evaluate());
        }
        // SYSTEM Token: Call operation system function
        case BasicTokenType::SYSTEM: {
            return System.execute(mpoFirstParam->evaluate(), mpoSecondParam->evaluate());
        }
        // TAN Token: Return the Tangents of the value parameter
        case BasicTokenType::TAN: {
            return Tan.execute(mpoFirstParam->evaluate());
        }
        // VAL Token: Return the value of the parameter
        case BasicTokenType::VAL: {
            return Val.execute(_oFirstParam->evaluate());
        }
        default: {
            mpoLogger->error("Function::evaluate", "Unknown function called: " + moToken.getText());
            exit(ERR_UNDEFINED_FUNCTION);
        }
    }
}

/**
 * This method is used in testing and debugging. It returns the set values when the constructor has been called.
 *
 * @return - readable string with the name and the value of the assignment
 */
string Function::content() {
    string strReturn = "Token: " + BasicTokenTypeUtilities::to_string(moToken.getType()) + " Content: <";

    if (mpoFirstParam != NULL) {
        strReturn += mpoFirstParam->to_String();
    }

    if (mpoSecondParam != NULL) {
        strReturn += ", " + mpoSecondParam->to_String();
    }

    if (mpoThirdParam != NULL) {
        strReturn += ", " + mpoThirdParam->to_String();
    }

    strReturn += ">";

    return strReturn;
}
