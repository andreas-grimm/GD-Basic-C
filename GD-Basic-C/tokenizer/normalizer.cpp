//
//  normalizer.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 16/08/2023.
//

#include "normalizer.hpp"

Normalizer::Normalizer() {
    mpoLogger = Logger::getInstance();
};

/**
 * The normalize function converts the input string by removing un-needed spaces and ensures that the format of the
 * line in working with the lexer.
 *
 * @param strProgramLine string to be adjusted
 * @return normalized string
 */
string Normalizer::normalize(string strProgramLine) {
     string strWork = strProgramLine;
     string strOutput;

     bool bQuotationMark = false;
     bool bArrayParenthenes = false;
     bool bSquareBrackets = false;

     // replace tabs with spaces
     replace(strWork.begin(), strWork.end(), '\t', ' ');
    
     // ignore anything in quotation marks (") and add it to the string
     char cPreviousChar = '\0';
     char cCurrentChar = '\0';

     for (int i = 0; i < strWork.length(); i++) {
         cPreviousChar = cCurrentChar;
         cCurrentChar = strWork.at(i);

         if (cCurrentChar == '[') {
             bSquareBrackets = true;
         }
         
         if (cCurrentChar == '('
                 && (cPreviousChar == '$'
                     || cPreviousChar == '#'
                     || cPreviousChar == '!'
                     || cPreviousChar == '%'
                     || cPreviousChar == '&'
                     || cPreviousChar == '@')) {
             bArrayParenthenes = true;
         }

         // if the quotation mark is not set, then just pass thru...
         if (cCurrentChar == '"') {
             bQuotationMark = !bQuotationMark;
         }

         // now check whether we are between square brackets [] - here remove all spaces
         if (bSquareBrackets) {
             if (cCurrentChar != ' ') {
                 strOutput += cCurrentChar;
             }

             if (cCurrentChar == ']') {
                 bSquareBrackets = false;
             }
         } else if (bQuotationMark || bArrayParenthenes) {
             strOutput += cCurrentChar;
             if (cCurrentChar == ')'
                     && bArrayParenthenes) {
                 bArrayParenthenes = false;
             }
         } else {
             // else apply filters
             switch (cCurrentChar) {
                 case ',':
                     strOutput += " ,";
                     break;
                 case ';':
                     strOutput += " ;";
                     break;
                 case ':':
                     strOutput += " :";
                     break;
                 case '(':
                     strOutput += " ( ";
                     break;
                 case ')':
                     strOutput += " ) ";
                     break;
                 default:
                     strOutput += cCurrentChar;
             }
         }
     }

    return strOutput;
};

/**
 * The normalizeIndex function converts the input string by removing un-needed spaces and ensures that the format of
 * the line in working with the lexer.
 *
 * @param strProgramLine string to be adjusted
 * @return normalized string
 * @throws SyntaxErrorException if the parenthesis are not set correctly
 */
string Normalizer::normalizeFunction(string strProgramLine) {
    string strWork = strProgramLine;

    // this function only runs if there are two parenthesis in the string
    long lIndexStart = strWork.find("(", 0);
    long lIndexEnd = strWork.find(")", 0);

    if (lIndexStart < 0 && lIndexEnd < 0) {
        return strWork;
    // if there is only one then I see a problem and throw an exception
    } else {
        if (lIndexStart < 0 || lIndexEnd < 0) {
            mpoLogger->error("Normalizer::normalizeFunction", "Syntax Error: Parenthesis incorrectly set: `" + strProgramLine + "`");
            exit(ERR_SYNTAX_ERROR);
        }
    }

    mpoLogger->debug("Normalizer::normalizeFunction", "Index Start: `" + to_string(lIndexStart) + "`");
    mpoLogger->debug("Normalizer::normalizeFunction", "Index End: `" + to_string(lIndexEnd) + "`");
    // ok - I know there are two parenthesis. Now lets see whether the word immediately connected to the
    // parenthesis is a keyword. This is also done in the Lexer, but here we need it to put appropiate spaces in
    // place

    // reduce the found word from the left parenthesis
    string strStub = strWork.substr(0, lIndexStart -1);
    strStub = strStub.substr(strStub.find_last_of(" ") +1);

    // and check whether the rest is a keyword
    int iIndex = oReservedWords.getIndex(strStub);

    // we found a keyword
    if (iIndex > -1) {
        // the pre-scan shows that the scan will find a function. So we need to put extra spaces between the
        // function, the opening parentheses, the number in the parenthesis, and the closing parenthesis
        strWork = strWork.substr(0, lIndexStart) + " " + strWork.substr(lIndexStart);
    }

    // after the normalization above, () becomes " (  ) " - still needs to be removed
    strWork = regex_replace(strWork, regex(" \\(  \\) "), "");
    return strWork;
};

/**
 * The normalizeIndex function converts the input string by removing un-needed spaces and ensures that the format of
 * the
 * line in working with the lexer.
 *
 * @param strProgramLine string to be adjusted
 * @return normalized string
 */
string Normalizer::normalizeIndex(string strProgramLine) {
    string strWork = strProgramLine;
    unsigned long ulIndexStart = strWork.find_first_of("(");
    unsigned long ulIndexEnd = strWork.find_first_of(")");

    if (ulIndexStart < 0 && ulIndexEnd < 0) {
        return strWork;
    } else {
        if (ulIndexStart < 0 || ulIndexEnd < 0) {
            mpoLogger->error("Normalizer::normalizeIndex", "Parenthesis incorrectly set: " + strProgramLine);
            exit(ERR_PARENTHESIS_INCORRECT);
        }
    }

    // replace tabs with spaces
    strWork = strWork.substr(ulIndexStart + 1, ulIndexEnd);

    std::regex oRegexTabs("\\t+");
    strWork = std::regex_replace(strWork, oRegexTabs, " ");
    
    std::regex oRegexSpaces("\\s+");
    strWork = std::regex_replace(strWork, oRegexSpaces, "");

    strWork = strProgramLine.substr(0, ulIndexStart) + "-" + strWork;

    return strWork;
}

