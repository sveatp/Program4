#pragma once

#ifndef CLASSIC_H
#define CLASSIC_H


#include "Movie.h"


class Classic : public Movie {
	public:
		Classic();
		virtual ~Classic();

		virtual bool operator==(const Movie& other) const override;
		virtual bool operator<(const Movie& other) const override;

		string getMajorActor() const;
		int getReleaseMonth() const;
	

		virtual void setData(istream& infile) override;

		// Displays the movie's information in the specified format
		// Format: "C, Stock, Director, Title, Major Actor, Release Month Release Year"
		virtual void display(std::ostream& os) const override;

	protected: 
		string majorActor;			// Format: "FirstName LastName"
		int releaseMonth;
};
	
#endif // CLASSIC_H
