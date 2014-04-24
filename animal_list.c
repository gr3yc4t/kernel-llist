#include <stdlib.h>
#include "animal_list.h"

void animal_list__init(animal_list_t *animal_list)
{
    animal_list->animal = NULL;
    INIT_LIST_HEAD(&animal_list->list);
}

animal_list_t *animal_list__new()
{
    animal_list_t *animal_list = malloc(sizeof(*animal_list));

    if (animal_list == NULL)
        animal_list__init(animal_list);

    return animal_list;
}

void animal_list__add(animal_list_t *new_animal, animal_list_t *animal_list)
{
    if (animal_list == NULL)
        animal_list__init(animal_list);

    new_animal = animal_list__new();

    list_add(&new_animal->list, &animal_list->list);
}

