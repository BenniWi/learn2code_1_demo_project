#include "book.h"
#include "student.h"

int main()
{
    student max;
    student maria;
    book tele;
    book tubbies;

    student_init(&max, "Max Mustermann");
    student_init(&maria, "Maria Musterfrau");
    student_print(&max);
    student_print(&maria);

    book_init(&tele, "ah oh, lala");
    book_init(&tubbies, "ah oh, tipsie");
    book_print(&tele);
    book_print(&tubbies);
}
