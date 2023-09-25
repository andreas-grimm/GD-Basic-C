//
//  basic_parser.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 24/08/2023.
//

#include "basic_parser.hpp"

BasicParser::BasicParser(string strLogLevel) {
    mstrLogLevel = strLogLevel;
    
    mpoLogger = Logger::getInstance();
    mpoLogger->setLogLevel(mstrLogLevel);
    
    mpoLineNumber = LineNumberXRef::getInstance();
    mpoLineNumber->setLogLevel(strLogLevel);
}

BasicParser::~BasicParser() {
}

void BasicParser::setTokens(vector<Token> voTokens) {
    mvoTokens = voTokens;
};

vector<Statement*> BasicParser::parsePreRun() {
    vector<Statement*> vpoStatements;
    int iPosition = 0;
    BasicTokenTypeUtilities oTokenUtil;
    
    mpoLogger->debug("BasicParser::parsePreRun", "Start parsing for pre-run commands...");
    
    bool bContinue = true;
    while (bContinue) {
        Token oToken = getToken(iPosition, 0);
        
        switch (oToken.getType()) {

            case DATA: {
                mpoLogger->debug("BasicParser::parsePreRun", "found Token: <" + to_string(iPosition) + "> [DATA] ");
  
                mpoLineNumber->putLineNumber(oToken.getLine(), iPosition); // map token and line number
                
                vector<Value*> vpoValues;
                Value* poValue;
                
                iPosition++;
                
                oToken = getToken(iPosition, 0);
                if ((oToken.getType() != BasicTokenType::STRING) &&
                    (oToken.getType() != BasicTokenType::NUMBER)) {
                    BasicTokenTypeUtilities oUtil;
                    mpoLogger->error("BasicParser::parsePreRun", "Token not of expected type: '" + oUtil.to_string(oToken.getType()) +
                        "' Value: '" + oToken.getText() +"'");
                     exit(ERR_UNEXPECTED_TYPE);
                }

                if (oToken.getType() == BasicTokenType::STRING) {
                    poValue = new StringValue(oToken.getText());
                } else {
                    poValue = new RealValue(oToken.getText());
                }

                vpoValues.push_back(poValue);

                iPosition++;
                while (getToken(iPosition, 0).getType() == BasicTokenType::COMMA) {
                    iPosition++;
                    oToken = getToken(iPosition, 0);
                    if ((oToken.getType() != BasicTokenType::STRING) &&
                        (oToken.getType() != BasicTokenType::NUMBER)) {
                        BasicTokenTypeUtilities oUtil;
                        mpoLogger->error("BasicParser::parsePreRun", "Token not of expected type: '" + oUtil.to_string(oToken.getType()) +
                            "' Value: '" + oToken.getText() +"'");
                        exit(ERR_UNEXPECTED_TYPE);
                    }

                    if (oToken.getType() == BasicTokenType::STRING) {
                        poValue = new StringValue(oToken.getText());
                    } else {
                        poValue = new RealValue(oToken.getText());
                    }
                    
                    vpoValues.push_back(poValue);
                    iPosition++;
                }
                
                vpoStatements.push_back(new DataStatement(iPosition, vpoValues));
                break;
            }

            case BasicTokenType::EOP: {
                mpoLogger->debug("BasicParser::parsePreRun", "found Token: <" + to_string(iPosition) + "> [EOP] ");
                bContinue = false;
                iPosition++;
                break;
            }

            default: {
                mpoLogger->debug("BasicParser::parsePreRun", "found Token: <" + to_string(iPosition) + "> [" + oTokenUtil.to_string(oToken.getType()) + "] ");
                iPosition++;
            }
        }
    }
    
    return vpoStatements;
};


