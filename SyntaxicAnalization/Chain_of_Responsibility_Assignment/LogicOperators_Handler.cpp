#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "LogicOperators_Handler.h"
bool LogicOperators_Handler::Handle(Lex Type)
{
    //<  >
    if(Type.dataTypeID>=35&&Type.dataTypeID<=37)
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==7||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==8||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==49||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==50)
        {
            singletone_currentposition->currentPosition++;
            return AbstractHandler_Assigment::Handle(Type);
        }
    }
    //==
    if(Type.dataTypeID>=34&&Type.dataTypeID<=39)
    {
        //
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==53||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==51)
        {
            singletone_currentposition->currentPosition++;
            return AbstractHandler_Assigment::Handle(Type);
        }
        return false;
    }
    else
    {
        return false;
    }
}