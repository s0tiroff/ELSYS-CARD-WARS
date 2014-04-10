#ifndef ___deck___
#define ___deck___

#include "card.h"
#define deck_size 30

struct deck_t {
    struct card_t card[deck_size];
    int top;
};

int push_card(struct card_t card_to_push, struct deck_t *player_deck);
int draw_card(struct deck_t *player_deck, struct card_t *card);
int look_card(struct deck_t player_deck, struct card_t *card);

#endif
