#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv) {
	struct gameState *G = malloc(sizeof(struct gameState));
	int before, after;
	int beforeACT, afterACT;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

	printf("\n*****Test Village*****\n");

	if (initializeGame(2, k, 2, G) == -1) {
		printf("	**GAME INITIALIZATION FAILED: ENDING TEST**");
		return 0;
	}
	else {
		printf("	**GAME INITIALIZATION PASSED: PROCEED**");
		before = numHandCards(G);
		beforeACT = G->numActions;
	}

	printf("\n ----Test 3: Village Card Effects----\n");
	if (cardEffect(village, 0, 0, 0, G, 0, 0) == -1) {
		printf("	**CARD INITIALIZATION FAILED: ENDING TEST**");
		return 0;
	}
	else {
		after = numHandCards(G);
		afterACT = G->numActions;
		if (before == after && afterACT == (beforeACT+2)) {
			printf("	**PASSED**");
		}
		else
		{
			printf("	**FAILED**");
		}
	}

	return 0;
}