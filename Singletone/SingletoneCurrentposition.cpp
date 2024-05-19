#pragma once
#include "SingletoneCurrentposition.h"
SingletoneCurrentposition* SingletoneCurrentposition::singleton_= nullptr;;

SingletoneCurrentposition *SingletoneCurrentposition::GetInstance()
{
    if(singleton_==nullptr){
        singleton_ = new SingletoneCurrentposition();
    }
    return singleton_;
}
int SingletoneCurrentposition::currentPosition = 0;
int SingletoneCurrentposition::currentPosition_backup = 0;
bool SingletoneCurrentposition::isLogicOperator = false;
