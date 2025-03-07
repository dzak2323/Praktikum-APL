#include <iostream>
using namespace std;


int main() {
    double PIN = 6056; // PIN default
    double pinInput;
    int trial = 0; // Percobaan login
    int maxTrial = 3; // Maksimal percobaan

    cout << "===============================" << endl;
    cout << "Silahkan masukkan PIN Anda" << endl;
    cout << "===============================" << endl;

    for (int trial = 1; trial <= maxTrial; trial++) {
        cout << "Masukkan PIN: ";
        cin >> pinInput;

        if (pinInput == PIN) {
            cout << "Login berhasil! Selamat datang!" << endl;
            return 0; 
        } else {
            cout << "PIN salah. Percobaan (" << trial << "/" << maxTrial << ")" << endl;
        }
    }

    cout << "Anda telah gagal login sebanyak " << maxTrial << " kali. Akses ditolak." << endl;
    return 0;
}
