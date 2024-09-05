#include <assert.h>
#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>

using namespace std;

void testSuplimentar(){
	Multime m;
	assert(m.diferentaMaxMin() == -1); //m = {}
	m.adauga(5);
	m.adauga(1);
	m.adauga(10);
	m.adauga(7);
	assert(m.diferentaMaxMin() == 9); //m = {5, 1, 10, 7}
	m.sterge(1);
	m.sterge(10);
	assert(m.diferentaMaxMin() == 2); //m = {5, 7}
	m.sterge(7);
	assert(m.diferentaMaxMin() == 0);  //m = {5}
	m.adauga(-10);
	m.adauga(-3);
	assert(m.diferentaMaxMin() == 15); //m = {5, -10, -3}
	m.sterge(5);
	m.sterge(-10);
	m.sterge(-3);
	assert(m.diferentaMaxMin() == -1); //m = {}
}