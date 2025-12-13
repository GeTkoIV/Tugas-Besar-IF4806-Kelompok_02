#include <iostream>
#include "mll.h"
using namespace std;

void menuUser() {
    cout << "\n===== MENU USER =====\n";
    cout << "1. Tambah Client ke Developer\n";
    cout << "2. Hapus Client by ID\n";
    cout << "3. Tampilkan Semua Developer\n";
    cout << "4. Tampilkan Semua Client dari Developer\n";
    cout << "5. Tampilkan Client berdasarkan Progress\n";
    cout << "6. Cari Developer dengan Klien Terbanyak\n";
    cout << "7. Cari Klien dengan Kontrak Terendah\n";
    cout << "0. Kembali\n";
    cout << "Pilih: ";
}

void userPage(ListDeveloper &L) {

    int pilihan = -1;

    while (pilihan != 0) {

        menuUser();
        cin >> pilihan;

        if (pilihan == 1) {
            InfoChild ic;
            string idDev;

            cout << "ID Developer: "; cin >> idDev;
            cout << "ID Klien: "; cin >> ic.idKlien;
            cout << "Nama Klien: "; cin >> ic.namaKlien;
            cout << "Project: "; cin >> ic.project;
            cout << "Progress: "; cin >> ic.progress;
            cout << "Nilai Kontrak: "; cin >> ic.nilaiKontrak;

            insertChildToDeveloper(L, ic, idDev);
        }

        else if (pilihan == 2) {
            string idDev, idKli;

            cout << "ID Developer: "; cin >> idDev;
            cout << "ID Klien: "; cin >> idKli;

            adrDeveloper D = findDeveloper(L, idDev);

            if (D != nullptr) {
                PointerChild P;
                deleteChildById(D, idKli, P);
                if (P != nullptr) {
                    cout << "Delete klien berhasil: " << P->data.namaKlien << endl;
                    delete P;
                } else {
                    cout << "Klien tidak ditemukan.\n";
                }
            } else {
                cout << "Developer tidak ditemukan.\n";
            }
        }

        else if (pilihan == 3) {
            showAllDeveloper(L);
        }

        else if (pilihan == 4) {
            string idDev;
            cout << "ID Developer: "; cin >> idDev;
            showAllClientsByOneDeveloper(L, idDev);
        }

        else if (pilihan == 5) {
            string idDev, prog;

            cout << "ID Developer: "; cin >> idDev;
            cout << "Progress: "; cin >> prog;

            showChildByDeveloperAndProgress(L, idDev, prog);
        }

        else if (pilihan == 6) {
            string sp;
            cout << "Spesialisasi: "; cin >> sp;
            findMaxClientsBySpecialty(L, sp);
        }

        else if (pilihan == 7) {
            findKlienWithMinContract(L);
        }
    }
}
