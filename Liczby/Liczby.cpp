#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int silnia(int a)
{
	int sil = 1;
	if (a == 0) 
	{
		return 1;
	}
	else
	{
		for (int i = a; i > 0; i--)
		{
			sil = sil * i;
		}
		return sil;
	}
}

int cyfry[6];
void cyfryLiczby(int b)
{
	int x;
	int i = 5;
	while (b > 0)
	{
		x = b % 10;
		cyfry[i] = x;
		b = b / 10;
		i--;
	}
}

int NWD(int a, int b)
{
	if (b != 0)
		return NWD(b, a % b);
	return a;
}

int main()
{
	ifstream przyk("przyklad.txt");
	ifstream liczby("liczby.txt");
	ofstream wyniki("wyniki4.txt");
	//4.1
	int pot[100];
	pot[0] = 1;
	int potega = 3;
	int n = 1;
	while (potega <= 100000)
	{
		pot[n] = potega;
		potega = potega * 3;
		n++;
	}
	int liczba, ileLiczb = 0;
	for (int i = 0; i < 500; i++)
	{
		liczby >> liczba;
		for (int j = 0; j < 100; j++)
		{
			if (liczba == pot[j])
			{
				ileLiczb+=1;
			}
		}
	}
	cout << ileLiczb << endl;

	//4.2
	ifstream przyk2("przyklad.txt");
	ifstream liczby2("liczby.txt");
	int liczba2;
	for (int j = 0; j < 500; j++)
	{
		int sumaSil = 0;
		liczby2 >> liczba2;
		cyfryLiczby(liczba2);
		bool firstNormal = false;
		for (int i = 0; i < 6; i++)
		{
					if (cyfry[i] == 0 && !firstNormal)
					{
					}
					else if (cyfry[i] != 0)
					{
						firstNormal = true;
						sumaSil += silnia(cyfry[i]);
					}
					else if (cyfry[i] == 0 && firstNormal)
					{
						sumaSil += silnia(cyfry[i]);
					}
		}
		for (int i = 0; i < 6; i++)
		{
			cyfry[i] = 0;
		}
		if (sumaSil == liczba2)
		{
			cout << liczba2 << endl;
		}
	}
	//4.3
	//not working no idea how to solve right now
	/*int liczb3_1, liczb3_2, licznik, maxDzielnik, maxLicznik=0;
	int maxDzielnikCiagu, pierwszaLiczba;
	for (int i = 0; i < 500; i++)
	{
		liczby >> liczb3_1 >> liczb3_2;
		licznik = 1;
		maxDzielnik = NWD(liczb3_1, liczb3_2);
		while (NWD(liczb3_1, liczb3_2 != 1))
		{
			if (NWD(liczb3_1, liczb3_2) < maxDzielnik)
			{
				maxDzielnik = NWD(liczb3_1, liczb3_2);
			}
			licznik++;
			if (licznik > maxLicznik)
			{
				maxDzielnikCiagu = maxDzielnik;
				pierwszaLiczba = liczb3_1;
				maxLicznik = licznik;
			}
			liczby >> liczb3_2;
		}
	}
	cout << maxLicznik << endl;
	cout << pierwszaLiczba << endl;
	cout << maxDzielnikCiagu;*/
}
