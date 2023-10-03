//
//  system_func.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#include "system_func.hpp"
/**
 * Private Constructor.
 */
System::System() {
}

/**
 * Functions implemented here are similar to Statements with the difference
 * that they actually return a result to the caller of type Value. The method execute
 * triggers the function.
 *
 * @param poCommand  command to be executed
 * @param poValue input string value
 * @return Value the return message of the function
 */
Value* System::execute(Value* poCommand, Value* poValue) {
    Logger* mpoLogger = Logger::getInstance();
    
    string strReturn;
    int iStatus = 0;
    
    Value* poReturn;
    
    if ((poValue->getType() == VariableType::STRG) &&
        (poCommand->getType() ==VariableType::STRG)) {

        if (StringUtil::to_upper(poCommand->to_string()) == "RUN") {
            string strCommand = "bash -c " + poValue->to_string();
            const char* cCommand = strCommand.c_str();
            
            iStatus = system(cCommand);
            
            poReturn = new IntegerValue(iStatus);
        } else {
            if (StringUtil::to_upper(poCommand->to_string()) == "EXEC") {
                string strCommand = "bash -c " + poValue->to_string();
                
                strReturn = SystemUtil::exec(strCommand);
                
                poReturn = new StringValue(strReturn);
            } else {
                mpoLogger->error("System::execute", "Parameter error");
                exit(ERR_INCORRECT_PARAMETER);
            }
        }

        return poReturn;
    }

    mpoLogger->error("System::execute", "Parameter for System function call not of type String");
    exit(ERR_INCORRECT_TYPE);
}
