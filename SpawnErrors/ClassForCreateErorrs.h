//
// Created by loban on 5/18/2024.
//

#ifndef CLASSFORCREATEERORRS_H
#define CLASSFORCREATEERORRS_H

#pragma once

#include "../Singletone/SingletoneCurrentposition.h"
class ClassForCreateErorrs
{
protected:
    ClassForCreateErorrs(){}
    static ClassForCreateErorrs* create_erorrs_;
public:
    ClassForCreateErorrs(ClassForCreateErorrs& others) = delete;
    static ClassForCreateErorrs *GetInstance();
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
    void CreateSyntaxError();
    void CreateDeclarationError();

    void CreateTypeMismatchError();

    bool error_status = false;
};

#endif //CLASSFORCREATEERORRS_H
