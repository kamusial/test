#pragma once
#include "stdafx.h"
#include "obliczenia.h"
#include "Wczytaj.h"
#include "Licz.h"


class Harmonogram
{
	

	vector<short> spis_pracownikow;
	struct plan_pracownika 
	{
		short nr_maszyny = -1;
		short czas_na_maszynie = -1;
	};
	
	vector <vector<plan_pracownika>> harmonogram_pracownikow; //vector[pracownik][plan]



protected:
	vector<vector<short>> harmonogram_do_liczenia;
	vector<vector<short>> harmonogram_do_liczenia_wynik;

public:
	Harmonogram();
	void wczytaj(const int& ilosc_monter, const int& ilosc_spawacz);

	void przygotuj_do_liczenia(const int& ilosc_monter, const int& ilosc_spawacz);
	void funkcja_przystosowania(const int& ilosc_monter, const int& ilosc_spawacz);
	void wypisz(const int& ilosc_monter, const int& ilosc_spawac);
	
	vector<vector<short>> Harmonogram::get_harmonogram_do_liczenia_wynik();
};