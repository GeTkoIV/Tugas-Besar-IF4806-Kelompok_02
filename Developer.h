#ifndef DEVELOPER_H_INCLUDED
#define DEVELOPER_H_INCLUDED
#include <iostream>
#include "Klien.h"

using namespace std;

typedef struct elmDeveloper *adrDeveloper;

struct infotypeDeveloper {
    string idDeveloper;
    string namaDeveloper;
    string spesialisasi;
    int rating;
};

struct elmDeveloper {
    infotypeDeveloper info;
    adrDeveloper next;
    adrDeveloper prev;
    PointerChild nextKlien;
};

struct ListDeveloper {
    adrDeveloper first;
};

void createListDeveloper(ListDeveloper &L);
adrDeveloper createElementDeveloper(infotypeDeveloper x);

void insertFirstDeveloper(ListDeveloper &L, adrDeveloper P);
void insertLastDeveloper(ListDeveloper &L, adrDeveloper P);

void deleteFirstDeveloper(ListDeveloper &L, adrDeveloper &P);
void deleteLastDeveloper(ListDeveloper &L, adrDeveloper &P);
void deleteDeveloperByID(ListDeveloper &L, string id);

adrDeveloper findDeveloper(ListDeveloper L, string id);
void connectKlienToDeveloper(adrDeveloper P_Dev, PointerChild P_Kli);

void showAllDeveloper(ListDeveloper L);
void showDeveloperAndAllClients(ListDeveloper L);

adrDeveloper findDeveloperWithMaxClients(ListDeveloper L);

#endif // DEVELOPER_H_INCLUDED
