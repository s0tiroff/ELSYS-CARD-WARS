#ifndef ___card___
#define ___card___

struct card_t {
    char *name;
    int mana_cost;
    int atk;
    int hp;
};

void print_card(struct card_t card); 
int attack(struct card_t *attacker, struct card_t *defender);

#endif
