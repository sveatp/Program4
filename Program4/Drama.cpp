#include "Drama.h"
#include <iomanip>

Drama::Drama() {
	category = 'D';	// Set category to 'F' for Comedy
}

Drama::~Drama() {
	// No dynamic memory to clean up
}

bool Drama::operator==(const Movie& other) const {
	const Drama* otherDrama = dynamic_cast<const Drama*> (&other);

	if (otherDrama) {
		return this->getDirector() == otherDrama->getDirector() &&
			this->getTitle() == otherDrama->getTitle();
	}

	return false;
}

bool Drama::operator<(const Movie& other) const {
	const Drama* otherDrama = dynamic_cast<const Drama*> (&other);

	if (otherDrama) {
		if (this->getDirector() != otherDrama->getDirector()) {
			return this->getDirector() < otherDrama->getDirector();
		}
		if (this->getTitle() != otherDrama->getTitle()) {
			return this->getTitle() < otherDrama->getTitle();
		}
	}

	return false;
}

void Drama::setData(istream& infile) {
	// Expected Format: Stock, Director, Title, Release Year
	char comma; // To read the commas between fields
	infile >> stock >> comma;
	infile.ignore();
	getline(infile, director, ',');
	infile.ignore();
	getline(infile, title, ',');
	infile.ignore();
	infile >> releaseYear;
}

void Drama::display(std::ostream& os) const {
	os << "Category: " << category << " , Stock: " << stock << ", Director: " << director << ", Title: " << title << ", Release Year: " << releaseYear << endl;
}

void Drama::setSearchKey(string dir, string t) {
	director = dir;
	title = t;
}