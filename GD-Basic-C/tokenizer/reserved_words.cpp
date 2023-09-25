//
//  reserved_words.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 17/08/2023.
//

#include "reserved_words.hpp"

ReservedWords::ReservedWords() {
};

int ReservedWords::getIndex(string strTokenType) {
    int iReturn = -1;
    int iIndex = 0;

    for (string strReserveWord: mastrReservedWords) {
        transform(strTokenType.begin(), strTokenType.end(), strTokenType.begin(), ::toupper);
        if (strTokenType.compare(strReserveWord) == OK) {
            iReturn = iIndex;
            break;
        }

        iIndex++;
    }

    return iReturn;
}

BasicTokenType ReservedWords::getTokenType(int iIndex) {
    return maeTokenTypes[iIndex];
};
