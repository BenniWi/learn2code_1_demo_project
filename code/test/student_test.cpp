#include "gtest/gtest.h"  // include the gtest functions & macros
extern "C"
{  // the library we want to us is written in C
#include "student.h"
}

class StudentTest : public ::testing ::Test
{
   protected:
    student max;
    virtual void SetUp()
    {
        // set some values to check if the init method overwrites them correctly
        max.matrnr = 0;
        // init the student
        student_init(&max, "Max Mustermann");
    }
};

// the first test we want to write
TEST_F(StudentTest, init)
{
    ASSERT_STREQ("Max Mustermann", max.name);
    ASSERT_NE(0, max.matrnr);
}