#pragma once

class Matica
{
public:
	Matica(int stlpce, int riadky, int konst);
	Matica(int stlpce, int riadky, int* pole);
	virtual ~Matica();

	void SetRozmery(int stlpce, int riadky); // public metody zacinaju velkym 
	void Pridaj(int konst); 
	void Odcitaj(int konst);
	void Nasob(int konst);
	void Del(int konst);

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

};

