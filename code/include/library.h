#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <stdbool.h>

#include "book.h"
#include "student.h"

#define LIBRARY_MAX_NUM_STUDENTS 5
#define LIBRARY_MAX_NUM_BOOKS 5

typedef struct
{
    /**
     * @brief array of students. This is the storage for all students
     */
    student student_list[LIBRARY_MAX_NUM_STUDENTS];
    /**
     * @brief array of books. This is the storage for all books
     */
    book book_list[LIBRARY_MAX_NUM_BOOKS];
    /**
     * @brief the lend_list has the same length as the amount of books.
     *        If a book is lend, the corresponding entry of the book
     *        contains a pointer to the student who lent the book.
     *        If the book is not lent, the entry in the array is NULL
     */
    student const *lend_list[LIBRARY_MAX_NUM_BOOKS];
} library;

/**
 * @brief initialize the library structure
 *
 * @param lib library
 */
void library_init(library *lib);

/**
 * @brief add a student to the library database
 *
 * @param lib library
 * @param name name of the student
 * @return student const* pointer to the added student, NULL if invalid
 */
student const *library_add_student(library *lib, const char name[]);

/**
 * @brief add a book to the library database
 *
 * @param lib library
 * @param title title of the book
 * @return book const* pointer to the added book, NULL if invalid
 */
book const *library_add_book(library *lib, const char title[]);

/**
 * @brief get the student for a given matrnr
 *
 * @param lib library
 * @param matrnr matrnr of the student to search for
 * @return student const* pointer to the searched student, NULL if invalid
 */
student const *library_get_student_4_matrnr(library *lib, unsigned int matrnr);

/**
 * @brief lend a book from the library to a certain student
 *
 * @param lib library
 * @param matrnr matrnr of the student to lend the book to
 * @param book_id book book_id to lend
 * @return true if lending the book was successful
 * @return false if lending the book failed
 */
bool library_lend_book(library *lib, unsigned int matrnr, unsigned int book_id);

/**
 * @brief return a lend book from a student
 *
 * @param lib library
 * @param book_id book book_id to return
 * @return true if returning the book was successful
 * @return false if returning the book failed
 */
bool library_return_book(library *lib, unsigned int book_id);

/**
 * @brief find a certain book
 *
 * @param lib library
 * @param book_id book book_id to find
 * @return student const* pointer to the student who lend the book, NULL if not successful
 */
student const *library_find_book(library const *lib, unsigned int book_id);

/**
 * @brief print all available books to stdout
 *
 * @param lib library
 */
void library_list_books(library const *lib);

/**
 * @brief print all available students to the stdout
 *
 * @param lib library
 */
void library_list_students(library const *lib);

/**
 * @brief list all books a certain student has lent
 *
 * @param lib library
 * @param matrnr matrnr of the student to search for
 */
void library_list_books_4_student(library const *lib, unsigned int matrnr);

/**
 * @brief print the whole library content to the stdout
 *
 * @param lib library
 */
void library_print(library const *lib);

#endif /* LIBRARY_H_ */
