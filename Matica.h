#pragma once

class Matica
{
public:
	Matica(int stlpce, int riadky, int konst);
	Matica(int stlpce, int riadky, int* pole);
	Matica(const Matica& matica); // copy konstruktor //zapisovace sa nemozu kopirovat, lebo skopiruje bit po bite aj pointer a mozu dve triedy k rovnakemu polu napr pristupovat
	virtual ~Matica();

	void SetRozmery(int stlpce, int riadky); // public metody zacinaju velkym 
	void Pridaj(int konst); 
	void Odcitaj(int konst);
	void Nasob(int konst);
	void Del(int konst);

	Matica operator++();
	Matica operator--();
	Matica operator[](int pozicia1);

	Matica operator+(int konst);
	Matica operator-(int konst);
	Matica operator*(int konst);
	Matica operator/(int konst);
	Matica& operator=(const Matica& other);

	Matica operator+(Matica & rhs);
	Matica operator-(Matica & rhs);
	Matica operator*(Matica & rhs);

	void Pridaj(Matica& mat);
	void Odcitaj(Matica& mat);
	void Nasob(Matica& mat);

	void vymenStlpce(int prvy, int druhy);
	void vymenRiadky(int prvy, int druhy);

	void transponovat();
	Matica* inverzna();


	void to_String();
	int GetStlpce()  { return m_stlpce; };
	int GetRiadky()  { return m_riadky; };
	int GetPrvok(int riadok, int stlpec);


private:
	int m_stlpce;
	int m_riadky;
	int** m_matica;
	void MaticaNapln(int riadky, int stlpce, int **pole);
	void NastavPrvok(int riadok, int stlpec, int hodnota);
};

