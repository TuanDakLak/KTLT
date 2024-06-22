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