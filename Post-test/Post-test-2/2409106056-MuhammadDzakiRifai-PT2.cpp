#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_DATA = 100;
string dataBarang[MAX_DATA][3]; // Array 2D untuk menyimpan kode, nama, dan harga barang
int jumlahData = 0;

int main() {
    string username = "dzaki";
    string password = "2409106056";
    string inputUser, inputPass;
    int attempts = 0;
    
    // Proses login
    while (attempts < 3) {
        system("cls");
        cout << "\n===================================\n";
        cout << "|          LOGIN SISTEM          |\n";
        cout << "===================================\n";
        cout << "| Username: ";
        cin >> inputUser;
        cout << "| Password: ";
        cin >> inputPass;
        cout << "===================================\n";
        
        if (inputUser == username && inputPass == password) {
            cout << "Login berhasil!\n";
            cin.ignore();
            cin.get();
            break;
        } else {
            cout << "Login gagal, coba lagi!\n";
            attempts++;
            cin.ignore();
            cin.get();
        }
    }
    
    if (attempts == 3) {
        cout << "\nTerlalu banyak percobaan gagal. Program berhenti.\n";
        return 0;
    }
    
    int pilihan;
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
        
        if (pilihan == 1) {
            system("cls");
            if (jumlahData >= MAX_DATA) {
                cout << "\nData penuh!\n";
                cin.ignore();
                cin.get();
                continue;
            }
            cout << "\nMasukkan Kode Barang: ";
            cin >> dataBarang[jumlahData][0];
            cout << "Masukkan Nama Barang: ";
            cin.ignore();
            getline(cin, dataBarang[jumlahData][1]);
            
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
            
            dataBarang[jumlahData][2] = harga;
            jumlahData++;
            cout << "Data berhasil ditambahkan!\n";
            cin.ignore();
            cin.get();
        } 
        else if (pilihan == 2) {
            system("cls");
            if (jumlahData == 0) {
                cout << "\nData masih kosong!\n";
            } else {
                cout << "\n-----------------------------------------------------------------------\n";
                cout << "| No |   Kode   |       Nama Barang       |      Harga      |\n";
                cout << "-----------------------------------------------------------------------\n";
                for (int i = 0; i < jumlahData; i++) {
                    cout << "| " << setw(2) << i + 1 << " | " << setw(8) << dataBarang[i][0] << " | "
                         << setw(20) << dataBarang[i][1] << " | Rp. " << setw(12) << dataBarang[i][2] << " |\n";
                }
                cout << "-----------------------------------------------------------------------\n";
            }
            cin.ignore();
            cin.get();
        }
        else if (pilihan == 3 || pilihan == 4) {
            system("cls");
            if (jumlahData == 0) {
                cout << "\nData masih kosong!\n";
                cin.ignore();
                cin.get();
                continue;
            }
            
            cout << "\nDaftar Barang:\n";
            cout << "-----------------------------------------------------------------------\n";
            cout << "| No |   Kode   |       Nama Barang       |      Harga      |\n";
            cout << "-----------------------------------------------------------------------\n";
            for (int i = 0; i < jumlahData; i++) {
                cout << "| " << setw(2) << i + 1 << " | " << setw(8) << dataBarang[i][0] << " | "
                     << setw(20) << dataBarang[i][1] << " | Rp. " << setw(12) << dataBarang[i][2] << " |\n";
            }
            cout << "-----------------------------------------------------------------------\n";
            
            int index;
            cout << "Masukkan nomor data yang ingin diubah: ";
            cin >> index;
            if (index < 1 || index > jumlahData) {
                cout << "Nomor tidak valid!\n";
                cin.ignore();
                cin.get();
                continue;
            }
            
            if (pilihan == 3) {
                for (int i = index - 1; i < jumlahData - 1; i++) {
                    dataBarang[i][0] = dataBarang[i + 1][0];
                    dataBarang[i][1] = dataBarang[i + 1][1];
                    dataBarang[i][2] = dataBarang[i + 1][2];
                }
                jumlahData--;
                cout << "Data berhasil dihapus!\n";
            } else {
                cout << "Masukkan Kode Barang baru: ";
                cin >> dataBarang[index - 1][0];
                cout << "Masukkan Nama Barang baru: ";
                cin.ignore();
                getline(cin, dataBarang[index - 1][1]);
                
                string harga;
                bool valid;
                do {
                    valid = true;
                    cout << "Masukkan Harga Barang baru: ";
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
                
                dataBarang[index - 1][2] = harga;
                cout << "Data berhasil diedit!\n";
            }
            cin.ignore();
            cin.get();
        }
    } while (pilihan != 5);
    
    return 0;
}
