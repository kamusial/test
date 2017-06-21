#pragma once
#include "stdafx.h"
#include "Harmonogram.h"

class Harmonogram_optymalny
	:public Harmonogram
{

	int size = -1;
public:
	void optymalizuj(const int& ilosc_monter, const int& ilosc_spawacz, vector<vector<short>>& harmonogram_do_liczenia_wynik);
};