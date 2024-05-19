#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "CheckVar_Handler.h"
bool CheckVar_Handler::Handle(Lex Type)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==
        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
        if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
        {
            Lex tmpLex = declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]);
            switch (Type.dataTypeID)
            {
                //bool
            case 34:
                if(tmpLex.dataTypeID==Type.dataTypeID)
                {
                    singletone_currentposition->currentPosition++;
                    return true;
                }
                break;
                //int
            case 35:
                if(tmpLex.dataTypeID==Type.dataTypeID)
                {
                    singletone_currentposition->currentPosition++;
                    return true;
                }
                break;
            case 36:
                if(tmpLex.dataTypeID==35||tmpLex.dataTypeID==36)
                {
                    singletone_currentposition->currentPosition++;
                    return true;
                }
                break;
            case 37:
                if(tmpLex.dataTypeID==35||tmpLex.dataTypeID==36||tmpLex.dataTypeID==37)
                {
                    singletone_currentposition->currentPosition++;
                    return true;
                }
                break;
            case 38:
                if(tmpLex.dataTypeID==Type.dataTypeID)
                {
                    singletone_currentposition->currentPosition++;
                    return true;
                }
                break;
            case 39:
                if(tmpLex.dataTypeID==Type.dataTypeID)
                {
                    singletone_currentposition->currentPosition++;
                    return true;
                }
                break;
                default:
                    create_erorrs->error_status=true;
                return false;
                    break;
            }
        }
        else
        {
            create_erorrs->error_status;
            return false;
        }
    }
    return AbstractHandler_Assigment::Handle(Type);
}