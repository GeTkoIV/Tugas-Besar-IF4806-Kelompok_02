#ifndef KLIEN_H_INCLUDED
#define KLIEN_H_INCLUDED
#include <iostream>
#include "Developer.h"

using namespace std;

struct InfoChild {
    string idKlien;
    string namaKlien;
    string project;
};

typedef struct NodeChild *PointerChild;

struct NodeChild {
    InfoChild data;
    PointerChild next;
    adrDeveloper parent;
};

struct ListChild {
    PointerChild first;
};

void createList_Child(ListChild &L);
PointerChild createElement_Child(InfoChild data);

void insertFirst_Child(ListChild &L, PointerChild P);
void insertLast_Child(ListChild &L, PointerChild P);

PointerChild findElement_Child(ListChild L, string ID);
void showAll_Child(ListChild L);

void deleteFirst_Child(ListChild &L, PointerChild &P);
void deleteLast_Child(ListChild &L, PointerChild &P);
void deleteElement_Child(ListChild &L, PointerChild P);

bool isEmpty_Child(ListChild L);

#endif // KLIEN_H_INCLUDED
