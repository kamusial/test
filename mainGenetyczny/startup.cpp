#include "stdafx.h"
#include "startup.h"

/*
vector<vector<float>> wczytaj_przejscia_bufory(string sciezka)
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

	vector<vector<float>> przejscia;

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
	return przejscia;
}

void print_state(const std::ios& stream) 
{
	std::cout << " good()=" << stream.good();
	std::cout << " eof()=" << stream.eof();
	std::cout << " fail()=" << stream.fail();
	std::cout << " bad()=" << stream.bad();
}

void fix_bom_shit(ifstream& file)
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

void wczytaj_proces(string sciezka, vector<operacja>& proc)
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
	for (int i=0; i < ilosc_op; ++i)
	{
		operacja p;
		ilosc_op_csv >> p.nr_operacji >> ctmp >>
			p.nr_stanowiska >> ctmp >>
			p.czas >> ctmp >>
			p.ilosc_monter >> ctmp >>
			p.ilosc_spawacz >> ctmp >>
			p.ilosc_kabin;
		proc.push_back(p);
	}
}

void wczytaj_zamowienia(vector<zamowienie>& zam)
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
	//vector<zamowienie> zam;
	zamowienie z;
	for (int i = 0; i < 4; ++i)
	{
		zamowienie_csv >> z.nazwa >> ctmp >> z.ilosc;
		zam.push_back(z);
	}
	zamowienie_csv >> stmp;
	for (int i = 0; i < 2; ++i)
	{
		zamowienie_csv >> z.nazwa >> ctmp >> z.ilosc>>ctmp>>z.ilosc_max;
		zam.push_back(z);
	}
	//return zam;
}


*/