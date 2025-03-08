#include <iostream>
#include <cstdlib> // Untuk system()
using namespace std;

int main() {
    int PIN = 6056;
    int pinInput;
    int maxCoba = 3;
    bool akses = false;
    int saldo = 0;
    int saldout = 0;
    int saldoin = 0;
    string enter;

//Verifikasi PIN
    system("cls");
    for (int percobaan = 1; percobaan <= maxCoba; percobaan++) {
    cout << "Masukkan PIN Anda: ";
    cin >> pinInput;

    if (pinInput == PIN) {
        cout << "Login berhasil! Selamat datang!" << endl;
        cin.ignore(); 
        cin.get();    
        system("cls");
        akses = true;
        break;
    } else {
        cout << "PIN salah. Percobaan (" << percobaan << "/" << maxCoba << ")" << endl;
        cin.ignore(); 
        cin.get();
        system("cls");
    }
}

if (!akses) {
    cout << "Anda telah gagal login sebanyak " << maxCoba << " kali. Akses ditolak." << endl;
    cin.ignore(); 
    cin.get();    
    return 0;
}


    // Menu utama
    int pilihan = 0;
    while (akses) {
        system("cls");
        cout << "===============================" << endl;
        cout << "        Selamat datang         " << endl;
        cout << "===============================" << endl;
        cout << "1 -> Cek saldo" << endl;
        cout << "2 -> Setor tunai" << endl;
        cout << "3 -> Tarik tunai" << endl;
        cout << "4 -> Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Masukkan angka yang valid!" << endl;
            cin.ignore();
            continue;
        }

        if (pilihan == 1) {
            cout << "Saldo Anda adalah Rp " << saldo << "." << endl;
            cin.ignore();
            cin.get();
        } else if (pilihan == 2) {
            cout << "Masukkan jumlah uang yang ingin disetor: Rp ";
            cin >> saldoin;

            if (saldoin > 0) {
                saldo += saldoin;
                cout << "Setor tunai berhasil. Saldo Anda sekarang adalah Rp " << saldo << "." << endl;
            } else {
                cout << "Nominal setor tunai harus lebih besar dari 0." << endl;
            }
            cin.ignore();
            cin.get();
        } else if (pilihan == 3) {
            cout << "Masukkan nominal yang ingin Anda tarik: Rp ";
            cin >> saldout;

            if (saldout > saldo) {
                cout << "Saldo Anda tidak cukup untuk melakukan penarikan." << endl;
            } else if (saldout > 0) {
                saldo -= saldout;
                cout << "Tarik tunai berhasil. Saldo Anda sekarang adalah Rp " << saldo << "." << endl;
            } else {
                cout << "Nominal penarikan harus lebih besar dari 0." << endl;
            }
            cin.ignore();
            cin.get();
        } else if (pilihan == 4) {
            cout << "Keluar. Terima kasih telah menggunakan layanan kami." << endl;
            akses = false;
        } else {
            cout << "Pilihan tidak valid! Harap masukkan angka antara 1-4." << endl;
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