vector<Statement*> BasicParser::parse() {

    LabelStatement* poLabelStatement = new LabelStatement();

    vector<Statement*> vpoStatements;
    int iPosition = 0;
    int iOrgPosition;
    string strTargetLineNumber;

    mpoLogger->debug("BasicParser::parse", "Start parsing...");
    bool bContinue = true;
    
    
    while (bContinue) {
        Token oToken = getToken(iPosition, 0);

        switch (oToken.getType()) {
            // PRAGMA Token: Change execution behaviour of the program.
            case PRAGMA: {
                int iPragmaLineNumber = iPosition;
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [@PRAGMA] ");
                oToken = getToken(iPosition, 0);
                mpoLineNumber->putLineNumber(oToken.getLine(), iPosition);
                iPosition++;
                
                // Get start assignment, target value, and step size
                iPosition++;
                string strSetting = consumeToken(iPosition,BasicTokenType::STRING).getText();
                iPosition++;
                
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [STRING] " + strSetting);
                
                oToken = getToken(iPosition, 0);
                if (oToken.getType() != BasicTokenType::ASSIGN_EQUAL) {
                    BasicTokenTypeUtilities oUtil;
                    mpoLogger->error("BasicParser::parse", "Incorrect Operator: '" + oUtil.to_string(oToken.getType()) +
                                     "' in line: '" + to_string(oToken.getLine()) +"'");
                    exit(ERR_INCORRECT_OPERATOR);
                }
                
                iPosition++;
                string strValue = consumeToken(iPosition, BasicTokenType::STRING).getText();
                iPosition++;
                
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [VALUE] " + strValue);
                
                vpoStatements.push_back((new PragmaStatement(iPragmaLineNumber, strSetting, strValue)));
                
                iPosition++;
                break;
            }

                // COLON Token: Ignore any following part of the line, identical to the REM token.
            case COLON: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [COLON] ");
                mpoLineNumber->putLineNumber(getToken(iPosition, 0).getLine(), iPosition);
                vpoStatements.push_back(new ColonStatement(iPosition));
                iPosition++;
                break;
            }

                // COMMENT Token: Ignore any following part of the line, identical to the REM token.
            case COMMENT: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [COMMENT] ");
                iPosition++;
                break;
            }
/*
         // DATA Token: Already processed in the pre-run parse step, still in to ensure stability
         case DATA:
             _oLogger.debug("BasicParser::parse", "found Token: <" + _iPosition + "> [DATA] ");
             _oLineNumber.putLineNumber(getToken(0).getLine(), _iPosition);

             Token oToken = getToken(1);
             if (oToken.getType() != BasicTokenType.STRING
                     && oToken.getType() != BasicTokenType.NUMBER) {
                 throw new SyntaxErrorException("Token not of expected type:" + oToken.getType() + " Value: " + oToken.getText());
             }
             _iPosition++;

             while (getToken(1).getType() == BasicTokenType.COMMA) {
                 _iPosition++;

                 oToken = getToken(1);
                 if (oToken.getType() != BasicTokenType.STRING
                         && oToken.getType() != BasicTokenType.NUMBER) {
                     throw new SyntaxErrorException("Token not of expected type:" + oToken.getType() + " Value: " + oToken.getText());
                 }
                 _iPosition++;
             }

             _iPosition++;
             break;
*/
         // DEF Token: Ignored as this part of the code is processed in the MacroProcessor.
            case DEF: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [DEF] ");
                mpoLineNumber->putLineNumber(getToken(iPosition, 0).getLine(), iPosition);
                vpoStatements.push_back(new RemStatement(iPosition, "found DEF statement"));
                
                int iMoveTo = 1;
                while (getToken(iPosition, iMoveTo).getType() != BasicTokenType::STRING) {
                    iMoveTo++;
                }
                iPosition = iPosition + iMoveTo;
                iPosition++;
                break;
            }
/*
         // DO Token: Define the anchor point for the DO - UNTIL loop
         case DO:
             _oLogger.debug("BasicParser::parse", "found Token: <" + _iPosition + "> [DO] ");
             _oLineNumber.putLineNumber(getToken(0).getLine(), _iPosition);
             aoStatements.add(new DoStatement(_iPosition));
             _iPosition++;
             break;
 */
         // END Token: Terminate execution of program
            case END: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [END] ");
                mpoLineNumber->putLineNumber(getToken(iPosition, 0).getLine(), iPosition);
                vpoStatements.push_back(new EndStatement(iPosition));
                iPosition++;
                break;
            }
                
         // List of all tokens that are used in a different context (e.g. as part of the IFTHEN token)
            case ENDIF: {
                BasicTokenTypeUtilities oUtil;
                mpoLogger->debug("BasicParser::parse", "ignoring token: <" + to_string(iPosition) + "> [" + oUtil.to_string(getToken(iPosition, 0).getType()) + "] ");
                iPosition++;
                break;
            }

         // EOP Token: End of the program found, finishing the loop thru the program
            case EOP: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [EOP] ");
                bContinue = false;
                iPosition++;
                break;
            }
