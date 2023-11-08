// Rental.hh
#ifndef RENTAL_HH
#define RENTAL_HH
#include "Movie.hh"

class Rental {
public:
  Rental( const Movie& movie, int daysRented );

  int getDaysRented() const;
  const Movie& getMovie() const;
  const double getCharge() const;

private:
  Movie _movie;
  int _daysRented;
};

inline Rental::Rental( const Movie& movie, int daysRented ):
  _movie( movie ),
  _daysRented( daysRented ) {}

inline int Rental::getDaysRented() const { return _daysRented; }

inline const Movie& Rental::getMovie() const { return _movie; }

inline const double Rental::getCharge() const { 
  double thisAmount = 0;

  // determine amounts for each line
  switch (getMovie().getPriceCode())
  {
  case Movie::REGULAR:
    thisAmount += 2;
    if (getDaysRented() > 2)
      thisAmount += (getDaysRented() - 2) * 1.5;
    break;
  case Movie::NEW_RELEASE:
    thisAmount += getDaysRented() * 3;
    break;
  case Movie::CHILDRENS:
    thisAmount += 1.5;
    if (getDaysRented() > 3)
      thisAmount += (getDaysRented() - 3) * 1.5;
    break;
  }
  return thisAmount;
}

#endif // RENTAL_HH
