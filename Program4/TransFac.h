#pragma once

#ifndef TRANSFAC_H
#define TRANSFAC_H

#include "History.h"
#include "Borrow.h"
#include "Return.h"

class TransFac {
	public: 

		TransFac();
		~TransFac();

		Transaction* createTransaction(char category) const;
};

#endif // TRANSFAC_H