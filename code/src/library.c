#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void library_init(library *const l)
{
    if (l == NULL)
    {
        printf("\033[4;33mlibrary init: invalid data\n\033[0m");
    }
    else
    {
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_BOOKS; ++i)
        {
            l->book_list[i].id = 0;
            strncpy(l->book_list[i].title, "", 1);
        }

        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_STUDENTS; ++i)
        {
            l->student_list[i].matrnr = 0;
            strncpy(l->student_list[i].name, "", 1);
        }

        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_BOOKS; ++i)
        {
            l->lend_list[i] = NULL;
        }
    }
}

student const *library_add_student(library *const l, const char name[])
{
    if (l == NULL)
    {
        printf("\033[4;33madd student: invalid data\n\033[0m");
    }
    else
    {
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_STUDENTS; ++i)
        {
            if (l->student_list[i].matrnr == 0)
            {
                student_init(&(l->student_list[i]), name);
                return &(l->student_list[i]);
            }
        }
        printf("Adding a student was not possible. Maximum amount of students reached\n");
    }
    return NULL;
}

book const *library_add_book(library *const l, const char title[])
{
    if (l == NULL)
    {
        printf("\033[4;33madd book: invalid data\n\033[0m");
    }
    else
    {
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_BOOKS; ++i)
        {
            if (l->book_list[i].id == 0)
            {
                book_init(&(l->book_list[i]), title);
                return &(l->book_list[i]);
            }
        }
        printf("Adding a book was not possible. Maximum amount of books reached\n");
    }
    return NULL;
}

student const *library_get_student_4_matrnr(library *l, unsigned int MatrNr)
{
    if (l == NULL)
    {
        printf("\033[4;33mget student 4 matrnr: invalid data\n\033[0m");
    }
    else
    {
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_STUDENTS; ++i)
        {
            if (l->student_list[i].matrnr == MatrNr)
            {
                return &(l->student_list[i]);
            }
        }
        printf("Finding a student for the MatrNr=%i was not possible\n", MatrNr);
    }
    return NULL;
}

bool library_lend_book(library *const l, const unsigned int MatrNr, const unsigned int ID)
{
    bool success = false;
    if (l == NULL)
    {
        printf("\033[4;33mlend book: invalid data\n\033[0m");
    }
    else
    {
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_BOOKS; ++i)
        {
            if (l->book_list[i].id == ID)
            {
                if (l->lend_list[i] == NULL)
                {
                    student const *const s = library_get_student_4_matrnr(l, MatrNr);
                    l->lend_list[i] = s;
                    success = true;
                }
                else
                {
                    printf("Book with ID=%i is already lent by student:\n", ID);
                    student_print(l->lend_list[i]);
                }
                return success;
            }
        }
        printf("Can not lend book with ID=%i. It does not exist.\n", ID);
    }
    return success;
}

bool library_return_book(library *const l, const unsigned int ID)
{
    bool success = false;
    if (l == NULL)
    {
        printf("\033[4;33mreturn book: invalid data\n\033[0m");
    }
    else
    {
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_BOOKS; ++i)
        {
            if (l->book_list[i].id == ID)
            {
                if (l->lend_list[i] == NULL)
                {
                    printf("Can not return book with ID=%i. It is already lent\n", ID);
                }
                else
                {
                    l->lend_list[i] = NULL;
                    success = true;
                }
                return success;
            }
        }
        printf("Can not return book with ID=%i. It does not exist.\n", ID);
    }
    return success;
}

student const *library_find_book(library const *const l, const unsigned int ID)
{
    unsigned int found = 0;
    if (l == NULL)
    {
        printf("\033[4;33mfind book: invalid data\n\033[0m");
    }
    else
    {
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_BOOKS; ++i)
        {
            if (l->book_list[i].id == ID)
            {
                found = 1;
                if (l->lend_list[i] == NULL)
                {
                    printf("The book with ID %i is not lent by any student.\n", ID);
                }
                else
                {
                    printf("The book with ID %i is lent by student: \n", ID);
                    student_print(l->lend_list[i]);
                    return l->lend_list[i];
                }
            }
        }
        if (found == 0)
        {
            printf("Couldn't find the book with ID=%i\n", ID);
        }
    }
    return NULL;
}

void library_list_books(library const *const l)
{
    if (l == NULL)
    {
        printf("\033[4;33mlist books: invalid data\n\033[0m");
    }
    else
    {
        printf("^^^^^^^^^^^^^^^^^^\n");
        printf("Library - Listing Books\n");
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_BOOKS; ++i)
        {
            if (l->book_list[i].id != 0)
            {
                book_print(&l->book_list[i]);
            }
        }
        printf("^^^^^^^^^^^^^^^^^^\n");
    }
}

void library_list_students(library const *const l)
{
    if (l == NULL)
    {
        printf("\033[4;33mInvalid data\n\033[0m");
    }
    else
    {
        printf("^^^^^^^^^^^^^^^^^^\n");
        printf("Library - Listing Students\n");
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_STUDENTS; ++i)
        {
            if (l->student_list[i].matrnr != 0)
            {
                student_print(&l->student_list[i]);
            }
        }
        printf("^^^^^^^^^^^^^^^^^^\n");
    }
}

void library_list_books_4_student(library const *const l, const unsigned int MatrNr)
{
    if (l == NULL)
    {
        printf("\033[4;33mlist books 4 student: invalid data\n");
    }
    else
    {
        printf("$$$$$$$$$$$$$$$$$$$$\n");
        printf("Printing all lend books for student with MatrNr=%i\n", MatrNr);
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_BOOKS; ++i)
        {
            if ((l->lend_list[i] != NULL) && (l->lend_list[i]->matrnr == MatrNr))
            {
                book_print(&l->book_list[i]);
            }
        }
        printf("$$$$$$$$$$$$$$$$$$$$\n");
    }
}

void library_print(library const *const l)
{
    if (l == NULL)
    {
        printf("\033[4;33mlibrary print: invalid data\n\033[0m");
    }
    else
    {
        printf("***********************\n");
        printf("Library: \n");
        library_list_books(l);
        library_list_students(l);
        printf("***********************\n");
    }
}
