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

Matica::~Matica()
{
	for (int i = 0; i < m_riadky; ++i) //tu uz m riadky lebo mozu byt ine uz
		delete m_matica[i];

	delete m_matica;
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
	if (m_stlpce!= mat.GetRiadky())
	{
		std::cout << "Riadky prvej a stlpce druhej sa nerovnaju";
	}
	else
	{
		int** temp = new int*[m_riadky];
		for (int i = 0; i < m_riadky; ++i)
		{
			temp[i] = new int[mat.GetStlpce()];
		}
		for (int i = 0; i < m_riadky; ++i)
		{
			for (int j = 0; j < mat.GetStlpce)
			{
				temp[i][j] += this->GetPrvok(i, j)*mat.GetPrvok(j, i);
			}
		}
		for (int i = 0; i < (sizeof(p) / sizeof(*p)); ++i)
		{
			for (int j = 0; j < mat.GetStlpce)
			{
				std::cout << temp
			}
		}
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
