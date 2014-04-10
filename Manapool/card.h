#ifndef ___card___
#define ___card___

#define card_name_size 30

struct card_t {
    char name[card_name_size];
    int mana_cost;
    int atk;
    int hp;
};

int attack(struct card_t *attacker, struct card_t *defender);

#endif
