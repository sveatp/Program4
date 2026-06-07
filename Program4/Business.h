#pragma once

#include "InventoryManager.h"
#include "TransFac.h"
#include "CustomerDatabase.h"

class Business {

	public: 
		Business();
		~Business();

		void buildMovie(ifstream& infile);
		void buildCustomer(ifstream& infile);
		void processTransaction(ifstream& infile);

	private:
		InventoryManager inventory;
		CustomerDatabase customers;
};

