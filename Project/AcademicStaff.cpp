#include "AcademicStaff.h"
ListClasses listclasses;
Year y;
ListStudent studentList;
ListCourses l_Course;
Date currentDate;

Class* NodeClass;
Student* s;
Class* cl;
string classname;
Semester HocKi;
void CreateSchoolYear() {
    cout << "The begining of the school year: ";
    cin >> y.From;
    cout << "The end of the school year: ";
    cin >> y.To;
}
void khoitaolistclass()
{
    listclasses.head = listclasses.tail = NULL;
}
void khoitaostudentlist()
{
    studentList.head = studentList.tail = NULL;
}
void khoitaolophoc()
{
    cl = new Class();
    cin.ignore();
    cout << "Input the class name: ";
    cin >> cl->className;
    cl->next = NULL;
}
void nhapngay(Student*& s)
{
    cout << "Input date: ";
    cin >> s->dateOfBirth.ngay;
    cout << "Input month: ";
    cin >> s->dateOfBirth.thang;
    cout << "Input year: ";
    cin >> s->dateOfBirth.nam;
}
void khoitaosinhvien()
{
    s = new Student();
    cout << "Enter NO: ";
    cin >> s->NO;
    cin.ignore();
    cout << "Enter student id: ";
    getline(cin, s->studentID, '\n');
    cout << "Enter last name: ";
    getline(cin, s->lastName, '\n');
    cout << "Enter first name: ";
    getline(cin, s->firstName, '\n');
    cout << "Enter gioi tinh: ";
    getline(cin, s->gender, '\n');
    cout << "Enter social id: ";
    getline(cin, s->socialID, '\n');
    nhapngay(s);
    s->next = NULL;
}
void khoitaoliststudent(ListStudent& ls)
{
    ls.head = ls.tail = NULL;
}
void AddClass(ListClasses& l)
{
    khoitaolophoc();
    if (l.head == NULL)
    {
        l.head = l.tail = cl;
        return;
    }
    else
    {
        l.tail->next = cl;
        l.tail = cl;
        return;
    }
}
void AddnClass(ListClasses& l, int n)
{
    cout << "Enter amount of classes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        AddClass(l);
    }
    y.listclasses = listclasses;
}
void AddStudent(ListStudent& ls)
{
    khoitaosinhvien();
    if (ls.head == NULL)
    {
        ls.head = ls.tail = s;
    }
    else
    {
        ls.tail->next = s;
        ls.tail = s;
    }
}
void AddStudent1(ListStudent& ls, Student* stu)
{
    if (ls.head == NULL)
    {
        ls.head = ls.tail = stu;
    }
    else
    {
        ls.tail->next = stu;
        ls.tail = stu;
        ls.tail->next = NULL;
    }
}
void AddStudenttoClass(ListClasses& lc)
{
    cout << "Enter class name: ";
    cin >> classname;
    Class* tmp = lc.head;
    while (tmp != NULL)
    {
        if (tmp->className == classname)
        {
            int numStudents;
            cout << "Enter amount of student: ";
            cin >> numStudents;
            for (int i = 0; i < numStudents; i++) {
                cout << "Enter the infomation of student number " << i + 1 << endl;
                AddStudent(tmp->list);
            }
            cout << "Adding successfully !" << endl;
            break;
        }
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        cout << "There's no infomation about entered class !" << endl;
    }
}
void print(ListClasses lc)
{
    Class* tmp = lc.head;
    cout << "Enter class name to printout information: " << endl;
    cin >> classname;
    while (tmp != NULL)
    {
        if (tmp->className == classname)
        {
            Student* tmp1 = tmp->list.head;
            if (tmp1 == NULL)
            {
                cout << "----------------INFORMATION----------------\n";
                cout << "Empty Class !" << endl;
                cout << "-------------------------------------------\n";
            }
            if (tmp == NULL) return;
            cout << "----------------INFORMATION----------------\n";
            int i = 1;
            while (tmp1 != NULL)
            {
                cout << "Student number " << i + 1 << endl;
                cout << "NO: " << tmp1->NO << endl;
                cout << "Student ID: " << tmp1->studentID << endl;
                cout << "Last name: " << tmp1->lastName << endl;
                cout << "First name: " << tmp1->firstName << endl;
                cout << "Gioi tinh: " << tmp1->gender << endl;
                cout << "Social ID: " << tmp1->socialID << endl;
                cout << "Born date: " << endl;
                cout << "Day: " << tmp1->dateOfBirth.ngay << endl;
                cout << "Month: " << tmp1->dateOfBirth.thang << endl;
                cout << "Year: " << tmp1->dateOfBirth.nam << endl;
                cout << endl;
                tmp1 = tmp1->next;
            }
            cout << "-------------------------------------------\n";
            break;
        }
        tmp = tmp->next;
    }
}
void importfile(ListClasses& lc)
{
    Class* tmp = lc.head;
    string classname;
    cout << "Enter class name to import: ";
    cin >> classname;
    ifstream file;
    //Doc tu file 23CTT5.csv
    file.open("23CTT5.csv");
    if (!file)
    {
        cout << "Khong the mo file !" << endl;
        return;
    }

    string line;
    getline(file, line);
    while (tmp != NULL)
    {
        if (tmp->className == classname)
        {

            while (getline(file, line))
            {
                Student* tmp1 = new Student();
                stringstream ss(line);
                getline(ss, tmp1->NO, ',');
                getline(ss, tmp1->studentID, ',');
                getline(ss, tmp1->lastName, ',');
                getline(ss, tmp1->firstName, ',');
                getline(ss, tmp1->gender, ',');
                string stringtmp;
                getline(ss, stringtmp, '/');
                tmp1->dateOfBirth.ngay = stoi(stringtmp);
                string stringtmp1;
                getline(ss, stringtmp1, '/');
                tmp1->dateOfBirth.thang = stoi(stringtmp1);
                string stringtmp2;
                getline(ss, stringtmp2, ',');
                tmp1->dateOfBirth.nam = stoi(stringtmp2);
                getline(ss, tmp1->socialID, '\n');
                AddStudent1(tmp->list, tmp1);
            }
            cout << "Import file successfully !" << endl;
            break;
        }
        tmp = tmp->next;
    }
    string fileName = "./Class/" + classname + ".csv";
    ifstream checkFile(fileName);
    if (checkFile.good()) {
        // Nếu file đã tồn tại, xóa file cũ
        remove(fileName.c_str());
        cout << "File existed, delete old file" << std::endl;
    }
    checkFile.close();

    ofstream file1;
    file1.open("./Class/" + classname + ".csv", ios::out | ios::app);
    file1 << "NO,Student ID,Last Name,First Name,Gender,Social ID,Date of Birth\n";
    tmp = lc.head;
    while (tmp != NULL)
    {
        if (tmp->className == classname)
        {
            Student* stu = tmp->list.head;
            while (stu != NULL)
            {
                file1 << stu->NO << "," << stu->studentID << "," << stu->lastName << "," << stu->firstName << "," << stu->gender << stu->dateOfBirth.ngay << "/" << stu->dateOfBirth.thang << "/" << stu->dateOfBirth.nam << "," << stu->socialID << "\n";
                stu = stu->next;
            }
            cout << "Export file successfully !" << endl;
            break;
        }
        tmp = tmp->next;
    }
    file.close();
    file1.close();
}

