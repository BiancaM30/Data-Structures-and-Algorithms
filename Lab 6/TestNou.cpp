#include "TestNou.h"
#include "MDO.h"
#include "IteratorMDO.h"
#include "IteratorValori.h"

#include <assert.h>
#include <exception>
#include <vector>
#include <iostream>

using namespace std;

bool cresc1(TCheie c1, TCheie c2) {
	if (c1 <= c2) {
		return true;
	}
	else {
		return false;
	}
}

bool desc1(TCheie c1, TCheie c2) {
	if (c1 >= c2) {
		return true;
	}
	else {
		return false;
	}
}

void testNou(){
    MDO dictOrd1 = MDO(cresc1);

	dictOrd1.adauga(1, 2);
	dictOrd1.adauga(1, 3);
	dictOrd1.adauga(1, 5);
	dictOrd1.adauga(8, 98);
	dictOrd1.adauga(7, 99);
	dictOrd1.adauga(1, 1);
	dictOrd1.adauga(2, 98);
	dictOrd1.adauga(2, 99);

	try {
		IteratorValori it = dictOrd1.iteratorValori(9999999999999);
		assert(false);
	}

	catch (exception){
		assert(true);
	}

	int nrElem = 0;
	IteratorValori it = dictOrd1.iteratorValori(1);
	it.prim();
	while (it.valid()) {
		TValoare e = it.element();
		nrElem++;
		it.urmator();
	}
	assert(nrElem == 4);


	MDO dictOrd2 = MDO(desc1);

	dictOrd2.adauga(1, 2);
	dictOrd2.adauga(1, 3);
	dictOrd2.adauga(1, 5);
	dictOrd2.adauga(8, 98);
	dictOrd2.adauga(7, 99);
	dictOrd2.adauga(1, 1);
	dictOrd2.adauga(2, 98);
	dictOrd2.adauga(2, 99);

	nrElem = 0;
	IteratorValori it2 = dictOrd1.iteratorValori(2);
	it2.prim();
	while (it2.valid()) {
		TValoare e = it2.element();
		nrElem++;
		it2.urmator();
	}
	assert(nrElem == 2);
}