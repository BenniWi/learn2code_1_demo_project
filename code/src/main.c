#include <stdio.h>
#include <stdlib.h>

#include "library.h"

int main()
{
    long action = 0;

    char *ptr;
    char input1[30];
    char input2[30];

    int continue_loop = 1;

    library lib;
    library_init(&lib);

#if 1
    /* add already some entries to the database for playing around*/
    student const *s = library_add_student(&lib, "max");
    book const *b = library_add_book(&lib, "having_fun");
    library_lend_book(&lib, s, b->id);

    s = library_add_student(&lib, "moritz");
    b = library_add_book(&lib, "how_to_play");
    library_lend_book(&lib, s, b->id);
    b = library_add_book(&lib, "rule_the_world");
    library_lend_book(&lib, s, b->id);

    s = library_add_student(&lib, "lilo");
    b = library_add_book(&lib, "no_way_home");
    library_lend_book(&lib, s, b->id);

    s = library_add_student(&lib, "stitch");
    b = library_add_book(&lib, "kidding around");
    library_lend_book(&lib, s, b->id);

    library_add_student(&lib, "pinky");
#endif

    while (continue_loop)
    {
        printf("\033[4;92m========================\n");
        printf("Choose your library action: \n");
        printf("Print library \t\t[1]\n");
        printf("Add student \t\t[2]\n");
        printf("Add Book \t\t[3]\n");
        printf("Lend book \t\t[4]\n");
        printf("Return book \t\t[5]\n");
        printf("List books for student \t[6]\n");
        printf("Find a book \t\t[7]\n");
        printf("Exit \t\t\t[8]\n");
        printf("========================\033[0m\n");

        printf("Enter your selection: ");
        scanf("%s", input1);
        action = strtol(input1, &ptr, 10);

        switch (action)
        {
            case 0:
                printf("That was not a valid input!\n");
                break;
            case 1:
                library_print(&lib);
                break;
            case 2:
                printf("Enter student name: ");
                {
                    char studentname[STUDENT_MAX_NAME_LENGTH];
                    scanf("%s", studentname);
                    library_add_student(&lib, studentname);
                }
                break;
            case 3:
                printf("Enter book tile: ");
                {
                    char bookname[BOOK_MAX_NAME_LENGTH];
                    scanf("%s", bookname);
                    library_add_book(&lib, bookname);
                }
                break;
            case 4:
                printf("Enter book ID to lend: ");
                scanf("%s", input1);
                printf("Enter student MatrNr: ");
                scanf("%s", input2);
                {
                    unsigned int bookID = (unsigned int)strtol(input1, &ptr, 10);
                    unsigned int MatrNr = (unsigned int)strtol(input2, &ptr, 10);
                    library_lend_book(&lib, library_get_student_4_matrnr(&lib, MatrNr), bookID);
                }
                break;
            case 5:
                printf("Enter book ID to return: ");
                scanf("%s", input1);
                {
                    unsigned int bookID = (unsigned int)strtol(input1, &ptr, 10);
                    library_return_book(&lib, bookID);
                }
                break;
            case 6:
                printf("For which student do you want to know the books: ");
                scanf("%s", input1);
                {
                    unsigned int MatrNr = (unsigned int)strtol(input1, &ptr, 10);
                    library_list_books_4_student(&lib, MatrNr);
                }
                break;
            case 7:
                printf("Which book do you want to find: ");
                scanf("%s", input1);
                {
                    unsigned int bookID = (unsigned int)strtol(input1, &ptr, 10);
                    library_find_book(&lib, bookID);
                }
                break;
            case 8:
                continue_loop = 0;
                break;
            default:
                printf("That was not a valid input!\n");
                break;
        }
    }
}
