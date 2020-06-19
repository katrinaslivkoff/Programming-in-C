#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13

int main(){

	size_t sumOfTwoDice; 
	unsigned int roll;
	unsigned int frequency[ SIZE ] = { 0 }; 

	srand(time( NULL )); 

    // roll the dice 36000 times
	for (roll = 1; roll <= 36000; ++roll) {
		sumOfTwoDice = ( 1 + rand() % 6 ) + ( 1 + rand() % 6 );
		++frequency[ sumOfTwoDice ];
	}

	printf( "%s%17s\n", "sumOfTwoDice", "Frequency" );

    // print the sum and frequency until number of dice is rolled
	for (sumOfTwoDice = 2; sumOfTwoDice < SIZE; ++sumOfTwoDice) {
		printf ("%3zu%17d\n", sumOfTwoDice, frequency [ sumOfTwoDice ] );
	}

}