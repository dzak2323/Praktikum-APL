#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_DATA = 100;
const int MAX_USER = 15;

struct InfoBarang {
    string nama;
    int harga;
};

struct Barang {
    string kode;
    InfoBarang info;
};

struct loginState {
    int pilihMenu;
    int attempts = 0;
    string inputNama;
    string inputPassword;
    bool loggedIn = false;
};

struct loginData {
    string nama;
    string password;
};

struct User {
    loginData login;
};

Barang dataBarang[MAX_DATA];
User users[MAX_USER]; 
int jumlahData = 0;
int jumlahUser = 1;

int main() {
    users[0].login.nama = "dzaki";
    users[0].login.password = "056";

    loginState state;

    do {
        system("cls");
        cout << "\n===================================\n";
        cout << "|         SELAMAT DATANG         |\n";
        cout << "===================================\n";
        cout << "| 1. Login                       |\n";
        cout << "| 2. Register                    |\n";
        cout << "| 3. Keluar                      |\n";
        cout << "===================================\n";
        cout << "Pilih menu: ";
        cin >> state.pilihMenu;
        cin.ignore();

        if (state.pilihMenu == 1) {
            state.attempts = 0;
            state.loggedIn = false;

            while (state.attempts < 3) {
                system("cls");
                cout << "\n===================================\n";
                cout << "|          LOGIN SISTEM          |\n";
                cout << "===================================\n";
                cout << "Nama: ";
                getline(cin, state.inputNama);
                cout << "Password: ";
                getline(cin, state.inputPassword);

                for (int i = 0; i < jumlahUser; i++) {
                    if (state.inputNama == users[i].login.nama && state.inputPassword == users[i].login.password) {
                        state.loggedIn = true;
                        int pilihan;
                        Barang barang;

                        do {
                            system("cls");
                            cout << "\n===================================\n";
                            cout << "|         MENU UTAMA             |\n";
                            cout << "===================================\n";
                            cout << "| 1. Tambah Barang               |\n";
                            cout << "| 2. Tampilkan Barang            |\n";
                            cout << "| 3. Hapus Barang                |\n";
                            cout << "| 4. Edit Barang                 |\n";
                            cout << "| 5. Keluar                      |\n";
                            cout << "===================================\n";
                            cout << "Pilih menu: ";
                            cin >> pilihan;
                            cin.ignore();

                            if (pilihan == 1) {
                                system("cls");
                                if (jumlahData >= MAX_DATA) {
                                    cout << "\nData penuh!\n";
                                    cin.get();
                                    continue;
                                }
                                cout << "\nMasukkan Kode Barang: ";
                                getline(cin, barang.kode);
                                cout << "Masukkan Nama Barang: ";
                                getline(cin, barang.info.nama);
                                string harga;
                                bool valid;
                                do {
                                    valid = true;
                                    cout << "Masukkan Harga Barang: ";
                                    cin >> harga;
                                    for (char c : harga) {
                                        if (c < '0' || c > '9') {
                                            valid = false;
                                            break;
                                        }
                                    }
                                    if (!valid) {
                                        cout << "Harga harus berupa angka! Coba lagi.\n";
                                    }
                                } while (!valid);
                                barang.info.harga = stoi(harga);
                                dataBarang[jumlahData++] = barang;
                                cout << "Data berhasil ditambahkan!\n";
                                cin.get();
                            } else if (pilihan == 2) {
                                system("cls");
                                if (jumlahData == 0) {
                                    cout << "\nData masih kosong!\n";
                                } else {
                                    cout << "\n--------------------------------------------\n";
                                    cout << "| No |   Kode   |    Nama Barang    | Harga   |";  
                                    cout << "\n--------------------------------------------\n";
                                    for (int i = 0; i < jumlahData; i++) {
                                        cout << "| " << setw(2) << i + 1 << " | " << setw(8) << dataBarang[i].kode << " | "
                                             << setw(15) << dataBarang[i].info.nama << " | " << setw(6) << dataBarang[i].info.harga << " |\n";
                                    }
                                    cout << "--------------------------------------------\n";
                                }
                                cin.get();
                            } else if (pilihan == 3) {
                                system("cls");
                                if (jumlahData == 0) {
                                    cout << "\nData masih kosong!\n";
                                } else {
                                    cout << "\n--------------------------------------------\n";
                                    cout << "| No |   Kode   |    Nama Barang    | Harga   |";  
                                    cout << "\n--------------------------------------------\n";
                                    for (int i = 0; i < jumlahData; i++) {
                                        cout << "| " << setw(2) << i + 1 << " | " << setw(8) << dataBarang[i].kode << " | "
                                             << setw(15) << dataBarang[i].info.nama << " | " << setw(6) << dataBarang[i].info.harga << " |\n";
                                    }
                                    cout << "--------------------------------------------\n";
                                    cout << "Masukkan nomor barang yang akan dihapus: ";
                                    
                                    int hapusIndex;
                                    cin >> hapusIndex;
                                    if (hapusIndex > 0 && hapusIndex <= jumlahData) {
                                        for (int i = hapusIndex - 1; i < jumlahData - 1; i++) {
                                            dataBarang[i] = dataBarang[i + 1];
                                        }
                                        jumlahData--;
                                        cout << "Data berhasil dihapus!\n";
                                    } else {
                                        cout << "Nomor tidak valid!\n";
                                    }
                                }
                                cin.ignore();
                                cin.get();
                            } else if (pilihan == 4) {
                                system("cls");
                                if (jumlahData == 0) {
                                    cout << "\nData masih kosong!\n";
                                } else {
                                    cout << "\n--------------------------------------------\n";
                                    cout << "| No |   Kode   |    Nama Barang    | Harga   |";  
                                    cout << "\n--------------------------------------------\n";
                                    for (int i = 0; i < jumlahData; i++) {
                                        cout << "| " << setw(2) << i + 1 << " | " << setw(8) << dataBarang[i].kode << " | "
                                             << setw(15) << dataBarang[i].info.nama << " | " << setw(6) << dataBarang[i].info.harga << " |\n";
                                    }
                                    cout << "--------------------------------------------\n";
                                    cout << "Masukkan nomor barang yang akan diedit: ";
                                    int index;
                                    cin >> index;
                                    if (index < 1 || index > jumlahData) {
                                        cout << "Nomor tidak valid!\n";
                                        cin.ignore();
                                        cin.get();
                                        continue;
                                    }
                                    cin.ignore();
                                    cout << "Masukkan Nama Baru: ";
                                    getline(cin, dataBarang[index - 1].info.nama);
                                    cout << "Masukkan Harga Baru: ";
                                    cin >> dataBarang[index - 1].info.harga;
                                    cin.ignore();
                                    cout << "Data berhasil diubah!\n";
                                }
                                cin.get();
                            }
                        } while (pilihan != 5);
                    }
                }
            }
        }
                string newNama, newPassword;
                system("cls");
                cout << "\n===================================\n";
                cout << "|          REGISTER AKUN         |\n";
                cout << "===================================\n";
                cout << "Masukkan Nama: ";
                getline(cin, newNama);
                cout << "Masukkan Password: ";
                getline(cin, newPassword);

                users[jumlahUser].login.nama = newNama;
                users[jumlahUser].login.password = newPassword;
                jumlahUser++;
                cout << "\nRegistrasi berhasil! Silakan login.\n";
                cin.ignore();
                cin.get();
    } while (state.pilihMenu != 3);
    return 0;
}
