#ifndef SESSION_H
#define SESSION_H

#include "quiz.h"
#include "user.h"

class session {
    private :
        user player;
        quiz currentQuiz;
        int score;
        int currentIndex;

    public : 
        session(user player, quiz currentQuiz);

        void start();
        void play();
};

#endif