#include "stdafx.h"
#include "Pracownik.h"



Pracownik::Pracownik(short id, short typ)
{
	id_pracownik = id;
	typ_pracownik = typ;
}

short Pracownik::getId()
{
	return id_pracownik;
}

short Pracownik::getType()
{
	return typ_pracownik;
}

//void setType(short new_type)
//{
//	typ_pracownik = new_type;
//}