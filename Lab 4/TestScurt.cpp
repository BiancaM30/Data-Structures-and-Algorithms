#include <assert.h>

#include "Iterator.h"
#include "LO.h"
#include<iostream>

using namespace std;

bool relatie1(TElement cheie1, TElement cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testNou() {
    LO lo = LO(relatie1);
    lo.adauga(5);
    assert(lo.ultimulIndex(5) == 0);//lista curenta: 5
    lo.adauga(7);
    lo.adauga(3);
    lo.adauga(5);
    lo.adauga(7); //lista curenta: 3 5 5 7 7
    assert(lo.ultimulIndex(5) == 2);
    assert(lo.ultimulIndex(7) == 4);
    assert(lo.ultimulIndex(17) == -1); //nu exista
    lo.adauga(7);
    lo.adauga(7); //lista curenta: 3 5 5 7 7 7 7
    assert(lo.ultimulIndex(7) == 6);
}

void testAll() {
    LO lo = LO(relatie1);
    assert(lo.dim() == 0);
    assert(lo.vida());
    lo.adauga(1);
    assert(lo.dim() == 1);
    assert(!lo.vida());
    Iterator iterator = lo.iterator();
    assert(iterator.valid());
    iterator.prim();
    assert(iterator.element() == 1);
    iterator.urmator();
    assert(!iterator.valid());
    iterator.prim();
    assert(iterator.valid());
    assert(lo.cauta(1) == 0);
    assert(lo.sterge(0) == 1);
    assert(lo.dim() == 0);
    assert(lo.vida());


    testNou();
}

