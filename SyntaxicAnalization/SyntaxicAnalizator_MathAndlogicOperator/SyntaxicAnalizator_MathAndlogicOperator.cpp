#pragma once
#include "SyntaxicAnalizator_MathAndlogicOperator.h"
#include "../../LexAnalizator/LexAnalizator.h"

bool SyntaxicAnalizator_MathAndlogicOperator::ConditionCheck(bool isloop)
{
    //<,>,<=,>=,==
    //add check for declareted var
    if((LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1&&
         declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))||
         LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    {
        singletone_currentposition->currentPosition++;
    }
    //<   >     >=    <=
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==7||LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==8||
       LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==49||LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==50)
    {
        singletone_currentposition->currentPosition++;
    }
    //==
    else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==55)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        //singletone_currentposition->currentPosition--;
        return false;
    }
    if((LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1&&
         declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))||
         LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        //create_erorrs->CreateSyntaxError();
        return false;
    }
    if(isloop)
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==4)
        {
            return true;
        }
    }
    else
    {
        
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
        {
            return true;
        }
        else
        {
            //create_erorrs->CreateSyntaxError();
            return false;
        }
    }
}
