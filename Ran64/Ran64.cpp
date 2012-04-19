/*
 * RanLim64.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */


#include "Ran64.hpp"


Ran64::Ran64() {
	u = 0;
	v = 0;
	w = 0;
}

Ran64::Ran64( unsigned long long i ) :
v( 4101842887655102017LL ),
w( 1 ) {
	u = i ^ v; int64();
	v = u; int64();
	w = v; int64();
}

double Ran64::uniGen( double min, \
					  double max ) {
	try {
		checkMinMax( min, max );
	} catch ( std::runtime_error & e ) {
		throw;
	}

	return min + doub() * ( max - min );
}

double Ran64::normGen( double mu, \
					   double sigma ) {
	throw std::runtime_error( "Exception: Wrong random number generator!" );
}

unsigned long long Ran64::int64() {
	u = u * 2862933555777941757LL + 7046029254386353087LL;

	v ^= v >> 17;
	v ^= v << 31;
	v ^= v >> 8;

	w = 4294957665U*( w & 0xffffffff ) + ( w >> 32 );

	unsigned long long x = u ^ ( u << 21 );
	x ^= x >> 35;
	x ^= x << 4;

	return ( x + v ) ^ w;
}

double Ran64::doub() {
	return 5.42101086242752217E-20 * int64();
}

unsigned int Ran64::int32() {
	return ( unsigned int )int64();
}

void Ran64::checkMinMax( double min, \
						 double max ) {
	if ( min >= max )
		throw std::runtime_error( "Exception: min >= max" );
}
