#include "stdafx.h"
#include "Harmonogram.h"

void wczytaj();
void licz();
void wypisz();

Harmonogram::Harmonogram(vector<vector<int>> struktura_harm)
{
	harmonogram = struktura_harm;
};