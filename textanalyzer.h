#pragma once
#include <string>
#include <fstream>
#include <iostream>

class textAnalyzer{
    public:
        std::string content;
        textAnalyzer(const std::string filePath,bool *flag);

        int strLenght();

        int countWords();

        int countSentences();

        int countPunctuation();

        int countSpace();

    private:

        int countN=0;

};
