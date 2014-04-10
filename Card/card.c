#include "card.h"

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

