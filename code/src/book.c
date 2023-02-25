#include "book.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void book_init(book *const b_ptr, const char title[BOOK_MAX_NAME_LENGTH])
{
    if (b_ptr == NULL)
    {
        printf("\033[4;33mbook init: invalid data\n\033[0m");
    }
    else
    {
        b_ptr->id = rand();  // Returns a pseudo-random integer between 0 and RAND_MAX.
        // instead of using a for loop to copy the array, we can use strncpy
        strncpy(b_ptr->title, title, strlen(title) + 1);
    }
}

void book_print(book const *const b_ptr)
{
    if (b_ptr == NULL)
    {
        printf("\033[4;33mbook print: invalid data\n\033[0m");
    }
    else
    {
        printf("=====================\n");
        printf("Book: \n");
        // print the name in a colored output
        // you can find a lot of details here: https://stackoverflow.com/a/33206814
        // \033[ to start ANSI escape
        // 4 is underlined, 35 is magenta, 0 deletes all formats to return to default
        printf("title: \033[4;36m%s\033[0m\n", b_ptr->title);
        printf("ID: %u\n", b_ptr->id);
        printf("=====================\n");
    }
}
