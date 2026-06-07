#include "TransFac.h"

TransFac::TransFac() {
	// No initialization needed for this factory class
}

TransFac::~TransFac() {
	// No dynamic memory to clean up in the factory class
}

Transaction* TransFac::createTransaction(char category) const {
	switch (category) {
		case 'H': return new History();
		case 'B': return new Borrow();
		case 'R': return new Return();
	default:
		cerr << "Error: Unknown action code '" << category << "'. Cannot create movie." << endl;
		return nullptr;
	}
}