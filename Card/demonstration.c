#include <stdio.h>
#include "card.h"

int main() {
	struct card_t card1 = {"Skarner", 0, 5, 6};
	struct card_t card2 = {"Shyvana", 0, 3, 4};
	struct card_t card3 = {"Renekton", 0, 6, 18};
	struct card_t card4 = {"Rammus", 0, 3, 10};
	struct card_t card5 = {"Rumble", 0, 15, 4};
	
	printf("winner (Renekton vs Shyvana): %d\n", attack(&card3, &card2));
	print_card(card3);
	print_card(card2);
	printf("\nwinner (Skarner vs Renekton): %d\n", attack(&card1, &card3));
	print_card(card1);
	print_card(card3);
	printf("\nwinner (Renekton vs Rammus): %d\n", attack(&card3, &card4));	
	print_card(card3);
	print_card(card4);
	printf("\nwinner (Renekton vs Rumble): %d\n", attack(&card3, &card5));
	print_card(card3);
	print_card(card5);
	
 
	return 0;
}
