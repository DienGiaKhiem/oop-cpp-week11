#include <iostream>
#include <string>
using namespace std;

class Date {
public:
    int year, month, day;
    Date() { year = 0; month = 0; day = 0; }
    Date(int y, int m, int d) { year = y; month = m; day = d; }
};

class Student {
private:
    string name;
    string address;  
    Date birthdate; // yyyy/mm/dd
    string cccd; 

public: 
    // ===== Constructors =====
    Student() {
        name = ""; 
        address = "";
        birthdate = Date(); 
        cccd = "";
    }

    Student(string n) {
        name = n; 
        address = "";
        birthdate = Date(); 
        cccd = "";
    }  

    Student(string n, string addr) {
        name = n; 
        address = addr;
        birthdate = Date(); 
        cccd = "";
    }

    Student(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d; 
        cccd = "";
    }

    Student(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d; 
        cccd = id;
    }
    
    // ===== Methods =====
    void setStudentInfo(string n) {
        name = n;
    }

    void setStudentInfo(string n, string addr) {
        name = n;
        address = addr;
    }

    void setStudentInfo(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
    }

    void setStudentInfo(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    void getStudentInfo() {
        cout << "====================" << endl;
        cout << "=== Student Info ===" << endl;
        cout << "====================" << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: " << birthdate.year << "/" << birthdate.month << "/" << birthdate.day << endl;
        cout << "CCCD: " << cccd << endl;

    }
};

int main() {
    Student student1;                          
    Student student2("Huong");                 
    Student student3("An", "Vo Van Ngan");     

    Date d(1989, 9, 12);
    Student student4("DoMIXI", "Ha Noi", d, "0007777056"); 

    Date d2(1996, 10, 26);
    Student student5("DungSenpai", "Da Nang", d2, "999993884"); 

    student2.getStudentInfo();
    student3.getStudentInfo();
    student4.getStudentInfo();
    student5.getStudentInfo();

    return 0;
}