/*
         // FOR Token: Start of the FOR-NEXT loop
         case FOR:
             Expression oStartValueExpression;
             Expression oEndValueExpression;
             Expression oStepSize;

             _oLogger.debug("BasicParser::parse", "found Token: <" + _iPosition + "> [FOR] ");
             final int iForPosition = _iPosition++;
             _oLineNumber.putLineNumber(getToken(0).getLine(), iForPosition);

             // Get start assignment, target value, and step size
             String strForVariable = consumeToken(BasicTokenType.WORD).getText();
             _oLogger.debug("-parse-> found Token: <" + _iPosition + "> [WORD] " + strForVariable);

             if (getToken(0).getType() != BasicTokenType.ASSIGN_EQUAL) {
                 throw new SyntaxErrorException("Incorrect Operator: " + getToken(0).getType().toString() + " in Line ["
                         + getToken(0).getLine() + "]");
             } else {
                 _iPosition = _iPosition + 1;
                 oStartValueExpression = expression();
                 _oLogger.debug("-parse-> found Token: <" + _iPosition + "> [NUMBER] " + oStartValueExpression.content());
             }

             if (getToken(0).getType() != BasicTokenType.TO) {
                 throw new SyntaxErrorException("Missing TO Operator: " + getToken(0).getType().toString()
                         + " in Line [" + getToken(0).getLine() + "]");
             } else {
                 _iPosition = _iPosition + 1;
                 oEndValueExpression = expression();
                 _oLogger.debug("-parse-> found Token: <" + _iPosition + "> [NUMBER] " + oEndValueExpression.content());
             }

             if (getToken(0).getType() != BasicTokenType.STEP) {
                 _oLogger.debug("-parse-> found Token: <" + _iPosition + "> [" + getToken(0).getType().toString() + " ] StepSize set to 1");
                 oStepSize = new RealValue(1); // default step size
             } else {
                 _iPosition = _iPosition + 1;
                  oStepSize = expression();

                 _oLogger.debug("-parse-> found Token: <" + _iPosition + "> [NUMBER] " + oStepSize.content());
             }

             Token oNextToken = findToken(BasicTokenType.NEXT);
             _oLogger.debug("-parse-> followed Token: <" + oNextToken.getLine() + "> [NEXT]");

             // add FOR statement to statement list
             try {
                 ForStatement oForStatement = new ForStatement(iForPosition, strForVariable, oStartValueExpression,
                                                               oEndValueExpression, oStepSize, oNextToken.getLine());

                 aoStatements.add(oForStatement);
             } catch (Exception e) {
                 e.printStackTrace();
             }
             break;
*/
         // GOTO Token: Read the line from terminal for processing
            case GOTO: {
                iOrgPosition = iPosition;
                mpoLineNumber->putLineNumber(getToken(iPosition, 0).getLine(), iPosition);
                iPosition++;
                strTargetLineNumber = consumeToken(iPosition, BasicTokenType::NUMBER).getText();
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [GOTO] " + strTargetLineNumber);
                vpoStatements.push_back(new GotoStatement(iOrgPosition, strTargetLineNumber));
                iPosition++;
                break;
            }
