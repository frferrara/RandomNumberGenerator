/*
 * NumGenContext.hpp
 *
 *  Created on: Apr 13, 2012
 *      Author: frferrara
 */

#ifndef RANDOMNUMBERGENERATOR_HPP_
#define RANDOMNUMBERGENERATOR_HPP_


#include "RNGInterface.hpp"
#include "Ran32.hpp"
#include "Ran64.hpp"
#include "Marsaglia32.hpp"
#include "Marsaglia64.hpp"


class RandomNumberGenerator {
public:
	RandomNumberGenerator();

	RandomNumberGenerator( RNGInterface * randNumGen );

	~RandomNumberGenerator();

	double uniGen( double min, \
			       double max );

	double normGen( double mu, \
				    double sigma );

private:
	void checkNum_uniGen( double num, \
						  double min, \
						  double max );

	void checkNum_normGen( double num, \
						   double mu, \
						   double sigma );

	RNGInterface * randNumGen;
};


#endif /* RANDOMNUMBERGENERATOR_HPP_ */
