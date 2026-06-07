#include "Borrow.h"
#include <limits>

Borrow::Borrow() {
    action = 'B';
}

Borrow::~Borrow() {

}

void Borrow::setData(istream& input) { //set data for borrow transaction
    char mediaType;
    char movieType;
    input >> customerId >> mediaType >> movieType;
    
    if (mediaType != 'D') {
        cerr << "Error: Invalid media type " << mediaType
             << " - only DVD (D) supported." << endl;
        input.ignore(numeric_limits<streamsize>::max(), '\n');
        delete movie;
        movie = nullptr;
        return;
    }

    movie = MovieFac::createMovie(movieType); //create movie using factory
    if (movie == nullptr) { 
        input.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
        return;
    }

    if (movieType == 'F') {
        string title;
        int year;

        getline(input, title, ',');
        if (!title.empty() && title[0] == ' ') {
            title = title.substr(1);
        }

        input >> year;
        static_cast<Comedy*>(movie)->setSearchKey(title, year);
    } else if (movieType == 'D') {
        string director, title;
        getline(input, director, ',');

        if (!director.empty() && director[0] == ' ') {
            director = director.substr(1);
        }

        getline(input, title, ',');
        if (!title.empty() && title[0] == ' ') {
            title = title.substr(1);
        }

        static_cast<Drama*>(movie)->setSearchKey(director, title);
    } else if (movieType == 'C') {
        int month, year;
        string firstName, lastName;
        input >> month >> year >> firstName >> lastName;
        static_cast<Classic*>(movie)->setSearchKey(month, year, firstName + " " + lastName);
    }
    
    input.ignore(256, '\n');
}

void Borrow::doTrans(CustomerDatabase& customerDB, InventoryManager& inventory) { //perform borrow transaction
    Customer* customer = customerDB.getCustomer(customerId); //get customer from database

    if (customer == nullptr) {
        cerr << "Error: Customer ID " << customerId << " not found." << endl;
		delete movie; // Clean up movie if customer not found
		movie = nullptr;
        return;
    }
    if (movie == nullptr) {
        cerr << "Error: Invalid movie." << endl;
        return;
    }

    Movie* inventoryMovie = nullptr; //result movie from inventory search
    
    if (!inventory.getMovie(movie, inventoryMovie)) {
        cerr << "Error: Movie not found in inventory." << endl;
		delete movie; // Clean up movie if not found in inventory
		movie = nullptr;
        return;
    }

    delete movie;
    movie = inventoryMovie;
    ownsMovie = false;

	if (!inventoryMovie->borrowMovie()) { // Attempt to borrow the movie
		cerr << "Error: Movie is currently unavailable." << endl;
		movie = nullptr; // Set movie to nullptr since the borrow failed
		return;
    }
    
	customer->addTransaction(new Borrow(*this)); // Add this borrow transaction to the customer's history
}

void Borrow::display() const { //display borrow transaction
    cout << "Borrow Transaction - Movie: " << (movie ? movie->getTitle() : "None") << endl;
}