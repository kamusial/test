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
	

	Wczytaj& wczytywanie = Wczytaj::GetInstance();
	Wczytaj& wczytywanie2 = Wczytaj::GetInstance();

	wczytywanie.wczytaj_przejscia("dane_in/przejscia.csv");
	wczytywanie.wczytaj_bufory("dane_in/bufory.csv");
	wczytywanie.wczytaj_zamowienia();
	wczytywanie.wczytaj_procesy();

	Licz obliczanie;
	obliczanie.licz_zapotrzebowanie();
	obliczanie.stworz_pracownikow();


	getchar(); //oczekiwanie na wciœniêcie klawisza
	return 0;
    
}
