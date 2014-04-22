#include <stdio.h>
#include "card.h"

void print_card(struct card_t card) {
	printf("%s(%d) (%d|%d)\n", card.name, card.mana_cost, card.atk, card.hp);
}

//returns 0 if both cards are death
//returns 1 if the attacker won returns 2 if the defender won
//returns 3 if both cards are alive
int attack(struct card_t *attacker, struct card_t *defender) {
	defender->hp -= attacker->atk;
    attacker->hp -= defender->atk;
    if(attacker->hp > 0 && defender->hp > 0) {
        return 3;
    } else {
        if(attacker->hp > 0) {
            defender->hp = 0; //causes bugs in play algorithm if the defeated card has negative HP
            return 1;
        } else if(defender->hp > 0) {
            attacker->hp = 0;
            return 2;
        } else {
            defender->hp = 0; //causes bugs in play algorithm if the defeated card has negative HP
            attacker->hp = 0; //causes bugs in play algorithm if the defeated card has negative HP
            return 0;
        }
    }
}

