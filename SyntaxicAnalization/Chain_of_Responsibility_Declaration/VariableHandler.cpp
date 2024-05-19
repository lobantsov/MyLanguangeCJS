#pragma once
#include "VariableHandler.h"
#include "../SynAnalizator.h"
#include "../../LexAnalizator/LexAnalizator.h"

bool VariableHandler::Handle(Lex TypeID)
{
    Lex foundLex;
    for (const auto& lex : declarered_variables_->CreatedLexemus)
    {
        if (lex.lexID == LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID &&
            lex.value == LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value) {
            foundLex = lex;
            break;
            }
    }
    
    if (foundLex.lexID<0)
    {
        if (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == -1)
            if (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 1)
            {
                for (int i = 0; i < LexAnalizator::FinalLexConfig.size(); i++)
                {
                    if (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value == LexAnalizator::FinalLexConfig[i].value)
                    {
                        LexAnalizator::FinalLexConfig[i].dataTypeID = TypeID.lexID;
                        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition+1].lexID == 17
                            &&LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition+2].lexID==18)
                        {
                            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].array = 1;
                        }
                        declarered_variables_->CreatedLexemus.push_back(LexAnalizator::FinalLexConfig[i]);
                        break;
                    }
                }
                singletone_currentposition->currentPosition++;
            }
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    return AbstractHandler::Handle(TypeID);
}
