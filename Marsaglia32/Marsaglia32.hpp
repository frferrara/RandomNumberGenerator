/*
 * BoxMuller.hpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */

#ifndef MARSAGLIA32_HPP_
#define MARSAGLIA32_HPP_


#include <cmath>
#include "Ran32.hpp"


class Marsaglia32 : public RNGInterface {
public:
	Marsaglia32();

	Marsaglia32( unsigned long long i );

	~Marsaglia32();

	virtual double uniGen( double min, \
						   double max );

	virtual double normGen( double mu, \
							double sigma );

private:
	double dev( double mu, \
				double sigma );

	Ran32 * ran32;

	double storedval;
};


#endif /* MARSAGLIA32_HPP_ */
