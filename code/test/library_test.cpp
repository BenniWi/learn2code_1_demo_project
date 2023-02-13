#include "gtest/gtest.h"  // include the gtest functions & macros
extern "C"
{  // the library we want to us is written in C
#include "library.h"
}

class LibraryTest : public ::testing ::Test
{
   protected:
    library lib{}{};
    virtual void SetUp()
    {
        // set some values to check if the init method overwrites them correctly
        // lib.id = 0;
    }
};

// the first test we want to write
TEST_F(LibraryTest, init)
{
    // ASSERT_STREQ("my first book", b.title);
    // ASSERT_NE(0, b.id);
}