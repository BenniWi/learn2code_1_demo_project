#include "gtest/gtest.h"  // include the gtest functions & macros
extern "C"
{  // the library we want to us is written in C
#include "book.h"
}

class BookTest : public ::testing ::Test
{
   protected:
    book b;
    virtual void SetUp()
    {
        // set some values to check if the init method overwrites them correctly
        b.id = 0;
        // init the student
        book_init(&b, "my first book");
    }
};

// the first test we want to write
TEST_F(BookTest, init)
{
    ASSERT_STREQ("my first book", b.title);
    ASSERT_NE(0, b.id);
}