#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;



struct Date {
    int ngay, thang, nam;
};
struct User {
    string id;
    string password;
    string lastName;
    string firstName;
    string className;
    string gender;
    bool isStaff;
    User* prev;
    User* next;
};
struct Course {
    string id;
    string courseName;
    string teacherName;
    Course* prev;
    Course* next;
};
struct ListCourses {
    Course* head;
    Course* tail;
    Date startDate, endDate;
    int size;
};
struct ListUser {
    User* head;
    User* tail;
    int size;
};
struct Student {
    string NO;
    string studentID;
    string lastName;
    string firstName;
    string gender;
    string socialID;
    Date dateOfBirth;
    int academicYear;
    ListCourses enrolledCourses;
    Student* prev;
    Student* next;
};
// Thêm data vào struclisst 
struct ListStudent {
    Student* head;
    Student* tail;
    Student data; 
    string className;
    string year;
};
// Struct Class thêm ID 
struct Class 
{
    ListStudent list;
    int ID; 
    string className;
    Class* prev;
    Class* next;
};
struct ListClasses {
    Class* head;
    Class* tail;
    int size;
};
struct Semester {
    int semester;
    Date startDate, endDate;
};
struct Year {
    int From, To;
    ListClasses listclasses;
};
// Ham chuc nang cho Staff
void CreateSchoolYear();
void khoitaolophoc();
void nhapngay(Student*& s);
void khoitaosinhvien();
void AddClass(ListClasses& l);
void AddnClass(ListClasses& l, int n);
void AddStudent(ListStudent& s);
void importfile(ListClasses& lc);
void print(ListClasses lc);
void khoitaoliststudent(ListStudent& ls);
void academicstaffmember();

// Hàm của Quốc 
void RemoveStudentFromTheCourse(Course* toCourse); 
void deleteCourse(); 
void ViewCourse(); // xem khóa học 
void ViewListOfClass(); // xem tất cả lớp học 
void ViewListOfStuInClass(ListClasses& listclasses); // xem tất cả học sinh trong một lớp 
void ViewListOfCourse(ListCourses& listcourses);   // Xem tất cả các khóa học 
void ViewListOfStuInCourse(ListCourses& listcourses, ListClasses& listclasses); // Xem tất cả học sinh trong một khóa học 
// Function of Student 