/*
         // GOSUB Token: Read the line from terminal for processing
         case GOSUB:
             _oLogger.debug("BasicParser::parse", "found Token: <" + _iPosition + "> [GOSUB] ");
             iOrgPosition = _iPosition;
             _oLineNumber.putLineNumber(getToken(0).getLine(), _iPosition);
             _iPosition++;
             strTargetLineNumber = consumeToken(BasicTokenType.NUMBER).getText();
             aoStatements.add(new GosubStatement(iOrgPosition, strTargetLineNumber));
             break;
*/
         // IF Token: Conditional processing
            case IF: {
                int iElsePosition; // initialize the variable that holds the location of the ELSE token
                iOrgPosition = iPosition;
                mpoLineNumber->putLineNumber(getToken(iPosition, 0).getLine(), iPosition);
                iPosition++;
                
                Expression* poCondition = expression(&iPosition);
                
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition - 1) + "> [IF]: <" + poCondition->content() + ">");
                
                string strLabel = consumeToken(iPosition, BasicTokenType::THEN).getText();
                
                mpoLogger->debug("BasicParser::parse", "followed Token: <" + to_string(iPosition) + "> [THEN]: <" + strLabel + ">");
                
                // jumped over THEN
                iPosition++;
                
                // if the programmer wants to jump to a specific location instead of executing the IF block, then
                // the next token is a number.
                if (getToken(iPosition, 0).getType() == BasicTokenType::NUMBER) {
                    vpoStatements.push_back(new IfThenStatement(poCondition, iOrgPosition, 0, 0, stoi(getToken(iPosition, 0).getText())));
                    iPosition++;
                } else {
                    // This block is executed if the next token is a command - means the parser looks for a ELSE token.
                    Token oElseToken;
                    
                    oElseToken = findToken(iPosition, BasicTokenType::ELSE);
                    
                    if (!oElseToken.isTokenEmpty()) {
                        mpoLogger->debug("BasicParser::parse", "followed Token: <" + to_string(oElseToken.getLine()) + "> [ELSE]");
                        iElsePosition = oElseToken.getLine();
                    } else {
                        iElsePosition = 0;
                    }
                    
                    Token oEndIfToken = findToken(iPosition, BasicTokenType::ENDIF);
                    mpoLogger->debug("BasicParser::parse", "followed Token: <" + to_string(oEndIfToken.getLine()) + "> [END-IF]");
                    
                    if (!oElseToken.isTokenEmpty()) {
                        mpoLogger->debug("BasicParser::parse", "processing Token: <" + to_string(oEndIfToken.getLine()) + "> [ELSE]");
                        if (oElseToken.getLine() >= oEndIfToken.getLine()) {
                            mpoLogger->debug("BasicParser::parse", "found ELSE token not in block: <" + to_string(oElseToken.getLine())
                                           + "> [ELSE]");
                        } else {
                            mpoLogger->debug("BasicParser::parse", "found ELSE token in block: <" + to_string(oElseToken.getLine()) + "> "
                                           + "> [ELSE]");
                        }
                    }
                    
                    vpoStatements.push_back(new IfThenStatement(poCondition, iOrgPosition, iElsePosition, oEndIfToken.getLine(), 0));
                }
                
                break;
            }
                
         // ELSE Token: When the IF block is executed, then the program can run into an ELSE statement.
            case ELSE: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [ELSE] ");
                mpoLineNumber->putLineNumber(getToken(iPosition, 0).getLine(), iPosition);
                iPosition++;
                vpoStatements.push_back(new ElseStatement(iPosition - 1));
                break;
            }
/*

         // INPUT Token: Read the line from terminal for processing
         case INPUT:
             _oLogger.debug("BasicParser::parse", "found Token: <" + _iPosition + "> [INPUT] ");
             _oLineNumber.putLineNumber(getToken(0).getLine(), _iPosition);
             _iPosition++;
             aoStatements.add(new InputStatement(_iPosition - 1, consumeToken(BasicTokenType.WORD).getText()));
             break;
*/
         // LABEL Token: tbd
            case LABEL: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [LABEL] ");
                poLabelStatement->putLabelStatement(getToken(iPosition, 0).getText(), (int)vpoStatements.size());
                iPosition++;
                break;
            }

         // LINE Token: Describe an empty line, ignore
            case LINE: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [LINE] ");
                iPosition++;
                break;
            }
/*
         // RETURN Token: Jump to the GoSub statement
         case RETURN:
             _oLogger.debug("-parse-> found Token: <" + _iPosition + "> [RETURN], to be translated ");
             _oLineNumber.putLineNumber(getToken(0).getLine(), _iPosition);
             aoStatements.add(new ReturnStatement(_iPosition));
             _iPosition++;
             break;

         // ENDWHILE Token: Identical to the NEXT functionality:
         case ENDWHILE:

         // NEXT Token: Start of the FOR-NEXT loop
         case NEXT:
             _oLineNumber.putLineNumber(getToken(0).getLine(), _iPosition);
             _oLogger.debug("-parse-> found Token: <" + _iPosition + "> [NEXT] ");
             aoStatements.add(new NextStatement(_iPosition));
             _iPosition++;
             break;
*/
         // PRINT Token: print to the terminal
            case PRINT: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [PRINT] ");
                int iPrintPosition = iPosition;
                vector<Expression*> vpoExpression;
                bool bCRLF = true;
                
                mpoLineNumber->putLineNumber(getToken(iPosition, 0).getLine(), iPrintPosition);
                iPosition++;
                
                
                if (getToken(iPosition, 0).getType() != BasicTokenType::NUMBER
                    && getToken(iPosition, 0).getType() != BasicTokenType::STRING
                    && getToken(iPosition, 0).getType() != BasicTokenType::WORD) {
                    vpoExpression.push_back(new StringExpression(" "));
                } else {
                    vpoExpression.push_back(expression(&iPosition));
                }
                
                while (getToken(iPosition, 0).getType() == BasicTokenType::COMMA) {
                    iPosition++;
                    vpoExpression.push_back(expression(&iPosition));
                }
                
                if (getToken(iPosition, 0).getType() == BasicTokenType::SEMICOLON) {
                    iPosition++;
                    bCRLF = false;
                }
                
                vpoStatements.push_back(new PrintStatement(iPrintPosition, vpoExpression, bCRLF));
                break;
            }
