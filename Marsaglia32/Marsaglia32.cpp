/*
 * BoxMuller.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */


#include "Marsaglia32.hpp"


Marsaglia32::Marsaglia32() {
	ran32 = NULL;

	storedval = 0.0;
}

Marsaglia32::Marsaglia32( unsigned long long i ) :
storedval( 0.0 ) {
	ran32 = new Ran32( i );
}

Marsaglia32::~Marsaglia32() {
	delete ran32;
}

double Marsaglia32::uniGen( double min, \
							double max ) {
	return 0.0;
}

double Marsaglia32::normGen( double mu, \
							 double sigma ) {
	return dev( mu, sigma );
}

double Marsaglia32::dev( double mu, \
					     double sigma ) {
	double v1, v2, rsq, fac;

	if ( storedval == 0.0 ) {
		do {
			v1 = 2.0 * ran32->uniGen( 0.0, 1.0 ) - 1.0;
			v2 = 2.0 * ran32->uniGen( 0.0, 1.0 ) - 1.0;

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
