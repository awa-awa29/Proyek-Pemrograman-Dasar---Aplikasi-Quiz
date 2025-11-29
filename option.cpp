#include "option.h"

option::option() {}

option::option(string text) : text(text) {}

void option::setText(string t) {
    text = t;
}

string option::getText() {
    return text;
}