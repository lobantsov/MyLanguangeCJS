#pragma once
#include "LexAnalizator.h"
#include <algorithm>
#include <fstream>
#include <iostream>
std::vector<Lex> LexAnalizator::FinalLexConfig;
std::vector<std::string> LexAnalizator::SingleLexConfig=
    { ";",":","'","(",")","{","}","<",">","+","-","*","/" ,"=","\""," ",",","[","]" };
std::vector<std::string> LexAnalizator::MultiplyLexConfig= { "for","or","while","do_while","of","if","else","switch","case",
                                        "default","break","function","return","write","read", "bool", "int", "float", "double",
                                        "string", "char", "let", "main","++","--","**","+=","-=","*=","/=","<=",">=","!=","new",
                                         "=="};

std::vector<Lex>* LexAnalizator::readCode(std::string path)
{
    std::ifstream fileForParth(path);
    if (!fileForParth.is_open())
    {
        std::cerr << "????????? ??????? ????" << '\n';
    }
    else {
        std::string line;
        std::string currentWord;
        Lex lex;
        int index = 0;

        while (getline(fileForParth, line))
        {
            index++;

            for (int i = 0; i < line.length(); i++)
            {
                auto found = find(SingleLexConfig.begin(), SingleLexConfig.end(), std::string(1, line[i]));

                if (found != SingleLexConfig.end())
                {
                    if (!currentWord.empty())
                    {
                        processLexeme(currentWord, index, line);
                        currentWord.clear();
                    }

                    //++ -- += -= *= /=
                    std::string possibleOperator = std::string(1, line[i]);
                    if ((possibleOperator == "+" || possibleOperator == "-" || possibleOperator == "*" || possibleOperator == "/") &&
                        i + 1 < line.length() && line[i + 1] == '=')
                    {
                        possibleOperator += "=";
                        i++;
                    }
                    else if ((possibleOperator == "+" || possibleOperator == "-" || possibleOperator == "*") &&
                             i + 1 < line.length() && line[i + 1] == possibleOperator[0])
                    {
                        possibleOperator += possibleOperator[0];
                        i++;
                    }
                    else if (possibleOperator == "*" && i + 1 < line.length() && line[i + 1] == '*')
                    {
                        possibleOperator += "*";
                        i++;
                    }

                    auto operatorFound = find(MultiplyLexConfig.begin(), MultiplyLexConfig.end(), possibleOperator);
                    if (operatorFound != MultiplyLexConfig.end())
                    {
                        lex.value = *operatorFound;
                        lex.lexID = distance(MultiplyLexConfig.begin(), operatorFound)+SingleLexConfig.size();
                        lex.lexLine = index;
                        FinalLexConfig.push_back(lex);
                    }
                    else
                    {
                        lex.value = *found;
                        lex.lexID = distance(SingleLexConfig.begin(), found);
                        lex.lexLine = index;
                        FinalLexConfig.push_back(lex);
                    }
                }
                else
                {
                    currentWord += line[i];
                }
            }

            if (!currentWord.empty())
            {
                processLexeme(currentWord, index, line);
                currentWord.clear();
            }
        }

        fileForParth.close();
        auto it = FinalLexConfig.begin();
        while (it != FinalLexConfig.end())
        {
            if (it->lexID == 15)
            {
                auto next = std::next(it);
                while (next != FinalLexConfig.end() && next->lexID == 15)
                {
                    next = FinalLexConfig.erase(next);
                }
                // Переміщуємо ітератор на наступний за останнім lexID=15
                it = std::next(next);
            }
            else
            {
                ++it;
            }
        }
         groupQuotedLexemes();
                groupQuotedLexemes2();
                CheckConst();

        //removeElementAfter15(0);
        remove15BeforeAndAfterID(0);
        remove15BeforeAndAfterID(3);
        remove15BeforeAndAfterID(4);
        remove15BeforeAndAfterID(5);
        remove15BeforeAndAfterID(6);
        remove15BeforeAndAfterID(7);
        remove15BeforeAndAfterID(8);
        remove15BeforeAndAfterID(9);
        remove15BeforeAndAfterID(10);
        remove15BeforeAndAfterID(11);
        remove15BeforeAndAfterID(12);
        remove15BeforeAndAfterID(13);
        remove15BeforeAndAfterID(16);
        remove15BeforeAndAfterID(17);
        remove15BeforeAndAfterID(18);
        remove15BeforeAndAfterID(42);
        remove15BeforeAndAfterID(43);
        remove15BeforeAndAfterID(44);
        remove15BeforeAndAfterID(45);
        remove15BeforeAndAfterID(46);
        remove15BeforeAndAfterID(47);
        remove15BeforeAndAfterID(48);
        remove15BeforeAndAfterID(49);
        remove15BeforeAndAfterID(50);
        remove15BeforeAndAfterID(51);
        remove15BeforeAndAfterID(53);

        return &FinalLexConfig;
    }
    return {};
}

