#pragma once
#include "stdafx.h"
#include "obliczenia.h"

class Harmonogram
{
	
	vector<vector<int>> harmonogram;


public:
	void licz();
	void wypisz();

	Harmonogram(vector<vector<int>> struktura_harm);

};