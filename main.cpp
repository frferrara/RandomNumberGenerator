/*
 * main.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: frferrara
 */


#include <iostream>
#include "RandomNumberGenerator.hpp"


int main() {

	std::cout << "32 bit UNIFORM (min = 0.5, max = 4.5)\n" <<
				 "-------------------------------------\n";

	RandomNumberGenerator * randNumGen = new RandomNumberGenerator( new Ran32( 50 ) );

	double min = 0.5;
	double max = 4.3;

	double num;

	for ( int i = 0; i < 10; i++ ) {
		num = randNumGen->uniGen( min, max );

		std::cout << num << std::endl;
	}

	num = randNumGen->uniGen( max, min );
	std::cout << num << std::endl;

	num = randNumGen->normGen( min, max );
	std::cout << num << std::endl;

	std::cout << "64 bit UNIFORM (min = 0.5, max = 4.5)\n" <<
				 "-------------------------------------\n";

	delete randNumGen;

	randNumGen = new RandomNumberGenerator( new Ran64( 70 ) );

	for ( int i = 0; i < 10; i++ ) {
		num = randNumGen->uniGen( min, max );

		std::cout << num << std::endl;
	}

	num = randNumGen->uniGen( max, min );
	std::cout << num << std::endl;

	num = randNumGen->normGen( min, max );
	std::cout << num << std::endl;

	std::cout << "32 bit NORMAL (mu = 0.5, sigma = 4.5)\n" <<
				 "-------------------------------------\n";

	delete randNumGen;

	randNumGen = new RandomNumberGenerator( new Marsaglia32( 120 ) );

	for ( int i = 0; i < 10; i++ ) {
		num = randNumGen->normGen( min, max );

		std::cout << num << std::endl;
	}
	num = randNumGen->uniGen( min, max );
	std::cout << num << std::endl;

	num = randNumGen->uniGen( max, min );
	std::cout << num << std::endl;

	std::cout << "64 bit NORMAL (mu = 0.5, sigma = 4.5)\n" <<
				 "-------------------------------------\n";

	delete randNumGen;

	randNumGen = new RandomNumberGenerator( new Marsaglia64( 1 ) );

	for ( int i = 0; i < 10; i++ ) {
		num = randNumGen->normGen( min, max );

		std::cout << num << std::endl;
	}
	num = randNumGen->uniGen( min, max );
	std::cout << num << std::endl;

	num = randNumGen->uniGen( max, min );
	std::cout << num << std::endl;

	delete randNumGen;

	return 0;
}
