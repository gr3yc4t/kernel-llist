#include "animal_list.h"

void animal_list__init(animal_list_t *list)
{
    list->animal = NULL;
    INIT_LIST_HEAD(&list->entries);
}

animal_list_t *animal_list__new()
{
    animal_list_t *animal_list = malloc(sizeof(*animal_list));

    if (animal_list == NULL)
        animal_list__init(animal_list);

    return animal_list;
}

animal_list_t *animal_list__new_default()
{
    animal_list_t *animal_list = animal_list__new();

    if (animal_list && animal_list__add_default(animal_list))
    {
        animal_list__delete(animal_list);
        animal_list = NULL;
    }

    return animal_list;
}


