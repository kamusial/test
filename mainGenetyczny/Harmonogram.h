#pragma once
#include "stdafx.h"
#include "obliczenia.h"
#include "Wczytaj.h"
#include "Licz.h"


class Harmonogram
{
	
	vector<vector<short>> harmonogram_do_liczenia;
	vector<vector<short>> harmonogram_do_liczenia_wynik;
	vector<short> spis_pracownikow;
	struct plan_pracownika 
	{
		short nr_maszyny = -1;
		short czas_na_maszynie = -1;
	};
	
	vector <vector<plan_pracownika>> harmonogram_pracownikow; //vector[pracownik][plan]



public:
	void wczytaj(const int& ilosc_monter, const int& ilosc_spawacz);

	void przygotuj_do_liczenia(const int& ilosc_monter, const int& ilosc_spawacz);
	void funkcja_przystosowania(const int& ilosc_monter, const int& ilosc_spawacz);
	void wypisz();
	Harmonogram();

};