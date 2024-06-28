#include "AcademicStaff.h"
#include "AcademicStaff.h"
ListStudent list;
ListStudent list2;
ListCourses list3;

const string filename = "23CTT5.csv";
const string filename1 = "Scoreboard.csv";

void addStudentTail(ListStudent& list, const Student& student)
{
    Student* newStudent = new Student(student);
    newStudent->next = nullptr; // Khởi tạo con trỏ next của newStudent là nullptr

    if (list.head == nullptr) {
        // Nếu danh sách chưa có phần tử nào
        list.head = newStudent;
        list.tail = newStudent;
        newStudent->prev = nullptr; // Khởi tạo con trỏ prev của newStudent là nullptr
    }
    else {
        // Nếu danh sách đã có phần tử
        list.tail->next = newStudent;
        newStudent->prev = list.tail;
        list.tail = newStudent;
    }
}

void exportCSVClass(const string filename, ListStudent& list)
{
    string tmp;
    cout << "Nhap vao ten lop hoc: "; getline(cin, tmp);

    string path = "Class\\" + tmp + ".csv";
    ifstream file(path);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    // Skip the header
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        Student student;
        string field;

        getline(ss, student.NO, ',');
        getline(ss, student.studentID, ',');
        getline(ss, student.lastName, ',');
        getline(ss, student.firstName, ',');
        getline(ss, student.gender, ',');
        getline(ss, field, ',');
        student.dateOfBirth = strToDate(field);
        getline(ss, student.socialID, ',');

        addStudentTail(list, student);
    }
    cout << line << endl;
    file.close();
}
void viewListStudent(ListStudent list) {
    exportCSVClass(filename, list);
    printCentered("DANH SACH HOC SINH");

    ostringstream headerStream;
    headerStream << left << setw(5) << "NO"
        << setw(15) << "Student ID"
        << setw(15) << "Last Name"
        << setw(15) << "First Name"
        << setw(10) << "Gender"
        << setw(15) << "Date of Birth"
        << setw(15) << "Social ID";
    printCentered(headerStream.str());
    cout << string(145, '-') << endl;
    Student* current = list.head;
    while (current != nullptr) {
        ostringstream studentStream;
        studentStream << left << setw(5) << current->NO
            << setw(15) << current->studentID
            << setw(15) << current->lastName
            << setw(15) << current->firstName
            << setw(10) << current->gender
            << setw(15) << to_string(current->dateOfBirth.ngay) + "/" + to_string(current->dateOfBirth.thang) + "/" + to_string(current->dateOfBirth.nam)
            << setw(15) << current->socialID;
        cout << string(145, '-') << endl;
        printCentered(studentStream.str());
        current = current->next;
    }
}
void exportCSVGrades(const string filename1, ListStudent& list2)
{
    cout << "Nhap vao ID khoa hoc: ";
    string tmp;
    getline(cin, tmp);

    string path = "Mark\\" + tmp + ".csv";

    ifstream file(path);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filename1 << endl;
        return;
    }

    string line;
    // Skip the header
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        Student student;
        string field;

        getline(ss, field, ',');
        student.NO = field;
        getline(ss, student.studentID, ',');
        getline(ss, student.firstName, ',');
        getline(ss, student.lastName, ',');
        getline(ss, student.gender, ',');
        getline(ss, field, ',');
        student.dateOfBirth = strToDate(field);
        getline(ss, student.socialID, ',');
        getline(ss, field, ',');
        student.courseMark.otherMark = stoi(field);
        getline(ss, field, ',');
        student.courseMark.midtermMark = stoi(field);
        getline(ss, field, ',');
        student.courseMark.finalMark = stoi(field);
        getline(ss, field, ',');
        student.courseMark.totalMark = stoi(field);

        addStudentTail(list2, student);
    }

    file.close();
}
void viewScoreboardCourse(ListStudent& list2)
{
    exportCSVGrades(filename1, list2);
    printCentered("DANH SACH HOC SINH");

    cout << left << setw(5) << "NO"
        << setw(15) << "Student ID"
        << setw(15) << "First Name"
        << setw(15) << "Last Name"
        << setw(10) << "Gender"
        << setw(15) << "Date of Birth"
        << setw(15) << "Social ID"
        << setw(12) << "Other Mark"
        << setw(12) << "Midterm Mark"
        << setw(12) << "Final Mark"
        << setw(12) << "Total Mark" << endl;
    cout << string(145, '-') << endl;
    Student* student = list2.head;
    while (student != NULL)
    {
        cout << left << setw(5) << student->NO
            << setw(15) << student->studentID
            << setw(15) << student->firstName
            << setw(15) << student->lastName
            << setw(10) << student->gender
            << setw(15) << to_string(student->dateOfBirth.ngay) + "/" + to_string(student->dateOfBirth.thang) + "/" + to_string(student->dateOfBirth.nam)
            << setw(15) << student->socialID
            << setw(12) << student->courseMark.otherMark
            << setw(12) << student->courseMark.midtermMark
            << setw(12) << student->courseMark.finalMark
            << setw(12) << student->courseMark.totalMark << endl;
        cout << string(145, '-') << endl;
        student = student->next;
    }
}
void addCourseTail(ListCourses& list3, Course* course)
{
    if (list3.tail)
    {
        list3.tail->next = course;
        course->prev = list3.tail;
        list3.tail = course;
    }
    else {
        list3.head = list3.tail = course;
    }
}
int dayOfWeekToInt(string& day)
{
    if (day == "MON") return 2;
    if (day == "TUE") return 3;
    if (day == "WED") return 4;
    if (day == "THU") return 5;
    if (day == "FRI") return 6;
    if (day == "SAT") return 7;
    if (day == "SUN") return 8;
    return 0; // Invalid day
}
void exportCSVCourseSemester(const string& filename, ListCourses& list3)
{
    string tmp;
    cout << "Nhap vao ki hoc: "; getline(cin, tmp);

    string path = "Course\\" + tmp + ".csv";

    ifstream file(path);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << path << endl;
        return;
    }

    string line;
    // Skip the header
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        Course* course = new Course;
        string field;

        getline(ss, course->id, ',');
        getline(ss, course->courseName, ',');
        getline(ss, course->teacherName, ',');
        getline(ss, field, ',');
        course->credits = stoi(field);
        getline(ss, field, ',');
        course->academic = stoi(field);
        getline(ss, field, ',');
        course->max = stoi(field);
        getline(ss, field, ',');
        course->size = stoi(field);
        getline(ss, field, ',');
        course->dayOfWeek = dayOfWeekToInt(field);
        getline(ss, course->session, ',');
        course->prev = course->next = nullptr;
        addCourseTail(list3, course);
    }
}
// Hàm in thông tin khóa học của kì này 
void printCourses(ListCourses& list)
{
    exportCSVCourseSemester(filename, list);

    cout << left << setw(10) << "ID"
        << setw(25) << "Course Name"
        << setw(20) << "Teacher Name"
        << setw(10) << "Credits"
        << setw(15) << "Academic Year"
        << setw(15) << "Max Students"
        << setw(20) << "Enrolled Students"
        << setw(15) << "Day of Week"
        << setw(15) << "Session" << endl;

    cout << string(145, '-') << endl;

    Course* current = list.head;
    while (current != nullptr)
    {
        cout << left << setw(10) << current->id
            << setw(25) << current->courseName
            << setw(20) << current->teacherName
            << setw(10) << current->credits
            << setw(15) << current->academic
            << setw(15) << current->max
            << setw(20) << current->size
            << setw(15) << current->dayOfWeek
            << setw(15) << current->session << endl;
        cout << string(145, '-') << endl;
        current = current->next;
    }
}

void menutest()
{
    int choice;
    do {
        cout << "========== MENU ==========" << endl;
        cout << "1. View list of students" << endl;
        cout << "2. View scoreboard of courses" << endl;
        cout << "3. Print list of courses" << endl;
        cout << "4. Exit" << endl;
        cout << "==========================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            viewListStudent(list);
            break;
        case 2:
            viewScoreboardCourse(list2);
            break;
        case 3:
            printCourses(list3);
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
        cout << "Press Enter to continue...";
        cin.get();

    } while (choice != 4);
}

