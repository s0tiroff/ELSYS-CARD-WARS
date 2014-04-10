#ifndef ___manapool___
#define ___manapool___

#include "card.h"

struct manapool_t {
    int current_mp;
    int max_mp;
};

int use_mana(struct manapool_t *pool, int amount);
void gain_mana(struct manapool_t *pool, int gain);
int can_put_card(struct card_t card, struct manapool_t pool);

#endif