/*
         // READ Token: read a data value from a DATA block
         case READ:
             int iReadPosition = _iPosition;
             _oLogger.debug("-parse-> found Token: <" + _iPosition + "> [READ] ");
             _oLineNumber.putLineNumber(getToken(0).getLine(), _iPosition);
             List<String> astrVariables = new ArrayList<>();
             _iPosition++;

             Token oReadToken = getToken(0);
             if (oReadToken.getType() != BasicTokenType.WORD) {
                 throw new SyntaxErrorException("Token not of expected type:" + oReadToken.getType()
                                                        + " Value" + ": " + oReadToken.getText());
             }

             astrVariables.add(oReadToken.getText());
             _iPosition++;

             while (getToken(0).getType() == BasicTokenType.COMMA) {
                 _iPosition++;
                 oReadToken = getToken(0);
                 if (oReadToken.getType() != BasicTokenType.WORD) {
                     throw new SyntaxErrorException("Token not of expected type:" + oReadToken.getType()
                                                            + " Value: " + oReadToken.getText());
                 }

                 astrVariables.add(oReadToken.getText());
                 _iPosition++;
             }

             aoStatements.add(new ReadStatement(iReadPosition, astrVariables));
             break;
*/
         // REM Token: contains comments to the program, ignore the rest of the line
            case REM: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [REM] ");
                mpoLineNumber->putLineNumber(getToken(iPosition, 0).getLine(), iPosition);
                vpoStatements.push_back(new RemStatement(iPosition, "Comment"));
                iPosition++;
                break;
            }
/*
         // UNTIL Token: Conditional processing
         case UNTIL:
             iOrgPosition = _iPosition;
             _oLineNumber.putLineNumber(getToken(0).getLine(), iOrgPosition);
             _iPosition++;
             Expression oUntilCondition = expression();
             _oLogger.debug("-parse-> found Token: <" + (iOrgPosition) + "> [UNTIL]: <" + oUntilCondition.content() + ">");
             aoStatements.add(new UntilStatement(iOrgPosition, oUntilCondition));
             break;

         // WHILE Token: Conditional looping
         case WHILE:
             iOrgPosition = _iPosition;
             _oLineNumber.putLineNumber(getToken(0).getLine(), _iPosition);
             _iPosition++;
             Expression oWhileCondition = expression();
             _oLogger.debug("-parse-> found Token: <" + (_iPosition - 1) + "> [WHILE]: <" + oWhileCondition.content() + ">");
             Token oEndWhileToken = findToken(BasicTokenType.ENDWHILE);
             _oLogger.debug("-parse-> followed Token: <" + oEndWhileToken.getLine() + "> [END-WHILE]");
             aoStatements.add(new WhileStatement(iOrgPosition, oWhileCondition, oEndWhileToken.getLine()));
             break;
*/
         // WORD Token: This word is a variable or function, anything following is variable manipulation
            case WORD: {
                mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition) + "> [WORD] '"
                                 + getToken(iPosition, 0).getText() + "' [" + to_string(oToken.getLine()) + "]");
                
                int iCurrPosition = iPosition;
                
                mpoLineNumber->putLineNumber(getToken(iPosition, 0).getLine(), iCurrPosition);
                
                if (getToken(iPosition, 1).getType() == BasicTokenType::ASSIGN_EQUAL) {
                    mpoLogger->debug("BasicParser::parse", "found Token: <" + to_string(iPosition + 1) + "> [ASSIGN_EQUAL] '" + getToken(iPosition, 1).getText() + "' [" + to_string(oToken.getLine()) + "]");
                    string strName = getToken(iPosition, 0).getText();
                    iPosition = iPosition + 2;
                    Expression* poExpression = expression(&iPosition);
                    //-> here we should have an expression
                    
                    vpoStatements.push_back(new AssignStatement(iCurrPosition, strName, poExpression));
                } else {
                    BasicTokenTypeUtilities oUtil;
                    mpoLogger->error("BasicParser::parse", "Token not of expected type: '" + oUtil.to_string(getToken(iPosition, 0).getType()) +
                                     "' in Line: '" + getToken(iPosition, 0).getText() +"' ");
                    exit(ERR_INCORRECT_OPERATOR);
                }
                break;
            }

         // No Token identified, Syntax Error
            default: {
                BasicTokenTypeUtilities oUtil;
                mpoLogger->error("BasicParser::parse", "Token not of expected type: '" + oUtil.to_string(oToken.getType()) +
                                 "' Value: '" + oToken.getText() +"' in Line: '" + to_string(getToken(iPosition, 0).getLine()) +"' ");
                exit(ERR_UNEXPECTED_TYPE);
            }
        }
    }

    for (auto poIndexStatement: vpoStatements) {
        mpoLineNumber->putStatementNumber(poIndexStatement->getTokenNumber(), VectorUtil::find_first(vpoStatements, poIndexStatement));
    }

    return vpoStatements;
};