//19
void ExportCourseInforamtion(ListCourses& listcourses, ListClasses& listclasses)
{
    string courseID;
    cout << "Enter ID of course: ";
    cin >> courseID;

    ofstream file;
    file.open("./CourseInformation/" + courseID + ".csv", ios::out | ios::app);
    if (!file)
    {
        cout << "Khong the mo file" << endl;
        return;
    }
    file << "NO,Student ID,Last Name,First Name,Gender,Date of birth,Social ID" << endl;
    // Find the course with the specified ID
    Course* course = listcourses.head;
    while (course != nullptr)
    {
        if (course->id == courseID)
        {
            Class* classNode = listclasses.head;
            bool studentFound = false;
            while (classNode != nullptr)
            {
                Student* student = classNode->list.head;
                while (student != nullptr)
                {

                    Course* enrolledCourse = student->enrolledCourses.head;
                    while (enrolledCourse != nullptr)
                    {
                        if (enrolledCourse->id == courseID)
                        {
                            file << student->NO << "," << student->studentID << "," << student->lastName << "," << student->firstName << "," << student->gender << "," << student->dateOfBirth.ngay << "/" << student->dateOfBirth.thang << "/" << student->dateOfBirth.nam << "," << student->socialID << endl;
                            studentFound = true;
                            break;
                        }
                        enrolledCourse = enrolledCourse->next;
                    }
                    student = student->next;
                }
                classNode = classNode->next;
            }
            if (studentFound == true)
            {
                cout << "Export successfully !" << endl;
            }
            file.close();
            return;
        }
        course = course->next;
    }
    cout << "Course not found!" << endl;
}
//20
void importfile(ListCourses& listcourses, ListClasses& listclasses)
{
    string courseID;
    cout << "Enter ID of course: ";
    cin >> courseID;

    ifstream file;
    file.open("Scoreboard.csv");
    if (!file)
    {
        cout << "Khong the mo file! " << endl;
        return;
    }
    string line;
    getline(file, line);
    Course* course = listcourses.head;
    while (course != nullptr)
    {
        if (course->id == courseID)
        {

            Class* classNode = listclasses.head;
            bool studentFound = false;
            while (classNode != nullptr)
            {
                Student* student = classNode->list.head;
                while (student != nullptr)
                {

                    Course* enrolledCourse = student->enrolledCourses.head;
                    while (enrolledCourse != nullptr)
                    {
                        if (enrolledCourse->id == courseID)
                        {
                            stringstream ss;
                            string tmp;
                            getline(ss, tmp, ',');
                            getline(ss, tmp, ',');
                            getline(ss, tmp, ',');
                            getline(ss, tmp, ',');
                            getline(ss, tmp, ',');
                            getline(ss, tmp, ',');
                            getline(ss, tmp, ',');
                            getline(ss, tmp, ',');
                            int mark = stoi(tmp);
                            student->courseMark.otherMark = mark;
                            getline(ss, tmp, ',');
                            mark = stoi(tmp);
                            student->courseMark.midtermMark = mark;
                            getline(ss, tmp, ',');
                            mark = stoi(tmp);
                            student->courseMark.finalMark = mark;
                            getline(ss, tmp, ',');
                            mark = stoi(tmp);
                            student->courseMark.totalMark = mark;
                            studentFound = true;
                            break;
                        }
                        enrolledCourse = enrolledCourse->next;
                    }
                    student = student->next;
                }
                classNode = classNode->next;
            }

            cout << "Import Successfully !" << endl;
            file.close();
            return;
        }
        course = course->next;
    }
    cout << "Course not found!" << endl;
}
//Menu tu 1-5, 19,20
void displayStaffMenu()
{
    cout << "\n===========================================" << endl;
    cout << "|           ACADEMIC STAFF MENU           |" << endl;
    cout << "===========================================" << endl;
    cout << "|  1. Create a school year                |" << endl;
    cout << "|  2. Create several classes for 1st year |" << endl;
    cout << "|  3. Add new 1st year students to classes|" << endl;
    cout << "|  4. Import students from CSV to system  |" << endl;
    cout << "|  5. View list of students               |" << endl;
    cout << "|  0. Exit                                |" << endl;
    cout << "===========================================" << endl;
    cout << "Choose an option: ";
}
void academicstaffmember()
{
    int choice;
    bool running = true;

    while (running) {
        displayStaffMenu();
        cin >> choice;
        cin.ignore(); // Consume the newline character left by cin

        switch (choice) {
        case 1:
            CreateSchoolYear();
            break;
        case 2: {
            int num = 0;
            khoitaolistclass();
            AddnClass(listclasses, num);
            break;
        }
        case 3:
            khoitaoliststudent(studentList);
            AddStudenttoClass(listclasses);
            break;
        case 4:
            importfile(listclasses);
            break;
        case 5:
            print(listclasses);
            break;
        case 0:
            running = false;
            cout << "\nExiting the Academic Staff Menu.\n";
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
            break;
        }

        if (running) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
        }
    }
}
void deleteCourse()
{
    Course* p = nullptr;
    while (1)
    {
        Course* tmp = l_Course.head;
        int cnt = 0;
        while (tmp != nullptr)
        {
            ++cnt;
            cout << cnt << ". " << tmp->id;
        }
        if (cnt == 0)
        {
            cout << "Course Empty \n";
            return;
        }
        int IDCourse = 0;
        cout << "Enter the course (1-" << cnt << "): ";
        cin >> IDCourse;
        if (IDCourse > 0 && IDCourse <= cnt)
        {
            p = l_Course.head;
            for (int i = 0; i < IDCourse; i++)
            {
                p = p->next;
                break;
            }
        }
        else
        {
            cout << "error \n";
            system("pause");
        }
    }
    Course* toCourse = l_Course.head;
    Course* tam = nullptr;
    while (toCourse != nullptr)
    {
        if (toCourse == p)
        {
            if (tam == nullptr)
            {
                l_Course.head = toCourse->next;
            }
            else
            {
                tam->next = toCourse->next;
            }
            delete toCourse;
            cout << "Successful \n";
            return;
        }
        tam = toCourse;
        toCourse = toCourse->next;
    }
}
void ViewCourse()
{
    Course* Course = l_Course.head;
    int size = l_Course.size;
    for (int i = 0; i < size; i++)
    {
        cout << "\n----------------------\n";
        cout << "Start - End :" << l_Course.startDate.nam << "-" << l_Course.endDate.nam << endl;
        cout << "ID: " << Course->id << endl;
        cout << "Course Name: " << Course->courseName << endl;
        cout << "Teacher Name: " << Course->teacherName << endl;
        Course = Course->next;
    }
}
void ViewListOfClass()
{
    Class* currentClass = listclasses.head;
    if (currentClass == nullptr) {
        cout << "Class list is empty.\n";
        return;
    }

    int cnt = 0;
    while (currentClass != nullptr) {
        ++cnt;
        cout << "\n----------------------\n";
        cout << "Class name: " << currentClass->className << endl;
        currentClass = currentClass->next;
    }
}
void ViewListOfCourse(ListCourses& listcourses)
{
    if (listcourses.head == nullptr)
    {
        cout << "No courses available.\n";
        return;
    }
    Course* course = listcourses.head;
    int cnt = 0;
    while (course != nullptr)
    {
        cout << "Course " << ++cnt << ":" << endl;
        cout << "  Course ID: " << course->id << endl;
        cout << "  Course Name: " << course->courseName << endl;
        cout << "  Teacher Name: " << course->teacherName << endl;
        cout << "----------------------------------------" << endl;
        course = course->next;
    }
}
void ViewListOfStuInCourse(ListCourses& listcourses, ListClasses& listclasses) {
    string courseID;
    cout << "Enter ID of course: ";
    cin >> courseID;

    Course* currentCourse = listcourses.head;
    while (currentCourse != nullptr) {
        if (currentCourse->id == courseID) {
            Class* currentClass = listclasses.head;
            bool studentFound = false;
            while (currentClass != nullptr) {
                Student* currentStudent = currentClass->list.head;
                while (currentStudent != nullptr) {
                    Course* enrolledCourse = currentStudent->enrolledCourses.head;
                    while (enrolledCourse != nullptr) {
                        if (enrolledCourse->id == courseID) {
                            cout << "Student ID: " << currentStudent->studentID << endl;
                            cout << "Name: " << currentStudent->lastName << " " << currentStudent->firstName << endl;
                            cout << "Gender: " << currentStudent->gender << endl;
                            cout << "Social ID: " << currentStudent->socialID << endl;
                            cout << "Date of Birth: " << currentStudent->dateOfBirth.ngay << "/" << currentStudent->dateOfBirth.thang << "/" << currentStudent->dateOfBirth.nam << endl;
                            cout << "Academic Year: " << currentStudent->academicYear << endl;
                            cout << "----------------------------------------" << endl;
                            studentFound = true;
                        }
                        enrolledCourse = enrolledCourse->next;
                    }
                    currentStudent = currentStudent->next;
                }
                currentClass = currentClass->next;
            }
            if (!studentFound) {
                cout << "No students enrolled in this course.\n";
            }
            return;
        }
        currentCourse = currentCourse->next;
    }
    cout << "Course not found.\n";
}
void showMenu()
{
    cout << "===== MENU =====" << endl;
    cout << "1. View Course" << endl;
    cout << "2. View List of Classes" << endl;
    cout << "3. View List of Students in a Class" << endl;
    cout << "4. View List of Courses" << endl;
    cout << "5. View List of Students in a Course" << endl;
    cout << "6. Remove Student from a Course" << endl;
    cout << "7. Delete a Course" << endl;
    cout << "8. Exit" << endl;
    cout << "================" << endl;
}
// Initialize your data structures and variables
void Menuof()
{
    int choice;
    bool exit = false;

    while (!exit) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ViewListOfCourse(l_Course);
            break;
        case 2:
            ViewListOfClass();
            break;
        case 3:
            print(listclasses);
            break;
        case 4:
            ViewCourse();
            break;
        case 5:
            ViewListOfStuInCourse(l_Course, listclasses);
            break;
        case 6:

            break;
        case 7:
            deleteCourse();
            break;
        case 8:
            exit = true;
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }
    }
}
//6-11
Student* khoitaosinhvien2() {
    Student* s = new Student();

    cout << "Enter NO: ";
    cin >> s->NO;
    cin.ignore();
    cout << "Enter student id: ";
    getline(cin, s->studentID, '\n');
    cout << "Enter last name: ";
    getline(cin, s->lastName, '\n');
    cout << "Enter first name: ";
    getline(cin, s->firstName, '\n');
    cout << "Enter gioi tinh: ";
    getline(cin, s->gender, '\n');
    cout << "Enter social id: ";
    getline(cin, s->socialID, '\n');
    nhapngay(s);
    s->next = NULL;
    cout << "----------------------------------------------------------------------------------------------------------------------------\n";
    return s;
}
bool checkTime(Date a, Date b) {
    if (a.thang < b.thang) return false;
    else if (a.thang > b.thang) return true;
    else if (a.thang == b.thang) {
        if (a.ngay < b.ngay) return false;
        return true;
    }

}
Semester createSemester()
{
    Semester tmp;

    cout << "Hoc ki bao nhieu (1,2 hay 3) : "; cin >> tmp.semester;
    cout << "Nam hoc :"; cin >> tmp.startDate.nam; tmp.endDate.nam = tmp.startDate.nam;
    cout << "Ngay bat dau : " << endl;;
    cout << "\t\tNgay : ";
    cin >> tmp.startDate.ngay;
    cout << "\t\tThang : ";
    cin >> tmp.startDate.thang;
    cout << "Ngay ket thuc : " << endl;
    cout << "\t\tNgay : ";
    cin >> tmp.endDate.ngay;
    cout << "\t\tThang : ";
    cin >> tmp.endDate.thang;
    while (checkTime(tmp.startDate, tmp.endDate)) {
        cout << "Thoi gian khong hop le!!Vui long nhap lai... \n";
        cout << "Ngay bat dau : " << endl;;
        cout << "\t\tNgay : ";
        cin >> tmp.startDate.ngay;
        cout << "\t\tThang : ";
        cin >> tmp.startDate.thang;
        cout << "Ngay ket thuc : " << endl;
        cout << "\t\tNgay : ";
        cin >> tmp.endDate.ngay;
        cout << "\t\tThang : ";
        cin >> tmp.endDate.thang;
    }
    cout << "---------------------------------------------------------------------------------------------------------------------\n";
    tmp.list.head = tmp.list.tail = NULL;
    return tmp;
}
Course* CreateCourse() {
    Course* p = new Course();


    cout << "ID mon hoc : ";
    getline(cin, p->id);
    cout << "Ten mon hoc : ";
    getline(cin, p->courseName);
    cout << "Ten giao vien : ";
    getline(cin, p->teacherName);
    cout << "So tin chi mon hoc do : ";
    cin >> p->credits;
    cout << "So luong sinh vien (toi da 50) : ";
    cin >> p->max;
    while (p->max < 0 || p->max>50) {
        cout << "So luong sinh vien da qua gioi han , vui long nhap lai!!";
        cout << "So luong sinh vien (toi da 50) : ";
        cin >> p->max;
    }
    cout << "THOI GIAN BUOI HOC DIEN RA :" << endl;
    cout << "\t\t\tNGAY TRONG TUAN:               THOI GIAN:" << endl;
    cout << "\t\t\tchon 2: Thu hai                 S1: 07:30\n";
    cout << "\t\t\tchon 3: Thu ba                  S2: 09:30\n";
    cout << "\t\t\tchon 4: Thu tu                  S3: 12:30\n";
    cout << "\t\t\tchon 5: Thu nam                 S4: 15:30\n";
    cout << "\t\t\tchon 6: Thu sau\n";
    cout << "\t\t\tchon 7: Thu bay\n";
    cout << "Hoc vao thu : "; cin >> p->dayOfWeek;
    cin.ignore();
    cout << "Hoc vao luc : "; getline(cin, p->session);
    cout << "---------------------------------------------------------------------------------------------------------\n";
    return p;
}
void addCourseToSemester(Semester& hk) {
    Course* monHoc = CreateCourse();
    ofstream file;
    file.open("./Course/" + monHoc->id + ".csv", ios::out);
    if (!file.is_open()) {
        cout << "error\n";
        return;
    }
    file << "ID,LAST NAME,FIST NAME,DATE OF BIRT" << endl;
    if (monHoc == NULL) return;

    if (hk.list.head == NULL) {
        hk.list.head = hk.list.tail = monHoc;
        return;
    }
    Course* p = hk.list.head;
    while (1) {
        if (p->next == NULL) break;
        p = p->next;
    }
    p->next = monHoc;
    //file.close();
}


