#pragma once
#include "stdafx.h"

class Pracownik
{
	short id_pracownik;
	short typ_pracownik;//0-monter, 1-spawacz

public:
	friend class Licz;
	Pracownik(short id, short typ);
	short getId();
	short getType();
};
