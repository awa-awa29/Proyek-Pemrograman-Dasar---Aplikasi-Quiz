// soal quiz dapat disimpan

#include <iostream>
#include <vector>
#include "user.h"
#include "quiz.h"
#include "question.h"
#include "session.h"
#include "option.h"
using namespace std;

int main () {
    user User;
    quiz Quiz("Games Quiz");

    cout << "=== REGISTER ===\n";
    string email, username, password, role;

    cout << "Email : ";
    cin >> email;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    cout << "Pilih Role (master/ player) : ";
    cin >> role;

    User.setData(email, username, password, role);

    cout << "\n=== LOGIN ===\n";
    string u, p;
    cout << "Username : ";
    cin >> u;
    cout << "Password : ";
    cin >> p;

    if (!User.login(u, p)) {
        cout << "Login gagal!\n";
        return 0;
    }

    cout << "\nSelamat Datang, " << User.getUsername() << " (" << User.getRole() << ")\n";

    // MASTER MODE =======================================
    if (User.getRole() == "master") {
        int n;
        cout << "\nBerapa soal yang ingin ditambahkan? ";
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; i++) {
            string qText;
            cout << "\nSoal " << i + 1 << ": ";
            getline(cin, qText);

            question q(qText);

            for (int j = 0; j < 4; j++) {
                string op;
                cout << "Opsi " << j << ": ";
                getline(cin, op);
                q.addOption(option(op));
            }

            int correct;
            cout << "Opsi Jawaban Benar (0-3) : ";
            cin >> correct;
            cin.ignore();

            q.setCorrectIndex(correct);

            Quiz.addQuestions(q);
        }

        // SAVE TO CSV
        Quiz.saveToCSV("quiz.csv");
        cout << "\n=== Data soal tersimpan ===\n";

        }

    // Player Mode ======================================
    if (User.getRole() == "player") {
        
        // LOAD CSV AUTOMATIS
        Quiz.loadFromCSV("quiz.csv");

        session S(User, Quiz);
        S.start();
    }

    return 0;
}