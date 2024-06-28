#include "AcademicStaff.h"
Date strToDate(const std::string& dateStr) 
{
    Date date;
   istringstream ss(dateStr);
   string token;
    getline(ss, token, '/');
    date.thang = stoi(token);
    getline(ss, token, '/');
    date.ngay = stoi(token);
    getline(ss, token);
    date.nam = stoi(token);
    return date;
}
int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int width = 80; // Giá trị mặc định nếu không thể lấy được chiều rộng
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return width;
}
void printCentered(const string& text)
{
    int consoleWidth = getConsoleWidth();
    int textWidth = text.length();
    int padding = (consoleWidth - textWidth) / 2;
    if (padding > 0) {
        cout << string(padding, ' ') << text << endl;
    }
    else {
        cout << text << endl;
    }
}
