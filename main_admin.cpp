#include "mll.h"

void menuAdmin() {
    cout << "\n===== MENU ADMIN =====\n";
    cout << "=== DEVELOPER ===\n";
    cout << "1. Insert First Developer\n";
    cout << "2. Insert After Developer\n";
    cout << "3. Insert Last Developer\n";
    cout << "4. Delete First Developer\n";
    cout << "5. Delete After Developer\n";
    cout << "6. Delete Last Developer\n";

    cout << "\n=== CLIENT (CHILD) ===\n";
    cout << "7. Insert First Client\n";
    cout << "8. Insert After Client\n";
    cout << "9. Insert Last Client\n";
    cout << "10. Delete First Client\n";
    cout << "11. Delete After Client\n";
    cout << "12. Delete Last Client\n";

    cout << "\n0. Kembali\n";
    cout << "Pilih: ";
}


void adminPage(ListDeveloper &L) {

    int pilihan = -1;

    while (pilihan != 0) {

        menuAdmin();
        cin >> pilihan;

        if (pilihan == 1) {
            infotypeDeveloper x;
            cout << "ID Developer: "; cin >> x.idDeveloper;
            cout << "Nama: "; cin >> x.namaDeveloper;
            cout << "Spesialisasi: "; cin >> x.spesialisasi;
            cout << "Rating: "; cin >> x.rating;

            adrDeveloper P = createElementDeveloper(x);
            insertFirstDeveloper(L, P);
            cout << "Insert First berhasil.\n";
        } else if (pilihan == 2) {
            string idPrev;
            cout << "ID Developer sebelumnya: ";
            cin >> idPrev;

            adrDeveloper Prec = findDeveloper(L, idPrev);

            if (Prec != nullptr) {
                infotypeDeveloper x;
                cout << "ID Developer: "; cin >> x.idDeveloper;
                cout << "Nama: "; cin >> x.namaDeveloper;
                cout << "Spesialisasi: "; cin >> x.spesialisasi;
                cout << "Rating: "; cin >> x.rating;

                adrDeveloper P = createElementDeveloper(x);
                insertAfterDeveloper(L, Prec, P);
                cout << "Insert After berhasil.\n";
            } else {
                cout << "Developer tidak ditemukan.\n";
            }
        } else if (pilihan == 3) {
            infotypeDeveloper x;
            cout << "ID Developer: "; cin >> x.idDeveloper;
            cout << "Nama: "; cin >> x.namaDeveloper;
            cout << "Spesialisasi: "; cin >> x.spesialisasi;
            cout << "Rating: "; cin >> x.rating;

            adrDeveloper P = createElementDeveloper(x);
            insertLastDeveloper(L, P);
            cout << "Insert Last berhasil.\n";
        } else if (pilihan == 4) {
            adrDeveloper P;
            deleteFirstDeveloper(L, P);
            if (P != nullptr) {
                cout << "Delete First berhasil: " << P->info.namaDeveloper << endl;
                delete P;
            } else {
                cout << "List kosong.\n";
            }
        } else if (pilihan == 5) {
            string idPrev;
            cout << "ID Developer sebelumnya: ";
            cin >> idPrev;

            adrDeveloper Prec = findDeveloper(L, idPrev);

            if (Prec != nullptr) {
                adrDeveloper P;
                deleteAfterDeveloper(L, Prec, P);
                if (P != nullptr) {
                    cout << "Delete After berhasil: " << P->info.namaDeveloper << endl;
                    delete P;
                } else {
                    cout << "Tidak ada developer setelahnya.\n";
                }
            } else {
                cout << "Developer tidak ditemukan.\n";
            }
        } else if (pilihan == 6) {
            adrDeveloper P;
            deleteLastDeveloper(L, P);
            if (P != nullptr) {
                cout << "Delete Last berhasil: " << P->info.namaDeveloper << endl;
                delete P;
            } else {
                cout << "List kosong.\n";
            }
        } else if (pilihan == 7) {
            string idDev;
            InfoChild ic;

            cout << "ID Developer: "; cin >> idDev;
            adrDeveloper D = findDeveloper(L, idDev);

            if (D != nullptr) {
                cout << "ID Klien: "; cin >> ic.idKlien;
                cout << "Nama Klien: "; cin >> ic.namaKlien;
                cout << "Project: "; cin >> ic.project;
                cout << "Progress: "; cin >> ic.progress;
                cout << "Nilai Kontrak: "; cin >> ic.nilaiKontrak;

                PointerChild P = createElement_Child(ic);
                insertFirst_Child(D, P);
                cout << "Insert First Client berhasil.\n";
            } else {
                cout << "Developer tidak ditemukan.\n";
            }
        } else if (pilihan == 8) {
            string idDev, idPrev;
            InfoChild ic;

            cout << "ID Developer: "; cin >> idDev;
            adrDeveloper D = findDeveloper(L, idDev);

            if (D != nullptr) {
                cout << "ID Klien sebelumnya: "; cin >> idPrev;
                PointerChild Prec = findElement_Child(D, idPrev);
                if (Prec != nullptr) {
                    cout << "ID Klien: "; cin >> ic.idKlien;
                    cout << "Nama Klien: "; cin >> ic.namaKlien;
                    cout << "Project: "; cin >> ic.project;
                    cout << "Progress: "; cin >> ic.progress;
                    cout << "Nilai Kontrak: "; cin >> ic.nilaiKontrak;
                    PointerChild P = createElement_Child(ic);
                    insertAfter_Child(Prec, P);
                    cout << "Insert After Client berhasil.\n";
                } else {
                    cout << "Klien sebelumnya tidak ditemukan.\n";
                }
            } else {
                cout << "Developer tidak ditemukan.\n";
            }
        } else if (pilihan == 9) {
            string idDev;
            InfoChild ic;

            cout << "ID Developer: "; cin >> idDev;
            adrDeveloper D = findDeveloper(L, idDev);

            if (D != nullptr) {
                cout << "ID Klien: "; cin >> ic.idKlien;
                cout << "Nama Klien: "; cin >> ic.namaKlien;
                cout << "Project: "; cin >> ic.project;
                cout << "Progress: "; cin >> ic.progress;
                cout << "Nilai Kontrak: "; cin >> ic.nilaiKontrak;

                PointerChild P = createElement_Child(ic);
                insertLast_Child(D, P);
                cout << "Insert Last Client berhasil.\n";
            } else {
                cout << "Developer tidak ditemukan.\n";
            }
        } else if (pilihan == 10) {
            string idDev;
            cout << "ID Developer: "; cin >> idDev;

            adrDeveloper D = findDeveloper(L, idDev);
            if (D != nullptr) {
                PointerChild P;
                deleteFirst_Child(D, P);
                if (P != nullptr) {
                    cout << "Delete First Client berhasil: " << P->data.namaKlien << endl;
                } else {
                    cout << "Tidak ada client.\n";
                }
            } else {
                cout << "Developer tidak ditemukan.\n";
            }
        } else if (pilihan == 11) {
            string idDev, idPrev;
            cout << "ID Developer: "; cin >> idDev;

            adrDeveloper D = findDeveloper(L, idDev);
            if (D != nullptr) {
                cout << "ID Klien sebelumnya: "; cin >> idPrev;
                PointerChild Prec = findElement_Child(D, idPrev);

                if (Prec != nullptr) {
                    PointerChild P;
                    deleteAfter_Child(D, Prec, P);
                    if (P != nullptr) {
                        cout << "Delete After Client berhasil: " << P->data.namaKlien << endl;
                    } else {
                        cout << "Tidak ada client setelahnya.\n";
                    }
                } else {
                    cout << "Klien sebelumnya tidak ditemukan.\n";
                }
            } else {
                cout << "Developer tidak ditemukan.\n";
            }
        } else if (pilihan == 12) {
            string idDev;
            cout << "ID Developer: "; cin >> idDev;

            adrDeveloper D = findDeveloper(L, idDev);
            if (D != nullptr) {
                PointerChild P;
                deleteLast_Child(D, P);
                if (P != nullptr) {
                    cout << "Delete Last Client berhasil: " << P->data.namaKlien << endl;
                } else {
                    cout << "Tidak ada client.\n";
                }
            } else {
                cout << "Developer tidak ditemukan.\n";
            }
        }
    }
}
