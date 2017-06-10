// mainGenetyczny.cpp : Defines the entry point for the console application. p.puchala
//

#include "stdafx.h"
#include "startup.h"
#include "obliczenia.h"
#include "Pracownik.h"
#include "Wczytaj.h"
#include "Licz.h"


int main()
{
	

	Wczytaj wczytywanie;
	wczytywanie.wczytaj_przejscia("dane_in/przejscia.csv");
	wczytywanie.wczytaj_bufory("dane_in/bufory.csv");
	wczytywanie.wczytaj_zamowienia();
	wczytywanie.wczytaj_procesy();

	// nowa zmiana super
	
	//Licz obliczanie;

	//ilosc_pracownikow zapotrzebowanie = licz_zapotrzebowanie(LL_V1, LL_V2, RL_V1, RL_V2, zamowienia);

	//vector<Pracownik> vektor_pracownikow = stworz_pracownikow(zapotrzebowanie);

	//vector<vector<int>> harmonogram = wczytaj_bazowy_harmonogram();

	getchar(); //oczekiwanie na wciœniêcie klawisza
	return 0;
    
}
