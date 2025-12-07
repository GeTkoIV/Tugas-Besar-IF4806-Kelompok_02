#include "Developer.h"
#include "Klien.h"
void insertSortedDeveloper(ListDeveloper &L, adrDeveloper P){
    if (L.first == nullptr) {
        insertFirstDeveloper(L, P);
    } else if (P->info.idDeveloper < L.first->info.idDeveloper) {
        insertFirstDeveloper(L, P);
    } else if (P->info.idDeveloper > L.last->info.idDeveloper) {
        insertLastDeveloper(L, P);
    } else {
        adrDeveloper Q = L.first;
        while (Q->next != nullptr) {
            if (P->info.idDeveloper < Q->next->info.idDeveloper) {
                insertAfterDeveloper(Q, P);
                Q->next = nullptr;
            } else {
                Q = Q->next;
            }
        }
    }
}

void deleteFirstDeveloper(ListDeveloper &L, adrDeveloper &P){
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = nullptr;
        P->next = nullptr;
        P->prev = nullptr;
    }
}
void deleteLastDeveloper(ListDeveloper &L, adrDeveloper &P){
    if (L.first == nullptr) {
        P = nullptr;
    }
    else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }
    else {
        P = L.last;
        L.last = P->prev;
        L.last->next = nullptr;
        P->prev = nullptr;
        P->next = nullptr;
    }
}
void deleteAfterDeveloper(ListDeveloper &L, adrDeveloper Prec, adrDeveloper &P){
    if (Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
    }
    else {
        P = Prec->next;
        if (P == L.last) {
            L.last = Prec;
            Prec->next = nullptr;
            P->prev = nullptr;
        }
        else {
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = nullptr;
            P->prev = nullptr;
        }
    }
}
void findMaxClientsBySpecialty(ListDeveloper L, string specialty) {
    adrDeveloper P_Dev = L.first;
    adrDeveloper maxDev = nullptr;
    int maxClients = -1;

    while (P_Dev != nullptr) {

        if (P_Dev->info.spesialisasi == specialty) {

            int clientCount = 0;
            PointerChild P_Kli = P_Dev->firstKlien;

            while (P_Kli != nullptr) {
                clientCount++;
                P_Kli = P_Kli->next;
            }

            if (clientCount > maxClients) {
                maxClients = clientCount;
                maxDev = P_Dev;
            }
        }

        P_Dev = P_Dev->next;
    }
    if (maxDev != nullptr) {
        cout << "SUKSES: Developer " << maxDev->info.namaDeveloper
             << " (" << specialty << ") ditemukan dengan "
             << maxClients << " klien terbanyak." << endl;
    } else {
        cout << "GAGAL: Tidak ada Developer dengan spesialisasi '"
             << specialty << "'." << endl;
    }
}

