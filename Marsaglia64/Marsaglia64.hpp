/*
 * BoxMuller.hpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */

#ifndef MARSAGLIA64_HPP_
#define MARSAGLIA64_HPP_


#include <cmath>
#include "Ran64.hpp"


class Marsaglia64 : public RNGInterface {
public:
	Marsaglia64();

	Marsaglia64( unsigned long long i );

	~Marsaglia64();

	virtual double uniGen( double min, \
						   double max );

	virtual double normGen( double mu, \
							double sigma );

private:
	double dev( double mu, \
				double sigma );

	Ran64 * ran64;

	double storedval;
};


#endif /* MARSAGLIA64_HPP_ */