Token BasicParser::getToken(int iPosition, int iOffset) {
    if (iPosition + iOffset >= mvoTokens.size()) {
        Token oToken("", BasicTokenType::EOP, 0);
        return oToken;
    }
    
    return mvoTokens[iPosition + iOffset];
}

/**
  * Consumes the next token if it's the given type. If not, throws an
  * exception. This is for cases where the parser demands a token of a
  * certain type in a certain position, for example a matching ) after
  * an opening (.
  *
  * @param  eType expected type of the next token.
  * @return the consumed token.
  * @throws SyntaxErrorException the next token is not of the expected type
  */
Token BasicParser::consumeToken(int iPosition, BasicTokenType eType) {
    BasicTokenTypeUtilities oUtil;
    mpoLogger->debug("BasicParser::consumeToken", "looking for Token: <" + to_string(iPosition) + "> [" + oUtil.to_string(eType) + "]: <" +
         oUtil.to_string(getToken(iPosition, 0).getType()) + ">");

    if (getToken(iPosition, 0).getType() != eType) {
        mpoLogger->error("BasicParser::consumeToken", to_string(getToken(iPosition, 0).getLine()) + " Found: " + getToken(iPosition, 0).getText() + " expected: " + oUtil.to_string(eType) + ".");
        exit(ERR_UNEXPECTED_TYPE);
    }

    return mvoTokens.at(iPosition++);
}

/**
 * Retrieves the next token of a certain type. If no token is found, the method
 * throws an exception. This is for cases where the parser demands a token of a
 * certain type in a certain position, for example a matching ) after an opening (.
 *
 * @param  eType expected type of the found token.
 * @return the found token.
 */
Token BasicParser::findToken(int iPosition, BasicTokenType eType) {
    BasicTokenTypeUtilities oUtil;
    mpoLogger->debug("BasicParser::findToken", "looking for Token: <" + to_string(iPosition) + "> [" + oUtil.to_string(eType) + "]: <"
            + oUtil.to_string(getToken(iPosition, 0).getType()) + ">");

    int iCurrentPosition = iPosition;

    while (iCurrentPosition < mvoTokens.size()) {
        Token oToken = mvoTokens.at(iCurrentPosition);

        if (oToken.getType() == eType) {
            mpoLogger->debug("BasicParser::findToken", "found: <" + to_string(iCurrentPosition) + "> [" + oUtil.to_string(oToken.getType()) + "]");
            return oToken;
        } else {
            mpoLogger->debug("BasicParser::findToken", "failed: <" + to_string(iCurrentPosition) + "> [" + oUtil.to_string(oToken.getType()) + "]");
            iCurrentPosition++;
        }
    }
    
    Token oReturnToken;
    oReturnToken.setTokenEmpty();
    
    return oReturnToken;
}

/**
 * Parses a single expression. Recursive descent parsers start with the
 * lowest-precedent term and moves towards higher priority. For Basic,
 * binary operators (+, -, etc.) are the lowest.
 *
 * @return The parsed expression.
 * @throws SyntaxErrorException - marks any syntax errors
 */
Expression* BasicParser::expression(int* piPosition) {
    BasicTokenTypeUtilities oUtil;
    mpoLogger->debug("BasicParser::expression","process Token: <" + to_string(*piPosition) + "> [" + oUtil.to_string(getToken(*piPosition, 0).getType()) + "]");
    return operate(piPosition);
}

