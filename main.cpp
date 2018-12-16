#include <stdio.h>
#include "Matica.h"
#include <vector>
#include <iostream>
#include <string> //c++ string
#include <cstring> //c string

int main()
{	
	int pole[4][4] = //rychla inicializacia v kode
	{
		{0,1,2,3},
		{0,1,2,4},
		{0,1,2,5},
		{0,1,2,6},
	};
	Matica mat(4, 4, (int*)pole);
	Matica mat2(4, 4, (int*)pole);
	mat.vymenStlpce(0,1);
	mat.to_String();
	std::cout << std::endl;
	mat2.to_String();
	mat.Odcitaj(mat2);
	mat.to_String();
	mat.Pridaj(mat2);
	mat.to_String();
	
	
	return 0;
}


//printf("%d", sizeof(pole) / 16 / sizeof(int )); // 64 bajtov vypise 16*4(32) vypise pocet prvkov v poli ale len pre staticke pole to ide
//	std::vector<int> zoznam;
//	zoznam.push_back(5);
//	zoznam.push_back(4);
//	zoznam.push_back(3);
//	zoznam.push_back(2);
//	zoznam.push_back(1);
//	for (int hodnota : zoznam)
//		std::cout << hodnota << std::endl;
//	const char* cislo = "5";
//	const char* cislo2 = "5";
//	int premenna = std::atof(cislo); //string do float
//	printf("Dlzka stringu: %d", strlen(cislo));
//	if (strcmp(cislo, cislo2) == 0) //ak sa rovna nule tak sa rovnaju, ak zaporne tak prve cislo vacsie   strcat spaja dva stringy   strtok
//		printf("Cisla sa rovnaju.");