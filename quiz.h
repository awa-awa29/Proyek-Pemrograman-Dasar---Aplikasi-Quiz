#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>
#include "question.h"
using namespace std;

class quiz {
    private : 
        string title;
        vector<question> questions;

    public :
        quiz();
        quiz(string title);

        void setTitle(string title);
        void addQuestions(question q);
        void removeQuestion(int index);

        vector<question> getQuestions();
        string getTitle();

        void shuffleQuestions();

        // Tambahan CSV untuk menyimpan soal
        void saveToCSV(string filename);
        void loadFromCSV(string filename);
};

#endif