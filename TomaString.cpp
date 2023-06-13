#include "TomaString.h"
#include <iostream>

int TomaString::length() {
    return curMarkPos;
}

void TomaString::append(char ch) {
    curMarkPos++;
    tomaString[curMarkPos] = MARK;
    tomaString[curMarkPos - 1] = ch;
}

char & TomaString::operator[](unsigned index) {
    return tomaString[index];
}

int TomaString::search(TomaString substr) {
    int subLength = substr.length();
    int index = -1;
    for (int i = 0; i < curMarkPos; i++) {
        if (tomaString[i] == substr[0]) {
            index = i;
            int j;
            for (j = 1; j < subLength; j++) {
                if (tomaString[i+j] != substr[j]) {
                    index = -1;
                    break;
                }
            }
            if (j == subLength) return index;
        }
    }
    return index;
}

bool TomaString::deleteSubStr(TomaString substr) {
    if (search(substr) != -1) {
        int start = search(substr);
        int subLength = substr.length();
        int i;
        for (i = 0; start+i != curMarkPos; i++) {
            tomaString[start+i] = tomaString[start+i+subLength];
        }
        curMarkPos -= subLength;
        for (i = curMarkPos + 1; i <= N; i++) {
            tomaString[i] = 0;
        }
        return true;
    }
    return false;
}

TomaString & TomaString::operator=(const char *str) {
    int i;
    for (i = 0; str[i] && i < N - 1; i++) {
        tomaString[i] = str[i];
    }
    tomaString[i] = MARK;
    curMarkPos = i;
    if (curMarkPos < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

TomaString & TomaString::operator=(TomaString str) {
    int i;
    for (i = 0; i < str.length(); i++) {
        tomaString[i] = str[i];
    }
    tomaString[i] = MARK;
    curMarkPos = i;
    if (curMarkPos < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const TomaString &str) {
    for (int i = 0; i < str.curMarkPos; i++) {
        stream << str.tomaString[i];
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, TomaString &str) {
    char buffer[80];
    stream >> buffer;
    str = buffer;
    return stream;
}
