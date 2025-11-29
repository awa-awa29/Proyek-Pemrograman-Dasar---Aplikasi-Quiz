#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <algorithm> //untuk shuffle option
#include <random>
#include "option.h"
using namespace std;

class question {
    private :
        string text;
        vector<option> options;
        int correctIndex;

    public :
        question();
        question(string text);

        void setText(string t);
        void addOption(option op);
        void setCorrectIndex(int i);

        string getText();
        vector<option> getOptions();
        bool isCorrect(int index);

        int getCorrectIndex();
        void shuffleOptions(); //mengacak opsi soal
};

#endif