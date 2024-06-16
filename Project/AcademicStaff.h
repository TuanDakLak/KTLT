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
    //So luong sinh vien trong lop 
    int max;
    //So tin tin chi
    int credits;
    //Ngay hoc trong tuan
    int dayOfWeek;
    //tiet hoc trong ngay
    string session;
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
//CourseMark
struct CourseMark {
    float otherMark = 0;
    float midtermMark = 0;
    float finalMark = 0;
    float totalMark = 0;
};
//SemesterMark
struct SemesterMark {
    float GPA = 0;
    float overallGPA = 0;
};

//Dong bo Struct
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
    CourseMark courseMark;
    SemesterMark semesterMark;
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
    //danh sach mon hoc cua hoc ki
    ListCourses list;
};
struct Year {
    int From, To;
    ListClasses listclasses;
};
// Ham cua Tuan
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
void Exportfile(ListClasses lc);
void ExportCourseInforamtion(ListCourses& listcourses, ListClasses& listclasses);

// Hàm của Quốc 
void RemoveStudentFromTheCourse(Course* toCourse); 
void deleteCourse(); 
void ViewCourse(); // xem khóa học 
void ViewListOfClass(); // xem tất cả lớp học 
void ViewListOfStuInClass(ListClasses& listclasses); // xem tất cả học sinh trong một lớp 
void ViewListOfCourse(ListCourses& listcourses);   // Xem tất cả các khóa học 
void ViewListOfStuInCourse(ListCourses& listcourses, ListClasses& listclasses); // Xem tất cả học sinh trong một khóa học 


//Ham cua Ty
Student* khoitaosinhvien2();
bool checkTime(Date a, Date b);
Semester createSemester();
Course* CreateCourse();
void addCourseToSemester(Semester& hk);
void viewOfCourse(ListCourses list);
void updateCourseInfo(ListCourses& List);
void fileListStudent(Course* x, Student* a);
void addStudentToCourse(Student*& a, Course* x);
ListStudent CreateListStudent();
void tu6_11();
