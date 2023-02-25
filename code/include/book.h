#ifndef BOOK_H_
#define BOOK_H_

#define BOOK_MAX_NAME_LENGTH (25U)

typedef struct
{
    unsigned int id;
    char title[BOOK_MAX_NAME_LENGTH];
} book;

/**
 * @brief initialize the book structure
 *
 * @param b_ptr book
 * @param title title of the book
 */
void book_init(book *b_ptr, const char title[BOOK_MAX_NAME_LENGTH]);

/**
 * @brief print the book structure to the stdout
 *
 * @param b_ptr book
 */
void book_print(book const *b_ptr);

#endif /* BOOK_H_ */
