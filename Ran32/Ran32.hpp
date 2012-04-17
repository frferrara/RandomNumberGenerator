/*
 * RanLim32.hpp
 *
 *  Created on: Apr 13, 2012
 *      Author: frferrara
 */

#ifndef RAN32_HPP_
#define RAN32_HPP_


#include <iostream>
#include <stdexcept>
#include "RNGInterface.hpp"


class Ran32 : public RNGInterface {
public:
	Ran32();

	Ran32( unsigned int i );

	virtual ~Ran32() {}

	virtual double uniGen( double min, \
				    	   double max );

	virtual double normGen( double mu, \
							double sigma );

private:
	inline unsigned int int32();

	inline double doub();

	inline double trueDoub();

	void checkMinMax( double min, \
					  double max );

	unsigned int u, v, w1, w2;
};


#endif /* RAN32_HPP_ */
