#ifndef DEVELOPER_H_INCLUDED
#define DEVELOPER_H_INCLUDED

#include "Klien.h"

struct infotypeDeveloper {
    string idDeveloper;
    string namaDeveloper;
    string spesialisasi;
    int rating;
};

typedef struct elmDeveloper *adrDeveloper;
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
#endif // DEVELOPER_H_INCLUDED
