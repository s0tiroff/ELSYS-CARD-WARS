#include <stdio.h>
#include "manapool.h"

int main() {
	struct manapool_t pool;
	struct card_t card = {"Hineca", 6, 7, 7};

	init_manapool(&pool);
	printf("mana: %d / %d\n", pool.current_mp, pool.max_mp); //test init_manapool
	pool.max_mp = 10;
	gain_mana(&pool, 100);
	printf("mana: %d / %d\n", pool.current_mp, pool.max_mp);
	if( can_put_card(card, pool) ) {
		use_mana(&pool, card.mana_cost);
		printf("mana: %d / %d\n", pool.current_mp, pool.max_mp);
	} else {
		printf("Not enough mana\n");
	}
	if( can_put_card(card, pool) ) {
		use_mana(&pool, card.mana_cost);
		printf("mana: %d / %d\n", pool.current_mp, pool.max_mp);
	} else {
		printf("Not enough mana\n");
	}

	return 0;
}
