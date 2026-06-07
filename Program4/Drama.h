#pragma once

#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"


class Drama : public Movie {
	public:
		Drama();
		virtual ~Drama();

		virtual bool operator==(const Movie& other) const override;
		virtual bool operator<(const Movie& other) const override;
	
		virtual void setData(istream& infile) override;

		// Displays the movie's information in the specified format
		// Format: "D, Stock, Director, Title, Release Year"
		virtual void display(std::ostream& os) const override;

		void setSearchKey(string director, string t);
};	

#endif // DRAMA_H