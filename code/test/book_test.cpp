#include "gtest/gtest.h"  // include the gtest functions & macros
extern "C"
{  // the library we want to us is written in C
#include "book.h"
}

class BookTestFixture : public ::testing ::Test
{
   protected:
    book book_{};
    void SetUp() override
    {
        // set some values to check if the init method overwrites them correctly
        book_.id = 0;
        // init the student
        book_init(&book_, "my first book");
    }
};

// the first test we want to write
TEST_F(BookTestFixture, InitValid)
{
    ASSERT_STREQ("my first book", book_.title);
    ASSERT_NE(0, book_.id);
}

TEST(BookTest, InitInvalid)
{
    book_init(nullptr, "my first book");
}

TEST_F(BookTestFixture, PrintValid)
{
    book_print(&book_);
}

TEST(BookTest, PrintInvalid)
{
    book_print(nullptr);
}