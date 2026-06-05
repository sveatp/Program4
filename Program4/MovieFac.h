#pragma once

#ifndef MOVIEFAC_H
#define MOVIEFAC_H

#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"



class MovieFac {
	public:

		MovieFac();
		~MovieFac();

		// Returns a heap-allocated Movie object based on the category character, or nullptr if the category is invalid
		Movie* createMovie(char category) const;
};

#endif // MOVIEFAC_H
