#ifndef ANIMAL_LIST_H
#define ANIMAL_LIST_H

#include <stdint.h>
#include "dllist.h"

#define MAX_WIDTH 1280
#define MAX_HEIGHT 720

#define MAX_ANIMALS 4
#define MAX_MOVES 20
#define MAX_ATTACKS 10
#define MAX_SURROUNDING_RADIUS 1
#define MAX_LIONS 1
#define MAX_BEARS 1
#define MAX_STONES 1
#define MAX_WOLVES 1

typedef enum moves {UP, DOWN, RIGHT, LEFT, HOLD, END_MOVE} moves_t;

// PAPER wins ROCK, ROCK wins SCISSORS, SCISSORS win PAPER,
typedef enum attacks {ROCK, PAPER, SCISSORS, SUICIDE, END_ATTACK} attacks_t;

// Kind of animals that can be used.
typedef enum animal_kind {LION, BEAR, STONE, WOLF, END_ANIMAL} animal_kind_t;

typedef struct animal
{
    int8_t print_type;
    animal_kind_t kind;
    int32_t x;
    int32_t y;
    moves_t moves[MAX_MOVES];
    attacks_t attacks[MAX_ATTACKS];
    attacks_t attack;
    uint8_t winner;
    uint8_t looser;
    uint8_t isdead;
}animal_t;

typedef struct animal_list
{
    struct list_head list;
    animal_t animal;
}animal_list_t;


void animal_list__init(animal_list_t *);

void populate_animal(animal_t *);
animal_list_t *animal_list__new(void);

void animal_list__add(animal_list_t *, animal_list_t *);
void animal_list__add_tail(animal_list_t *, animal_list_t *);


#endif /* ANIMAL_LIST_H */
