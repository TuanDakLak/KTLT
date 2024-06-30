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
    // Them vào struct Dateofbirth, academicYear
    string id;
    string password;
    string lastName;
    string firstName;
    string className;
    string gender;
    int academicYear; 
    Date dateofbirth;
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
//CourseMark for import file
struct CourseMark {
    float otherMark = 0;
    float midtermMark = 0;
    float finalMark = 0;
    float totalMark = 0;
};
//SemesterMark for import file
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
void importfile(ListCourses& listcourses, ListClasses& listclasses);
void displayStaffMenu();

// Hàm của Quốc 
void deleteCourse();
void ViewCourse(); // xem khóa học 
void ViewListOfClass(); // xem tất cả lớp học 
void ViewListOfStuInClass(ListClasses& listclasses); // xem tất cả học sinh trong một lớp 
void ViewListOfCourse(ListCourses& listcourses);   // Xem tất cả các khóa học 
void ViewListOfStuInCourse(ListCourses& listcourses, ListClasses& listclasses); // Xem tất cả học sinh trong một khóa học 
void showMenu();
void Menuof();
void showMenuStaff();
void MainMenu();

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
void updateStudentResult(ListCourses& listcourses, ListClasses& listclasses);
void ViewTheScoreboardOfAClass(ListClasses listclasses);
void displayMainMenuStaff();
void StaffMenu();
Course* chooseCourse(ListCourses& list);


<<<<<<< HEAD
// Cac ham login 
User * convertUserData(ifstream & data);
void addUser(ListUser& l, User* u);
void getList();
User* login(string id, string pass);
string getPass(bool isHidden);
void Menu();
void LoginMenu();

// function setting 
Date strToDate(const std::string& dateStr);
int getConsoleWidth();
void printCentered(const string& text);


// stu (file) 
void menutest();
void addStudentTail(ListStudent& list, const Student& student);
void exportCSVClass(const string filename, ListStudent& studentList);
void viewListStudent(ListStudent studentList);
void exportCSVGrades(const string filename1, ListStudent& list2);
void viewScoreboardCourse(ListStudent& list2);
int dayOfWeekToInt(string& day);
void exportCSVCourseSemester(const string& filename, ListCourses& list);
void printCourses(ListCourses& list);


=======
void ViewTheScoreboardOfACourse(ListCourses listcourses, ListClasses listclasses);
>>>>>>> 5f77cc6d580f15235f6da6c578baf86d073bae28
