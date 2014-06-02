#ifndef ___card___
#define ___card___

#define max_chars_in_card_name 30

struct card_t {
    char name[max_chars_in_card_name];
    int mana_cost;
    int atk;
    int hp;
};

//printf card: name(cost) (atk|hp)
void print_card(struct card_t card); 

//returns 0 if both cards are death
//returns 1 if the attacker won returns 2 if the defender won
//returns 3 if both cards are alive
int attack(struct card_t *attacker, struct card_t *defender);

#endif
