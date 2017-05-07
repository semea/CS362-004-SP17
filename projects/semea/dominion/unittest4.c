#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef enum { numBuys, supply, coins};


int main() {

	struct gameState G;
	int testCase = numBuys;

	printf("\n*****Test Buy Card*****\n");

	for (testCase; testCase <= coins; testCase++){
		switch (testCase)
		{
		case numBuys:
			printf("\n ----Test 1: Number of Buys left----\n");
			G.numBuys = 0;
			if (buyCard(0, &G) == -1) {
				printf("	**PASSED**");
			}
			else {
				
			}
			break;
		case supply:
			printf("\n ----Test 2: Supply Count Per Card----\n");
			G.numBuys = 2;
			for (int i = curse; i < treasure_map; i++) {
				printf("\n  --Test 1.%d: Card %d Supply--", i + 1, i + 1);
				G.supplyCount[i] = 0;
				if (buyCard(i, &G) == -1) {
					printf("	**PASSED**");
				}
				else {
					printf("	**FAILED**");
				}
			}
			break;
		case coins:
			printf("\n ----Test 3: Afford Card----\n");
			for (int i = curse; i < treasure_map; i++) {
				printf("\n  --Test 2.%d: Card %d Cost--", i + 1, i + 1);
				G.numBuys = 1;
				G.coins = 0;
				if (buyCard(i, &G) == -1) {
					printf("	**PASSED**");
				}
				else {
					printf("	**FAILED**");
				}
			}
		default:
			break;
		}
	}

	return 0;
}