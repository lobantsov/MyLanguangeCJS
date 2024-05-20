//
// Created by loban on 5/18/2024.
//

#ifndef CODE_EXECUTION_H
#define CODE_EXECUTION_H
#pragma once
#include "Polish_Inverse_Writing.h"
#include "../SpawnErrors/ClassForCreateErorrs.h"
#include "../SyntaxicAnalization/SingletoneDeclaretedVariables/DeclareredVariables.h"

class Code_execution
{
private:
    Polish_Inverse_Writing *inverse_writing = new Polish_Inverse_Writing();
    std::vector<Lex> source_string_stack;
    std::stack<Lex> tmp_stack;
    ClassForMethoodContainer *class_for_methood_container_ = new ClassForMethoodContainer();
    DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
    ClassForCreateErorrs *class_for_create_erorrs_ = ClassForCreateErorrs::GetInstance();
    int iterator=0;
public:
    void Execution();
    void EqualExecute(Lex tmp1, Lex tmp2);
    Lex MathOperators(Lex operator_, Lex tmp2, Lex tmp1);

    Lex CheckLogicSentence(Lex operator_, Lex tmp1, Lex tmp2);

    void Incrementa(Lex operator_, Lex var);

    void Write(Lex var);

    void Read(Lex var);

    void EaserMyLive();

    void UpdataVariableData(const Lex &lex);

    std::variant<std::string, bool, char, double, int> stringToNumber(const std::string &str);

    void CommandEction(Lex lex);
};



#endif //CODE_EXECUTION_H
