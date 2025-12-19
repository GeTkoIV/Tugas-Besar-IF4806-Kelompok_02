#include "mll.h"
void insertAfter_Child(PointerChild Prec, PointerChild P_Kli) {
    if (P_Kli != nullptr) {
        if (Prec == nullptr) {
        } else if (Prec->next == nullptr) {
            Prec->next = P_Kli;
            P_Kli->next = nullptr;
        } else {
            P_Kli->next = Prec->next;
            Prec->next = P_Kli;
        }
    }
}
void insertSorted_Child(adrDeveloper P_Dev, PointerChild P_Kli) {
    if (P_Dev->firstKlien == nullptr ||
        P_Kli->data.idKlien < P_Dev->firstKlien->data.idKlien) {

        P_Kli->next = P_Dev->firstKlien;
        P_Dev->firstKlien = P_Kli;
    }
    else {
        PointerChild Q = P_Dev->firstKlien;
        while (Q->next != nullptr &&
               P_Kli->data.idKlien > Q->next->data.idKlien) {
            Q = Q->next;
        }
        insertAfter_Child(Q, P_Kli);
    }
}
void findKlienWithMinContract(ListDeveloper L) {
    adrDeveloper P_Dev = L.first;
    PointerChild minKlien = nullptr;
    int minContract;
    while (P_Dev != nullptr) {
        PointerChild P_Kli = P_Dev->firstKlien;
        while (P_Kli != nullptr) {
            if (minKlien == nullptr) {
                minKlien = P_Kli;
                minContract = P_Kli->data.nilaiKontrak;
            }
            else if (P_Kli->data.nilaiKontrak < minContract) {
                minKlien = P_Kli;
                minContract = P_Kli->data.nilaiKontrak;
            }

            P_Kli = P_Kli->next;
        }
        P_Dev = P_Dev->next;
    }
    if (minKlien != nullptr) {
        cout << "SUKSES: Project dengan nilai kontrak terendah ditemukan.\n";
        cout << "  -> Klien: " << minKlien->data.namaKlien
             << " (Project: " << minKlien->data.project
             << ") dengan Nilai Kontrak: " << minContract << endl;
    } else {
        cout << "GAGAL: Tidak ada Klien yang ditemukan dalam list." << endl;
    }
}

void showChildByDeveloperAndProgress(ListDeveloper L, string idDev, string targetProgress) {
    adrDeveloper P_Dev = findDeveloper(L, idDev);
    int count = 0;

    if (P_Dev == nullptr) {
        cout << "ERROR: Developer dengan ID " << idDev << " tidak ditemukan." << endl;
    } else {
        cout << "\n============================================================" << endl;
        cout << " PROYEK " << targetProgress << " OLEH DEVELOPER: " << P_Dev->info.namaDeveloper << endl;
        cout << "============================================================" << endl;

        PointerChild P_Kli = P_Dev->firstKlien;
        while (P_Kli != nullptr) {
            if (P_Kli->data.progress == targetProgress) {
                cout << "  [" << ++count << "] Project: " << P_Kli->data.project
                 << ", Klien: " << P_Kli->data.namaKlien
                 << ", Kontrak: " << P_Kli->data.nilaiKontrak << endl;
            }

            P_Kli = P_Kli->next;
        }
        if (count == 0) {
            cout << "  (Tidak ditemukan proyek dengan status '" << targetProgress << "')." << endl;
        } else {
            cout << "Total " << count << " proyek " << targetProgress << " ditemukan." << endl;
        }
    }
}
void insertChildToDeveloper(ListDeveloper &L, InfoChild infoKlien, string idDev){
    adrDeveloper P_Dev = findDeveloper(L, idDev);
    if (P_Dev != nullptr) {
        PointerChild P_Kli = createElement_Child(infoKlien);
        insertLast_Child(P_Dev, P_Kli);
        cout << "SUKSES: Klien " << infoKlien.namaKlien;
        cout << " (Project: " << infoKlien.project;
        cout << ") telah berhasil ditambahkan ke Developer ";
        cout << P_Dev->info.namaDeveloper << "." << endl;
    } else {
        cout << "ERROR: Developer dengan ID " << idDev << " tidak ditemukan. Penambahan klien dibatalkan." << endl;

    }
}
void deleteChildByProgress(adrDeveloper P_Dev, string progress, PointerChild &P_Kli){
    P_Kli = nullptr;
    if (P_Dev->firstKlien != nullptr) {
        if (P_Dev->firstKlien->data.progress == progress) {
            P_Kli = P_Dev->firstKlien;
            P_Dev->firstKlien = P_Kli->next;
            P_Kli->next = nullptr;
        }
        else {
            PointerChild Q = P_Dev->firstKlien;
            while (Q->next != nullptr) {
                if (Q->next->data.progress == progress) {
                    P_Kli = Q->next;
                    Q->next = P_Kli->next;
                    P_Kli->next = nullptr;
                    Q = Q->next;
                }
                else {
                    Q = Q->next;
                }
            }
        }
    }
}
void deleteAfter_Child(adrDeveloper P_Dev, PointerChild Prec, PointerChild &P_Kli){
    P_Kli = nullptr;
    if (P_Dev != nullptr && Prec != nullptr) {
        PointerChild target = Prec->next;
        if (target != nullptr) {
            Prec->next = target->next;
            target->next = nullptr;
            P_Kli = target;
        }
    }
}
void deleteChildById(adrDeveloper P_Dev, string id, PointerChild &P_Kli) {
    P_Kli = nullptr;

    if (P_Dev != nullptr && P_Dev->firstKlien != nullptr) {

        if (P_Dev->firstKlien->data.idKlien == id) {
            P_Kli = P_Dev->firstKlien;
            P_Dev->firstKlien = P_Kli->next;
            P_Kli->next = nullptr;
        }
        else {
            PointerChild Prec = P_Dev->firstKlien;
            PointerChild Cur = Prec->next;

            while (Cur != nullptr && P_Kli == nullptr) {
                if (Cur->data.idKlien == id) {
                    P_Kli = Cur;
                    Prec->next = Cur->next;
                    P_Kli->next = nullptr;
                } else {
                    Prec = Cur;
                    Cur = Cur->next;
                }
            }
        }
    }
}
PointerChild findElement_Child(adrDeveloper P_Dev, string idKlien) {
    PointerChild P = nullptr;
    if (P_Dev != nullptr) {

        P = P_Dev->firstKlien;

        while (P != nullptr && P->data.idKlien != idKlien) {
            P = P->next;
        }
    }
    return P;
}
void updateProgressKlien(adrDeveloper P_Dev, string idKlien, string progressBaru) {
    PointerChild P = P_Dev->firstKlien;

    while (P != nullptr) {
        if (P->data.idKlien == idKlien) {
            P->data.progress = progressBaru;
            cout << "Progress klien berhasil diperbarui.\n";
        }
        P = P->next;
    }

    cout << "Klien tidak ditemukan.\n";
}
