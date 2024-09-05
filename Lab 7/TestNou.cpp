#include "TestNou.h"
#include <assert.h>

#include "DO.h"
#include "Iterator.h"

#include <exception>

bool relatieCresc(TCheie cheie1, TCheie cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

bool relatieDesc(TCheie cheie1, TCheie cheie2) {
    if (cheie1 >= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testAllNew() {
	DO dictOrd = DO(relatieCresc);
	
	dictOrd.adauga(1, 2);
    dictOrd.adauga(3, 2);
    dictOrd.adauga(17, 2);
    dictOrd.adauga(8, 2);
    dictOrd.adauga(13, 2);
    dictOrd.adauga(25, 2);

    dictOrd.inlocuieste(17, 2, 23); //cheia exista in dictionar si valoarea veche coincide
    dictOrd.inlocuieste(8, 45, 100); //cheia exista in dictionar, dar valoarea veche nu coincide
    dictOrd.inlocuieste(170, 2, 23); //cheia nu exista in dictionar 

    bool gasit = false;
    Iterator it = dictOrd.iterator();
    it.prim();
    while (it.valid()) {
        TElem e = it.element();
        if (e.first == 17)
            assert(e.second == 23);
        if (e.first == 8)
            assert(e.second == 2);
        if (e.first == 100) {
            gasit = true;
        }
        it.urmator();
    }
    assert(gasit == false);


    DO dictOrd2 = DO(relatieCresc);

    dictOrd2.adauga(1, 2);
    dictOrd2.adauga(3, 2);
    dictOrd2.adauga(17, 2);
    dictOrd2.adauga(8, 2);
    dictOrd2.adauga(13, 2);
    dictOrd2.adauga(25, 2);

    dictOrd2.inlocuieste(17, 2, 23); //cheia exista in dictionar si valoarea veche coincide
    dictOrd2.inlocuieste(8, 45, 100); //cheia exista in dictionar, dar valoarea veche nu coincide
    dictOrd2.inlocuieste(170, 2, 23); //cheia nu exista in dictionar 

    bool gasit2 = false;
    Iterator it2 = dictOrd2.iterator();
    it2.prim();
    while (it2.valid()) {
        TElem e = it2.element();
        if (e.first == 17)
            assert(e.second == 23);
        if (e.first == 8)
            assert(e.second == 2);
        if (e.first == 100) {
            gasit2 = true;
        }
        it2.urmator();
    }
    assert(gasit2 == false);
}