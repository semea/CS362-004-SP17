#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


int main() {

	struct gameState G;

	printf("\n*****Test Game Over*****\n");


	printf("\n----Test 1: No Province Cards Left----\n");

	G.supplyCount[province] = 0;
	if (isGameOver(&G) == 1) {
		printf("	**PASSED**\n");
		G.supplyCount[province] = 1;
	}
	else {
		printf("	**FAILED**\n");
		G.supplyCount[province] = 1;
	}


	printf("\n----Test 2: No Supply Piles left----\n");
	for (int i = 0; i < 25; i++) {
		printf("\n  --Test 2.%d: Supply Pile %d--", i + 1, i + 1);
		G.supplyCount[i] = 0;
		if (isGameOver(&G) == 1) {
			printf("	**PASSED**");
		}
		else {
			printf("	**FAILED**");
		}
	}
	
	return 0;
}