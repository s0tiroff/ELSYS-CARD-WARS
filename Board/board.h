#ifndef ___BOARD___
#define ___BOARD___

#include "player.h"
#define border_count 60

struct board_t {
	struct card_t slot[2][5];
	struct player_t pl[2];	
};

//init board to 0
void init_board(struct board_t *board);
//prints fixed amount of chars
void print_border(char ch);
//prints cards on field[side]
void print_field(struct board_t board, int side);
//prints the board
void print_board(struct board_t board);
//returns 1 if can play card
//returns 0 if can't play card
int is_slot_empty(struct board_t board, int side, int corr);
//returns 1 if successful
//returns 0 if failure
int play_card(struct board_t *board, struct card_t card, int side);
//cards on board[side] attacks 
//if there are no enemies pl[!side] takes the dmg
void turn_end(struct board_t *board, int side);
//returns 0 if there is no winner
//returns 1 if player1 is the winner
//returns 2 if player2 is the winner
int winner(struct board_t board);
//returns 1 if successfuly loaded
//returns 0 if loading failed
int load_deck_from_file(struct board_t *board, int side, char *filename);
//init player to starting stats
//reads names
//load decks
void game_begin(struct board_t *board, int *side);

#endif
