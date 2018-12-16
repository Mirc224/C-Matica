#include "Matica.h"
#include <iostream>
#include "stdio.h"



Matica::Matica(int stlpce, int riadky, int konst) : m_stlpce(stlpce), m_riadky(riadky), m_matica(new int*[riadky]) // musi ti to vytvorit prvotnu maticu
{
	for (int i = 0; i < riadky; ++i) //vzdy pis ++i
		m_matica[i] = new int[stlpce];

	for (int r = 0; r < m_riadky; ++r)
	{
		for (int s = 0; s < m_stlpce; ++s)
		{
			m_matica[r][s] = konst;
		}
	}
}

Matica::Matica(int stlpce, int riadky, int* pole) : m_stlpce(stlpce), m_riadky(riadky), m_matica(new int*[riadky])
{
	for (int i = 0; i < riadky; ++i) //vzdy pis ++i
		m_matica[i] = new int[stlpce];

	for (int r = 0; r < m_riadky; ++r)
	{
		for (int s = 0; s < m_stlpce; ++s)
		{
			m_matica[r][s] = pole[r * m_riadky + s];
		}
	}

}

Matica::Matica(const Matica & matica): m_stlpce(matica.m_riadky), m_riadky(matica.m_riadky), m_matica(new int*[matica.m_riadky])
{
	for (int i = 0; i < m_riadky; ++i) //vzdy pis ++i
		m_matica[i] = new int[m_stlpce];
	for (int r = 0; r < m_riadky; ++r)
	{
		for (int s = 0; s < m_stlpce; ++s)
		{
			m_matica[r][s] = matica.m_matica[r][s];
			std::cout << &m_matica[r][s] << "  " << &matica.m_matica[r][s] << std::endl;
		}
	}
	std::cout << "Kopirovacka" << std::endl;
}

Matica::~Matica()
{
	for (int i = 0; i < m_riadky; ++i) //tu uz m riadky lebo mozu byt ine uz
		delete []m_matica[i];

	delete []m_matica;
}

void Matica::SetRozmery(int stlpce, int riadky)
{
	for (int i = 0; i < m_riadky; ++i) //vzdy pis ++i
		delete m_matica[i];
	delete m_matica;

	m_stlpce = stlpce;
	m_riadky = riadky;
	m_matica = new int*[riadky]; // toto mi vyrobi m_matica[]

	for (int i = 0; i < riadky; ++i) //vzdy pis ++i
		m_matica[i] = new int[stlpce]; //toto mi vyrobi m_matica[][]

}

void Matica::Pridaj(int konst)
{
	for (int r = 0; r < m_riadky; ++r)
	{
		for (int s = 0; s < m_stlpce; ++s)
		{
			m_matica[r][s] = m_matica[r][s] + konst;
		}
	}
}

void Matica::Odcitaj(int konst)
{
	for (int r = 0; r < m_riadky; ++r)
	{
		for (int s = 0; s < m_stlpce; ++s)
		{
			m_matica[r][s] -= konst;
		}
	}
}

void Matica::Nasob(int konst)
{
	for (int r = 0; r < m_riadky; ++r)
	{
		for (int s = 0; s < m_stlpce; ++s)
		{
			m_matica[r][s] *= konst;
		}
	}
}

void Matica::Del(int konst)
{
	for (int r = 0; r < m_riadky; ++r)
	{
		for (int s = 0; s < m_stlpce; ++s)
		{
			m_matica[r][s] /= konst;
		}
	}
}

Matica Matica::operator++()
{
	this->Pridaj(1);
	return *this;
}

Matica Matica::operator--()
{
	this->Odcitaj(1);
	return *this;
}

//int Matica::operator[](int pozicia1)
//{
//	return m_matica[pozicia1];
//}

Matica Matica::operator+(int konst)
{
	Pridaj(konst);
	return *this; // lebo this je pointer a mi chceme hodnotu
}

Matica Matica::operator-(int konst)
{
	Odcitaj(konst);
	return *this;
}


Matica Matica::operator*(int konst)
{
	Nasob(konst);
	return *this;
}
Matica Matica::operator/(int konst)
{
	Del(konst);
	return *this;
}

Matica & Matica::operator=(const Matica & other) //other len meno parametra //
{
	SetRozmery(other.m_stlpce, other.m_riadky);
	for (int r = 0; r < m_riadky; ++r)
	{
		for (int s = 0; s < m_stlpce; ++s)
		{
			m_matica[r][s] = other.m_matica[r][s];
		}
	}
	return *this;
}

Matica Matica::operator+(Matica & rhs)
{
	this->Pridaj(rhs);
	return *this;
}

Matica Matica::operator-(Matica & rhs)
{
	this->Odcitaj(rhs);
	return *this;
}

Matica Matica::operator*(Matica & rhs)
{
	this->Nasob(rhs);
	return *this;
}


