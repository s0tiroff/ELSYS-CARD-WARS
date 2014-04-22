#include <stdio.h>
#include "deck.h"

int main() {
	struct card_t card = {"Random", 1, 2, 3};
	struct card_t card_buffer;
	struct deck_t deck;
	
	init_deck(&deck);
	printf("top=%d\n", deck.top); //init_deck test
	print_card(deck.card[6]); //init_deck test
	deck.card[0] = card;
	deck.card[1] = card;
	deck.card[2] = card;
	deck.top = 3;
	draw_card(&deck, &card_buffer);
	print_card(card_buffer);
	card_buffer.atk = 100;
	push_card(card_buffer, &deck);
	printf("deck.top = %d / 3\n", deck.top);
	look_card(deck, &card_buffer);
	print_card(card_buffer);
	
	
	return 0;
}
