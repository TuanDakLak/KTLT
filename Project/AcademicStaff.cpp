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
    void khoitaoliststudent(ListStudent &ls)
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
    void AddnClass(ListClasses& l,int n)
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
                while (tmp1 != NULL)
                {
                    
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
        ifstream file;
        file.open("Import.csv");
        if (!file)
        {
            cout << "Khong the mo file !" << endl;
            return;
        }
        string classname;
        cout << "Enter class name to import: ";
        cin >> classname;
        string line;
        getline(file, line);

        
        while (tmp != NULL)
        {
            if (tmp->className == classname)
            {

                while (getline(file,line))
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
        file.close();
    }
    void academicstaffmember()
    {
        cout << "-------------------Staff Member------------------\n";
        cout << "1. Create a school year \n";
        cout << "2. Create Several Classes for 1st students\n";
        cout << "3. Add new 1st year students to 1st year classes \n";
        cout << "4. Import CSV file containing all students in a specific class to the system\n";
        cout << "5. See list student !\n";
        cout << "0. Exit !\n";
        int lc;
        while (1)
        {
            cout << "Enter option: ";
            cin >> lc;
            if (lc == 1)
            {
                CreateSchoolYear();
            }
            else if (lc == 2)
            {
                int num = 0;
                khoitaolistclass();
                AddnClass(listclasses, num);
            }
            else if (lc == 3)
            {
                khoitaoliststudent(studentList);
                AddStudenttoClass(listclasses);
            }
            else if (lc == 4)
            {
                importfile(listclasses);
            }
            else if (lc == 5)
            {
                print(listclasses);
            }
            else if (lc == 0)
            {
                break;
            }
            else
            {
                cout << "Cannot get your requirement !" << endl;
                break;
            }
        }
    }
    void RemoveStudentFromTheCourse(Course* toCourse)
    {
        // Xóa nhờ student ID 
        string ID; 
        cin.ignore(); 
        cout << "Student ID: "; getline(cin, ID); 

        Course* p = toCourse; 
        Course* prev = nullptr;
        while (p != NULL)
        {
            if (p->id == ID)
            {
                if (prev == nullptr)
                {
                    toCourse = p->next;
                }
                else
                {
                    prev->next = p->next;
                }
                delete p; 
                cout << "Succesful \n"; 
                return; 
            }
            // Nếu không có id 
            prev = p;
            p = p->next; 
        }
        cout << "Student not found \n"; 
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
        Class* lop = listclasses.head;
        int size = listclasses.size;
        if (size == 0)
        {
            cout << "Danh sach lop rong \n"; 
        }
        else
        {
            int cnt = 0;
            for (int i = 0; i < size; i++)
            {
                ++cnt;
                cout << "\n----------------------\n";
                cout << "Class name: "  << lop->className << endl;
                lop = lop->next;
            }

        }
    }
    void ViewListOfStuInClass(ListClasses& listclasses)
    {
        // Prompt for class ID
        int IDClass = 0;
        cout << "Enter ID of class: ";
        cin >> IDClass;

        // Find the class with the specified ID
        Class* p = listclasses.head;
        while (p != nullptr)
        {
            if (p->ID == IDClass)
            {
                
                ListStudent tmp = p->list;
                Student* student = tmp.head;
                while (student != nullptr)
                {
                    
                    cout << "Student NO: " << student->NO << endl;
                    cout << "Student ID: " << student->studentID << endl;
                    cout << "Name: " << student->lastName << " " << student->firstName << endl;
                    cout << "Gender: " << student->gender << endl;
                    cout << "Social ID: " << student->socialID << endl;
                    cout << "Date of Birth: " << student->dateOfBirth.ngay << "/" << student->dateOfBirth.thang << "/" << student->dateOfBirth.nam << endl;
                    cout << "Academic Year: " << student->academicYear << endl;
                    cout << "Enrolled Courses: " << endl;
                    Course* course = student->enrolledCourses.head;
                    while (course != nullptr)
                    {
                        cout << "  Course ID: " << course->id << endl;
                        cout << "  Course Name: " << course->courseName << endl;
                        cout << "  Teacher Name: " << course->teacherName << endl;
                        course = course->next;
                    }
                    cout << "----------------------------------------" << endl;
                    student = student->next;
                }
                return; 
            }
            p = p->next;
        }
        
        cout << "Class not found!" << endl;
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
    void ViewListOfStuInCourse(ListCourses& listcourses, ListClasses& listclasses)
    {
        
        string courseID;
        cout << "Enter ID of course: ";
        cin >> courseID;

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
                                
                                cout << "Student NO: " << student->NO << endl;
                                cout << "Student ID: " << student->studentID << endl;
                                cout << "Name: " << student->lastName << " " << student->firstName << endl;
                                cout << "Gender: " << student->gender << endl;
                                cout << "Social ID: " << student->socialID << endl;
                                cout << "Date of Birth: " << student->dateOfBirth.ngay << "/" << student->dateOfBirth.thang << "/" << student->dateOfBirth.nam << endl;
                                cout << "Academic Year: " << student->academicYear << endl;
                                cout << "----------------------------------------" << endl;
                                studentFound = true;
                                break;
                            }
                            enrolledCourse = enrolledCourse->next;
                        }
                        student = student->next;
                    }
                    classNode = classNode->next;
                }

                if (!studentFound)
                {
                    cout << "No students enrolled in this course.\n";
                }
                return; 
            }
            course = course->next;
        }
        cout << "Course not found!" << endl;
    }

