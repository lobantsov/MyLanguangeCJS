#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "IncrementaOperators_Handler.h"
bool IncrementaOperators_Handler::Handle(Lex Type)
{
    //++ -- **
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==42||
    LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==43||
    LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==44)
    {
        singletone_currentposition->currentPosition++;
        return true;
    }
    return AbstractHandler_Assigment::Handle(Type);
}

