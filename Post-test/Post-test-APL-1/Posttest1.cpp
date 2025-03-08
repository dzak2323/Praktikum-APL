#include <iostream>
using namespace std;

int main() {
    
    int PIN = 6056; 
    int pinInput;
    int maxCoba = 3; 
    bool akses = false;
    double saldo = 0; 
    double saldout = 0; 
    double saldoin = 0; 
    
    string enter;
    
    for (int percobaan = 1; percobaan <= maxCoba; percobaan++) {
        cout << "Masukkan PIN Anda: ";
        cin >> pinInput;

        if (pinInput == PIN) {
            cout << "Login berhasil! Selamat datang!" << endl;
            akses = true; 
            break; 
        } else {
            cout << "PIN salah. Percobaan (" << percobaan << "/" << maxCoba << ")" << endl;
        }
    }

    if (!akses) {
        
        cout << "Anda telah gagal login sebanyak " << maxCoba << " kali. Akses ditolak." << endl;
        return 0; 
    }

    
    int pilihan = 0;
    while (akses) {
        cout << "===============================" << endl;
        cout << "        Selamat datang         " << endl;
        cout << "===============================" << endl;
        cout << "1 -> Cek saldo" << endl;
        cout << "2 -> Setor tunai" << endl;
        cout << "3 -> Tarik tunai" << endl;
        cout << "4 -> Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            
            cout << "Saldo Anda adalah Rp " << saldo << "." << endl;
            cout << "Ketik apa saja untuk lanjut" << endl;
            cin >> enter;
        } else if (pilihan == 2) {
            
            cout << "Masukkan jumlah uang yang ingin disetor: Rp ";
            cin >> saldoin;

            if (saldoin > 0) {
                saldo += saldoin; 
                cout << "Setor tunai berhasil. Saldo Anda sekarang adalah Rp " << saldo << "." << endl;
            } else {
                cout << "Nominal setor tunai harus lebih besar dari 0." << endl;
            }

            cout << "Ketik apa saja untuk lanjut" << endl;
            cin >> enter;
        } else if (pilihan == 3) {
            // Tarik tunai
            cout << "Masukkan nominal yang ingin Anda tarik: Rp ";
            cin >> saldout;

            if (saldout > saldo) {
                cout << "Saldo Anda tidak cukup untuk melakukan penarikan." << endl;
            } else if (saldout > 0) {
                saldo -= saldout; // Kurangi saldo
                cout << "Tarik tunai berhasil. Saldo Anda sekarang adalah Rp " << saldo << "." << endl;
            } else {
                cout << "Nominal penarikan harus lebih besar dari 0." << endl;
            }

            cout << "Ketik apa saja untuk lanjut" << endl;
            cin >> enter;
        } else if (pilihan == 4) {
            // Keluar dari aplikasi
            cout << "Keluar. Terima kasih telah menggunakan layanan kami." << endl;
            akses = false; // Keluar dari loop menu
        } else {
            cout << "Pilihan tidak valid! Harap masukkan angka antara 1-4." << endl;
        }
    }

    return 0;
}
