#include <stdlib.h>
#include <string.h>
#include "animal_list.h"
#include "utils.h"

void animal_list__init(animal_list_t *animal_list)
{
    memset(&animal_list->animal, 0, sizeof(animal_t));
    INIT_LIST_HEAD(&animal_list->list);
}

void populate_animal(animal_t *animal)
{
    init_seed_srand();

    animal->kind = rand() % END_ANIMAL;

    // Initialize moves array
    for (uint32_t i = 0;i<MAX_MOVES;i++)
        animal->moves[i] = END_MOVE;

    // Initialize attacks array
    for (uint32_t i = 0;i<MAX_ATTACKS;i++)
        animal->attacks[i] = END_ATTACK;

    switch(animal->kind)
    {
        case LION:
            animal->print_type = 'L';

            animal->moves[0] = DOWN;
            animal->moves[1] = RIGHT;
            animal->attacks[0] = PAPER;
            animal->attacks[1] = SCISSORS;

            break;
        case BEAR:
            animal->print_type = 'B';

            animal->moves[0] = DOWN;
            animal->moves[1] = DOWN;
            animal->moves[2] = DOWN;
            animal->moves[3] = DOWN;
            animal->moves[4] = RIGHT;
            animal->moves[5] = RIGHT;
            animal->moves[6] = RIGHT;
            animal->moves[7] = RIGHT;
            animal->moves[8] = UP;
            animal->moves[9] = UP;
            animal->moves[10] = UP;
            animal->moves[11] = UP;
            animal->moves[12] = LEFT;
            animal->moves[13] = LEFT;
            animal->moves[14] = LEFT;
            animal->moves[15] = LEFT;
            animal->attacks[0] = PAPER;

            break;
        case STONE:
            animal->print_type = 'S';

            animal->moves[0] = HOLD;
            animal->attacks[0] = ROCK;

            break;
        case WOLF:
            animal->print_type = 'W';

            // Random moves
            for (uint32_t i = 0;i < MAX_MOVES;i++)
            {
                init_seed_srand();

                animal->moves[i] = rand() % END_MOVE;
            }

            // Random attacks
            for (uint32_t i = 0;i < MAX_ATTACKS;i++)
            {
                init_seed_srand();

                animal->attacks[i] = rand() % END_ATTACK;
            }

            break;
        case END_ANIMAL:
            break;
    }

    init_seed_srand();

    animal->x = MAX_WIDTH * ((double)rand()/RAND_MAX);
    animal->y = MAX_HEIGHT * ((double)rand()/RAND_MAX);

    animal->attack = END_ATTACK;
    animal->winner = 0;
    animal->looser = 0;
    animal->isdead = 0;

}

animal_list_t *animal_list__new()
{
    animal_list_t *animal_list = (animal_list_t *)malloc(sizeof(animal_list_t));

    if (animal_list == NULL)
        animal_list__init(animal_list);

    populate_animal(&animal_list->animal);

    return animal_list;
}

void animal_list__add(animal_list_t *new_animal, animal_list_t *animal_list)
{
    if (animal_list == NULL)
        animal_list = animal_list__new();

    new_animal = animal_list__new();

    list_add(&new_animal->list, &animal_list->list);
}

void animal_list__add_tail(animal_list_t *new_animal, animal_list_t *animal_list)
{
    if (animal_list == NULL)
        animal_list = animal_list__new();

    new_animal = animal_list__new();

    list_add_tail(&new_animal->list, &animal_list->list);
}

