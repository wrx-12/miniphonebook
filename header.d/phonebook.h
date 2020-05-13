/************************************************
 * Author = Emmanuel Bentum                     * 
 * Email = emmanuel.bentum@epita.fr             *
 *                                              *
 *          Headfer file of phonebook           *
 *                                              *
 * *********************************************/

#include <stdio.h>
#include <stdlib.h>


#ifndef DEF_PHONEBOOK
#define DEF_PHONEBOOK



 
typedef struct Identity {
    char name[50];
    char number[15];
    char mail[50];
} Identity;


void launch_menu();

void create_phonebook(size_t n);

void add_identity();

void retrieve_identity(int param);

void delete_phonebook();



#endif