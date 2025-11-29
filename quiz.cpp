#include "quiz.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm> // random_shuffle
using namespace std;

quiz::quiz() {}

quiz::quiz(string title) : title(title) {}

void quiz::setTitle(string t) {
    title = t;
}

void quiz::addQuestions(question q) { 
    questions.push_back(q);
}

void quiz::removeQuestion(int index) {
    if (index >= 0 && index < questions.size()) {
        questions.erase(questions.begin() + index);
    }
}

vector<question> quiz::getQuestions(){
    return questions;
}

string quiz::getTitle(){
    return title;
}

void quiz::shuffleQuestions() {
    random_shuffle(questions.begin(), questions.end());
}

// =============================== CSV ===============================
// SAVE TO CSV
void quiz::saveToCSV(string filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Gagal membuka file!\n";
        return;
    }

    for (auto &q : questions) {
        file << q.getText();

        vector<option> ops = q.getOptions();
        for (auto &op : ops) {
            file << "," << op.getText();
        }

        file << "," << q.getCorrectIndex();
        file << "\n";
    }

    file.close();
    cout << "Soal berhasil disimpan ke " << filename << "\n";
}

// LOAD FROM CSV
void quiz::loadFromCSV(string filename) {
    ifstream file(filename);

    if (! file.is_open()) {
        cout << "File tidak ditemukan! Master harus membuat soal dulu!\n";
        return; 
    }

    questions.clear();

    string line;
    while (getline(file, line)) {
        stringstream ss (line);
        string item;

        vector<string> parts;

        while (getline(ss, item, ',')) {
            parts.push_back(item);
        }

        if (parts.size() < 6) continue;

        question q(parts[0]);
        q.addOption(option(parts[1]));
        q.addOption(option(parts[2]));
        q.addOption(option(parts[3]));
        q.addOption(option(parts[4]));

        q.setCorrectIndex(stoi(parts[5]));

        questions.push_back(q);
    }

    file.close();
}
