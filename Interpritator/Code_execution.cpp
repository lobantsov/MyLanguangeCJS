#pragma once
#include "Code_execution.h"
#include <sstream>
#include "../LexAnalizator/LexAnalizator.h"

void Code_execution::Execution() {
    source_string_stack = inverse_writing->FormingSourceLine();
    EaserMyLive();
    while (source_string_stack.size() != iterator) {
        Lex &lex = source_string_stack[iterator];
        int constantID = LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 1;
        int variableID = LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 2;

        if (lex.lexID == constantID or lex.lexID == variableID) {
            tmp_stack.push(lex);
        } else if (class_for_methood_container_->isOperation(lex.value)) {
            if (lex.value == "=") {
                Lex tmp1, tmp2;
                tmp1 = tmp_stack.top();
                tmp_stack.pop();
                tmp2 = tmp_stack.top();
                tmp_stack.pop();
                EqualExecute(tmp2, tmp1);
            } else if (class_for_methood_container_->IsMathOperator(lex)) {
                Lex tmp1, tmp2;
                tmp1 = tmp_stack.top();
                tmp_stack.pop();
                tmp2 = tmp_stack.top();
                tmp_stack.pop();
                tmp_stack.push(MathOperators(lex,tmp2, tmp1));
            }
            else if(class_for_methood_container_->IsLogicOperator(lex)) {
                Lex tmp1, tmp2;
                tmp1 = tmp_stack.top();
                tmp_stack.pop();
                tmp2 = tmp_stack.top();
                tmp_stack.pop();
                tmp_stack.push(CheckLogicSentence(lex,tmp2, tmp1));
            }
        }


        iterator++;
    }
}

void Code_execution::EqualExecute(Lex tmp2, Lex tmp1) {
    for (Lex &op: declarered_variables_->CreatedLexemus) {
        if (tmp2.value == op.value) {
            op.data = tmp1.data;
            break;
        }
    }
}

Lex Code_execution::MathOperators(Lex operator_, Lex tmp2, Lex tmp1) {
    Lex result;

    if (operator_.value == "+") {
        result = tmp1 + tmp2;
    } else if (operator_.value == "-") {
        result = tmp1 - tmp2;
    } else if (operator_.value == "*") {
        result = tmp1 * tmp2;
    } else if (operator_.value == "/") {
        result = tmp1 / tmp2;
    } else if (operator_.value == "+=") {
        tmp1 += tmp2;
        result = tmp1;
    } else if (operator_.value == "-=") {
        tmp1 -= tmp2;
        result = tmp1;
    } else if (operator_.value == "/=") {
        tmp1 /= tmp2;
        result = tmp1;
    } else if (operator_.value == "*=") {
        tmp1 *= tmp2;
        result = tmp1;
    }

    result.value = result.toString();
    result.lexID=202;
    result.lexLine=operator_.lexLine;
    return result;
}

Lex Code_execution::CheckLogicSentence(Lex operator_, Lex tmp1, Lex tmp2) {
    Lex result;

    if (operator_.value == "==") {
        result.data = tmp1.equals(tmp2);
    } else if (operator_.value == "<=") {
        result.data =  tmp1.value <= tmp2.value;
    } else if (operator_.value == "<") {
         result.data = tmp1.value < tmp2.value;
    } else if (operator_.value == ">=") {
         result.data = tmp1.value >= tmp2.value;
    } else if (operator_.value == ">") {
         result.data = tmp1.value > tmp2.value;
    } else if (operator_.value == "!=") {
         result.data = tmp1.value != tmp2.value;
    }

    result.value = result.toString();
    result.lexID=202;
    result.lexLine=operator_.lexLine;
    return result;
}

bool Code_execution::CheckVarOrConst(const Lex &lex) {
    //const
    if (lex.lexID == LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 1) {
        return true;
    }
    //var
    else if (lex.lexID == LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 2) {
        return false;
    }
}

Lex Code_execution::FindLex(Lex lex) {
    for (const Lex &op: declarered_variables_->CreatedLexemus) {
        if (lex.value == op.value)
            return op;
    }
}

std::string Code_execution::CheckTypeOfConst(Lex lex) {
    switch (lex.dataTypeID) {
        case 341: return "bool";
        case 351:
        case 361: return "number";
        case 381: return "string";
        case 391: return "char";
    }
}

std::string Code_execution::CheckTypeOfVar(Lex lex) {
    switch (lex.dataTypeID) {
        case 34: return "bool";
        case 35:
        case 36:
        case 37: return "number";
        case 38: return "string";
        case 39: return "char";
    }
}

void Code_execution::EaserMyLive() {
    for (Lex &a: source_string_stack) {
        if (a.lexID == LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 2) {
            switch (a.dataTypeID) {
                case 341:
                    if (a.value == "true") a.data = true;
                    else if (a.value == "false") a.data = false;
                    break;
                case 351:
                case 361:
                    a.data = stringToNumber(a.value);
                    break;
                case 381:
                    a.data = a.value;
                    break;
                case 391: a.data = a.value[0];
                    break;
            }
        }
    }
}

std::variant<std::string, bool, char, double> Code_execution::stringToNumber(const std::string &str) {
    std::stringstream ss(str);
    double number;
    ss >> number;
    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid input string");
    }
    return number;
}