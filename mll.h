#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>

using namespace std;
struct infotypeDeveloper {
    string idDeveloper;
    string namaDeveloper;
    string spesialisasi;
    int rating;
};

typedef struct elmDeveloper *adrDeveloper;
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
struct elmDeveloper {
    infotypeDeveloper info;
    adrDeveloper next;
    adrDeveloper prev;
    PointerChild firstKlien;
};

struct ListDeveloper {
    adrDeveloper first;
    adrDeveloper last;
};

void createListDeveloper(ListDeveloper &L);
adrDeveloper createElementDeveloper(infotypeDeveloper x);
bool isEmptyDev(ListDeveloper L);
void insertFirstDeveloper(ListDeveloper &L, adrDeveloper P);
void insertLastDeveloper(ListDeveloper &L, adrDeveloper P);
void deleteFirstDeveloper(ListDeveloper &L, adrDeveloper &P);
void deleteLastDeveloper(ListDeveloper &L, adrDeveloper &P);

adrDeveloper findDeveloper(ListDeveloper L, string id);

void insertSortedDeveloper(ListDeveloper &L, adrDeveloper P);
void insertAfterDeveloper(adrDeveloper Prec, adrDeveloper P);
void deleteDeveloperByID(ListDeveloper &L, string id);
void deleteAfterDeveloper(ListDeveloper &L, adrDeveloper Prec, adrDeveloper &P);

void insertChildToDeveloper(ListDeveloper &L, InfoChild infoKlien, string idDev);

void showAllDeveloper(ListDeveloper L);

void findMaxClientsBySpecialty(ListDeveloper L, string specialty);

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
void deleteChildById(adrDeveloper P_Dev, string id, PointerChild &P_Kli);
void findKlienWithMinContract(ListDeveloper L);
void updateProgressKlien(adrDeveloper P_Dev, string idKlien, string progressBaru);
void hitungRataRataKontrakDeveloper(ListDeveloper L, string idDev);


#endif // MLL_H_INCLUDED
