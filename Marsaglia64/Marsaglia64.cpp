/*
 * BoxMuller.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */


#include "Marsaglia64.hpp"


Marsaglia64::Marsaglia64() {
	ran64 = NULL;

	storedval = 0.0;
}

Marsaglia64::Marsaglia64( unsigned long long i ) :
storedval( 0.0 ) {
	ran64 = new Ran64( i );
}

Marsaglia64::~Marsaglia64() {
	delete ran64;
}

double Marsaglia64::normGen( double mu, \
							 double sigma ) {
	return dev( mu, sigma );
}

double Marsaglia64::dev( double mu, \
					     double sigma ) {
	double v1, v2, rsq, fac;

	if ( storedval == 0.0 ) {
		do {
			v1 = 2.0 * ran64->uniGen( 0.0, 1.0 ) - 1.0;
			v2 = 2.0 * ran64->uniGen( 0.0, 1.0 ) - 1.0;

			rsq = v1 * v1 + v2 * v2;
		} while ( rsq >= 1.0 || rsq == 0.0 );

		fac = std::sqrt( -2.0 * log( rsq ) / rsq );

		storedval = v1 * fac;

		return mu + sigma * v2 * fac;
	} else {
		fac = storedval;
		storedval = 0.0;

		return mu + sigma * fac;
	}
}
