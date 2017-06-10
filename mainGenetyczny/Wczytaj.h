#pragma once
#include "stdafx.h"


class Wczytaj
{

	struct operacja
	{
		short int nr_operacji;
		short int nr_stanowiska;
		float czas;
		short int ilosc_monter;
		short int ilosc_spawacz;
		short int ilosc_kabin;
	};

	struct zamowienie
	{
		string nazwa = "nieprawidlowa";
		int ilosc = -1;
		int ilosc_max = -1;
	};

	vector<vector<float>> przejscia;
	vector<vector<float>> bufory;
	vector<zamowienie> zamowienia;

	vector<operacja> LL_V1;
	vector<operacja> LL_V2;
	vector<operacja> RL_V1;
	vector<operacja> RL_V2;

	

public:
	friend class Licz;
	
	static Wczytaj& GetInstance();


	void wczytaj_przejscia(string sciezka);
	void wczytaj_bufory(string sciezka);
	void wczytaj_zamowienia();
	void wczytaj_procesy();

	void print_state(const std::ios& stream);
	

private:
	Wczytaj();

	Wczytaj(const Wczytaj&) {}
	Wczytaj& operator=(const Wczytaj&) {}

	static void wczytaj_proces(string sciezka, vector<operacja>& op);
	static void fix_bom_shit(ifstream& file);

};
