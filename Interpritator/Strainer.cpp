#pragma once
#include "Strainer.h"
#include <vector>
#include "../LexAnalizator/Lex.h"
#include "../LexAnalizator/LexAnalizator.h"

void Strainer::groupQuotedLexemes()
{
    std::vector<Lex> processedLexemes;
    bool inQuotes = false;
    std::string accumulatedLexeme;
    Lex tempLex;

    for (auto& lex : LexAnalizator::FinalLexConfig) {
        if ((lex.value == "\"" || lex.value == "'") && !inQuotes) {
            // Початок кавичок
            inQuotes = true;
            accumulatedLexeme = lex.value; // Зберігаємо відкриваючу кавичку
            tempLex.lexLine = lex.lexLine; // Запам'ятовуємо рядок, де почалася кавичка
            continue;
        }

        if (inQuotes) {
            accumulatedLexeme += lex.value; // Додаємо зміст між кавичками
            if (lex.value == "\"" || lex.value == "'")
            {
                tempLex.value = accumulatedLexeme;
                tempLex.lexID = LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2;
                if(lex.value=="\"") tempLex.dataTypeID = 381;
                else if(lex.value == "'") tempLex.dataTypeID = 391;
                // Закриття кавичок
                inQuotes = false;
                processedLexemes.push_back(tempLex);
                continue;
            }
        } else {
            // Якщо не в кавичках, додаємо лексему до оброблених
            processedLexemes.push_back(lex);
        }
    }

    // Оновлюємо вектор лексем після обробки
    LexAnalizator::FinalLexConfig = processedLexemes;
}