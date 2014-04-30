#ifndef ___player___
#define ___player___

#include "deck.h"
#include "manapool.h"

#define MAX_HP 30
#define error_card {"0", 0, 0, 0}

struct player_t { 
	char *name;
	int hp;
	struct deck_t deck;
	struct deck_t hand;
	struct manapool_t pool;
};

//inits player stats to 0
void init_player(struct player_t *player);
//printf player: name(HP) (mana) hand
void print_player(struct player_t player);
//changes player's hp with fixed amount
//cannot exceed MAX_HP
void change_hp(struct player_t *player, int hp);
//returns 1 if successful
//returns 0 if failure
//return_card = discarded_card
int discard_card(struct player_t *player, int card, struct card_t *return_card); 
//returns the card you have played if successful 
//return card with 0 hp if failure
struct card_t play_card_from_hand(struct player_t *player, int card);
//adds 1 card into player's hand
void turn_begin(struct player_t *player);

#endif
