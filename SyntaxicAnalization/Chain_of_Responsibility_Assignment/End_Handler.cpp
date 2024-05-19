#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "End_Handler.h"
bool End_Handler::Handle(Lex Type)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        return true;
    }
    return AbstractHandler_Assigment::Handle(Type);
}