/**
 * Parses a series of binary operator expressions into a single
 * expression. In Basic, all operators have the same precedence and
 * associate left-to-right. That means it will interpret:
 *    1 + 2 * 3 - 4 / 5
 * like:
 *    ((((1 + 2) * 3) - 4) / 5)
 *
 * It works by building the expression tree one at a time. So, given
 * this code: 1 + 2 * 3, this will:
 *
 * 1. Parse (1) as an atomic expression.
 * 2. See the (+) and start a new operator expression.
 * 3. Parse (2) as an atomic expression.
 * 4. Build a (1 + 2) expression and replace (1) with it.
 * 5. See the (*) and start a new operator expression.
 * 6. Parse (3) as an atomic expression.
 * 7. Build a ((1 + 2) * 3) expression and replace (1 + 2) with it.
 * 8. Return the last expression built.
 *
 * @return The parsed expression.
 * @throws SyntaxErrorException - marks any syntax issues
 */
Expression* BasicParser::operate(int* piPosition) {
    BasicTokenTypeUtilities oUtil;

    Expression* poExpression = atomic(piPosition);
    
    // Keep building operator expressions as long as we have operators.
    Token oToken = getToken(*piPosition, 0);
    
    mpoLogger->debug("BasicParser::operate", "token: <" + to_string(*piPosition) + "> [" + oUtil.to_string(oToken.getType()) + "] '" + oToken.getText() + "' [" +  to_string(oToken.getLine()) + "]");

    // loop while the token inspected is either an operator or an assignment
    while (oToken.getType() == BasicTokenType::PLUS
            || oToken.getType() == BasicTokenType::MINUS
            || oToken.getType() == BasicTokenType::MULTIPLY
            || oToken.getType() == BasicTokenType::DIVIDE
            || oToken.getType() == BasicTokenType::MODULO
            || oToken.getType() == BasicTokenType::POWER
            || oToken.getType() == BasicTokenType::AND
            || oToken.getType() == BasicTokenType::OR
            || oToken.getType() == BasicTokenType::COMPARE_EQUAL
            || oToken.getType() == BasicTokenType::COMPARE_NOT_EQUAL
            || oToken.getType() == BasicTokenType::SMALLER
            || oToken.getType() == BasicTokenType::SMALLER_EQUAL
            || oToken.getType() == BasicTokenType::GREATER
            || oToken.getType() == BasicTokenType::GREATER_EQUAL
            || oToken.getType() == BasicTokenType::ASSIGN_EQUAL
            || oToken.getType() == BasicTokenType::SHIFT_LEFT
            || oToken.getType() == BasicTokenType::SHIFT_RIGHT
    ) {
        mpoLogger->debug("BasicParser::operate:while", "token: <" + to_string(*piPosition) + "> [" + oUtil.to_string(getToken(*piPosition, 0).getType()) + "] '"
                + oToken.getText() + "' [" + to_string(oToken.getLine()) + "]");
        (*piPosition)++;
        Expression* poRight = atomic(piPosition);
        
        if ((poExpression != NULL) && (poRight != NULL))
            poExpression = new OperatorExpression(poExpression, oToken.getType(), poRight);

        oToken = getToken(*piPosition, 0);
    };
 
    return poExpression;
}

/**
 * Parses an "atomic" expression. This is the highest level of
 * precedence and contains single literal tokens like 123 and "foo", as
 * well as parenthesized expressions.
 *
 * @return The parsed expression.
 * @throws SyntaxErrorException - mark any syntax issues
 */
