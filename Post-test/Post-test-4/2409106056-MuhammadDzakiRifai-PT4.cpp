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

// Fungsi rekursif validasi angka
bool isNumber(string input, int index = 0) {
    if (index >= input.length()) return true;
    if (!isdigit(input[index])) return false;
    return isNumber(input, index + 1);
}

// Overload cetak barang
void cetakBarang(const Barang& barang) {
    cout << barang.kode << " - " << barang.info.nama << " - Rp" << barang.info.harga << endl;
}

void cetakBarang(const Barang* arr, int n) {
    cout << "\n------------------------------------------------\n";
    cout << "| No |   Kode   |    Nama Barang    |  Harga   |";
    cout << "\n------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "| " << setw(2) << i + 1 << " | " << setw(8) << arr[i].kode << " | "
             << setw(17) << arr[i].info.nama << " | " << setw(8) << arr[i].info.harga << " |\n";
    }
    cout << "------------------------------------------------\n";
}

// Tambah barang
void tambahBarang(Barang* arr, int& count) {
    system("cls");
    if (count >= MAX_DATA) {
        cout << "Data penuh!\n";
        return;
    }
    Barang b;
    string hargaStr;
    bool valid = false;

    cout << "Masukkan Kode Barang: ";
    cin.ignore();
    getline(cin, b.kode);
    cout << "Masukkan Nama Barang: ";
    getline(cin, b.info.nama);

    do {
        cout << "Masukkan Harga Barang: ";
        getline(cin, hargaStr);
        valid = isNumber(hargaStr);
        if (!valid) cout << "Harga harus berupa angka!\n";
    } while (!valid);

    b.info.harga = stoi(hargaStr);
    arr[count++] = b;
    cout << "Data berhasil ditambahkan!\n";
}

// Tampilkan barang
void tampilkanBarang(const Barang* arr, int count) {
    system("cls");
    if (count == 0) {
        cout << "Data masih kosong!\n";
    } else {
        cetakBarang(arr, count);
    }
}

// Hapus barang
void hapusBarang(Barang* arr, int& count) {
    system("cls");
    if (count == 0) {
        cout << "Data masih kosong!\n";
        return;
    }
    cetakBarang(arr, count);
    cout << "Masukkan nomor barang yang akan dihapus: ";
    int index;
    cin >> index;

    if (index > 0 && index <= count) {
        for (int i = index - 1; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
        cout << "Data berhasil dihapus!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

// Edit barang
void editBarang(Barang* arr, int count) {
    system("cls");
    if (count == 0) {
        cout << "Data masih kosong!\n";
        return;
    }
    cetakBarang(arr, count);
    cout << "Masukkan nomor barang yang akan diedit: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index >= 1 && index <= count) {
        cout << "Masukkan Nama Baru: ";
        getline(cin, arr[index - 1].info.nama);
        cout << "Masukkan Harga Baru: ";
        cin >> arr[index - 1].info.harga;
        cout << "Data berhasil diubah!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

// Login
int login(User* users, int jumlahUser) {
    string nama, password;
    int attempts = 0;

    while (attempts < 3) {
        system("cls");
        cout << "\n============= LOGIN =============\n";
        cout << "Nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Password: ";
        getline(cin, password);

        for (int i = 0; i < jumlahUser; i++) {
            if (nama == users[i].login.nama && password == users[i].login.password) {
                return i;
            }
        }

        cout << "Login gagal. Coba lagi.\n";
        attempts++;
    }

    return -1;
}

// Registrasi
void registrasi(User* users, int& jumlahUser) {
    string nama, password;
    system("cls");
    cout << "\n========== REGISTER ==========\n";
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan Password: ";
    getline(cin, password);

    users[jumlahUser].login.nama = nama;
    users[jumlahUser].login.password = password;
    jumlahUser++;
    cout << "Registrasi berhasil!\n";
}

int main() {
    users[0].login.nama = "dzaki";
    users[0].login.password = "056";

    int pilih;
    do {
        system("cls");
        cout << "========================================\n";
        cout << "|             MENU UTAMA              |\n";
        cout << "========================================\n";
        cout << "| 1. Login                            |\n";
        cout << "| 2. Register                         |\n";
        cout << "| 3. Keluar                           |\n";
        cout << "========================================\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            int userIndex = login(users, jumlahUser);
            if (userIndex != -1) {
                int menu;
                do {
                    system("cls");
                    cout << "============================================\n";
                    cout << "|               MENU UTAMA                 |\n";
                    cout << "============================================\n";
                    cout << "| 1. Tambah Barang                         |\n";
                    cout << "| 2. Tampilkan Barang                      |\n";
                    cout << "| 3. Hapus Barang                          |\n";
                    cout << "| 4. Edit Barang                           |\n";
                    cout << "| 5. Logout                                |\n";
                    cout << "============================================\n";
                    cout << "Pilih: ";
                    cin >> menu;

                    switch (menu) {
                        case 1:
                            tambahBarang(dataBarang, jumlahData);
                            cin.ignore(); cin.get();
                            break;
                        case 2:
                            tampilkanBarang(dataBarang, jumlahData);
                            cin.ignore(); cin.get();
                            break;
                        case 3:
                            hapusBarang(dataBarang, jumlahData);
                            cin.ignore(); cin.get();
                            break;
                        case 4:
                            editBarang(dataBarang, jumlahData);
                            cin.ignore(); cin.get();
                            break;
                    }
                } while (menu != 5);
            }else {
                cout << "Login gagal 3 kali silahkan keluar.\n";
                cin.ignore(); cin.get();
                exit(0); 
            }
        } else if (pilih == 2) {
            registrasi(users, jumlahUser);
            cin.ignore(); cin.get();
        }
    } while (pilih != 3);

    return 0;
}
