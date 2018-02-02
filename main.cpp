#include <iostream>
#include <cstdlib>
#include "briefing.hpp"

int main(int argc, char * argv[]){
	int N, K;
	briefing * b;

	srand(time(NULL));

	if(argc < 2){
		std::cerr << "Call with exact 2 arguments, N, K" << std::endl;

		return EXIT_FAILURE;
	}

	//add arguments to variables
	N 	= atoi(argv[1]);
	K 	= atoi(argv[2]);

	b = new briefing(N, K);

	b->start();

	delete b;

	return EXIT_SUCCESS;
}
