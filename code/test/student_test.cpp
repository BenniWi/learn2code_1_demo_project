#include "gtest/gtest.h"  // include the gtest functions & macros
extern "C"
{  // the library we want to us is written in C
#include "student.h"
}

class StudentTestFixture : public ::testing ::Test
{
   protected:
    student stdnt_{};
    void SetUp() override
    {
        // set some values to check if the init method overwrites them correctly
        stdnt_.matrnr = 0;
        // init the student
        student_init(&stdnt_, "Max Mustermann");
    }
};

// the first test we want to write
TEST_F(StudentTestFixture, InitValid)
{
    ASSERT_STREQ("Max Mustermann", stdnt_.name);
    ASSERT_NE(0, stdnt_.matrnr);
}

TEST(StudentTest, InitInvalid)
{
    student_init(nullptr, "Maria Musterfrau");
}

TEST_F(StudentTestFixture, PrintValid)
{
    student_print(&stdnt_);
}

TEST(StudentTest, PrintInvalid)
{
    student_print(nullptr);
}