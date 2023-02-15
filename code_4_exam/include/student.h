#ifndef STUDENT_H_
#define STUDENT_H_

#define STUDENT_MAX_NAME_LENGTH (25U)

typedef struct
{
    unsigned int matrnr;
    char name[STUDENT_MAX_NAME_LENGTH];
} student;

void student_init(student *s, const char name[STUDENT_MAX_NAME_LENGTH]);
void student_print(student const *s);

#endif /* STUDENT_H_ */