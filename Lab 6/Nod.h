#pragma once


typedef int TCheie;
typedef int TValoare;
#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

class MDO;
class IteratorMDO;
class IteratorValori;

class Nod
{
private:
	TElem data;

	Nod* next;

public:
	friend class MDO;
	friend class IteratorMDO;
	friend class IteratorValori;

	Nod( TElem data, Nod* next);

	TElem element();

	Nod* urmator();

	~Nod() = default;

};

