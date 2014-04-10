#include <stdio.h>
#include "card.h"

int main() {
	struct card_t card1 = {"Skarner", 0, 5, 6};
	struct card_t card2 = {"Shyvana", 0, 3, 4};
	struct card_t card3 = {"Renekton", 0, 6, 18};
	struct card_t card4 = {"Rammus", 0, 3, 10};
	struct card_t card5 = {"Rumble", 0, 15, 4};
	
	printf("winner (Renekton vs Shyvana): %d\n", attack(&card3, &card2));
	printf("Renekton: %d / %d hp\n", card3.hp, 18);
	printf("Shyvana: %d / %d hp\n", card2.hp, 4);
	printf("\nwinner (Skarner vs Renekton): %d\n", attack(&card1, &card3));
	printf("Skarner: %d / %d hp\n", card1.hp, 6);
	printf("Renekton: %d / %d hp\n", card3.hp, 18);
	printf("\nwinner (Renekton vs Rammus): %d\n", attack(&card3, &card4));	
	printf("Renekton: %d / %d hp\n", card3.hp, 18);
	printf("Rammus: %d / %d hp\n", card4.hp, 10);
	printf("\nwinner (Renekton vs Rumble): %d\n", attack(&card3, &card5));
	printf("Renekton: %d / %d hp\n", card3.hp, 18);
	printf("Rumble: %d / %d hp\n", card5.hp, 4);
	
 
	return 0;
}
