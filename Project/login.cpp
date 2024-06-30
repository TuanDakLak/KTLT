#include "AcademicStaff.h"
const string userData = "Users.csv";
string id, pass;
User* current = NULL;
ListUser list;
void addUser(ListUser& l, User* u)
{
	if (u == nullptr)
	{
		return;
	}
	if (l.head == nullptr)
	{
		l.head = l.tail = u;
	}
	else
	{
		l.tail->next = u;
		u->prev = l.tail;
		l.tail = u;

	}
	l.size++;
}
User* convertUserData(ifstream& data) {
	User* u = new User;
	string p;

	getline(data, u->id, ',');
	if (u->id == "") {
		delete u;
		return nullptr;
	}

	getline(data, u->password, ',');
	getline(data, u->lastName, ',');
	getline(data, u->firstName, ',');
	getline(data, u->className, ',');
	getline(data, u->gender, ',');

	getline(data, p, ',');
	u->dateofbirth = strToDate(p);

	getline(data, p, ',');
	u->academicYear = stoi(p);

	getline(data, p, '\n');
	if (p == "TRUE")
	{
		u->isStaff = true;
	}
	else
		u->isStaff = false;

	// Bỏ qua cột cuối cùng không cần thiết

	u->next = nullptr;
	u->prev = nullptr;

	return u;
}
void getList()
{
	ifstream f(userData);
	string data = "";
	if (!f.is_open())
	{
		cout << "khong the mo file de doc \n";
		return;
	}
	// Khởi tạo rỗng 
	list.head = list.tail = nullptr;
	getline(f, data); // bỏ dòng đầu 
	while (!f.eof())
	{
		addUser(list, convertUserData(f));
	}
}
// tới hàm dô phần login 
User* login(string id, string pass)
{
	User* tmp = list.head;
	while (tmp != nullptr)
	{
		if (id == tmp->id)
		{
			if (pass == tmp->password)
				return tmp;
			else
				return NULL;
		}
		tmp = tmp->next;
		// Duyệt hết danh sách 
	}
	return tmp;
}
string getPass(bool isHidden)
{
	string pass;
	char ch;
	while ((ch = getchar()) != '\n') {
		if (ch == '\b') { // Handle backspace
			if (!pass.empty()) {
				cout << "\b \b";
				pass.pop_back();
			}
		}
		else {
			pass += ch;
			if (isHidden) {
				cout << '*';
			}
			else {
				cout << ch;
			}
		}
	}
	cout << endl;
	return pass;
}
void clearScreen()
{
	system("cls"); // Xóa màn hình console
}

void Menu()
{
	cin.ignore(); // Xóa bộ nhớ đệm
	cout << "\n-------------------------\n";
	cout << "		Login		" << endl;
	cout << "ID:";
	getline(cin, id);
	cout << "Password: ";
	pass = getPass(true);
	cout << "\n---------------------------\n";
}

void viewProfile(User* user)
{
	if (user == nullptr)
	{
		cout << "No user is logged in.\n";
		return;
	}

	clearScreen();
	cout << "\n-------------------------\n";
	cout << "       User Profile     \n";
	cout << "-------------------------\n";
	cout << "ID:               " << user->id << endl;
	cout << "First Name:      " << user->firstName << endl;
	cout << "Last Name:       " << user->lastName << endl;
	cout << "Class:           " << user->className << endl;
	cout << "Gender:          " << user->gender << endl;
	cout << "Date of Birth:   " << user->dateofbirth.ngay << "/"
		<< user->dateofbirth.thang << "/"
		<< user->dateofbirth.nam << endl;
	cout << "Academic Year:   " << user->academicYear << endl;
	cout << "Staff:           " << (user->isStaff ? "Yes" : "No") << endl;
	cout << "-------------------------\n";
	cout << "Press Enter to go back to the menu.";
	cin.ignore();
}

void LoginMenu()
{
	while (true)
	{
		getList(); // Cập nhật danh sách người dùng mỗi lần lặp
		Menu(); // Hiển thị menu đăng nhập và lấy id, pass từ người dùng

		if (id == "0")
		{
			cout << "Quitting login process.\n";
			break; // Thoát vòng lặp nếu người dùng nhập id là "0"
		}

		current = login(id, pass); // Đăng nhập và cập nhật current

		if (current != nullptr)
		{
			cout << "Login successful\n";
			viewProfile(current);
			if (current->isStaff)
			{
				cout << "Welcome, staff!\n";
				academicstaffmember(); // Gọi hàm cho staff
			}
			else
			{
				cout << "Welcome, user!\n";
				StaffMenu();  // Gọi hàm cho user
			}
		}
		else
		{
			cout << "Login failed. Please try again.\n";
		}
	}

	system("cls"); // Xóa màn hình sau khi hoàn thành
}