void viewOfCourse(ListCourses list) {
    if (list.head == NULL) {
        cout << "khong co mon hoc nao trong danh sach" << endl;
        return;
    }
    int i = 1;
    while (list.head != NULL) {

        cout << "Mon hoc thu " << i << endl;
        cout << "\t\tTen mon hoc : " << list.head->courseName << endl;
        cout << "\t\tMa mon hoc :" << list.head->id << endl;
        cout << "\t\tTen giao vien day mon hoc do : " << list.head->teacherName << endl;
        cout << "\t\tSo tin chi : " << list.head->credits << endl;
        cout << "\t\tHoc vao thu " << list.head->dayOfWeek;
        if (list.head->session == "S1") {
            cout << " 07:30\n";
        }
        else if (list.head->session == "S2") {
            cout << " 09:30\n";
        }
        else if (list.head->session == "S3") {
            cout << " 12:30\n";
        }
        else if (list.head->session == "S4") {
            cout << " 15:30\n";
        }
        cout << "-------------------------------------------------------------------------------------------------------------------\n";
        i++;
        list.head = list.head->next;
    }
}

void updateCourseInfo(ListCourses& List) {
    string Id;
    cin.ignore();
    if (List.head == NULL) {
        cout << "Hien tai khong co mon nao trong danh sach!!\n";
        cout << "-------------------------------------------------------------------------------------------------------------\n";
        return;
    }
    Course* pNode = List.head;
    cout << "Nhap id mon hoc de cap nhat thong tin : ";
    getline(cin, Id);

    while (pNode != NULL) {
        if (pNode->id == Id) {
            cout << "Ban muon cap nhat thong tin nao " << endl;
            cout << "\t1.Cap nhat ma mon hoc. \n";
            cout << "\t2.Cap nhat ten mon hoc.\n ";
            cout << "\t3.Cap nhat ten giao vien.\n";
            cout << "\t4.Cap nhat so luong sinh vien.\n";
            cout << "\t5.Cap nhat so tin chi.\n";
            cout << "\t6.Cap nhat ngay hoc trong tuan (2,3..).\n";
            cout << "\t7.Cap nhat tiet hoc trong ngay (S1,S2,S3 hoac S4).\n";
            cout << "\t0.Thoat" << endl;
            int chon = 0; cin >> chon;
            cin.ignore();
            if (chon == 1) {
                cout << "\t\tNhap ma lop moi : "; getline(cin, pNode->id);
            }
            else if (chon == 2) {
                cout << "\t\tNhap ten moc hoc moi : "; getline(cin, pNode->courseName);
            }
            else if (chon == 3) {
                cout << "\t\tNhap ten giao vien moi : "; getline(cin, pNode->teacherName);
            }
            else if (chon == 4) {
                cout << "\t\tNhap so luong sinh vien moi : "; cin >> pNode->max;
            }
            else if (chon == 5) {
                cout << "\t\tNhap so tin chi moi : "; cin >> pNode->credits;
            }
            else if (chon == 6) {
                cout << "\t\tNhap ngay hoc trong tuan moi : "; cin >> pNode->dayOfWeek;
            }
            else if (chon == 7) {
                cout << "\t\tNhap tiet hoc trong ngay moi : "; getline(cin, pNode->session);
            }

            else if (chon == 0) {
                cout << "-------------------------------------------------------------------------------------------------------------\n";
                return;
            }

            else {
                cout << "\t\tNHAP SAI ROI!!!\n";
                cout << "-------------------------------------------------------------------------------------------------------------\n";
                return;
            }
        }
        pNode = pNode->next;
    }
    cout << "-------------------------------------------------------------------------------------------------------------\n";
    return;
}
void fileListStudent(Course* x, Student* a) {
    if (x == NULL) {
        return;
    }
    ofstream file("./Course/" + x->id + ".csv", ios::out | ios::app);
    file << a->studentID << "," << a->lastName << "," << a->firstName << "," << a->dateOfBirth.ngay << "/" << a->dateOfBirth.thang << "/" << a->dateOfBirth.nam << endl;

    //file.close();
}
void addStudentToCourse(Student*& a, Course* x) {
    if (x == NULL) {
        cout << "Mon hoc ko ton tai " << endl;
        return;
    }
    if (a->enrolledCourses.head == NULL) {
        a->enrolledCourses.head = a->enrolledCourses.tail = x;
        fileListStudent(x, a);
        return;
    }
    Course* p = a->enrolledCourses.head;
    while (1) {
        if (p->next == NULL) break;
        p = p->next;
    }
    p->next = x;
    fileListStudent(x, a);
}

