#include "stdafx.h"
#include "Harmonogram.h"

void Harmonogram::wczytaj(const int& ilosc_monter, const int& ilosc_spawacz)
{
	const string sciezka = "dane_in/bazowy_harmonogram.csv";
	ifstream bazowy_harmonogram_csv(sciezka);
	if (!bazowy_harmonogram_csv.is_open())
	{
		cout << "plik " << sciezka << "nie istnieje\n";
		exit(0);
	}
	Wczytaj::GetInstance().fix_bom_shit(bazowy_harmonogram_csv);

	string stmp = "error";
	char ctmp;
	short typ_pracownika = -1;
	plan_pracownika plan;
	bazowy_harmonogram_csv >> stmp;
	harmonogram_pracownikow.resize(ilosc_monter + ilosc_spawacz);

	for (int i = 0; i < ilosc_monter + ilosc_spawacz; i++)
	{
		bazowy_harmonogram_csv >> stmp >> ctmp >> typ_pracownika >> ctmp;
		spis_pracownikow.push_back(typ_pracownika);
		
		do {
			bazowy_harmonogram_csv >> plan.nr_maszyny >> ctmp >> plan.czas_na_maszynie >> ctmp;
			if (plan.nr_maszyny < 99)
			{
				harmonogram_pracownikow[i].push_back(plan);
			}
		} while (plan.nr_maszyny < 99);

	}

	cout << "\nkoniec wczytywania harmonogramu pracownikow\n";
};


void Harmonogram::licz(const int& ilosc_monter, const int& ilosc_spawacz)

{
	Wczytaj::GetInstance().bufory;

	harmonogram.resize(ilosc_monter + ilosc_spawacz);
	int j = -1;
	int b = -1;
	int pozycja = -1;
	for (int i = 0; i < ilosc_monter + ilosc_spawacz; i++)
	{
		pozycja = 0;
		j = 0;

		do {

			for (int j = 0; j < harmonogram_pracownikow[i][pozycja].czas_na_maszynie; j++)
				harmonogram[i].push_back(harmonogram_pracownikow[i][pozycja].nr_maszyny);

			pozycja++;
		} while (pozycja < (size(harmonogram_pracownikow[i])));

		harmonogram_z_buforami = harmonogram;
/*

		do {

			j++;
			if (harmonogram_z_buforami[i][j] != (harmonogram_z_buforami[i][j + 1]))
			{
				b = harmonogram_z_buforami[i][j] * 10 + harmonogram_z_buforami[i][j + 1];

				for (int j=0;j<Wczytaj::GetInstance().bufory[harmonogram_z_buforami[i][j]][harmonogram_z_buforami[i][j+1]];j++)
				harmonogram_z_buforami.insert(harmonogram_z_buforami.begin() + (j + 1), b);
			}
		} while (j < size(harmonogram_z_buforami[i]));
		*/


		

	
	}
	cout << "\nkoniec wpisywania harmonogramu pracownikow do przeliczenia\n";




};
void wypisz();

Harmonogram::Harmonogram()
{
	
};