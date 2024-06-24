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
	    //Doc tu file 23CTT5.csv
        file.open("23CTT5.csv");
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

    //19
    void ExportCourseInforamtion(ListCourses& listcourses, ListClasses& listclasses)
    {
        string courseID;
        cout << "Enter ID of course: ";
        cin >> courseID;

        ofstream file;
        file.open("Export.csv");
        if (!file)
        {
            cout << "Khong the mo file Export.csv" << endl;
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
    void academicstaffmember()
    {
        cout << "----------------------------------Staff Member----------------------------------\n";
        cout << "1. Create a school year \n";
        cout << "2. Create Several Classes for 1st students\n";
        cout << "3. Add new 1st year students to 1st year classes \n";
        cout << "4. Import CSV file containing all students in a specific class to the system\n";
        cout << "5. See list student !\n";
	cout << "19. Export list student into a csv file \n";
	cout << "20. Import the scoreboard of a course \n";
        cout << "0. Exit !\n";
        cout << "--------------------------------------------------------------------------------\n";
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
	    else if (lc == 19)
	    {
		ExportCourseInforamtion(l_Course,listclasses);
	    }
	    else if (lc == 20)
	    {
		importfile(l_Course,listclasses);
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
//6-11
Student* khoitaosinhvien2()
    {
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
    Semester createSemester() {
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
        tmp.list.head = tmp.list.tail = NULL;
        return tmp;
    }
    Course* CreateCourse() {
        Course* p = new Course();
        cin.ignore();
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
        return p;
    }
    void addCourseToSemester(Semester& hk) {
        Course* monHoc = CreateCourse();
        ofstream file;
        file.open("./Course/" + monHoc->id + ".csv", ios::out);
        if (!file.is_open()) {
            cout << "errol\n";
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
            i++;
            list.head = list.head->next;
        }
    }

    void updateCourseInfo(ListCourses& List) {
        string Id;
        cin.ignore();
        cout << "Nhap id mon hoc de cap nhat thong tin : ";
        getline(cin, Id);
        if (List.head->id == Id) {
            cout << "Ban muon cap nhat thong tin nao " << endl;
            cout << "\t1.Cap nhat ma mon hoc. \n";
            cout << "\t2.Cap nhat ten mon hoc.\n ";
            cout << "\t3.Cap nhat ten giao vien.\n";
            int chon = 0; cin >> chon;
            cin.ignore();
            if (chon == 1) {
                cout << "\t\tNhap ma lop moi : "; getline(cin, List.head->id);
            }
            else if (chon == 2) {
                cout << "\t\tNhap ten moc hoc moi : "; getline(cin, List.head->courseName);
            }
            else if (chon == 3) {
                cout << "\t\tNhap ten giao vien moi : "; getline(cin, List.head->teacherName);
            }
            return;
        }
        Course* p = List.head;
        while (p != NULL) {
            if (p->id == Id) {
                cout << "Ban muon cap nhat thong tin nao " << endl;
                cout << "\t1.Cap nhat ma mon hoc. \n";
                cout << "\t2.Cap nhat ten mon hoc.\n ";
                cout << "\t3.Cap nhat ten giao vien.\n";
                int chon = 0; cin >> chon;
                cin.ignore();
                if (chon == 1) {
                    cout << "\t\tNhap ma lop moi : "; getline(cin, p->id);
                }
                else if (chon == 2) {
                    cout << "\t\tNhap ten moc hoc moi : "; getline(cin, p->courseName);
                }
                else if (chon == 3) {
                    cout << "\t\tNhap ten giao vien moi : "; getline(cin, p->teacherName);
                }
            }
            p = p->next;
        }

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

    void tu6_11() {
        
        bool Run = true;
	    cout << "1.Create a semester\n";
            cout << "2.Add a course to this semester\n";
            cout << "3.View list of course\n";
            cout << "4.Update coures infomartion\n";
            cout << "5.Add a student to the course\n";
            cout << "0.End\n";
        while (Run) {
            
            int chon = 0; cin >> chon;
            if (chon == 1) {
                HocKi = createSemester();
            }
            else if (chon == 2) {
                addCourseToSemester(HocKi);
            }
            else if (chon == 3) {
                viewOfCourse(HocKi.list);
            }
            else if (chon == 4) {
                updateCourseInfo(HocKi.list);
            }
            else if (chon == 0) {
                Run = false;
            }
            else if (chon == 5) {
                Student* sinhVien = khoitaosinhvien2();
                addStudentToCourse(sinhVien, HocKi.list.head);
		AddStudent1(studentList, sinhVien);
            }

        }
    }
//21
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
                Student* student = classNode->list.head;
                while (student != nullptr)
                {

                    Course* enrolledCourse = student->enrolledCourses.head;
                    while (enrolledCourse != nullptr)
                    {
                        if (enrolledCourse->id == courseID)
                        {

                            cout << student->firstName << " " << student->lastName << " : " << student->courseMark.otherMark << " " << student->courseMark.midtermMark << " ";
                            cout << student->courseMark.finalMark << " " << student->courseMark.totalMark << endl;
                            
                            studentFound = true;
                            break;
                        }
                        enrolledCourse = enrolledCourse->next;
                    }
                    student = student->next;
                }
                classNode = classNode->next;
            }

           
            return;
        }
        course = course->next;
    }
}
