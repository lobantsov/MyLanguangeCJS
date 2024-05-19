#pragma once
#include "ArrayAssingment_Handler.h"
#include "../../LexAnalizator/LexAnalizator.h"

bool ArrayAssingment_Handler::Handle(Lex Type)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition+1].lexID ==
            LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
        {
            singletone_currentposition->currentPosition++;
            if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
            {
                Lex tmp = declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]);
                if(tmp.dataTypeID==35)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
            }
            else
            {
                create_erorrs->CreateSyntaxError();
                return false;
            }
        }
        else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition+1].lexID ==
            LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
        {
            singletone_currentposition->currentPosition++;
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 351)
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                create_erorrs->CreateSyntaxError();
                return false;
            }
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
        {
            singletone_currentposition->currentPosition++;
            if(singletone_currentposition->isLogicOperator)
            {
                singletone_currentposition->isLogicOperator=false;
                return true;
            }
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
    }
    singletone_currentposition->isLogicOperator=false;
    return AbstractHandler_Assigment::Handle(Type);
}
