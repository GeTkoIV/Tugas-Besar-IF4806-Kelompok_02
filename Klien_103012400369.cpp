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
    if (P_Dev != nullptr || P_Kli != nullptr) {
        P_Kli->next = P_Dev->firstKlien;
        P_Dev->firstKlien = P_Kli;
    }
}

void insertLast_Child(adrDeveloper P_Dev, PointerChild P_Kli) {
    if (P_Dev == nullptr || P_Kli == nullptr){
        if (P_Dev->firstKlien == nullptr) {
            P_Dev->firstKlien = P_Kli;
        } else {
            PointerChild cur = P_Dev->firstKlien;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = P_Kli;
        }
        P_Kli->next = nullptr;
    }
}

void showAllClientsByOneDeveloper(ListDeveloper L, string idDev) {
    adrDeveloper dev = findDeveloper(L, idDev);
    if (dev == nullptr) {
        cout << "Developer dengan ID " << idDev << " tidak ditemukan.\n";
        return;
    }
    cout << "Clients of Developer " << dev->info.namaDeveloper << " (" << dev->info.idDeveloper << "):\n";
    PointerChild cur = dev->firstKlien;
    if (cur == nullptr) {
        cout << "  (tidak ada klien)\n";
        return;
    }
    while (cur != nullptr) {
        cout << " - ID: " << cur->data.idKlien
             << ", Nama: " << cur->data.namaKlien
             << ", Project: " << cur->data.project
             << ", Progress: " << cur->data.progress
             << ", NilaiKontrak: " << cur->data.nilaiKontrak
             << "\n";
        cur = cur->next;
    }
}
