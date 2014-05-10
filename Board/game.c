#include <stdio.h>
#include "board.h"

int main() {
	struct board_t board;
	int side;
	int card;
	char ch;
	game_begin(&board, &side);
	while( !winner(board) ) {
		turn_begin(&board.pl[side]);
		do {
			system("clear");
			printf("%s is on turn!\n", board.pl[side].name);
			print_board(board);
			printf("%s is on turn (-1 to end the turn): ", board.pl[side].name);
			scanf("%d", &card);
			if( card != -1) {			
				if( card > 0 && card <= board.pl[side].hand.top ) {
					card--;
					if( can_put_card(board.pl[side].hand.card[card], board.pl[side].pool) ) {
						if( play_card(&board, play_card_from_hand(&board.pl[side], card), side) ) {
							system("clear");
							print_board(board);
						} else {
							printf("There no free slots on the board!\n");
							ch = getchar();
							ch = getchar();
						} 
					} else {
						printf("Not enough mana!\n");
						ch = getchar();
						ch = getchar();
					}
				} else {
					printf("Invalid card!\n");
					ch = getchar();
					ch = getchar();
				}
			}
		} while(card != -1);
		printf("Press any ket to continue...\n");
		ch = getchar();
		ch = getchar();
		turn_end(&board, side);
		side = !side;
	}
	system("clear");
	if(winner(board) == 1) {
		printf("%s won the game!\n", board.pl[0].name);
	} else {
		printf("%s won the game!\n", board.pl[1].name);
	}
	return 0;
}