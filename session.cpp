#include "session.h"
#include <iostream>
using namespace std;

session::session(user player, quiz currentQuiz)
    : player(player), currentQuiz(currentQuiz), score(0), currentIndex(0) {}

// Menjalankan seluruh sisi quiz
 void session::start() {
    vector<question> qs = currentQuiz.getQuestions();
    score = 0;
    currentIndex = 0;

    cout << "\n=== MULAI QUIZ : " << currentQuiz.getTitle() << " ===\n";

    for (int i = 0; i < qs.size(); i++) {
        currentIndex = i;
        play();
    }

    cout << "\n=== QUIZ SELESAI ===\n";
    cout << "Skor Akhir : " << score << "/" << qs.size() << endl;
 }

 //Memainkan 1 soal
 void session::play() {
    vector<question> qs = currentQuiz.getQuestions();
    question q = qs[currentIndex];

    cout << "\n------------------------------------\n";
    cout << "Soal " << (currentIndex + 1) << ":\n";
    cout << q.getText() << endl;

    vector<option> ops = q.getOptions();

    //tampilkan opsi
    for (int i = 0; i < ops.size(); i++) {
        cout << i + 1 << ". " << ops[i].getText() << endl;
    }

    int jawab;
    cout << "Jawaban kamu (1-" << ops.size() << "): ";
    cin >> jawab;

    // validasi input
    while (jawab < 1 || jawab > ops.size()) {
        cout << "Input tidak valid. Masukkan ulang : ";
        cin >> jawab;
    }

    if (q.isCorrect (jawab - 1)) {
        cout << "Benar!\n";
        score++;
    } else {
        cout << "Salah.\n";
    }
 }