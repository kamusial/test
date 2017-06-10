#include "stdafx.h"
#include "Licz.h"
#include "Pracownik.h"


/*
Licz::Licz()
{};

void Licz::zapotrzebowanie_proces(const vector<operacja>& proc, float& czas_spawacz, float& czas_monter,
	const zamowienie& zam)
{
	for (int i = 0; i < proc.size(); i++)
	{
		if (proc[i].ilosc_spawacz != 0)
		{
			czas_spawacz += proc[i].ilosc_spawacz * proc[i].czas * zam.ilosc;
		};
		if (proc[i].ilosc_monter != 0)
		{
			czas_monter += proc[i].ilosc_monter * proc[i].czas * zam.ilosc;
		};
	};
	cout << endl << "Zamowienie " << zam.nazwa << "      czas monter = " << czas_monter << "    czas spawacz = " << czas_spawacz;

};

void Licz::licz_zapotrzebowanie(const vector<operacja>& procLL_V1,
	const vector<operacja>& procLL_V2,
	const vector<operacja>& procRL_V1,
	const vector<operacja>& procRL_V2,
	const vector<zamowienie>& zamowienia)
{
	float czas_spawacz = 0;
	float czas_monter = 0;
	float ilosc_monter = 0;
	float ilosc_spawacz = 0;

	zapotrzebowanie_proces(procLL_V1, czas_spawacz, czas_monter, zamowienia[0]);
	zapotrzebowanie_proces(procLL_V2, czas_spawacz, czas_monter, zamowienia[1]);
	zapotrzebowanie_proces(procRL_V1, czas_spawacz, czas_monter, zamowienia[2]);
	zapotrzebowanie_proces(procRL_V2, czas_spawacz, czas_monter, zamowienia[3]);

	ilosc_monter = czas_monter / ONE_DAY_TIME;
	ilosc_spawacz = czas_spawacz / ONE_DAY_TIME;
	cout << "\n\nilosc monter = " << ilosc_monter << "    ilosc spawacz = " << ilosc_spawacz << endl;

	ilosc_monter = ceil(czas_monter / ONE_DAY_TIME);
	ilosc_spawacz = ceil(czas_spawacz / ONE_DAY_TIME);
	cout << endl << "ilosc monter = " << ilosc_monter << "    ilosc spawacz = " << ilosc_spawacz << endl;

	ilosc_monter = max(static_cast<float>(zamowienia[4].ilosc), ilosc_monter);
	ilosc_monter = min(static_cast<float>(zamowienia[4].ilosc_max), ilosc_monter);
	ilosc_spawacz = max(static_cast<float>(zamowienia[5].ilosc), ilosc_spawacz);
	ilosc_spawacz = min(static_cast<float>(zamowienia[5].ilosc_max), ilosc_spawacz);

	cout << endl << "po restrykcjach:" << endl << "ilosc monter = " << ilosc_monter << endl << "ilosc spawacz = " << ilosc_spawacz;

	ilosc_pracownikow wyliczeni_pracownicy;
	wyliczeni_pracownicy.ilosc_monter = ceil(ilosc_monter);
	wyliczeni_pracownicy.ilosc_spawacz = ceil(ilosc_spawacz);

	return wyliczeni_pracownicy;

};

void stworz_pracownikow(ilosc_pracownikow wyliczeni_pracownicy)
{
	vector<Pracownik> vector_pracownikow;
	for (int i = 0; i < wyliczeni_pracownicy.ilosc_monter; i++)
	{
		//Pracownik a(i, 1);
		//vector_pracownikow.push_back(a);
		// to samo tylko lepiej:
		vector_pracownikow.emplace_back(i + 1, 0);
	};
	for (int i = 0; i < wyliczeni_pracownicy.ilosc_spawacz; i++)
	{
		vector_pracownikow.emplace_back(i + 1 + wyliczeni_pracownicy.ilosc_monter, 1);
	};
	return vector_pracownikow;



};

vector<vector<int>> wczytaj_bazowy_harmonogram()
{
	vector<vector<int>> testowy;
	return testowy;
};*/