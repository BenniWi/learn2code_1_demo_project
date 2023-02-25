#include "gtest/gtest.h"  // include the gtest functions & macros
extern "C"
{  // the library we want to us is written in C
#include "library.h"
}

class LibraryTestFixture : public ::testing ::Test
{
   protected:
    library lib{};
    void SetUp() override
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

        ASSERT_EQ(library_lend_book(&lib, lib.student_list[1].matrnr, lib.book_list[2].id), true);
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

TEST_F(LibraryTestFixture, AddBookOverflow)
{
    book const *bkptr = library_add_book(&lib, "nonsense title");
    ASSERT_EQ(nullptr, bkptr);
}

TEST_F(LibraryTestFixture, AddBookInvalid)
{
    book const *bkptr = library_add_book(nullptr, "nonsense title");
    ASSERT_EQ(nullptr, bkptr);
}

TEST_F(LibraryTestFixture, FindStudent)
{
    student const *stdnt = library_get_student_4_matrnr(&lib, lib.student_list[3].matrnr);
    ASSERT_EQ(stdnt->matrnr, lib.student_list[3].matrnr);
}

TEST_F(LibraryTestFixture, FindNotExistingStudent)
{
    student const *stdnt = library_get_student_4_matrnr(&lib, 12345);
    ASSERT_EQ(stdnt, nullptr);
}

TEST_F(LibraryTestFixture, FindStudentInvalid)
{
    student const *stdnt = library_get_student_4_matrnr(nullptr, 12345);
    ASSERT_EQ(stdnt, nullptr);
}

TEST_F(LibraryTestFixture, AddStudentOverflow)
{
    student const *stdnt = library_add_student(&lib, "nonsense name");
    ASSERT_EQ(nullptr, stdnt);
}

TEST_F(LibraryTestFixture, AddStudentInvalid)
{
    student const *stdnt = library_add_student(nullptr, "nonsense name");
    ASSERT_EQ(nullptr, stdnt);
}

TEST_F(LibraryTestFixture, LendBook)
{
    // book is lent correctly
    ASSERT_EQ(lib.lend_list[2]->matrnr, lib.student_list[1].matrnr);
}

TEST_F(LibraryTestFixture, LendNotAvailableBook)
{
    ASSERT_EQ(library_lend_book(&lib, lib.student_list[2].matrnr, lib.book_list[2].id), false);
    // book is still lent correctly
    ASSERT_EQ(lib.lend_list[2]->matrnr, lib.student_list[1].matrnr);
}

TEST_F(LibraryTestFixture, LendNotExistingBook)
{
    ASSERT_EQ(library_lend_book(&lib, lib.student_list[2].matrnr, 123456), false);
}

TEST_F(LibraryTestFixture, LendBookInvalid)
{
    ASSERT_EQ(library_lend_book(nullptr, lib.student_list[2].matrnr, 123456), false);
}

TEST_F(LibraryTestFixture, ReturnBook)
{
    ASSERT_EQ(library_return_book(&lib, lib.book_list[2].id), true);
    // book is lent correctly
    ASSERT_EQ(lib.lend_list[2], nullptr);
}

TEST_F(LibraryTestFixture, ReturnNotLentBook)
{
    ASSERT_EQ(library_return_book(&lib, lib.book_list[1].id), false);
    // book is lent correctly
    ASSERT_EQ(lib.lend_list[1], nullptr);
}

TEST_F(LibraryTestFixture, ReturnNotExistingBook)
{
    ASSERT_EQ(library_return_book(&lib, 123456), false);
}

TEST_F(LibraryTestFixture, ReturnBookInvalid)
{
    ASSERT_EQ(library_return_book(nullptr, 123456), false);
}

TEST_F(LibraryTestFixture, FindBook)
{
    student const *const stdnt = library_find_book(&lib, lib.book_list[2].id);
    ASSERT_EQ(stdnt->matrnr, lib.student_list[1].matrnr);
}

TEST_F(LibraryTestFixture, FindNotLentBook)
{
    student const *const stdnt = library_find_book(&lib, lib.book_list[0].id);
    ASSERT_EQ(stdnt, nullptr);
}

TEST_F(LibraryTestFixture, FindNotExistingBook)
{
    student const *const stdnt = library_find_book(&lib, 12345);
    ASSERT_EQ(stdnt, nullptr);
}

TEST_F(LibraryTestFixture, FindBookInvalid)
{
    student const *const stdnt = library_find_book(nullptr, 12345);
    ASSERT_EQ(stdnt, nullptr);
}

TEST_F(LibraryTestFixture, ListBooks4Student)
{
    // lend a second book
    ASSERT_EQ(library_lend_book(&lib, lib.student_list[1].matrnr, lib.book_list[3].id), true);
    library_list_books_4_student(&lib, lib.student_list[1].matrnr);
}

TEST_F(LibraryTestFixture, ListBooks4StudentWNoBooks)
{
    library_list_books_4_student(&lib, lib.student_list[4].matrnr);
}

TEST_F(LibraryTestFixture, ListBooks4StudentWNoBooksInvalid)
{
    library_list_books_4_student(nullptr, lib.student_list[4].matrnr);
}

TEST_F(LibraryTestFixture, PrintValid)
{
    library_print(&lib);
}

TEST(LibraryTest, PrintInvalid)
{
    library_print(nullptr);
}