ListStudent CreateListStudent() {
    ListStudent l;
    l.head = l.tail = NULL;
    return l;
}
void ViewTheScoreboardOfACourse(ListCourses listcourses, ListClasses listclasses)
{
    string courseID;
    cout << "Enter ID of course: ";
    cin >> courseID;
    Course* course = listcourses.head;
    while (course != nullptr)
    {
        if (course->id == courseID)
        {
            Class* classNode = listclasses.head;

            bool studentFound = false;
            while (classNode != nullptr)
            {
                cout << "Class Name : " << classNode->className << endl;
                cout << "Class ID : " << classNode->ID << endl;
                Student* student = classNode->list.head;
                while (student != nullptr)
                {
                    Course* enrolledCourse = student->enrolledCourses.head;
                    while (enrolledCourse != nullptr)
                    {
                        if (enrolledCourse->id == courseID)
                        {
                            cout << "Student ID : " << student->studentID << endl;
                            cout << "Name : " << student->firstName << " " << student->lastName << endl;
                            cout << "Gender : " << student->gender << endl;
                            cout << "Birth : " << student->dateOfBirth.ngay << "/" << student->dateOfBirth.thang << "/" << student->dateOfBirth.nam << endl;
                            cout << "Social ID : " << student->socialID << endl;
                            cout << "\tTotal Mark : " << student->courseMark.totalMark << endl;
                            cout << "\tFinal Mark : " << student->courseMark.finalMark << endl;
                            cout << "\tMidterm Mark : " << student->courseMark.midtermMark << endl;
                            cout << "\tOther Mark : " << student->courseMark.otherMark << endl;
                            studentFound = true;
                            break;
                        }
                        enrolledCourse = enrolledCourse->next;
                    }
                    student = student->next;
                }
                cout << "-----------------------------------------------------------------------------------------------------------\n";
                classNode = classNode->next;
            }
            return;
        }
        course = course->next;
    }
}
void updateStudentResult(ListCourses& listcourses, ListClasses& listclasses) {
    string courseID;
    string stuID;
    cout << "Enter ID of course: ";
    cin >> courseID;
    cout << "Enter ID of student: ";
    cin >> stuID;
    Course* course = listcourses.head;
    while (course != nullptr)
    {
        if (course->id == courseID)
        {
            Class* classNode = listclasses.head;

            bool studentFound = false;
            while (classNode != nullptr)
            {

                Student* student = classNode->list.head;
                while (student != nullptr)
                {
                    if (student->studentID == stuID) {
                        Course* enrolledCourse = student->enrolledCourses.head;
                        while (enrolledCourse != nullptr)
                        {
                            if (enrolledCourse->id == courseID)
                            {

                                cout << "1.Update other mark: " << endl;
                                cout << "2.Update midterm mark: \n";
                                cout << "3.Update final mark: \n";
                                cout << "4.Update total mark: \n";
                                cout << "0.Exit\n";
                                int chon = 0; cin >> chon;
                                if (chon == 1) {
                                    cin >> student->courseMark.otherMark;
                                    cout << "---------------------------------------------------------------------------------------------------------\n";

                                }
                                else if (chon == 2) {
                                    cin >> student->courseMark.midtermMark;
                                    cout << "---------------------------------------------------------------------------------------------------------\n";

                                }
                                else if (chon == 3) {
                                    cin >> student->courseMark.finalMark;
                                    cout << "---------------------------------------------------------------------------------------------------------\n";

                                }
                                else if (chon == 4) {
                                    cin >> student->courseMark.otherMark;
                                    cout << "---------------------------------------------------------------------------------------------------------\n";

                                }
                                else {
                                    cout << "---------------------------------------------------------------------------------------------------------\n";
                                    return;
                                }
                            }
                            enrolledCourse = enrolledCourse->next;
                        }
                    }
                    student = student->next;
                }
                cout << "-----------------------------------------------------------------------------------------------------------\n";
                classNode = classNode->next;
            }
            return;
        }
        course = course->next;
    }
}
void ViewTheScoreboardOfAClass(ListClasses listclasses)
{
    int classID;
    cout << "Enter ID of class: ";
    cin >> classID;

    Class* classNode = listclasses.head;

    while (classNode != nullptr)
    {
        if (classNode->ID == classID) {
            cout << "Class Name : " << classNode->className << endl;

            Student* student = classNode->list.head;
            while (student != nullptr)
            {
                cout << "Name student: " << student->firstName << " " << student->lastName << endl;
                cout << "\tGPA: " << student->semesterMark.GPA << endl;
                cout << "\tOverall GPA: " << student->semesterMark.overallGPA << endl;
                Course* enrolledCourse = student->enrolledCourses.head;
                while (enrolledCourse != nullptr)
                {
                    cout << "\tName Course: " << enrolledCourse->courseName << endl;
                    cout << "\t\tFinal marks: " << student->courseMark.finalMark << endl;

                    enrolledCourse = enrolledCourse->next;
                }
                student = student->next;
            }
            classNode = classNode->next;
        }
    }
    cout << "-----------------------------------------------------------------------------------------------------------\n";
    return;

}
Course* chooseCourse(ListCourses& list)
{
    if (list.head == nullptr) {
        cout << "No courses available.\n";
        return nullptr;
    }

    Course* current = list.head;
    int courseIndex = 1;

    // Display the list of courses
    cout << "\nAvailable Courses:\n";
    while (current != nullptr) {
        cout << courseIndex << ". " << current->id << " - " << current->courseName << endl;
        current = current->next;
        courseIndex++;
    }

    // Ask user to choose a course
    int choice;
    cout << "\nEnter the course number to select: ";
    cin >> choice;

    // Validate choice
    if (choice < 1 || choice >= courseIndex) {
        cout << "Invalid choice. Please try again.\n";
        return nullptr;
    }

    // Reset current pointer and find the selected course
    current = list.head;
    for (int i = 1; i < choice; ++i) {
        current = current->next;
    }

    return current;
}
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
void displayMainMenu()
{
    cout << "\n=========================================" << endl;
    cout << "|        SEMESTER MANAGEMENT MENU       |" << endl;
    cout << "=========================================" << endl;
    cout << "| 6. Create a semester                  |" << endl;
    cout << "| 7. Add a course to this semester      |" << endl;
    cout << "| 9. View list of courses               |" << endl;
    cout << "| 10. Update course information         |" << endl;
    cout << "| 11. Add a student to a course         |" << endl;
    cout << "| 12. Remove Student from a Course      |" << endl;
    cout << "| 13. Delete a Course                   |" << endl;
    cout << "| 15. View List of Courses              |" << endl;
    cout << "| 16. View List of Students in a Class  |" << endl;
    cout << "| 17. View Course Details               |" << endl;
    cout << "| 18. View List of Students in a Course |" << endl;
    cout << "| 19. Export list of students to CSV    |" << endl;
    cout << "| 20. Import course scoreboard          |" << endl;
    cout << "| 21. View the scoreboard of a course   |" << endl;
    cout << "| 22. Update a student's result         |" << endl;
    cout << "| 23. View the scoreboard of a class    |" << endl;
    cout << "| 0. Exit                               |" << endl;
    cout << "=========================================" << endl;
    cout << "Choose an option: ";
}

