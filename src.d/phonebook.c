/************************************************
 * Author = Emmanuel Bentum                     * 
 * Email = emmanuel.bentum@epita.fr             *
 *                                              *
 *          source file of phonebook            *
 *                                              *
 * *********************************************/

#include "../header.d/phonebook.h"
#include <stdlib.h>
#include <stdio.h>

/****
 * * Variable Space :
****/
    Identity *phonebook = NULL;
    int count_id=0;
//***

void launch_menu() {
    
    int menu_choice = -1, size_phonebook=-1,  search_choice=-1;

    
    
    printf("*************************************************\n"
               "*\t\t\t\t\t\t*\n"
               "*\t\t Mini Phonebook \t\t*\n"
               "*\t\t\t\t\t\t*\n"
              "*************************************************\n");
    do {

        printf("1. Create phonebook \n"
                "2. Add a contact \n"
                "3. Search a contact \n"
                "4. Delete phonebook\n"
                "0. Quit \n"
                "Make a choice ==> ");
        scanf("%d",&menu_choice);
        printf("\n\n");
    }while(menu_choice < 0 && menu_choice > 4);

    
    switch(menu_choice) {
        case 0: 
            exit(0);
            break;
        case 1:
            do {
                printf("Give size of phonebook > 0 :: ");
                scanf("%d",&size_phonebook);
            }while(size_phonebook < 1);
            
            create_phonebook(size_phonebook);
            break;

        case 2:
            if(phonebook == NULL) 
                printf("Create a phonebook first\n");
            else
                if (count_id < size_phonebook)
                    add_identity();
                else
                    printf("The phonebook is full\n");
            break;

        case 3:
            do {
                printf("Search by:\n"
                       "1.Name\n"
                       "2.Number\n"
                       "3.Mail\n");
                scanf("%d",&search_choice);
            }while(search_choice < 1 || search_choice > 3);
            
            retrieve_identity(search_choice);
            break;
        case 4:
            delete_phonebook();
            break;
        default:
            break;
    }
}


void create_phonebook(size_t n) {
    // based on the size , we have to resize array phonebook
    phonebook =realloc(phonebook, n*sizeof(Identity));
    if(phonebook == NULL)
        perror("Error! the phonebook has not been created.\n"
                "check the size given \n");
    else
    {
        printf("Phonebook created\n\n");
    }
    launch_menu();
}


int value_in_array(char *input, int id){
    int i;
    if (id == 1){
        for(i=0; i<count_id; i++) {
            if(*(phonebook+i)->name == *input)
                return 0;
        }
    }else if (id == 2){
        for(i=0; i<count_id; i++) {
            if(*(phonebook+i)->number == *input)
                return 0;
        }
    }else if( id == 3){
        for(i=0; i<count_id; i++) {
            if(*(phonebook+i)->mail == *input)
                return 0;
        }
    }
    else{}
    return 1;
}


void add_identity(){
    char input[50];
    int result=-1;
                printf("Enter name ==> ");
                fgets(input, sizeof(input),stdin);
                result = value_in_array(input, 1);
                if(result == 0) {
                    printf("Contact exists!");
                    exit(0);
                }
                printf("\nEnter number ==> ");
                fgets(input, sizeof(input),stdin);
                result = value_in_array(input, 2);
                if(result == 0) {
                    printf("Contact exists!");
                    exit(0);
                }
                printf("\nEnter mail ==> ");
                fgets(input, sizeof(input),stdin);
                result = value_in_array(input, 3);
                if(result == 0) {
                    printf("Contact exists!");
                    exit(0);
                }
                printf("\n");
                count_id++;
                printf("Contact created! \n");

    launch_menu();
}


void  retrieve_identity(int param){
    char pam[50]; 
    int i;
    if (param == 1) {
        printf("Name ==> ");
        fgets(pam,sizeof(pam),stdin);
        for (i=0; i<=count_id; i++) {
            if (*(phonebook+i)->name == *pam){
                printf("CONTACT FOUND!! \n");
                printf("Name : "); puts((phonebook+i)->name);
                printf("Number : "); puts((phonebook+i)->number);
                printf("mail: "); puts((phonebook+i)->mail);
                break;
            }
        }
    }
    else if(param == 2){
        printf("Number ==> ");
        fgets(pam,sizeof(pam),stdin);
        for (i=0; i<count_id; i++){
            if (*(phonebook+i)->number == *pam){
               printf("CONTACT FOUND!! \n");
                printf("Name : "); puts((phonebook+i)->name);
                printf("Number : "); puts((phonebook+i)->number);
                printf("mail: "); puts((phonebook+i)->mail);
                break;
            }
        }
    }
    else if(param == 3){
        printf("Email ==> ");
        fgets(pam,sizeof(pam),stdin);
        for (i=0; i<count_id; i++) {
        if (*(phonebook+i)->mail == *pam){
            printf("CONTACT FOUND!! \n");
                printf("Name : "); puts((phonebook+i)->name);
                printf("Number : "); puts((phonebook+i)->number);
                printf("mail: "); puts((phonebook+i)->mail);
                break;
        }
    }
    }
    else{}
    launch_menu();
}


void delete_phonebook() {
    free(phonebook);
    phonebook = NULL;   
    launch_menu();
}