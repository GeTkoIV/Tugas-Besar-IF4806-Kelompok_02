#ifndef KLIEN_H_INCLUDED
#define KLIEN_H_INCLUDED
#include <iostream>
using namespace std;

struct InfoChild {

};

typedef struct NodeChild *PointerChild;


struct NodeChild {
    InfoChild data;
    PointerChild next;
};

struct ListChild {
    PointerChild first;
};

#endif // KLIEN_H_INCLUDED