void Matica::Pridaj(Matica & mat)
{
	if ((m_stlpce != mat.GetRiadky()) && (m_riadky != mat.GetRiadky()))
	{
		std::cout << "Matice sa nerovnaju, nie je mozne ich scitanie";
	}
	else
	{
		for(int r = 0; r < m_stlpce; ++r)
			for (int s = 0; s < m_riadky; ++s)
			{
				m_matica[r][s] = m_matica[r][s] + mat.GetPrvok(r, s);
			}
	}
}

void Matica::Odcitaj(Matica & mat)
{
	if ((m_stlpce != mat.GetStlpce()) && (m_riadky != mat.GetRiadky()))
	{
		std::cout << "Matice sa nerovnaju, nie je mozne ich scitanie";
	}
	else
	{
		for (int r = 0; r < m_stlpce; ++r)
			for (int s = 0; s < m_riadky; ++s)
			{
				m_matica[r][s] = m_matica[r][s] - mat.GetPrvok(r, s);
			}
	}
}

void Matica::Nasob(Matica & mat)
{
	if (m_stlpce != mat.GetRiadky())
	{
		std::cout << "Riadky prvej a stlpce druhej sa nerovnaju";
	}
	else
	{
		int** vysledok = new int*[m_riadky];
		for (int i = 0; i < m_riadky; ++i)
		{
			vysledok[i] = new int[mat.GetStlpce()];
		}
		for (int i = 0; i < m_riadky; ++i)
		{
			for (int j = 0; j < mat.GetStlpce(); j++)
			{
				vysledok[i][j] = 0;
			}
		}


		for (int riadok = 0; riadok < this->GetRiadky(); ++riadok)
		{
			for (int stlpec = 0; stlpec < mat.GetStlpce(); ++stlpec)
			{
				for (int vnutro = 0; vnutro < this->GetStlpce(); ++vnutro)
				{
					vysledok[riadok][stlpec] += this->GetPrvok(riadok, vnutro) * mat.GetPrvok(vnutro, stlpec);
				}
			}
		}
		this->MaticaNapln(m_riadky, mat.GetStlpce(), vysledok);
		for (int i = 0; i < m_riadky; ++i) 
			delete vysledok[i];
		delete vysledok;	
	}
}

void Matica::to_String()
{
	std::cout << "Rozmer : stlpce: " << m_stlpce << " riadky: " << m_riadky  << std::endl;
		for (int r = 0; r < m_riadky; ++r)
		{
			for (int s = 0; s < m_stlpce; ++s)
			{
				std::cout << m_matica[r][s] << " ";
			}
			std::cout << std::endl;
		}
}

int Matica::GetPrvok(int riadok, int stlpec)
{
	return m_matica[riadok][stlpec];
}

void Matica::MaticaNapln(int riadky, int stlpce ,int **pole)
{
	this->SetRozmery(stlpce, riadky);
	for (int i = 0; i < riadky; ++i)
	{
		for (int j = 0; j < stlpce; j++)
		{
			this->NastavPrvok(i, j, pole[i][j]);
		}
	}	
}

void Matica::NastavPrvok(int riadok, int stlpec, int hodnota)
{
	m_matica[riadok][stlpec] = hodnota;
}

void Matica::vymenStlpce(int prvy, int druhy)
{
	for (int r = 0; r < m_riadky; ++r)
	{
		int temp = m_matica[r][prvy];
		m_matica[r][prvy] = m_matica[r][druhy];
		m_matica[r][druhy] = temp;
	}
	
}

void Matica::vymenRiadky(int prvy, int druhy)
{
	int* temp = m_matica[prvy];
	m_matica[prvy] = m_matica[druhy];
	m_matica[druhy] = temp;
}

void Matica::transponovat()
{
	int* pole = new int[m_riadky * m_stlpce]; // nasobime aby sme mali ekvivalenten pole tomu dvojrozmernemu
	for (int i = 0; i < m_riadky; ++i)
	{
		for (int j = 0; j < m_stlpce; ++j)
		{
			pole[j * m_riadky + i] = m_matica[i][j];
		}
	}
	for (int i = 0; i < m_riadky; ++i)
	{
		for (int j = 0; j < m_stlpce; ++j)
		{
			m_matica[i][j] = pole[i * m_riadky + j];
		}
	}

	delete pole;
}

Matica * Matica::inverzna()
{
	//if (m_riadky != m_stlpce)
	//{
	//	std::cout << "Nie je to stvorcova matica" << std::endl;
	//	return nullptr;
	//} 
	//else
	//{
	//	double** vysledok = new double*[m_riadky];
	//	for (int i = 0; i < m_riadky; ++i)
	//	{
	//		vysledok[i] = new double[m_stlpce];
	//	}
	//	for (int i = 0; i < m_riadky; ++i)
	//	{
	//		for (int j = 0; j < m_stlpce; j++)
	//		{
	//			vysledok[i][j] = 0;
	//			if(i == j)
	//				vysledok[i][j] = 1;
	//		}
	//	}

	//}
	return 0;
}
