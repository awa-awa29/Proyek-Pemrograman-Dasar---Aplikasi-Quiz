#ifndef OPTION_H
#define OPTION_H

#include <string>
using namespace std;

class option {
    private:
        string text;

    public:
        option();
        option(string text);

        void setText(string t);
        string getText();
};

#endif