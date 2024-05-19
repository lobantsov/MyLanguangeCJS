#pragma once
#include "Ifhandler.h"

#include "../../LexAnalizator/LexAnalizator.h"

bool Ifhandler::Handle()
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==24)
    {
        singletone_currentposition->currentPosition++;
        //(
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==3)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;

        }
        //var
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+
                LexAnalizator::MultiplyLexConfig.size()+1)
        {
            if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
            {
                Lex tmpLex = declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]);
                
                singletone_currentposition->currentPosition++;

                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
                {
                    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition+1].lexID ==
                        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
                    {
                        singletone_currentposition->currentPosition++;
                        if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
                        {
                            if(tmpLex.dataTypeID==35)
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
                    }
                }
                
                    //condition check
                    //error hear 
                    if(client_assigment->CheckAssigment(tmpLex, false))
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
        //const
        else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+
                LexAnalizator::MultiplyLexConfig.size()+2)
        {
            
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
        
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==5)
        {
          return true;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
    }
    return AbstractHandler_if::Handle();
}
