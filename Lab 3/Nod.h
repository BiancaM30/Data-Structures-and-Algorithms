#pragma once

//tip de data generic (pentru moment este intreg)
typedef int TElem;
class Multime;
class IteratorMultime;

class Nod {
private:

	TElem data;
	
	Nod* next;

public:

	friend class Multime;
	friend class IteratorMultime;

	//constructor
	Nod(TElem data, Nod* next);

	TElem element();

	Nod* urmator();

};
