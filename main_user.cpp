#include <iostream>
#include "mll.h"
using namespace std;

void menuUser() {
    cout <<endl<<"===== MENU USER ====="<<endl;
    cout << "1. Tambah Client ke Developer"<<endl;
    cout << "2. Hapus Client by ID"<<endl;
    cout << "3. Tampilkan Semua Developer"<<endl;
    cout << "4. Tampilkan Semua Client dari Developer"<<endl;
    cout << "5. Tampilkan Client berdasarkan Progress"<<endl;
    cout << "6. Cari Developer dengan Klien Terbanyak"<<endl;
    cout << "7. Cari Klien dengan Kontrak Terendah"<<endl;
    cout << "8. Tambah Developer (berdasarkan ID)"<<endl;
    cout << "9. Hapus Developer (berdasarkan ID)"<<endl;
    cout << "10. Ubah Progress Project Klien"<<endl;
    cout << "11. Hitung Rata-rata Kontrak Developer"<<endl;
    cout << "12. Tambah Client ke Developer (Sorted)"<<endl;
    cout << "0. Kembali"<<endl;
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
        } else if (pilihan == 2) {
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
                    cout << "Klien tidak ditemukan."<<endl;
                }
            } else {
                cout << "Developer tidak ditemukan."<<endl;
            }
        } else if (pilihan == 3) {
            showAllDeveloper(L);
        } else if (pilihan == 4) {
            string idDev;
            cout << "ID Developer: "; cin >> idDev;
            showAllClientsByOneDeveloper(L, idDev);
        } else if (pilihan == 5) {
            string idDev, prog;

            cout << "ID Developer: "; cin >> idDev;
            cout << "Progress: "; cin >> prog;

            showChildByDeveloperAndProgress(L, idDev, prog);
        } else if (pilihan == 6) {
            string sp;
            cout << "Spesialisasi: "; cin >> sp;
            findMaxClientsBySpecialty(L, sp);
        } else if (pilihan == 7) {
            findKlienWithMinContract(L);
        } else if (pilihan == 8) {
            infotypeDeveloper id;

            cout << "ID Developer   : "; cin >> id.idDeveloper;
            cout << "Nama Developer : "; cin >> id.namaDeveloper;
            cout << "Spesialisasi   : "; cin >> id.spesialisasi;
            cout << "Rating         : "; cin >> id.rating;

            if (findDeveloper(L, id.idDeveloper) == nullptr) {
                adrDeveloper P = createElementDeveloper(id);
                insertSortedDeveloper(L, P);
                cout << "Developer berhasil ditambahkan."<<endl;
            } else {
                cout << "ID Developer sudah terdaftar."<<endl;
            }
        } else if (pilihan == 9) {
            string idDev;
            cout << "ID Developer yang akan dihapus: ";
            cin >> idDev;

            if (findDeveloper(L, idDev) != nullptr) {
                deleteDeveloperByID(L, idDev);
                cout << "Developer berhasil dihapus."<<endl;
            } else {
                cout << "Developer tidak ditemukan."<<endl;
            }
        } else if (pilihan == 10) {
            string idDev, idKli, progBaru;
            cout << "ID Developer : ";
            cin >> idDev;
            cout << "ID Klien     : ";
            cin >> idKli;
            cout << "Progress Baru: ";
            cin >> progBaru;
            adrDeveloper D = findDeveloper(L, idDev);
            if (D != nullptr) {
                updateProgressKlien(D, idKli, progBaru);
            } else {
                cout << "Developer tidak ditemukan."<<endl;
            }
        } else if (pilihan == 11) {
            string idDev;
            cout << "ID Developer: ";
            cin >> idDev;
            hitungRataRataKontrakDeveloper(L, idDev);
        } else if (pilihan == 12) {
            InfoChild ic;
            string idDev;
            cout << "ID Developer: ";
            cin >> idDev;
            adrDeveloper D = findDeveloper(L, idDev);
            if (D != nullptr) {
                cout << "ID Klien       : ";
                cin >> ic.idKlien;
                cout << "Nama Klien     : ";
                cin >> ic.namaKlien;
                cout << "Project        : ";
                cin >> ic.project;
                cout << "Progress       : ";
                cin >> ic.progress;
                cout << "Nilai Kontrak  : ";
                cin >> ic.nilaiKontrak;
                if (findElement_Child(D, ic.idKlien) == nullptr) {
                    PointerChild P = createElement_Child(ic);
                    insertSorted_Child(D, P);
                    cout << "Klien berhasil ditambahkan secara TERURUT." << endl;
                } else {
                    cout << "ID Klien sudah terdaftar." << endl;
                }
            } else {
                cout << "Developer tidak ditemukan." << endl;
            }
        }
    }
}
