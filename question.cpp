#include "question.h"

question::question() {}

question::question(string text) : text(text), correctIndex(-1) {}

void question::setText(string t) {
    text = t;
}

void question::addOption(option op) {
    options.push_back(op);
}

void question::setCorrectIndex(int i) {
    correctIndex = i;
}

string question::getText() {
    return text;
}

vector<option> question::getOptions() {
    return options;
}

bool question::isCorrect(int index) {
    return index == correctIndex;
}

int question::getCorrectIndex() {
    return correctIndex;
}

void question::shuffleOptions() {
    // simpan opsi yang benar sebelum di-shuffle
    option correctOption = options[correctIndex];

    // proses shuffle
    random_device rd;
    mt19937 g(rd());
    shuffle(options.begin(), options.end(), g);

    // setelah shuffle, cari index baru yang benar
    for (int i = 0; i < options.size(); i++) {
        if (options[i].getText() == correctOption.getText()) {
            correctIndex = i;  // update posisi jawaban benar
            break;
        }
    }
}