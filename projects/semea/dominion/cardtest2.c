#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv) {
	struct gameState G;
	int before, after;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

	printf("\n*****Test Adventurer*****\n");

	if (initializeGame(2, k, 2, &G) == -1) {
		printf("	**GAME INITIALIZATION FAILED: ENDING TEST**");
		return 0;
	}
	else {
		printf("	**GAME INITIALIZATION PASSED: PROCEED**");
		before = numHandCards(&G);
	}

	printf("\n ----Test 2: Adventurer Card Effects----\n");
	if (cardEffect(adventurer, 0, 0, 0, &G, 0, 0) == -1) {
		printf("	**CARD INITIALIZATION FAILED: ENDING TEST**");
		return 0;
	}
	else {
		after = numHandCards(&G);
		if (before < after) {
			printf("	**PASSED**");
		}
		else
		{
			printf("	**FAILED**");
		}
	}

	return 0;
}