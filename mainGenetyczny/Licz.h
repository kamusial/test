#pragma once
#include "stdafx.h"
#include "Wczytaj.h"
#include "Pracownik.h"

class Licz
{
	const int ONE_DAY_TIME = 420;

	struct ilosc_pracownikow
	{
		int ilosc_monter = -1;
		int ilosc_spawacz = -1;
	};

	ilosc_pracownikow wyliczeni_pracownicy;
	vector<Pracownik> vector_pracownikow;
public:
	friend class Harmonogram;

	Licz::Licz();

	void zapotrzebowanie_czas(const vector<Wczytaj::operacja>& proc, float& spawacz, float& monter,
		const Wczytaj::zamowienie& zam);

	void licz_zapotrzebowanie();

	void stworz_pracownikow();

	int getIloscMonter();
	int getIloscSpawacz();

}; 