#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final)
    : midterm(midterm), final(final) {}

/* TODO: Initializer list 사용해 초기화 해보기 */


float StudentRecord::getTotal() const {

    /* TODO */
    return midterm + final;
}

void StudentRecord::updateScores(float midterm, float final) {
    this -> midterm = midterm;
    this -> final = final;
    /* TODO: this keyword 사용해 보기 */
}


/* Student */

Student::Student() 
    : name(""), id(0), record(StudentRecord(0.0, 0.0)) {}

/* TODO: Initializer list 사용해 초기화 해보기 */


Student::Student(const char *name, int id, float midterm, float final)
    : name(name), id(id), record(midterm, final) {}

/* TODO: Initializer list 사용해 초기화 해보기 */


void Student::updateRecord(const char *name, float midterm, float final) {
    this -> name = name;
    record.updateScores(midterm, final);    
    /* TODO */
}

