#include <iostream>
#include <string>
#include <vector>
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

    // ===== Set =====
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

    // ===== Get =====
    string getName() { return name; }
    string getAddress() { return address; }
    string getCCCD() { return cccd; }
    Date getBirthdate() { return birthdate; }

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

// ===== Cac ham lay danh sach: tra ve vector, khong tra ve void =====

// Lay danh sach sinh vien sinh nam year
vector<Student> getStudentbyYear(int year, vector<Student> students) {
    vector<Student> ketQua;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getBirthdate().year == year) {
            ketQua.push_back(students[i]);
        }
    }
    return ketQua;
}

// Lay danh sach sinh vien theo dia chi
vector<Student> getStudentbyAddress(string address, vector<Student> students) {
    vector<Student> ketQua;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getAddress() == address) {
            ketQua.push_back(students[i]);
        }
    }
    return ketQua;
}

// Sap xep sinh vien theo ngay sinh (tu nho den lon), tra ve danh sach moi
vector<Student> sapXepTheoNgaySinh(vector<Student> students) {
    for (int i = 0; i < (int)students.size() - 1; i++) {
        for (int j = i + 1; j < students.size(); j++) {
            Date a = students[i].getBirthdate();
            Date b = students[j].getBirthdate();

            bool doiCho = false;
            if (b.year < a.year) {
                doiCho = true;
            } else if (b.year == a.year && b.month < a.month) {
                doiCho = true;
            } else if (b.year == a.year && b.month == a.month && b.day < a.day) {
                doiCho = true;
            }

            if (doiCho == true) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    return students;
}

// Lay danh sach cac nam sinh (khong trung) tu danh sach da sap xep
vector<int> layDanhSachNam(vector<Student> students) {
    vector<int> dsNam;
    for (int i = 0; i < students.size(); i++) {
        int year = students[i].getBirthdate().year;
        if (year == 0) {
            continue; // sinh vien chua co ngay sinh
        }

        bool daCo = false;
        for (int j = 0; j < dsNam.size(); j++) {
            if (dsNam[j] == year) {
                daCo = true;
            }
        }
        if (daCo == false) {
            dsNam.push_back(year);
        }
    }
    return dsNam;
}

// Lay danh sach cac tinh (khong trung)
vector<string> layDanhSachTinh(vector<Student> students) {
    vector<string> dsTinh;
    for (int i = 0; i < students.size(); i++) {
        string tinh = students[i].getAddress();
        if (tinh == "") {
            continue; // sinh vien chua co dia chi
        }

        bool daCo = false;
        for (int j = 0; j < dsTinh.size(); j++) {
            if (dsTinh[j] == tinh) {
                daCo = true;
            }
        }
        if (daCo == false) {
            dsTinh.push_back(tinh);
        }
    }
    return dsTinh;
}

// ===== Ham in ra man hinh =====

// In danh sach sinh vien
void display(vector<Student> s) {
    if (s.size() == 0) {
        cout << "Khong co sinh vien nao." << endl;
    }
    for (int i = 0; i < s.size(); i++) {
        s[i].getStudentInfo();
    }
}

// Thong ke so luong sinh vien theo nam sinh: 2000, 2001, ...
// (liet ke theo nam va dua theo ngay sinh)
void thongKeTheoNamSinh(vector<Student> students) {
    cout << "\n===== Thong ke theo nam sinh =====" << endl;

    vector<Student> daSapXep = sapXepTheoNgaySinh(students);
    vector<int> dsNam = layDanhSachNam(daSapXep);

    for (int i = 0; i < dsNam.size(); i++) {
        vector<Student> ds = getStudentbyYear(dsNam[i], daSapXep);
        cout << dsNam[i] << ": " << ds.size() << " sinh vien" << endl;

        for (int j = 0; j < ds.size(); j++) {
            Date d = ds[j].getBirthdate();
            cout << "   - " << ds[j].getName() << " ("
                 << d.year << "/" << d.month << "/" << d.day << ")" << endl;
        }
    }
}

// Thong ke theo tinh: ten tinh -> so luong
void thongKeTheoTinh(vector<Student> students) {
    cout << "\n===== Thong ke theo tinh =====" << endl;

    vector<string> dsTinh = layDanhSachTinh(students);

    for (int i = 0; i < dsTinh.size(); i++) {
        vector<Student> ds = getStudentbyAddress(dsTinh[i], students);
        cout << dsTinh[i] << " -> " << ds.size() << endl;
    }
}

int main() {
    Student student1;
    Student student2("Huong");
    Student student3("An", "Vo Van Ngan");

    Date d(1989, 9, 12);
    Student student4("DoMIXI", "Ha Noi", d, "0007777056");

    Date d2(1996, 10, 26);
    Student student5("DungSenpai", "Da Nang", d2, "999993884");

    Student student6("Binh", "Ha Noi", Date(2006, 3, 15), "001");
    Student student7("Lan", "Da Nang", Date(2006, 11, 2), "002");
    Student student8("Minh", "Ha Noi", Date(2000, 6, 20), "003");
    Student student9("Nga", "Thu Duc", Date(2001, 1, 9), "004");
    Student student10("Phong", "Thu Duc", Date(2000, 12, 30), "005");

    // tao mang khoang 10 sinh vien
    vector<Student> students;
    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);
    students.push_back(student5);
    students.push_back(student6);
    students.push_back(student7);
    students.push_back(student8);
    students.push_back(student9);
    students.push_back(student10);

    // lay danh sach sinh vien sinh nam 2006 roi in ra
    cout << "===== Sinh vien sinh nam 2006 =====" << endl;
    vector<Student> s = getStudentbyYear(2006, students);
    display(s);

    // nhap dia chi muon tim
    string address;
    cout << "\nNhap dia chi muon tim kiem: ";
    getline(cin, address);

    vector<Student> s2 = getStudentbyAddress(address, students);
    cout << "\nDanh sach sinh vien o dia chi " << address << ":" << endl;
    display(s2);

    // thong ke
    thongKeTheoNamSinh(students);
    thongKeTheoTinh(students);

    return 0;
}