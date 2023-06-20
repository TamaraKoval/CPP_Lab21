#include "TomaString.h"
#include <iostream>

int TomaString::length() const {
    int i;
    for (i = 0; tomaString[i] != MARK; i++);
    return i;
}

void TomaString::append(char ch) {
    int length = this->length();
    if (length < N) {
        tomaString[length] = ch;
        tomaString[length + 1] = MARK;
    }
}

char & TomaString::operator[](unsigned index) {
    return tomaString[index];
}

int TomaString::search(TomaString substr) {
    int index = -1;
    if (tomaString[0] == MARK || substr[0] == MARK) {
        return index;
    }
    for (int i = 0; tomaString[i] != MARK; i++) {
        if (tomaString[i] == substr[0]) {
            index = i;
            int j;
            for (j = 1; substr[j] != MARK; j++) {
                if (tomaString[i+j] != substr[j]) {
                    index = -1;
                    break;
                }
            }
            if (substr[j] == MARK) return index;
        }
    }
    return index;
}

bool TomaString::deleteSubStr(TomaString substr) {
    if (search(substr) != -1) {
        int start = search(substr);
        int subLength = substr.length();
        int i;
        for (i = 0; tomaString[start+i] != MARK; i++) {
            tomaString[start + i] = tomaString[start + i + subLength];
        }
        tomaString[start+i] = MARK;

        for (; start+i <= N; i++) {
            tomaString[start+i] = 0;
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
    if (i < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

TomaString & TomaString::operator=(TomaString str) {
    int i;
    for (i = 0; str[i] != MARK; i++) {
        tomaString[i] = str[i];
    }
    tomaString[i] = MARK;
    if (i < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const TomaString &str) {
    int length = str.length();
    for (int i = 0; i < length; i++) {
        stream << str.tomaString[i];
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, TomaString &str) {
    char buffer[200];
    stream >> buffer;
    str = buffer;
    return stream;
}