#ifndef KLIEN_H_INCLUDED
#define KLIEN_H_INCLUDED

#include <iostream>

using namespace std;

struct InfoChild {
    string idKlien;
    string namaKlien;
    string project;
    string progress;
    int nilaiKontrak;
};

typedef struct NodeChild *PointerChild;
struct NodeChild {
    InfoChild data;
    PointerChild next;
};

struct elmDeveloper;
typedef elmDeveloper *adrDeveloper;
struct ListDeveloper;

PointerChild createElement_Child(InfoChild data);

void insertFirst_Child(adrDeveloper P_Dev, PointerChild P_Kli);
void insertLast_Child(adrDeveloper P_Dev, PointerChild P_Kli);
void deleteFirst_Child(adrDeveloper P_Dev, PointerChild &P_Kli);
void deleteLast_Child(adrDeveloper P_Dev, PointerChild &P_Kli);

void insertSorted_Child(adrDeveloper P_Dev, PointerChild P_Kli);
void insertAfter_Child(PointerChild Prec, PointerChild P_Kli);
void deleteChildByProgress(adrDeveloper P_Dev, string progress, PointerChild &P_Kli);
void deleteAfter_Child(adrDeveloper P_Dev, PointerChild Prec, PointerChild &P_Kli);

PointerChild findElement_Child(adrDeveloper P_Dev, string ID);
void showAllClientsByOneDeveloper(ListDeveloper L, string idDev);
void showChildByDeveloperAndProgress(ListDeveloper L, string idDev, string targetProgress);

PointerChild findKlienWithMinContract(ListDeveloper L);

#endif // KLIEN_H_INCLUDED
