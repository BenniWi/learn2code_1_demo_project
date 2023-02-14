#ifndef BOOK_H_
#define BOOK_H_

#define BOOK_MAX_NAME_LENGTH (25U)

typedef struct
{
    unsigned int id;
    char title[BOOK_MAX_NAME_LENGTH];
} book;

void book_init(book *b, const char title[BOOK_MAX_NAME_LENGTH]);
void book_print(book const *b);

#endif /* BOOK_H_ */
