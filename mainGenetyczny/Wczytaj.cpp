#include "stdafx.h"
#include "Wczytaj.h"

Wczytaj::Wczytaj()
{};

void Wczytaj::wczytaj_przejscia(string sciezka)
{
	ifstream przejscia_csv(sciezka);
	if (!przejscia_csv.is_open())
	{
		cout << "plik " << sciezka << " nie istnieje" << endl;
		exit(0);
	}
	fix_bom_shit(przejscia_csv);

	char ctmp;
	string str1;
	int a = -2;

	przejscia_csv >> str1; //1sza linia

	przejscia.resize(16);

	for (int j = 0; j < 16; j++)
	{
		przejscia_csv >> a >> ctmp;
		for (int i = 0; i < 15; i++)
		{
			przejscia_csv >> a >> ctmp;
			przejscia[j].push_back(a);
		}
		przejscia_csv >> a;
		przejscia[j].push_back(a);
	}
}

void Wczytaj::wczytaj_bufory(string sciezka)
{
	ifstream bufory_csv(sciezka);
	if (!bufory_csv.is_open())
	{
		cout << "plik " << sciezka << " nie istnieje" << endl;
		exit(0);
	}
	fix_bom_shit(bufory_csv);

	char ctmp;
	string str1;
	int a = -2;

	bufory_csv >> str1; //1sza linia

	bufory.resize(16);

	for (int j = 0; j < 16; j++)
	{
		bufory_csv >> a >> ctmp;
		for (int i = 0; i < 15; i++)
		{
			bufory_csv >> a >> ctmp;
			bufory[j].push_back(a);
		}
		bufory_csv >> a;
		bufory[j].push_back(a);
	}
}

void Wczytaj::wczytaj_zamowienia()
{
	const string sciezka = "dane_in/zamowienie.csv";
	ifstream zamowienie_csv(sciezka);
	if (!zamowienie_csv.is_open())
	{
		cout << "plik " << sciezka << "nie istnieje\n";
		exit(0);
	}
	fix_bom_shit(zamowienie_csv);

	string stmp;
	char ctmp;
	zamowienie_csv >> stmp;
	zamowienie z;
	for (int i = 0; i < 4; ++i)
	{
		zamowienie_csv >> z.nazwa >> ctmp >> z.ilosc;
		zamowienia.push_back(z);
	}
	zamowienie_csv >> stmp;
	for (int i = 0; i < 2; ++i)
	{
		zamowienie_csv >> z.nazwa >> ctmp >> z.ilosc >> ctmp >> z.ilosc_max;
		zamowienia.push_back(z);
	}
}

void Wczytaj::wczytaj_proces(string sciezka, vector<operacja>& op)
{
	ifstream ilosc_op_csv(sciezka);
	if (!ilosc_op_csv.is_open())
	{
		cout << "plik \"przejscia\" nie istnieje\n";
		exit(0);
	}
	fix_bom_shit(ilosc_op_csv);

	short int ilosc_op = -1;
	ilosc_op_csv >> ilosc_op;

	char ctmp;
	string stmp;
	ilosc_op_csv >> stmp >> stmp;
	for (int i = 0; i < ilosc_op; ++i)
	{
		operacja p;
		ilosc_op_csv >> p.nr_operacji >> ctmp >>
			p.nr_stanowiska >> ctmp >>
			p.czas >> ctmp >>
			p.ilosc_monter >> ctmp >>
			p.ilosc_spawacz >> ctmp >>
			p.ilosc_kabin;
		op.push_back(p);
	}
}

void Wczytaj::wczytaj_procesy()
{
	wczytaj_proces("dane_in/LL_V1.csv", LL_V1);
	wczytaj_proces("dane_in/LL_V2.csv", LL_V2);
	wczytaj_proces("dane_in/RL_V1.csv", RL_V1);
	wczytaj_proces("dane_in/RL_V2.csv", RL_V2);
}

void Wczytaj::print_state(const std::ios& stream)
{
	std::cout << " good()=" << stream.good();
	std::cout << " eof()=" << stream.eof();
	std::cout << " fail()=" << stream.fail();
	std::cout << " bad()=" << stream.bad();
}

void Wczytaj::fix_bom_shit(ifstream& file)
{
	char a, b, c;
	a = file.get();
	b = file.get();
	c = file.get();
	if (a == (char)0xEF && b == (char)0xBB && c == (char)0xBF)
	{
		std::cerr << "Warning: file contains the so-called 'UTF-8 signature'\n";
	}
	else
	{
		file.seekg(0);
	}
}
