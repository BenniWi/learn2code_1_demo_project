#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void student_init(student *const s, const char name[])
{
    if (s == NULL)
    {
        printf("Invalid data\n");
    }
    else
    {
        s->matrnr = rand();  // Returns a pseudo-random integer between 0 and RAND_MAX.
        // instead of using a for loop to copy the array, we can use strncpy
        strncpy(s->name, name, strlen(name) + 1);
    }
}

void student_print(student const *const s)
{
    if (s == NULL)
    {
        printf("Invalid data\n");
    }
    else
    {
        printf("=====================\n");
        printf("Student: \n");
        // print the name in a colored output
        // you can find a lot of details here: https://stackoverflow.com/a/33206814
        // \033[ to start ANSI escape
        // 4 is underlined, 35 is magenta, 0 deletes all formats to return to default
        printf("name: \033[4;35m%s\033[0m\n", s->name);
        printf("MatrNr: %u\n", s->matrnr);
        printf("=====================\n");
    }
}
