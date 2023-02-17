#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <stdbool.h>

#include "book.h"
#include "student.h"

#define LIBRARY_MAX_NUM_STUDENTS 5
#define LIBRARY_MAX_NUM_BOOKS 5

typedef struct
{
    student student_list[LIBRARY_MAX_NUM_STUDENTS];
    book book_list[LIBRARY_MAX_NUM_BOOKS];
    student const *lend_list[LIBRARY_MAX_NUM_BOOKS];
} library;

/**
 * @brief initialize the library structure
 *
 * @param l library
 */
void library_init(library *l);

/**
 * @brief add a student to the library database
 *
 * @param l library
 * @param name name of the student
 * @return student const* pointer to the added student, NULL if invalid
 */
student const *library_add_student(library *l, const char name[]);

/**
 * @brief add a book to the library database
 *
 * @param l library
 * @param title title of the book
 * @return book const* pointer to the added book, NULL if invalid
 */
book const *library_add_book(library *l, const char title[]);

/**
 * @brief get the student for a given matrnr
 *
 * @param l library
 * @param MatrNr matrnr of the student to search for
 * @return student const* pointer to the searched student, NULL if invalid
 */
student const *library_get_student_4_matrnr(library *l, unsigned int MatrNr);

/**
 * @brief lend a book from the library to a certain student
 *
 * @param l library
 * @param MatrNr matrnr of the student to lend the book to
 * @param ID book ID to lend
 * @return true if lending the book was successful
 * @return false if lending the book failed
 */
bool library_lend_book(library *l, unsigned int MatrNr, unsigned int ID);

/**
 * @brief return a lend book from a student
 *
 * @param l library
 * @param ID book ID to return
 * @return true if returning the book was successful
 * @return false if returning the book failed
 */
bool library_return_book(library *l, unsigned int ID);

/**
 * @brief find a certain book
 *
 * @param l library
 * @param ID book ID to find
 * @return student const* pointer to the student who lend the book, NULL if not successful
 */
student const *library_find_book(library const *l, unsigned int ID);

/**
 * @brief print all available books to stdout
 *
 * @param l library
 */
void library_list_books(library const *l);

/**
 * @brief print all available students to the stdout
 *
 * @param l library
 */
void library_list_students(library const *l);

/**
 * @brief list all books a certain student has lent
 *
 * @param l library
 * @param MatrNr matrnr of the student to search for
 */
void library_list_books_4_student(library const *l, unsigned int MatrNr);

/**
 * @brief print the whole library content to the stdout
 *
 * @param l library
 */
void library_print(library const *l);

#endif /* LIBRARY_H_ */
