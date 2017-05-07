#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_COIN 10

int main() {

	int cardCSG = copper;
	struct gameState G;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	printf("\n*****Test Coin Update*****\n");
	
	for (int p = 1; p <= MAX_PLAYERS; p++) {
		printf("\n ---Test %d: Player %d Coin Amount---\n", p, p);
		initializeGame(p, k, 100, &G);
		for (int i = 0; i < MAX_COIN; i++) {
			switch (cardCSG)
			{
			case copper:
				G.hand[p][i] = copper;
				updateCoins(p, &G, 0);

				if (G.coins == copper * MAX_COIN) {
					printf("	**PASSED: COPPER**\n");
				}
				else {
					printf("	**FAILED: COPPER**\n");
				}
				cardCSG = silver;
				break;
			case silver:
				G.hand[p][i] = silver;
				updateCoins(p, &G, 0);

				if (G.coins == silver * MAX_COIN) {
					printf("	**PASSED: SILVER**\n");
				}
				else {
					printf("	**FAILED: SILVER**\n");
				}
				cardCSG = gold;
				break;
			case gold:
				G.hand[p][i] = gold;
				updateCoins(p, &G, 0);

				if (G.coins == gold * MAX_COIN) {
					printf("	**PASSED: GOLD**\n");
				}
				else {
					printf("	**FAILED: GOLD**\n");
				}
				cardCSG = copper;
				break;
			default:
				break;
			}
		}
	}
	
	return 0;
}
