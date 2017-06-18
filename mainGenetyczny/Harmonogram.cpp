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


void Harmonogram::przygotuj_do_liczenia(const int& ilosc_monter, const int& ilosc_spawacz)

{
	

	harmonogram_do_liczenia.resize(ilosc_monter + ilosc_spawacz);
	int b = -1;
	int c = -1;

	for (int i = 0; i < ilosc_monter + ilosc_spawacz; i++)
	{

		for (int pozycja=0; pozycja < harmonogram_pracownikow[i].size(); pozycja++)
		 {
		
			for (int j = 0; j < harmonogram_pracownikow[i][pozycja].czas_na_maszynie; j++)
				harmonogram_do_liczenia[i].push_back(harmonogram_pracownikow[i][pozycja].nr_maszyny);

			if (pozycja + 1 < harmonogram_pracownikow[i].size())
			{
				b = harmonogram_pracownikow[i][pozycja].nr_maszyny * 100 + harmonogram_pracownikow[i][pozycja + 1].nr_maszyny;
				if ((harmonogram_pracownikow[i][pozycja].nr_maszyny < 17) && (harmonogram_pracownikow[i][pozycja + 1].nr_maszyny < 17))
				{
					c = Wczytaj::GetInstance().przejscia[harmonogram_pracownikow[i][pozycja].nr_maszyny - 1][harmonogram_pracownikow[i][pozycja + 1].nr_maszyny - 1];
					for (int jj = 0; jj < c; jj++)
						harmonogram_do_liczenia[i].push_back(b);
			
				}
			}
		}
		harmonogram_do_liczenia[i].resize(220);
	}
	cout << "\nkoniec wpisywania harmonogramu pracownikow do przeliczenia\n";
	
};

void Harmonogram::funkcja_przystosowania(const int& ilosc_monter, const int& ilosc_spawacz)
{
	int ilosc_czesci_LL_V1 = Wczytaj::GetInstance().zamowienia[0].ilosc;
	int ilosc_start_LL_V1 = -1;
	int ilosc_czesci_LL_V2 = Wczytaj::GetInstance().zamowienia[1].ilosc;
	int ilosc_start_LL_V2 = -1;
	int ilosc_czesci_LR_V1 = Wczytaj::GetInstance().zamowienia[2].ilosc;
	int ilosc_start_LR_V1 = -1;
	int ilosc_czesci_LR_V2 = Wczytaj::GetInstance().zamowienia[3].ilosc;
	int ilosc_start_LR_V2 = -1;
	int licznik_pola_pracownika = -1;
	int backup_licznik = -1;
	int pomocniczy_licznik = -1;
	int temp = 0;

	int dlugosc_operacji = -1;
	int walidacja_operacji = -1;
	bool operacja_w_harmonogramie = false;
	bool przeciazenie = false;
	int noop = -1;

	harmonogram_do_liczenia_wynik.resize(size(harmonogram_do_liczenia));
	
	pomocniczy_licznik = 0;
	ilosc_start_LL_V2 = 0;

	for (int czesci_LL_V2 = 0; czesci_LL_V2 < ilosc_czesci_LL_V2; czesci_LL_V2++) //zamowienie 10xLL_V2
	{
		temp++;
		operacja_w_harmonogramie = false;
		przeciazenie = false;
		licznik_pola_pracownika = 0;
		backup_licznik = 0;

		//dla pierwszej operacji
		for (int i = 0; i < ilosc_monter + ilosc_spawacz; i++) // po pracownikach
		{
			harmonogram_do_liczenia_wynik[i].resize(size(harmonogram_do_liczenia[i]));
			if (operacja_w_harmonogramie)
			{
				noop = 1;
			}
			else {
				licznik_pola_pracownika = 0;
				do {
					if (harmonogram_do_liczenia[i][licznik_pola_pracownika] == Wczytaj::GetInstance().LL_V2[0].nr_stanowiska) //po polach pracownika
					{
						dlugosc_operacji = ceil(Wczytaj::GetInstance().LL_V2[0].czas);
						walidacja_operacji = 0;
						for (int jj = licznik_pola_pracownika; jj < licznik_pola_pracownika + dlugosc_operacji; jj++)
						{
							if (harmonogram_do_liczenia[i][jj] == Wczytaj::GetInstance().LL_V2[0].nr_stanowiska)
								walidacja_operacji++;
						}
						if (walidacja_operacji == dlugosc_operacji)
						{
							ilosc_start_LL_V2++;
							for (int jj = licznik_pola_pracownika; jj < licznik_pola_pracownika + dlugosc_operacji; jj++)
							{
								harmonogram_do_liczenia_wynik[i][jj] = ilosc_start_LL_V2;
								harmonogram_do_liczenia[i][jj] = 0;
							}
							operacja_w_harmonogramie = true;
						}
					}
					licznik_pola_pracownika += 1 + pomocniczy_licznik;
					pomocniczy_licznik = 0;
				} while ((!operacja_w_harmonogramie) && ((licznik_pola_pracownika + dlugosc_operacji - 1) < harmonogram_do_liczenia[i].size()));
			}
		}
		if (!operacja_w_harmonogramie)
		{
			cout << "\n1czesc " << ilosc_start_LL_V2 << " dla LL_V2 nie miesci sie w harmonogramie";
		}


		//od 2 operacji


		for (int j = 1; j < Wczytaj::GetInstance().LL_V2.size(); j++) //po operacjach
		{
			backup_licznik = licznik_pola_pracownika;
			operacja_w_harmonogramie = false;


			for (int i = 0; i < ilosc_monter + ilosc_spawacz; i++) // po pracownikach
			{

				if ((operacja_w_harmonogramie) || (przeciazenie))
				{
					noop = 1;
				}
				else {

					licznik_pola_pracownika = backup_licznik;
					do {
						if (harmonogram_do_liczenia[i][licznik_pola_pracownika] == Wczytaj::GetInstance().LL_V2[j].nr_stanowiska) //po polach pracownika
						{
							dlugosc_operacji = ceil(Wczytaj::GetInstance().LL_V2[j].czas);
							walidacja_operacji = 0;
							for (int jj = licznik_pola_pracownika; jj < licznik_pola_pracownika + dlugosc_operacji; jj++)
							{
								if (harmonogram_do_liczenia[i][jj] == Wczytaj::GetInstance().LL_V2[j].nr_stanowiska)
									walidacja_operacji++;
							}
							if (walidacja_operacji == dlugosc_operacji)
							{

								for (int jj = licznik_pola_pracownika; jj < licznik_pola_pracownika + dlugosc_operacji; jj++)
								{
									harmonogram_do_liczenia_wynik[i][jj] = ilosc_start_LL_V2;
									harmonogram_do_liczenia[i][jj] = 0;
									pomocniczy_licznik++;
								}
								operacja_w_harmonogramie = true;

							}

						}

						licznik_pola_pracownika += 1 + pomocniczy_licznik;
						pomocniczy_licznik = 0;
					} while ((!operacja_w_harmonogramie) && ((licznik_pola_pracownika + dlugosc_operacji - 1) < (harmonogram_do_liczenia[i].size())));
				}
			}
			if ((!operacja_w_harmonogramie) && (!przeciazenie))
			{
				cout << "\n2czesc " << ilosc_start_LL_V2 << " dla LL_V2 nie miesci sie w harmonogramie";
				przeciazenie = true;
			}

		}
		if (!przeciazenie)
		cout << "\nCzesc "<<ilosc_start_LL_V2<<" w harmonogramie ";
	}
}

void wypisz();

Harmonogram::Harmonogram()
{
	
};