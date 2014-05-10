#include <stdio.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "board.h"


void init_board(struct board_t *board) {
	int corr;
	for(corr = 0; corr < 5; corr++) {
		board->slot[0][corr].hp = 0;
		board->slot[1][corr].hp = 0;
	}
	init_player(&board->pl[0]);
	init_player(&board->pl[1]);
}

void print_border(char ch) {
	int i;
	for(i = 0; i < border_count; i++) {
		printf("%c", ch);
	}
	printf("\n");
}

void print_field(struct board_t board, int side) {
	int corr;
	printf("#");
	for(corr = 0; corr < 5; corr++) {
		if( !is_slot_empty(board, side, corr) ) {
			printf("   %d|%d   #", board.slot[side][corr].atk, board.slot[side][corr].hp);
		} else {
			printf("         #");
		}
	}
	printf("\n");
}

void print_board(struct board_t board) {	
	print_player(board.pl[0]);
	print_border('_');
	printf("\n");
	print_hand(board.pl[0]);
	print_border('#');
	printf("\n");
	print_field(board, 0);
	printf("\n");
	print_field(board, 1);
	printf("\n");
	print_border('#');
	print_hand(board.pl[1]);
	print_border('_');
	printf("\n");
	print_player(board.pl[1]);	
}

int is_slot_empty(struct board_t board, int side, int corr) {
	return board.slot[side][corr].hp > 0 ? 0 : 1;
}

int play_card(struct board_t *board, struct card_t card, int side) {
	int corr;
	for(corr = 0; corr < 5; corr++) {
		if( is_slot_empty(*board, side, corr) ) {
			board->slot[side][corr] = card;
			return 1;
		}
	}
	return 0;
}

void turn_end(struct board_t *board, int side) {
	int corr;
	for(corr = 0; corr < 5; corr++) {
		if( !is_slot_empty(*board, side, corr) ) {
			if( !is_slot_empty(*board, !side, corr) ) {
				attack(&board->slot[side][corr], &board->slot[!side][corr]);
			} else {
				board->pl[!side].hp -= board->slot[side][corr].atk;
			}
		}
	}
}

int winner(struct board_t board) {
	if(board.pl[0].hp > 0 && board.pl[1].hp > 0) {
		return 0;
	} else if(board.pl[0].hp > 0) {
		return 1;
	} else {
		return 2;
	}
}

int load_deck_from_file(struct board_t *board, int side, char *filename) {
	FILE *fp;
	char str[1800];
	char *buff;
	fp = fopen(filename, "r");
	if (fp == NULL) return 0;
	while( fgets(str, 1800, fp) ) {
		buff = strtok(str, ",");
		sscanf(buff, "%s", board->pl[side].deck.card[board->pl[side].deck.top].name);
		buff = strtok(NULL, ",");
		sscanf(buff, "%d", &board->pl[side].deck.card[board->pl[side].deck.top].mana_cost);	
		buff = strtok(NULL, ",");
		sscanf(buff, "%d", &board->pl[side].deck.card[board->pl[side].deck.top].atk);
		buff = strtok(NULL, ",");
		sscanf(buff, "%d", &board->pl[side].deck.card[board->pl[side].deck.top].hp);
		board->pl[side].deck.top++;	
	} 	
	fclose(fp);
	return 1;
}

void game_begin(struct board_t *board, int *side) {
	char filename[30];
	char ch = '0';	
	int dice1, dice2;
	srand(time(NULL));
	init_board(board);
	system("clear");
	printf("Enter player1's name: ");
	scanf("%s", board->pl[0].name);
	printf("Enter player2's name: ");
	scanf("%s", board->pl[1].name);
	board->pl[0].hp = MAX_HP;
	board->pl[1].hp = MAX_HP;
	printf("%s's is choosing deck: ", board->pl[0].name);
	scanf("%s", filename);
	while( !load_deck_from_file(board, 0, filename) ) {
		printf("(invalid file name) %s's is choosing deck: ", board->pl[0].name);
		scanf("%s", filename);
	}
	printf("%s's is choosing deck: ", board->pl[1].name);
	scanf("%s", filename);
	while( !load_deck_from_file(board, 1, filename) ) {
		printf("(invalid file name) %s's is choosing deck: ", board->pl[1].name);
		scanf("%s", filename);
	}
	system("clear");
	do {
		dice1 = rand() % 6 + 1;
		dice2 = rand() % 6 + 1;
		printf("%s threw %d out of 6!\n", board->pl[0].name, dice1);
		printf("%s threw %d out of 6!\n\n", board->pl[1].name, dice2);
	} while(dice1 == dice2);
	if(dice1 > dice2) {
		printf("%s will begin first!\n", board->pl[0].name);
		*side = 0;
	} else {
		printf("%s will begin first!\n", board->pl[1].name);
		*side = 1;
	}
	printf("Press any key to continue...\n");
	ch = getchar();
	ch = getchar();
	system("clear");
}

