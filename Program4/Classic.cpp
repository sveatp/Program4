#include "Classic.h"

#include <iomanip>

Classic::Classic() : releaseMonth(0) {
	category = 'C';
}

Classic::~Classic() {
	// No dynamic memory to clean up
}

bool Classic::operator==(const Movie& other) const {
	const Classic* otherClassic = dynamic_cast<const Classic*> (&other);	// Using dynamic_cast to check if the other movie is a Classic

	if (otherClassic) {				// Check if the other movie is a Classic
		return this->getReleaseYear() == otherClassic->getReleaseYear() &&
			   this->getReleaseMonth() == otherClassic->getReleaseMonth() &&
			   this->getMajorActor() == otherClassic->getMajorActor();
	}

	return false; // Not the same type, so not equal
}

bool Classic::operator<(const Movie& other) const {
	const Classic* otherClassic = dynamic_cast<const Classic*> (&other);	// Using dynamic cast to check if the other movie is a Classic

	if (otherClassic) {
		if (this->getReleaseYear() != otherClassic->getReleaseYear()) {
			return this->getReleaseYear() < otherClassic->getReleaseYear();
		}

		if (this->getReleaseMonth() != otherClassic->getReleaseMonth()) {
			return this->getReleaseMonth() < otherClassic->getReleaseMonth();
		}

		return this->getMajorActor() < otherClassic->getMajorActor();
	}

	return false;	// Not the same type, so we can't compare
}

string Classic::getMajorActor() const {
	return majorActor;
}

int Classic::getReleaseMonth() const {
	return releaseMonth;
}

void Classic::setData(istream& infile) {
	// Expected Format: Stock, Director, Title, Major Actor, Release Month, Release Year
	char comma; // To read the commas between fields
	infile >> stock >> comma;
	infile.ignore();
	getline(infile, director, ',');
	infile.ignore();
	getline(infile, title, ',');
	infile.ignore();

	// Read Major Actor (FirstName LastName)
	string firstName, lastName;
	infile >> firstName >> lastName >> comma;
	majorActor = firstName + " " + lastName;

	infile >> releaseMonth >> comma >> releaseYear;
}

void Classic::display(std::ostream& os) const {
	os  << "Category: " << category
		<< " , Stock: " << stock
		<< ", Director: " << director
		<< ", Title: " << title
		<< ", Major Actor: " << majorActor
		<< ", Release Month: " << releaseMonth
		<< ", Release Year: " << releaseYear
		<< endl;
}
