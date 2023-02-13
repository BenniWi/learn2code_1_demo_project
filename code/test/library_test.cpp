#include "gtest/gtest.h"  // include the gtest functions & macros
extern "C"
{  // the library we want to us is written in C
#include "library.h"
}

class LibraryTestFixture : public ::testing ::Test
{
   protected:
    library lib{};
    virtual void SetUp()
    {
        // set some values to check if the init method overwrites them correctly
        library_init(&lib);
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_STUDENTS; ++i)
        {
            char name[STUDENT_MAX_NAME_LENGTH];
            sprintf(name, "Student %i", i);
            library_add_student(&lib, name);
        }
        for (unsigned int i = 0; i < LIBRARY_MAX_NUM_STUDENTS; ++i)
        {
            char title[BOOK_MAX_NAME_LENGTH];
            sprintf(title, "BOOK %i", i);
            library_add_book(&lib, title);
        }

        library_lend_book(&lib, &lib.student_list[1], lib.book_list[2].id);
    }
};

TEST(LibraryTest, init)
{
    library lib{};
    library_init(&lib);
    for (unsigned int i = 0; i < LIBRARY_MAX_NUM_STUDENTS; ++i)
    {
        ASSERT_EQ(lib.student_list[i].matrnr, 0);
    }
    for (unsigned int i = 0; i < LIBRARY_MAX_NUM_BOOKS; ++i)
    {
        ASSERT_EQ(lib.book_list[i].id, 0);
    }
    for (unsigned int i = 0; i < LIBRARY_MAX_NUM_BOOKS; ++i)
    {
        ASSERT_EQ(lib.lend_list[i], nullptr);
    }
}

TEST_F(LibraryTestFixture, add_book_overflow)
{
    book const *b = library_add_book(&lib, "nonsense title");
    ASSERT_EQ(nullptr, b);
}

TEST_F(LibraryTestFixture, add_student_overflow)
{
    student const *s = library_add_student(&lib, "nonsense name");
    ASSERT_EQ(nullptr, s);
}

TEST_F(LibraryTestFixture, lend_book)
{
    // book is lent correctly
    ASSERT_EQ(lib.lend_list[2]->matrnr, lib.student_list[1].matrnr);
}

TEST_F(LibraryTestFixture, lend_not_available_book)
{
    library_lend_book(&lib, &lib.student_list[2], lib.book_list[2].id);
    // book is still lent correctly
    ASSERT_EQ(lib.lend_list[2]->matrnr, lib.student_list[1].matrnr);
}

TEST_F(LibraryTestFixture, lend_not_existing_book)
{
    library_lend_book(&lib, &lib.student_list[2], 123456);
}

TEST_F(LibraryTestFixture, return_book)
{
    library_return_book(&lib, lib.book_list[2].id);
    // book is lent correctly
    ASSERT_EQ(lib.lend_list[2], nullptr);
}

TEST_F(LibraryTestFixture, return_not_lent_book)
{
    library_return_book(&lib, lib.book_list[1].id);
    // book is lent correctly
    ASSERT_EQ(lib.lend_list[1], nullptr);
}

TEST_F(LibraryTestFixture, return_not_existing_book)
{
    library_return_book(&lib, 123456);
}

TEST_F(LibraryTestFixture, find_book)
{
    student const *const s = library_find_book(&lib, lib.book_list[2].id);
    ASSERT_EQ(s->matrnr, lib.student_list[1].matrnr);
}

TEST_F(LibraryTestFixture, find_not_lent_book)
{
    student const *const s = library_find_book(&lib, lib.book_list[0].id);
    ASSERT_EQ(s, nullptr);
}

TEST_F(LibraryTestFixture, find_not_existing_book)
{
    student const *const s = library_find_book(&lib, 12345);
    ASSERT_EQ(s, nullptr);
}

TEST_F(LibraryTestFixture, list_books_4_students)
{
    // lend a second book
    library_lend_book(&lib, &lib.student_list[1], lib.book_list[3].id);
    library_list_books_4_student(&lib, lib.student_list[1].matrnr);
}

TEST_F(LibraryTestFixture, list_books_4_students_w_no_books)
{
    library_list_books_4_student(&lib, lib.student_list[4].matrnr);
}

TEST_F(LibraryTestFixture, print_valid)
{
    library_print(&lib);
}

TEST(LibraryTest, print_invalid)
{
    library_print(nullptr);
}