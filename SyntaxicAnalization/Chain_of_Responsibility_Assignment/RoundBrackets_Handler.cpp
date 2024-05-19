#pragma once
#include "RoundBrackets_Handler.h"

#include <algorithm>
#include <sstream>
#include "../../LexAnalizator/LexAnalizator.h"

bool RoundBrackets_Handler::Handle(Lex Type)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==3)
    {
        singletone_currentposition->currentPosition++;
        return true;
    }
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==4)
    {
        singletone_currentposition->currentPosition++;
        return true;
    }
    return AbstractHandler_Assigment::Handle(Type);
}
bool RoundBrackets_Handler::Translate(std::string line) {
    std::istringstream iss(line);
    std::string token;
    while (iss >> token) {
        Lex lex;
        if (!IsTokenValid(token, lex))
            return false;
        if (lex.lexID == 54 || lex.lexID == 55)
            result.push_back(lex);
        else {
            if (operation.empty() || lex.lexID == 3) // (
                operation.push(lex);
            else if (lex.lexID == 4) { // )
                while (operation.top().lexID != 3) { // (
                    result.push_back(operation.top());
                    operation.pop();
                }
                operation.pop(); // remove (
            } else {
                while (!operation.empty() && Priority(operation.top()) >= Priority(lex)) {
                    result.push_back(operation.top());
                    operation.pop();
                }
                operation.push(lex);
            }
        }
    }
    while (!operation.empty()) {
        result.push_back(operation.top());
        operation.pop();
    }
    return true;
}
bool RoundBrackets_Handler::IsTokenValid(const std::string& s, Lex& lex) {
    if (s == "(") {
        lex.value = s;
        lex.lexID = 3;
    } else if (s == ")") {
        lex.value = s;
        lex.lexID = 4;
    } else if (s == "+") {
        lex.value = s;
        lex.lexID = 9;
    } else if (s == "-") {
        lex.value = s;
        lex.lexID = 10;
    } else if (s == "*") {
        lex.value = s;
        lex.lexID = 11;
    } else if (s == "/") {
        lex.value = s;
        lex.lexID = 12;
    } else if (IsNumber(s)) {
        lex.value = s;
        lex.lexID = 55;
    } else if (IsVariable(s)) {
        lex.value = s;
        lex.lexID = 54;
    } else {
        return false; // Invalid token
    }
    return true;
}

bool RoundBrackets_Handler::IsNumber(const std::string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), [](char c) { return std::isdigit(c) || c == '.'; });
}

bool RoundBrackets_Handler::IsVariable(const std::string& s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), [](char c) { return std::isalpha(c); });
}

int RoundBrackets_Handler::Priority(const Lex& lex) {
    if (lex.lexID == 9 || lex.lexID == 10) return 1; // +, -
    if (lex.lexID == 11 || lex.lexID == 12) return 2; // *, /
    return -1; // error
}

