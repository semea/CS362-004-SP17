#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef enum { noPlayers = 0, tooLittle, minAmount, correctAmount, maxAmount, tooMany } test1Cases;
typedef enum { twoPlayer = 2, threePlayer, fourPlayer} test2Cases;

typedef struct { bool noPlayers, tooLittle, minAmount, correctAmount, maxAmount, tooMany, error; } t1;
typedef struct { bool twoPlayer, threePlayer, fourPlayer, error; } t2;
typedef struct { bool correct; } t3;

t1 test1(int *k[], struct gameState *G);
t2 test2(int *k[], struct gameState *G);
t3 test3(int *k[], struct gameState *G);



int main() {

	struct gameState s;

	t1 t1;
	int numPlayers = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	
	//Test game Initialization
	
	printf("*****Test Game Initialization*****\n");

	printf("\n----Test 1: Number of Players----\n");
	test1(k, &s);

	printf("\n----Test 2: Amount of Supply----\n");
	test2(k, &s);

	printf("\n----Test 3: Starting Hand Size----\n");
	test3(k, &s);
	printf("*****Test Game Initialization Complete*****\n");
	return 0;
}

/*
	TEST 1: Tests too see if the code reutrn the correct value depending on the amount of players.

	This test could be improved by tested the false conditions in addition to the true conditions.
*/
t1 test1(int *k[], struct gameState *G) {
	int numPlayers;
	t1 t1;

	for (numPlayers = 0; numPlayers <= MAX_PLAYERS + 1; numPlayers++) {
		switch (numPlayers)
		{
		case noPlayers:
			printf(" \n  --Test 1.1: No Players:");
			if (initializeGame(numPlayers, k, 100, G) == -1) {
				printf("	**PASSED**\n");
				t1.noPlayers = true;
			}
			else {
				printf("	**FAILED**\n");
				t1.noPlayers = false;
			}
			break;
		case tooLittle:
			printf("\n  --Test 1.2: Too Few Players:");
			if (initializeGame(numPlayers, k, 100, G) == -1) {
				printf("	**PASSED**\n");
				t1.tooLittle = true;
			}
			else {
				printf("	**FAILED**\n");
				t1.tooLittle = false;
			}
			break;
		case minAmount:
			printf("\n  --Test 1.3: Minimum Players:");
			if (initializeGame(numPlayers, k, 100, G) == 0) {
				printf("	**PASSED**\n");
				t1.minAmount = true;
			}
			else {
				printf("	**FAILED**\n");
				t1.minAmount = false;
			}
			break;
		case correctAmount:
			printf("\n  --Test 1.4: Correct Players:");
			if (initializeGame(numPlayers, k, 100, G) == 0) {
				printf("	**PASSED**\n");
				t1.correctAmount = true;
			}
			else {
				printf("	**FAILED**\n");
				t1.correctAmount = false;
			}
			break;
		case maxAmount:
			printf("\n  --Test 1.5: Maximum Players:");
			if (initializeGame(numPlayers, k, 100, G) == 0) {
				printf("	**PASSED**\n");
				t1.maxAmount = true;
			}
			else {
				printf("	**FAILED**\n");
				t1.maxAmount = false;
			}
			break;
		case tooMany:
			printf("\n  --Test 1.6: Too Many Players:");
			if (initializeGame(numPlayers, k, 100, G) == -1) {
				printf("	**PASSED**\n");
				t1.tooMany = true;
			}
			else {
				printf("	**FAILED**\n");
				t1.tooMany = false;
			}
			break;
		default:
			printf("\n  --**Error**--\n");
			t1.error = true;
			break;
		}
	}
	return t1;
}

/*
TEST 2: 

This test could be improved by tested the false conditions in addition to the true conditions.
*/
t2 test2(int *k[], struct gameState *G) {
	int numPlayers, supplyCurse, estateCards, duchyCards, provinceCards;
	int copperCards, silverCards, goldCards, copperAmount;
	t2 t2;
		
	for (numPlayers = 2; numPlayers <= MAX_PLAYERS; numPlayers++) {
		if (initializeGame(numPlayers, k, 100, G) == 0) {
			copperAmount = 60 - (7 * numPlayers);
			supplyCurse = G->supplyCount[curse];
			estateCards = G->supplyCount[estate];
			duchyCards = G->supplyCount[duchy];
			provinceCards = G->supplyCount[province];
			copperCards = G->supplyCount[copper];
			silverCards = G->supplyCount[silver];
			goldCards = G->supplyCount[gold];


			switch (numPlayers)
			{
			case twoPlayer:
				printf("\n  --Test 2.1: Two Players:");
				if (supplyCurse == 10 && (estateCards == 8 && duchyCards == 8 && provinceCards == 8) && copperCards == copperAmount && silverCards == 40 && goldCards == 30) {
					printf("	**PASSED**\n");
					t2.twoPlayer = true;
				}
				else {
					printf("	**FAILED**\n");
					t2.twoPlayer= false;
				}
				break;
			case threePlayer:
				printf("\n  --Test 2.2: Three Players:");
				if (supplyCurse == 20 && (estateCards == 12 && duchyCards == 12 && provinceCards == 12) && copperCards == copperAmount && silverCards == 40 && goldCards == 30) {
					printf("	**PASSED**\n");
					t2.threePlayer = true;
				}
				else {
					printf("	**FAILED**\n");
					t2.threePlayer = false;
				}
				break;
			case fourPlayer:
				printf("\n  --Test 2.3: Four Players:");
				if (supplyCurse == 30 && (estateCards == 12 && duchyCards == 12 && provinceCards == 12) && copperCards == copperAmount && silverCards == 40 && goldCards == 30) {
					printf("	**PASSED**\n");
					t2.fourPlayer = true;
				}
				else {
					printf("	**FAILED**\n");
					t2.fourPlayer= false;
				}
				break;
			default:
				printf("\n  --**Error**--\n");
				t2.error = true;
				break;
			}
		}
		else {
			printf("\n  --**Error**--\n");
			t2.error = true;
		}
	}
	return t2;
}

/*
TEST 3: 

This test could be improved by tested the false conditions in addition to the true conditions.
*/
t3 test3(int *k[], struct gameState *G) {
	int numPlayers;
	t3 t3;

	for (numPlayers = 2; numPlayers <= MAX_PLAYERS; numPlayers++) {
		printf("\n  --Test 3.%d: %d Players--", numPlayers - 1, numPlayers);
		if (initializeGame(numPlayers, k, 100, G) == 0) {
			for (int i = 0; i < numPlayers; i++) {
				printf("\n    -Test 3.%d.%d: %d Players: Player %d:", numPlayers - 1, i+1, numPlayers, i+1);
				if(G->deckCount[i] == 5) {
					printf("	**PASSED**");
					t3.correct = true;
				}
				else {
					printf("	**FAILED**");
					t3.correct = false;
				}
			}
		}
	}

	return t3;
}




bool myAssert() {


}