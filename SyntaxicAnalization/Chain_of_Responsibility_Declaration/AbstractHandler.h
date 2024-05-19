//
// Created by loban on 5/18/2024.
//

#ifndef ABSTRACTHANDLER_H
#define ABSTRACTHANDLER_H

#pragma once
#include <vector>
#include "IHandler.h"
using namespace std;
class AbstractHandler:public IHandler
{
    IHandler *next_handler_;
protected:
public:
    IHandler *SetNext(IHandler *handler) override;
    bool Handle(Lex TypeID) override;
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
};



#endif //ABSTRACTHANDLER_H