Expression* BasicParser::atomic(int* piPosition) {
    Token oToken = getToken(*piPosition, 0);

    BasicTokenTypeUtilities oUtil;
    mpoLogger->debug("BasicParser::atomic", "search Token: <" + to_string(*piPosition) + "> [" + oUtil.to_string(getToken(*piPosition, 0).getType()) + "] ");

    switch (oToken.getType()) {

        // If the current token is of type WORD, then we assume it is a variable.
        case WORD:
            oToken = getToken(*piPosition, 0);
            mpoLogger->debug("BasicParser::atomic:WORD", "found token: <" + to_string(*piPosition) + "> [" + oUtil.to_string(oToken.getType()) + "] '"
                        + oToken.getText() + "' [" + to_string(oToken.getLine()) + "]");
            (*piPosition)++;
            return new VariableExpression(oToken.getText());

        // If the current token is of type NUMBER, then return the value as a double value
        case NUMBER: {
            BasicTokenTypeUtilities oUtil;
            oToken = getToken(*piPosition, 0);
            mpoLogger->debug("BasicParser::atomic:NUMBER", "found token: <" + to_string(*piPosition) + "> [" + oUtil.to_string(oToken.getType()) + "] '"
                           + oToken.getText() + "' [" + to_string(oToken.getLine()) + "]");
            (*piPosition)++;
            return new RealExpression(oToken.getText());
        }
        // If the current token us of type STRING, then return the value as a string value
        case STRING: {
            BasicTokenTypeUtilities oUtil;
            oToken = getToken(*piPosition, 0);
            mpoLogger->debug("BasicParser::atomic:STRING", "found Token: <" + to_string(*piPosition) + "> [" + oUtil.to_string(oToken.getType()) + "] '"
                           + oToken.getText() + "' [" + to_string(oToken.getLine()) + "]");
            (*piPosition)++;
            return new StringExpression(oToken.getText());
        }
/*
        // The contents of a parenthesized expression can be any expression. This lets us "restart" the precedence cascade
        // so that you can have a lower precedence expression inside the parentheses.
        case LEFT_PAREN:
            oToken = getToken(0);
            _oLogger.debug("-atomic-> found token: <" + _iPosition + "> [" + oToken.getType().toString() + "] '"
                    + oToken.getText() + "' [" + oToken.getLine() + "]");
            _iPosition++;
            Expression oExpression = expression();
            consumeToken(BasicTokenType.RIGHT_PAREN);
            return oExpression;

        // three parameter function calls
        case MID:
            oToken = getToken(0);
            _oLogger.debug("-atomic-> found token: <" + _iPosition + "> [" + oToken.getType().toString() + "] '"
                                   + oToken.getText() + "' [" + oToken.getLine() + "]");
            _iPosition++;
            consumeToken(BasicTokenType.LEFT_PAREN);
            Expression oParameter1 = expression();
            consumeToken(BasicTokenType.COMMA);
            Expression oParameter2 = expression();
            consumeToken(BasicTokenType.COMMA);
            Expression oParameter3 = expression();
            Expression oThreeParameterFunction = new Function(oToken, oParameter1, oParameter2, oParameter3);
            consumeToken(BasicTokenType.RIGHT_PAREN);
            return oThreeParameterFunction;

        // two parameter function calls
        case INSTR: case LEFT: case RIGHT: case SYSTEM:
            oToken = getToken(0);
            _oLogger.debug("-atomic-> found token: <" + _iPosition + "> [" + oToken.getType().toString() + "] '"
                                   + oToken.getText() + "' [" + oToken.getLine() + "]");
            _iPosition++;
            consumeToken(BasicTokenType.LEFT_PAREN);
            Expression oParameter1Expression = expression();
            consumeToken(BasicTokenType.COMMA);
            Expression oParameter2Expression = expression();
            Expression oTwoParameterFunction = new Function(oToken, oParameter1Expression, oParameter2Expression);
            consumeToken(BasicTokenType.RIGHT_PAREN);
            return oTwoParameterFunction;
*/
        // single parameter function calls
        case ABS: case ASC: case ATN: case CDBL: case CHR: case CINT: case COS: case EXP: case LEN: case LOG:
        case LOG10: case NOT: case SIN: case SQR: case STR: case TAN: case VAL: {
            oToken = getToken(*piPosition, 0);
            mpoLogger->debug("BasicParser::atomic", "found Token: <" + to_string(*piPosition) + "> [" + oUtil.to_string(oToken.getType()) + "] '"
                             + oToken.getText() + "' [" + to_string(oToken.getLine()) + "]");
            (*piPosition)++;
            consumeToken(*piPosition, BasicTokenType::LEFT_PAREN);
            Expression* poFunctionExpression = expression(piPosition);
            Expression* poParameterFunction = new Function(oToken, poFunctionExpression);
            consumeToken(*piPosition, BasicTokenType::RIGHT_PAREN);
            return poParameterFunction;
        }
/*
        // zero parameter function calls
        case MEM: case RND: case TIME:
            oToken = getToken(0);
            _oLogger.debug("-atomic-> found token: <" + _iPosition + "> [" + oToken.getType().toString() + "] '"
                    + oToken.getText() + "' [" + oToken.getLine() + "]");
            _iPosition++;
            return new Function(oToken);
             */
        default: {
            // OK - here we have a text block that we cannot parse, so we throw an syntax exception
            BasicTokenTypeUtilities oUtil;
            mpoLogger->error("BasicParser::atomic", "Couldn't parse : [" + to_string(getToken(*piPosition, 0).getLine()) + ", Token found: " + oUtil.to_string(getToken(*piPosition, 0).getType()) + " " + getToken(*piPosition, 0).getText() + ".");
            exit(ERR_UNEXPECTED_TYPE);
        }

    }
}
