#ifndef LEXANALIZATOR_H
#define LEXANALIZATOR_H
#pragma once
#include <vector>
#include <string>

#include "Lex.h"

class LexAnalizator
{
public:
    static std::vector<std::string> SingleLexConfig;

    static std::vector<std::string> MultiplyLexConfig;

   std::vector<std::string> a = {";",":","'","(",")","{","}","<",">","+","-","*","/" ,"=","\""," ",",","[","]","for","or",
                                            "while","do","of","if","else","switch","case",
                                        "default","break","function","return","write","read", "bool", "int", "float", "double",
                                        "string", "char", "let", "main","++","--","**","+=","-=","*=","/=","<=",">=","!=","new",
                                         "=="};

    static std::vector<Lex> FinalLexConfig;
    std::vector<Lex> VariablesTable;
    std::vector<Lex> ConstantsTable;
    std::vector<Lex>* readCode(std::string path);
    void removeElementAfter15(int index);
    void remove15BeforeAndAfterID(int ID);
    void Print();
    void processLexeme(const std::string& word, int line, const std::string& orLine);
    bool isVariable(const std::string& word, const std::string& orLine);
    bool isConstant(const std::string& word, const std::string& orLine);
    bool isQuotedString(const std::string& word, const std::string& orLine);
    bool ThisContains(std::vector<Lex>* tmp, const std::string& word);
    Lex GetLex(std::vector<Lex>* tmp, const std::string& word);
    void CheckConst();
    int checkNumberType(const std::string& s);
    void groupQuotedLexemes();
    void groupQuotedLexemes2();
    bool isOperation(const std::string& op);
    bool isDigitOrVariable(const std::string& value);
};



#endif //LEXANALIZATOR_H