void StaffMenu()
{

    Semester HocKi;
    bool Run = true;
    int choice;

    while (Run) {
        displayMainMenu();
        cin >> choice;
        cin.ignore(); // To consume the newline character left by cin

        switch (choice) {
        case 6:
            HocKi = createSemester();
            cout << "\nSemester created successfully.\n";
            break;
        case 7:
            addCourseToSemester(HocKi);
            cout << "\nCourse added to the semester successfully.\n";
            break;
        case 9:
            viewOfCourse(HocKi.list);
            break;
        case 10:
            updateCourseInfo(HocKi.list);
            break;
        case 11: {
            Student* sinhVien = khoitaosinhvien2();
            Course* course = chooseCourse(HocKi.list);
            if (course != nullptr) {
                addStudentToCourse(sinhVien, course);
                cout << "\nStudent added to the course successfully.\n";
            }
            else {
                cout << "\nInvalid course selected.\n";
            }
            break;
        }
        case 12:
            // Implement remove student from course functionality
            break;
        case 13:
            deleteCourse();
            break;
        case 15:
            ViewListOfCourse(HocKi.list);
            break;
        case 16:
            print(listclasses);
            break;
        case 17:
            ViewCourse();
            break;
        case 18:
            ViewListOfStuInCourse(HocKi.list, listclasses);
            break;
        case 19:
            ExportCourseInforamtion(l_Course, listclasses);
            break;
        case 20:
            importfile(l_Course, listclasses);
            break;
        case 21:
            ViewTheScoreboardOfACourse(l_Course, listclasses);
            break;
        case 22:
            updateStudentResult(l_Course, listclasses);
            break;
        case 23:
            viewScoreboardCourse(list2);
            break;
        case 0:
            Run = false;
            cout << "\nExiting the Semester Management Menu.\n";
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
            break;
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
    }
}
void showMenuStaff()
{
    cout << "===== MENU =====" << endl;
    cout << "1. View List of Courses" << endl;
    cout << "3. View List of Students in a Class" << endl;
    cout << "4. View Course Details" << endl;
    cout << "5. View List of Students in a Course" << endl;
    cout << "6. Remove Student from a Course" << endl;
    cout << "7. Delete a Course" << endl;
    cout << "8. Create a Semester" << endl;
    cout << "9. Add a Course to a Semester" << endl;
    cout << "10. Update Course Information" << endl;
    cout << "11. Add a Student to a Course" << endl;
    cout << "12. Exit" << endl;
    cout << "================" << endl;
}
void MainMenu()
{
    
    int choice;
    bool exit = false;

    while (!exit) {
        showMenuStaff();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ViewListOfCourse(HocKi.list);
            break;
        case 2:
            ViewListOfClass();
            break;
        case 3:
            print(listclasses);
            break;
        case 4:
            ViewCourse();
            break;
        case 5:
            ViewListOfStuInCourse(HocKi.list, listclasses);
            break;
        case 6:
            // Implement remove student from course functionality
            break;
        case 7:
            deleteCourse();
            break;
        case 8:
            HocKi = createSemester();
            cout << "\nSemester created successfully.\n";
            break;
        case 9:
            addCourseToSemester(HocKi);
            cout << "\nCourse added to the semester successfully.\n";
            break;
        case 10:
            updateCourseInfo(HocKi.list);
            break;
        case 11: {
            Student* sinhVien = khoitaosinhvien2();
            Course* course = chooseCourse(HocKi.list);
            if (course != nullptr) {
                addStudentToCourse(sinhVien, course);
                cout << "\nStudent added to the course successfully.\n";
            }
            else {
                cout << "\nInvalid course selected.\n";
            }
            break;
        }
        case 12:
            exit = true;
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
    }
}
