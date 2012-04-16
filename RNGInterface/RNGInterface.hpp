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
						   double max ) {
		return 0.0;
	}

	virtual double normGen( double mu, \
							double sigma ) {
		return 0.0;
	}

protected:
	RNGInterface() {}
};


#endif /* RNGINTERFACE_HPP_ */
