#pragma once
#include "EnumerationHandler.h"
#include "VariableHandler.h"
#include "../../LexAnalizator/LexAnalizator.h"

bool EnumerationHandler::Handle(Lex TypeID)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==16||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0 )
    {
        return true;
    }
    else
    {
        return AbstractHandler::Handle(TypeID);
    }
}
