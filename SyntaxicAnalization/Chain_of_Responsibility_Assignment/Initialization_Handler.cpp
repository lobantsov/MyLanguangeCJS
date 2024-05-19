#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "Initialization_Handler.h"
bool Initialization_Handler::Handle(Lex Type)
{
    //array
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            //create error space
            return false;
        }

        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == tmpLex->dataTypeID)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            //create wrong type
            return false;
        }

        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 17)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            //create wrong type
            return false;
        }

        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
            LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            //wrong size
            return false;
        }

        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 18)
        {
            singletone_currentposition->currentPosition++;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    //number+let check
    if(Type.dataTypeID>=35 && Type.dataTypeID<=37 || Type.dataTypeID==40)
    {
        //const
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
            LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
        {
            singletone_currentposition->currentPosition++;
            return true;
        }
        //var
        else if(VarCheck(Type))
        {
            singletone_currentposition->currentPosition++;
            return true;
        }
        else
        {
            //wornt equal sentence
            return false;
        }
    }
    //string+let check
    else if(Type.dataTypeID==38||Type.dataTypeID==40)
    {
        if(VarCheck(Type))
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                //wront type equaling
                return false;
            }
            //const
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
                LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
            {
                singletone_currentposition->currentPosition++;
            }

            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                //wront type equaling
                return false;
            }
        }
    }
    //char+let
    else if(Type.dataTypeID==39||Type.dataTypeID==40)
    {
        if(VarCheck(Type))
        {
            singletone_currentposition->currentPosition++;
            return true;
        }
        else
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==2)
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                //wront type equaling
                return false;
            }
            //const
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
                LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
            {
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value.size()==1)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    //wront equling< cannot more one signt
                    return false;
                }
            }

            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==2)
            {
                singletone_currentposition->currentPosition++;
                return true;
            }
            else
            {
                //wront type equaling
                return false;
            }
        }
    }
    //bool+let
    else if(Type.dataTypeID==34||Type.dataTypeID==40)
    {
        //const
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
            LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value=="true"||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value=="false"||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value=="1"||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value=="0")
            {
                singletone_currentposition->currentPosition++;
                return true;
            }
            else
            {
                //wront equal data
                return false;
            }
        }
        //var
        else if(VarCheck(Type))
        {
            singletone_currentposition->currentPosition++;
            return true;
        }
    }
    return AbstractHandler_Assigment::Handle(Type);
}

bool Initialization_Handler::VarCheck(Lex Type)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
            LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
            
        if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
        {
            if(Type.dataTypeID ==
                declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]).dataTypeID)
            {
                return true;
                //singletone_currentposition->currentPosition++;
            }
            else
            {
                //wrong type
                return false;
            }
        }
        else
        {
            //var not exist
            return false;
        }
    }
    else
    {
        //wornt equal sentence
        return false;
    }
}