#include "textanalyzer.h"

textAnalyzer::textAnalyzer(const std::string filePath,bool *flag){
    std::fstream file(filePath);
    if (file.is_open()){
        std::string line;
        while (getline(file,line)){
            content += line + "\n";
            countN++;

        }
        file.close();
        *flag=true;
    }
    else{
        *flag=false;
    }
}

int textAnalyzer::strLenght(){
    return content.size()-countN;
}

int textAnalyzer::countWords(){
    int count=0;
    bool inWord=false;
    for (char c : content){
        if (isalpha(c)){
            if (!inWord){
                count++;
                inWord=false;
            }
            else{
                inWord=true;
            }
        }
    }
    return count;
}

int textAnalyzer::countSentences(){
    int count=0;
    for (char c : content){
        if (c=='.' or c=='!' or c=='?'){
            count++;
        }
    }
    return count;
}

int textAnalyzer::countPunctuation(){
    int count=0;
    for (char c: content){
        if ((c>=33 and c<=47) or (c>=58 and c<=63)){
            count++;
        }
    }
    return count;
}

int textAnalyzer::countSpace(){
    int count=0;
    for (char c:content){
        if (c==' '){
            count++;
        }
    }
    return count;
}
