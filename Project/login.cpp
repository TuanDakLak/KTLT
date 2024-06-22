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
User* convertUserData(ifstream& data)
{
	User* u = new User;
	Date dateofBirth; 
	string p; 
	getline(data, u->id, ','); 
	if (u->id = "")return NULL;
	getline(data, u->password, ',');
	getline(data, u->lastName, ',');
	getline(data, u->firstName, ',');
	getline(data, u->className, ',');
	getline(data, u->gender, ',');
	getline(data, p, ',');
	// Viết hàm strToDate; 
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
	u->next = NULL; 
	u->prev = NULL;
	return u; 
	f.close();
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
		if (id == data->id)
		{
			if (pass == tmp->password)
				return tmp;
			else
				return NULL;
		}
		tmp = tmp->next; 
		// Duyệt hết danh sách 
	}
}
string getPass(bool isHidden) 
{
	string pass;
	char ch;
	while ((ch = getchar()) != '\n') {
		if (ch == '\b') { // Handle backspace
			if (!pass.empty()) {
				std::cout << "\b \b";
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
void Menu()
{
	cout << "\n-------------------------\n";
	cout << "		Login		" << endl;
	cout << "ID:"; 
	cout << "Password: "; 
	getline(cin, id); 
	password = getPass(true);
	current = login(id, pass); 
	cout << "\n---------------------------\n";
}
void  LoginMenu()
{
	getList();
	while (true)
	{
		Menu();
		if (current == nullptr)
		{
			cout << "Login failed \n";
		}
		else
		{
			cout << "Login successful \n";
			break;
		}

	}

	if (current->isStaff)
	{
		academicstaffmember();
	}
	else
	{
		tu6_11();
	}
	system("cls");

}