#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "Equal_Handler.h"
bool Equal_Handler::Handle(Lex Type)
{
    // = += -= /= *=
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==45||
    LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==46||
    LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==47||
    LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==48)
    {
        singletone_currentposition->currentPosition++;
        return true;
    }
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        singletone_currentposition->currentPosition++;
        return true;
    }
    return AbstractHandler_Assigment::Handle(Type);
}