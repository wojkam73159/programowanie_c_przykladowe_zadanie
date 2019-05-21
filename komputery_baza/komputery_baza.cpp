// komputery_baza.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <cstdlib>
#include<fstream>

bool wa(unsigned int liczba)//5 jedynek binarnych 
{
	int jedynki = 0;
	for (int i = 0; i < 32; i++)
	{
		if ( liczba%2)
		{
			jedynki++;
		}
		liczba >>= 1;
	}

	if (jedynki == 5)
		return true;
	else return false;
}

int main()
{
	FILE * plikin, *alfa ,*beta;
	  fopen_s(&plikin,"odczyty.txt","r");
	 fopen_s(&alfa,"alfa.txt", "w");
	  fopen_s(&beta,"beta.txt", "w");
	unsigned int temp;
	unsigned int porzadkowa_liczba = 0;
	while (fscanf_s(plikin,"%u",&temp)!=EOF)
	{
		if (wa(temp))
		{
			porzadkowa_liczba++;
			continue;
		}

		if (porzadkowa_liczba % 2)
		{
			fprintf(beta, "%u", temp);
		}
		else
		{
			fprintf(alfa, "%u", temp);
		}

		
	}
	return 0;
}

