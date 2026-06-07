#include "Comedy.h"
#include <iomanip>

Comedy::Comedy() {
	category = 'F';	// Set category to 'F' for Comedy
}

Comedy::~Comedy() {
	// No dynamic memory to clean up
}

bool Comedy::operator==(const Movie& other) const {
	const Comedy* otherComedy = dynamic_cast<const Comedy*> (&other);
	
	if (otherComedy) {
		return this->getTitle() == otherComedy->getTitle() &&
			   this->getReleaseYear() == otherComedy->getReleaseYear();
	}

	return false;
}

bool Comedy::operator<(const Movie& other) const {
	const Comedy* otherComedy = dynamic_cast<const Comedy*> (&other);

	if (otherComedy) {
		if (this->getTitle() != otherComedy->getTitle()) {
			return this->getTitle() < otherComedy->getTitle();
		}
		if (this->getReleaseYear() != otherComedy->getReleaseYear()) {
			return this->getReleaseYear() < otherComedy->getReleaseYear();
		}
	}

	return false;
}

void Comedy::setData(istream& infile) {
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

void Comedy::display(std::ostream& os) const {
	os << "Category: " << category << " , Stock: " << stock << ", Director: " << director << ", Title: " << title << ", Release Year: " << releaseYear << endl;
}

void Comedy::setSearchKey(string t, int y) {
	title = t;
	releaseYear = y;
}

