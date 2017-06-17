#pragma once
#include "stdafx.h"
#include "obliczenia.h"
#include "Wczytaj.h"
#include "Licz.h"


class Harmonogram
{
	
	vector<vector<short>> harmonogram;
	vector<vector<short>> harmonogram_z_buforami;
	vector<short> spis_pracownikow;
	struct plan_pracownika 
	{
		short nr_maszyny = -1;
		short czas_na_maszynie = -1;
	};
	
	vector <vector<plan_pracownika>> harmonogram_pracownikow; //vector[pracownik][plan]



public:
	void wczytaj(const int& ilosc_monter, const int& ilosc_spawacz);

	void licz(const int& ilosc_monter, const int& ilosc_spawacz);
	void wypisz();

	Harmonogram();

};