void LexAnalizator::remove15BeforeAndAfterID(int ID)
{
    int pos = -1;
    for (int i = 0; i < FinalLexConfig.size(); i++)
    {
        if (FinalLexConfig[i].lexID == ID)
        {
            pos = i;
            if (pos != -1)
            {
                for (int i = pos + 1; i < FinalLexConfig.size(); i++)
                {
                    if (FinalLexConfig[i].lexID == 15)
                    {
                        FinalLexConfig.erase(FinalLexConfig.begin() + i);
                        i--;
                    }
                    else
                    {
                        break;
                    }
                }

                for (int i = pos - 1; i >= 0; i--)
                {
                    if (FinalLexConfig[i].lexID == 15)
                    {
                        FinalLexConfig.erase(FinalLexConfig.begin() + i);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            pos = -1;
        }
    }
}

void LexAnalizator::Print()
{
    // for (int i = 0; i < FinalLexConfig.size(); i++)
    // {
    //     cout << "ID: " << FinalLexConfig[i].lexID << endl;
    //     cout << "LineN: " << FinalLexConfig[i].lexLine << endl;
    //     cout << "ValueL: " << FinalLexConfig[i].value << endl;
    //     cout << "----------------------------------------------" << endl;
    // }

    for (int i = 0; i < a.size(); i++)
    {
        std::cout << "ID: " << i << std::endl;
        std::cout << "ValueL: " << a[i] <<std:: endl;
        std::cout << "----------------------------------------------" << std::endl;
    }
}

void LexAnalizator::processLexeme(const std::string& word, int line, const std::string& orLine)
{
    Lex lex;
    // ???????? ?? ?????
    if (isVariable(word, orLine))
    {
        if (!ThisContains(&VariablesTable, word))
        {
            lex.value = word;
            lex.lexID = 1;
            lex.lexLine = line;
            VariablesTable.push_back(lex);
            lex.lexID += SingleLexConfig.size() + MultiplyLexConfig.size();
            FinalLexConfig.push_back(lex);
        }
        else
        {
            auto lex = GetLex(&VariablesTable, word);
            lex.lexID += SingleLexConfig.size() + MultiplyLexConfig.size();
            FinalLexConfig.push_back(lex);
        }
    }

    else if (isConstant(word, orLine))
    {
        // if (!ThisContains(&ConstantsTable, word))
        // {
            //ConstIdexator+=2;
            lex.value = word;
            lex.lexID = 2;
            lex.lexLine = line;
            ConstantsTable.push_back(lex);
            lex.lexID += SingleLexConfig.size() + MultiplyLexConfig.size();
            FinalLexConfig.push_back(lex);
        // }
        // else
        // {
        //     auto lex = GetLex(&ConstantsTable, word);
        //     lex.lexID += SingleLexConfig.size() + MultiplyLexConfig.size();
        //     FinalLexConfig.push_back(lex);
        // }
    }
    else
    {
        auto it = find(MultiplyLexConfig.begin(), MultiplyLexConfig.end(), word);
        lex.value = word;
        lex.lexID = distance(MultiplyLexConfig.begin(), it)+ SingleLexConfig.size();
        lex.lexLine = line;
        FinalLexConfig.push_back(lex);
    }

}

bool LexAnalizator::isVariable(const std::string& word, const std::string& orLine)
{
    if (find(SingleLexConfig.begin(), SingleLexConfig.end(), word) != SingleLexConfig.end())
    {
        return false;
    }

    if (find(MultiplyLexConfig.begin(), MultiplyLexConfig.end(), word) != MultiplyLexConfig.end())
    {
        return false;
    }
    if (isQuotedString(word, orLine))
    {
        return false;
    }
    if (word.empty()) {
        return false;
    }
    if (!isalpha(word[0]) && word[0] != '_') {
        return false;
    }
    for (char ch : word.substr(1)) {
        if (!isalnum(ch) && ch != '_') {
            return false;
        }
    }
    if (word == "true" || word == "false") {
        return false;
    }
    return true;
}

bool LexAnalizator::isConstant(const std::string& word, const std::string& orLine)
{
    if (word.empty()) {
        return false;
    }
    if (isQuotedString(word, orLine))
    {
        return true;
    }
    bool hasDot = false;
    for (char ch : word) {
        if (isdigit(ch)) {
            continue;
        }
        else if (ch == '.' && !hasDot) {
            hasDot = true;
        }
        else
            {
            if (word == "true" || word == "false") {
                return true;
            }
            return false;
        }
    }

    return true;
}

bool LexAnalizator::isQuotedString(const std::string& word, const std::string& orLine)
{
    if (word.empty())
    {
        return false;
    }

    size_t position = orLine.find(word);
    if (position > 0)
    {
        if (orLine[position - 1] == '"' && orLine[position + word.length()] == '"'||
            orLine[position - 1] == '\'' && orLine[position + word.length()] == '\'') return true;
    }
    return false;
}

bool LexAnalizator::ThisContains(std::vector<Lex> *tmp,const std::string& word)
{
    for (int i = 0; i < tmp->size(); i++)
    {
        if ((*tmp)[i].value == word)
        {
            return true;
        }
    }
    return false;
}

Lex LexAnalizator::GetLex(std::vector<Lex> *tmp ,const std::string&word)
{
    Lex newLex;
    for (int i = 0; i < tmp->size(); i++)
    {
        if ((*tmp)[i].value == word)
        {
            newLex.value = (*tmp)[i].value;
            newLex.lexID = (*tmp)[i].lexID;
            newLex.lexLine = (*tmp)[i].lexLine;
            return newLex;
        }
    }
}

void LexAnalizator::CheckConst()
{
    for(int i =0; i<FinalLexConfig.size(); i++)
    {
       FinalLexConfig[i].dataTypeID=checkNumberType(FinalLexConfig[i].value);
            if(FinalLexConfig[i].value=="\"")
            {
                i++;
                FinalLexConfig[i].dataTypeID=381;
                i++;
            }
        if(FinalLexConfig[i].value=="'")
        {
            i++;
            FinalLexConfig[i].dataTypeID=391;
            i++;
        }
        if(FinalLexConfig[i].value == "true" || FinalLexConfig[i].value == "false")
        {
            FinalLexConfig[i].dataTypeID=341;
        }
    }
}

int LexAnalizator::checkNumberType(const std::string &s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return -1;

    char *p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0) ? 351 : 361;
}

void LexAnalizator::groupQuotedLexemes() {
    std::vector<Lex> processedLexemes;
    bool inQuotes = false;
    std::string accumulatedLexeme;
    Lex tempLex;

    for (auto& lex : FinalLexConfig) {
        if ((lex.value == "\"" || lex.value == "'") && !inQuotes) {
            processedLexemes.push_back(lex);
            inQuotes = true;
            accumulatedLexeme.clear();
            tempLex.lexLine = lex.lexLine;
            continue;
        }

        if (inQuotes) {
            if (lex.value == "\"" || lex.value == "'") {
                tempLex.value = accumulatedLexeme;
                tempLex.lexID = SingleLexConfig.size() + MultiplyLexConfig.size() + 2;
                processedLexemes.push_back(tempLex);
                processedLexemes.push_back(lex);
                inQuotes = false;
                accumulatedLexeme.clear();
            } else {
                accumulatedLexeme += lex.value;
            }
        } else {
            processedLexemes.push_back(lex);
        }
    }
    FinalLexConfig = processedLexemes;
}

void LexAnalizator::groupQuotedLexemes2() {
    std::vector<Lex> processedLexemes;
    std::string accumulatedLexeme;
    Lex tempLex;
    bool isSpecialOperator = false;

    for (size_t i = 0; i < FinalLexConfig.size(); ++i) {
        Lex& lex = FinalLexConfig[i];

        if (lex.value == "<" || lex.value == ">" || lex.value == "=" || lex.value == "!") {
            isSpecialOperator = true;
            tempLex = lex;
            accumulatedLexeme = lex.value;

            if (i + 1 < FinalLexConfig.size() && FinalLexConfig[i + 1].value == "=") {
                accumulatedLexeme += "=";
                tempLex.value = accumulatedLexeme;
                tempLex.lexLine = lex.lexLine;

                if (accumulatedLexeme == "<=") {
                    tempLex.lexID = 49;
                } else if (accumulatedLexeme == ">=") {
                    tempLex.lexID = 50;
                } else if (accumulatedLexeme == "==") {
                    tempLex.lexID = 53;
                } else if (accumulatedLexeme == "!=") {
                    tempLex.lexID = 51;
                }

                processedLexemes.push_back(tempLex);
                i++;
                isSpecialOperator = false;
                continue;
            }
            else
            {
                isSpecialOperator = false;
            }
        }

        if (!isSpecialOperator) {
            processedLexemes.push_back(lex);
        } else {
            isSpecialOperator = false;
        }
    }
    FinalLexConfig = processedLexemes;
}

bool LexAnalizator::isOperation(const std::string& op) {
    return op == "+" || op == "*" || op == "/" || op == "<=" || op == ">=" || op == "==" || op == "!=";
}
