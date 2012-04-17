/*
 * RanLim64.hpp
 *
 *  Created on: Apr 16, 2012
 *      Author: frferrara
 */

#ifndef RAN64_HPP_
#define RAN64_HPP_


#include <iostream>
#include <stdexcept>
#include "RNGInterface.hpp"


class Ran64 : public RNGInterface {
public:
	Ran64();

	Ran64( unsigned long long i );

	~Ran64() {}

	virtual double uniGen( double min, \
						   double max );

	virtual double normGen( double mu, \
							double sigma );

private:
	inline unsigned long long int64();

	inline double doub();

	inline unsigned int int32();

	void checkMinMax( double min, \
					  double max );

	unsigned long long u, v, w;
};

#endif /* RAN64_HPP_ */
