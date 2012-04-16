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
	double num = randNumGen->uniGen( min, max );

	try {
		checkNum_uniGen( num, min, max );
	} catch( std::runtime_error & e ) {
		std::cout << std::endl << e.what() << std::endl;

		return 0.0;
	}
	return num;
}

double RandomNumberGenerator::normGen( double mu, \
							   	   	   double sigma ) {
	double num = randNumGen->normGen( mu, sigma );

	try {
		checkNum_normGen( num, mu, sigma );
	} catch (std::runtime_error & e) {
		std::cout << std::endl << e.what() << std::endl;

		return 0.0;
	}
	return num;
}

void RandomNumberGenerator::checkNum_uniGen( double num, \
											 double min, \
											 double max ) {
	if ( num == 0.0 )
		num = randNumGen->uniGen( min, max );

	if ( num == 0.0 )
		throw std::runtime_error( "Wrong random number generator!" );
}

void RandomNumberGenerator::checkNum_normGen( double num, \
											  double mu, \
											  double sigma ) {
	if ( num == 0.0 )
		num = randNumGen->normGen( mu, sigma );

	if ( num == 0.0 )
		throw std::runtime_error( "Wrong random number generator!" );
}
