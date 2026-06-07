#include "MovieFac.h"

MovieFac::MovieFac() {
	// No initialization needed for this factory class
}

MovieFac::~MovieFac() {
	// No dynamic memory to clean up in the factory class
}

Movie* MovieFac::createMovie(char category) {
	switch (category) {
		case 'F': return new Comedy();
		case 'D': return new Drama();
		case 'C': return new Classic();
	default:
		cerr << "Error: Unknown movie genre '" << category << "'. Cannot create movie." << endl;
		return nullptr;
	}
}