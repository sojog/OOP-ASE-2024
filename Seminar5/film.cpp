#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Film {
private:
	char* nume;
	char* gen;
	int const anulAparitiei;
	int* episoade;
	int nrEpisoade;
public:

	Film(const char* nume, const char* gen, int const anulAparitiei, int* episoade, int nrEpisoade) :anulAparitiei(anulAparitiei) {
		this->nume = new char[strlen(nume) + 1];
		this->gen = new char[strlen(gen) + 1];
		strcpy(this->nume, nume);
		strcpy(this->gen, gen);
		this->episoade = episoade;
		this->nrEpisoade = nrEpisoade;

		episoade = new int[nrEpisoade];
		for (int i = 0; i < nrEpisoade; i++) {
			this->episoade[i] = episoade[i];
		}
	}

	int durataMinute() {
		if (nrEpisoade == 0) {
			return 0;
		}
		int minute = 0;
		for (int i = 0; i < nrEpisoade; i++) {
			minute += episoade[i];
		}
		return minute;
	}

	friend ostream& operator<< (ostream& os, Film film) {
		os << "Film cu titlul" << film.nume << endl;
		os << "Film cu durata" << film.durataMinute() << endl;

		return os;
	}

};

int main() {
	int anulAparitiei = 1999;
	int episoade[] = {10, 20, 30};
	int nrEpisoade = 3;
	Film f1("Atomic", "actiune", anulAparitiei, episoade, nrEpisoade);

	cout << f1 << endl;

	return 0;
}