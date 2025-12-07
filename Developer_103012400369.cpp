#include "Developer.h"
void createListDeveloper(ListDeveloper &L);
adrDeveloper createElementDeveloper(infotypeDeveloper x);
bool isEmptyDev(ListDeveloper L);
adrDeveloper findDeveloper(ListDeveloper L, string id);
void insertFirstDeveloper(ListDeveloper &L, adrDeveloper P);
void insertLastDeveloper(ListDeveloper &L, adrDeveloper P);
void deleteDeveloperByID(ListDeveloper &L, string id);
void showAllDeveloper(ListDeveloper L);
