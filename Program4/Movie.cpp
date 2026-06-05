#include "Movie.h"

Movie::Movie() {
	stock = 0;
	director = "";
	title = "";
	releaseYear = 0;
	category = ' ';
}

Movie::~Movie() {
	// No dynamic memory to clean up
}

int Movie::getStock() const {
	return stock;
}

void Movie::addStock(int amount) {
	stock += amount;
}

bool Movie::borrowMovie() {
	if (stock > 0) {
		stock--;
		return true;
	}
	return false;
}

void Movie::returnMovie() {
	stock++;
}

string Movie::getTitle() const {
	return title;
}

std::string Movie::getDirector() const {
	return director;
}

int Movie::getReleaseYear() const {
	return releaseYear;
}

char Movie::getCategory() const {
	return category;
}

void Movie::display(std::ostream& os) const {
	os << "Category: " << category << " , Stock: " << stock << ", Director: " << director << ", Title: " << title << ", Release Year: " << releaseYear << endl;
}

std::ostream& operator<<(std::ostream& os, const Movie& movie) {
	movie.display(os);
	return os;
}