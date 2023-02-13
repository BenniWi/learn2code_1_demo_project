#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "book.h"
#include "student.h"

#define LIBARY_MAX_NUM_STUDENTS 10
#define LIBARY_MAX_NUM_BOOKS 10

typedef struct
{
    student student_list[LIBARY_MAX_NUM_STUDENTS];
    book book_list[LIBARY_MAX_NUM_BOOKS];
    student const *lend_list[LIBARY_MAX_NUM_BOOKS];
} library;

void library_init(library *l);

student const *library_add_student(library *l, const char name[]);

book const *library_add_book(library *l, const char title[]);

void library_lend_book(library *l, student const *s, unsigned int ID);

void library_return_book(library *l, unsigned int ID);

student const *library_find_book(library const *l, unsigned int ID);

void library_list_books(library const *l);

void library_list_students(library const *l);

void library_list_books_4_student(library const *l, unsigned int MatrNr);

void libary_print(library const *l);

#endif /* LIBRARY_H_ */
