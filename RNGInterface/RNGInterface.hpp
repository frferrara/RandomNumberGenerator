/*
 * RandNumGen.hpp
 *
 *  Created on: Apr 12, 2012
 *      Author: frferrara
 */

#ifndef RNGINTERFACE_HPP_
#define RNGINTERFACE_HPP_


class RNGInterface {
public:
	virtual ~RNGInterface() {}

	virtual double uniGen( double min, \
						   double max ) = 0;

	virtual double normGen( double mu, \
							double sigma ) = 0;

protected:
	RNGInterface() {}
};


#endif /* RNGINTERFACE_HPP_ */
