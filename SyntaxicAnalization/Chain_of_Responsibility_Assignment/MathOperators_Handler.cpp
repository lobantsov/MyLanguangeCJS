#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "MathOperators_Handler.h"
bool MathOperators_Handler::Handle(Lex Type)
{
    //+-*/
    if(Type.dataTypeID>=35&&Type.dataTypeID<=37)
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==9||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==10||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==11||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==12)
        {
            singletone_currentposition->currentPosition++;
            return AbstractHandler_Assigment::Handle(Type);
        }
        else
        {
            create_erorrs->CreateSyntaxError();
        }
    }
    else if(Type.dataTypeID==38||Type.dataTypeID==39)
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==9)
        {
            singletone_currentposition->currentPosition++;
            return AbstractHandler_Assigment::Handle(Type);
        }
        else
        {
            create_erorrs->CreateSyntaxError();
        }
    }
    else if(Type.dataTypeID==34)
    {
        create_erorrs->CreateSyntaxError();
    }
    return false;
}
