#include "mll.h"
#include <iostream>
using namespace std;

void createListDeveloper(ListDeveloper &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrDeveloper createElementDeveloper(infotypeDeveloper x) {
    adrDeveloper P = new elmDeveloper;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    P->firstKlien = nullptr;
    return P;
}

bool isEmptyDev(ListDeveloper L) {
    return (L.first == nullptr && L.last == nullptr);
}

adrDeveloper findDeveloper(ListDeveloper L, string id) {
    adrDeveloper cur = L.first;
    while (cur != nullptr) {
        if (cur->info.idDeveloper == id) return cur;
        cur = cur->next;
    }
    return nullptr;
}

void insertFirstDeveloper(ListDeveloper &L, adrDeveloper P) {
    if (P == nullptr) return;
    if (isEmptyDev(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastDeveloper(ListDeveloper &L, adrDeveloper P) {
    if (P == nullptr) return;
    if (isEmptyDev(L)) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteDeveloperByID(ListDeveloper &L, string id) {
    adrDeveloper target = findDeveloper(L, id);
    if (target == nullptr) return;
    PointerChild cur = target->firstKlien;
    while (cur != nullptr) {
        PointerChild tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    if (target == L.first && target == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else if (target == L.first) {
        L.first = target->next;
        L.first->prev = nullptr;
    } else if (target == L.last) {
        L.last = target->prev;
        L.last->next = nullptr;
    } else {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    delete target;
}

void showAllDeveloper(ListDeveloper L) {
    if (isEmptyDev(L)) {
        cout << "Tidak ada developer.\n";
        return;
    }
    adrDeveloper cur = L.first;
    while (cur != nullptr) {
        cout << "Developer ID: " << cur->info.idDeveloper
             << ", Nama: " << cur->info.namaDeveloper
             << ", Spesialisasi: " << cur->info.spesialisasi
             << ", Rating: " << cur->info.rating << "\n";
        int cnt = 0;
        PointerChild c = cur->firstKlien;
        while (c != nullptr) { cnt++; c = c->next; }
        cout << "  Jumlah klien: " << cnt << "\n";
        PointerChild curChild = cur->firstKlien;
        while (curChild != nullptr) {
            cout << "    - [" << curChild->data.idKlien << "] "
                 << curChild->data.namaKlien
                 << " | Project: " << curChild->data.project
                 << " | Progress: " << curChild->data.progress
                 << " | NilaiKontrak: " << curChild->data.nilaiKontrak
                 << "\n";
            curChild = curChild->next;
        }
        cur = cur->next;
    }
}
