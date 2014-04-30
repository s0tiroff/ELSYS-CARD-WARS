#include <stdio.h>
#include "player.h"

int main() {
	struct player_t player;
	struct card_t hineca = {"HINECA", 9, 9, 9};
	struct card_t stela = {"STELA", 9, 9, 9};
	struct card_t card;
	init_player(&player);
	player.deck.top = 30;
	player.deck.card[29] = hineca;
	player.deck.card[27] = hineca;
	turn_begin(&player);
	turn_begin(&player);
	turn_begin(&player);
	turn_begin(&player);
	print_player(player);
	card = play_card_from_hand(&player, 1);
	printf("\nCARD PLAYED: "); 
	print_card(card);
	change_hp(&player, 50);
	printf("player:\n");
	print_player(player);
	return 0;
}
