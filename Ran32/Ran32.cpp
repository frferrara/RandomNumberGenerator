/*
 * RanLim32.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: frferrara
 */


#include "Ran32.hpp"


Ran32::Ran32() {
	u = 0;
	v = 0;
	w1 = 0;
	w2 = 0;
}

Ran32::Ran32( unsigned int i ) :
v( 2244614371U ),
w1( 521288629U ),
w2( 362436069U ) {
	u = i ^ v;

	int32();

	v = u;

	int32();
}

double Ran32::uniGen( double min, \
					  double max ) {
	try {
		checkMinMax( min, max );
	} catch( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;

		return -1.0;
	}

	return min + doub() * ( max - min );
}

double Ran32::normGen( double mu, \
					   double sigma ) {
	return 0.0;
}

unsigned int Ran32::int32() {
	u = u * 2891336453U + 1640531513U;

	v ^= v >> 13;
	v ^= v << 17;
	v ^= v >> 5;

	w1 = 33378 * ( w1 & 0xffff ) + ( w1 >> 16 );
	w2 = 57225 * ( w2 & 0xffff ) + ( w2 >> 16 );

	unsigned int x = u ^ ( u << 9 );
	x ^= x >> 17;
	x ^= x << 6;

	unsigned int y = w1 ^ ( w1 << 17 );
	y ^= y >> 15;
	y ^= y << 5;

	return ( x + v ) ^ ( y + w2 );
}

double Ran32::doub() {
	return 2.32830643653869629E-10 * int32();
}

double Ran32::trueDoub() {
	return 2.32830643653869629E-10 * \
			( int32() + 2.32830643653869629E-10 * int32() );
}

void Ran32::checkMinMax( double min, \
						 double max ) {
	if ( min >= max )
		throw std::runtime_error( "min >= max" );
}
