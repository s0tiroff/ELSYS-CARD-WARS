#include <stdio.h>
#include "deck.h"

int main() {
	struct card_t card = {"Random", 1, 2, 3};
	struct card_t card_buffer;
	struct deck_t deck;

	deck.card[0] = card;
	deck.card[1] = card;
	deck.card[2] = card;
	deck.top = 3;
	draw_card(&deck, &card_buffer);
	printf("deck.top = %d / 3 card.name = %s card.atk = %d\n", deck.top,card_buffer.name, card_buffer.atk);
	card_buffer.atk = 100;
	push_card(card_buffer, &deck);
	printf("deck.top = %d / 3\n", deck.top);
	look_card(deck, &card_buffer);
	printf("deck.top = %d / 3 card.name = %s card.atk = %d\n", deck.top,card_buffer.name, card_buffer.atk);
	
	
	return 0;
}
