#pragma once
#include "ArrayCheck_Handler.h"
#include "../../LexAnalizator/LexAnalizator.h"

bool ArrayCheck_Handler::Handle(Lex TypeID)
{
    //new

    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].lexID==
            LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
        {
            if(declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2]).array==1)
            {
                singletone_currentposition->currentPosition++;
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }

                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == TypeID.dataTypeID)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID==351)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
                {
                    singletone_currentposition->currentPosition++;
                    return true;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
            }
        }
    }
    return AbstractHandler_Assigment::Handle(TypeID);
}
