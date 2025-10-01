#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    students[num_of_students++] = Student(name, ++last_student_id, midterm, final);
    /* TODO */

}

void StudentManager::deleteStudent(int id) {
    if(num_of_students == 0) return;
    int idx = findStudentByID(id);
    if(idx == -1) return;
    for(int i = idx; i < num_of_students - 1; i++){
        students[i] = students[i+1];
    }
    num_of_students--;

    /* TODO */
}

void StudentManager::modifyStudent(const Student& student) {
    int id = student.getID();
    for(int i = 0; i < num_of_students; i++){
        if(students[i].getID() == id){
            students[i] = student;
            break;
        }
    }
    /* TODO */
}

int StudentManager::findStudentByID(int id) const {
    for(int i = 0; i < num_of_students; i++){
        if(students[i].getID() == id){
            return i;
        }
    }
    /* TODO */
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    float max = -1.0f;
    int bestid = -1;
    for(int i = 0 ; i < num_of_students; i++){
       if(students[i].getRecord().getMidterm() > max){
            max = students[i].getRecord().getMidterm();
            bestid = i;
       }
    }
    /* TODO */
    return students[bestid].getID();
}

int StudentManager::findBestStudentInFinal() const {
    float max = -1.0f;
    int bestid = -1;
    for(int i = 0; i < num_of_students; i++){
        if(students[i].getRecord().getFinal() > max){
            max = students[i].getRecord().getFinal();
            bestid = i;
        }
    }
    /* TODO */
    return students[bestid].getID();
}

int StudentManager::findBestStudent() const {
    float max = -1.0f;
    int bestid = -1;
    for(int i = 0; i < num_of_students; i++){
        if(students[i].getRecord().getTotal() > max){
            max = students[i].getRecord().getTotal();
            bestid = i;
        }
    }
    /* TODO */
    return students[bestid].getID();
}

float StudentManager::getMidtermAverage() const {
    float sum = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        sum += students[i].getRecord().getMidterm();
    }
    /* TODO */
    if(num_of_students == 0) return 0.0f;
    return sum / num_of_students;
}

float StudentManager::getFinalAverage() const {
    float sum = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        sum += students[i].getRecord().getFinal();
    }
    /* TODO */
    if(num_of_students == 0) return 0.0f;
    
    return sum / num_of_students;
}

float StudentManager::getTotalAverage() const {
    float sum = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        sum += students[i].getRecord().getTotal();
    }
    /* TODO */
    if(num_of_students == 0) return 0.0f;
    return sum / num_of_students;
}

