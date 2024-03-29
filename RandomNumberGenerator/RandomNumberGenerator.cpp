/*
 * NumGenContext.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: frferrara
 */


#include "RandomNumberGenerator.hpp"


RandomNumberGenerator::RandomNumberGenerator() {
	randNumGen = NULL;
}

RandomNumberGenerator::RandomNumberGenerator( RNGInterface * randNumGen ) {
	this->randNumGen = randNumGen;
}

RandomNumberGenerator::~RandomNumberGenerator() {
	delete randNumGen;
}

double RandomNumberGenerator::uniGen( double min, \
						   	  	  	  double max ) {
	try {
		num = randNumGen->uniGen( min, max );
	} catch( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;

		num = 0.0;
	}
	return num;
}

double RandomNumberGenerator::normGen( double mu, \
							   	   	   double sigma ) {
	try {
		num = randNumGen->normGen( mu, sigma );
	} catch (std::runtime_error & e) {
		std::cout << std::endl << e.what() << std::endl;

		num = 0.0;
	}

	return num;
}
