// mainGenetyczny.cpp : Defines the entry point for the console application. p.puchala
//

#include "stdafx.h"
#include "startup.h"
#include "obliczenia.h"
#include "Pracownik.h"
#include "Wczytaj.h"
#include "Licz.h"
#include "Harmonogram.h"

int main()
{
	

	Wczytaj& wczytywanie = Wczytaj::GetInstance();
	wczytywanie.wczytaj_przejscia("dane_in/przejscia.csv");
	wczytywanie.wczytaj_bufory("dane_in/bufory.csv");
	wczytywanie.wczytaj_zamowienia();
	wczytywanie.wczytaj_procesy();

	Licz obliczanie;
	obliczanie.licz_zapotrzebowanie();
	obliczanie.stworz_pracownikow();

	Harmonogram harm;
	harm.wczytaj(obliczanie.getIloscMonter(), obliczanie.getIloscSpawacz());
	harm.przygotuj_do_liczenia(obliczanie.getIloscMonter(), obliczanie.getIloscSpawacz());
	harm.funkcja_przystosowania(obliczanie.getIloscMonter(), obliczanie.getIloscSpawacz());


	getchar(); //oczekiwanie na wciœniêcie klawisza
	return 0;
    
}
