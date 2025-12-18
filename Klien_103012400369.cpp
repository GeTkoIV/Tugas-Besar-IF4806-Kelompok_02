#include "mll.h"
#include <iostream>
using namespace std;

PointerChild createElement_Child(InfoChild data) {
    PointerChild P = new NodeChild;
    P->data = data;
    P->next = nullptr;
    return P;
}

void insertFirst_Child(adrDeveloper P_Dev, PointerChild P_Kli) {
    if (P_Dev != nullptr || P_Kli != nullptr){
        P_Kli->next = P_Dev->firstKlien;
        P_Dev->firstKlien = P_Kli;
    }
}

void insertLast_Child(adrDeveloper P_Dev, PointerChild P_Kli) {
    if (P_Dev != nullptr && P_Kli != nullptr) {
        if (P_Dev->firstKlien == nullptr) {
            P_Dev->firstKlien = P_Kli;
        } else {
            PointerChild Q = P_Dev->firstKlien;
            while (Q->next != nullptr) {
                Q = Q->next;
            }
            Q->next = P_Kli;
        }
    }
}

void showAllClientsByOneDeveloper(ListDeveloper L, string idDev) {
    adrDeveloper P_Dev = findDeveloper(L, idDev);

    if (P_Dev != nullptr) {
        cout << "\n============================================================" << endl;
        cout << " DAFTAR KLIEN DARI DEVELOPER: " << P_Dev->info.namaDeveloper << endl;
        cout << " ID Developer: " << P_Dev->info.idDeveloper << endl;
        cout << "============================================================" << endl;

        PointerChild P_Kli = P_Dev->firstKlien;
        if (P_Kli == nullptr) {
            cout << "  (Developer ini belum memiliki klien/proyek)." << endl;
        } else {
            int i = 1;
            while (P_Kli != nullptr) {
                cout << "  [" << i++ << "] ID Klien  : " << P_Kli->data.idKlien << endl;
                cout << "      Nama Klien: " << P_Kli->data.namaKlien << endl;
                cout << "      Project   : " << P_Kli->data.project << endl;
                cout << "      Progress  : " << P_Kli->data.progress << endl;
                cout << "      Kontrak   : " << P_Kli->data.nilaiKontrak << endl;
                cout << "  ------------------------------------------" << endl;
                P_Kli = P_Kli->next;
            }
        }
    } else {
        cout << "ERROR: Developer dengan ID " << idDev << " tidak ditemukan." << endl;
    }
}
