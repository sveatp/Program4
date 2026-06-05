#pragma once

#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"


class Comedy : public Movie {
	public:
		Comedy();
		virtual ~Comedy();

		virtual bool operator==(const Movie& other) const override;
		virtual bool operator<(const Movie& other) const override;

		virtual void setData(istream& infile) override;

		// Displays the movie's information in the specified format
		// Format: "F, Stock, Director, Title, Release Year"
		virtual void display(std::ostream& os) const override;
};

#endif // COMEDY_H