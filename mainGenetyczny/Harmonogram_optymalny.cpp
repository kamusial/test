#include "stdafx.h"
#include "Harmonogram_optymalny.h"

void Harmonogram_optymalny::optymalizuj(const int& ilosc_monter, const int& ilosc_spawacz, vector<vector<short>>& harmonogram_do_liczenia_wynik)
{
	cout << "\nObcinanie harmonogramu";

		for (int i = 0; i < ilosc_monter + ilosc_spawacz; i++)
		{
			size = harmonogram_do_liczenia_wynik[i].size() - 1;

			do
			{
				size--;
			} while
				(harmonogram_do_liczenia_wynik[i][size] == 0);


			harmonogram_do_liczenia_wynik[i].resize(size + 1);

			cout << "\nCzas pracownika " << i << " skrocony o " << 220-size << " sekund";
		}
}