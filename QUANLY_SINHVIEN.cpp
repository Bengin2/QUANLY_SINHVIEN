// nhom so 6
//tran thanh tri ---- Nguyen thi tuong vy

#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

class Person {
public:
    string ten, gioiTinh;
    int day, month, year;

    virtual void nhap() {
        cout << "Nhap ho va ten: ";
        fflush(stdin);
        do {
            getline(cin, ten);
        } while (ten.length() == 0 || !kiemTraHoTen(ten));

        cout << "Nhap ngay thang nam sinh(dd/mm/yyyy): ";
        do {
            cin >> day >> month >> year;
            if (!setDate(day, month, year)) {
                cout << "Nhap sai moi ban nhap lai: ";
            }
        } while (!setDate(day, month, year));

        cout << "Nhap gioi tinh: ";
        fflush(stdin);
        getline(cin, gioiTinh);
    }

    virtual void in() {
        cout << "******************************************************\n";
        cout << " Ho ten : " << ten << endl;
        cout << " Ngay thang nam sinh : " << day << "/" << month << "/" << year << endl;
        cout << " Gioi tinh : " << gioiTinh << endl;
        cout << "******************************************************\n";
    }

    bool setDate(int day, int month, int year) {
        if (year < 0) {
            return false;
        } else {
            if (month < 1 || month > 12) {
                return false;
            } else {
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                    if (day < 1 || day > 31) {
                        return false;
                    }
                } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                    if (day < 1 || day > 30) {
                        return false;
                    }
                } else if (month == 2) {
                    if (year % 4 == 0 && (year % 400 == 0 && year % 100 != 0)) {
                        if (day < 1 || day > 29) {
                            return false;
                        }
                    } else {
                        if (day < 1 || day > 28) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool kiemTraHoTen(string hoTen) {
        for (int i = 0; i < hoTen.length(); i++) {
            if (!((hoTen[i] >= 'a' && hoTen[i] <= 'z') || (hoTen[i] >= 'A' && hoTen[i] <= 'Z') || hoTen[i] == ' ')) {
                return false;
            }
        }
        return true;
    }
};

class Student : public Person {
public:
    string lop, mssv;
    float diemThanhPhan, diemGiuaKy, diemCuoiKy;

    void nhap() override {
        Person::nhap();

        cout << "Nhap lop cua sinh vien: ";
        cin >> lop;

        cout << "Nhap ma sinh vien: ";
        do {
            cin >> mssv;
            if (!kiemTraMaSo(mssv)) {
                cout << "Nhap sai moi ban nhap lai: ";
            }
        } while (!kiemTraMaSo(mssv));

        do {
            cout << "Nhap diem thanh phan: ";
            cin >> diemThanhPhan;
        } while (diemThanhPhan < 0 || diemThanhPhan > 10);

        do {
            cout << "Nhap diem giua ky: ";
            cin >> diemGiuaKy;
        } while (diemGiuaKy < 0 || diemGiuaKy > 10);

        do {
            cout << "Nhap diem cuoi ky: ";
            cin >> diemCuoiKy;
        } while (diemCuoiKy < 0 || diemCuoiKy > 10);
    }

    void in() override {
        Person::in();
        cout << " Lop sinh vien : " << lop << endl;
        cout << " Ma sinh vien : " << mssv << endl;
        cout << " Diem thanh phan : " << diemThanhPhan << endl;
        cout << " Diem giua ky : " << diemGiuaKy << endl;
        cout << " Diem cuoi ky : " << diemCuoiKy << endl;
        cout << " Diem trung binh : " << diemTB() << endl;
        cout << " Hoc luc : " << HocLuc() << endl;
        cout << "******************************************************\n";
    }

    bool kiemTraMaSo(string mssv) {
        for (int i = 0; i < mssv.length(); i++) {
            if (!(mssv[i] >= '0' && mssv[i] <= '9')) {
                return false;
            }
        }
        return true;
    }

    float diemTB() {
        return (diemThanhPhan + diemGiuaKy + diemCuoiKy) / 3;
    }

    string HocLuc() {
        string hl;
        if (diemTB() >= 9)
            hl = "Xuat sac";
        else if (diemTB() >= 8)
            hl = "Gioi";
        else if (diemTB() >= 6.5)
            hl = "Kha";
        else if (diemTB() >= 5)
            hl = "Trung binh";
        else
            hl = "Yeu";

        return hl;
    }

    void Xuat() {
        cout << setw(12) << ten << setw(12) << lop << setw(12) << mssv << setw(12) << gioiTinh;
        cout << setw(12) << diemThanhPhan << setw(12) << diemGiuaKy << setw(12) << diemCuoiKy << setw(12) << diemTB() << setw(12) << HocLuc() << endl;
    }
};

typedef Student SINHVIEN;

void nhapSVT(SINHVIEN a[], int &n) {
    do {
        cout << "Nhap so luong sinh vien(>0): ";
        cin >> n;
        if (n <= 0) {
            cout << "Moi ban nhap lai" << endl;
        }
    } while (n <= 0);

    for (int i = 0; i < n; i++) {
        int res = 0;
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;

        a[i].nhap();
        for (int j = 0; j < i; j++) {
            if (a[j].mssv == a[i].mssv) {
                cout << "Trung ma so sinh vien! Moi ban nhap lai." << endl;
                res++;
            }
        }
        res++;
    }
}

void inds(SINHVIEN a[], int n) {
    cout << "THONG TIN DANH SACH SINH VIEN:\n";
    for (int i = 0; i < n; i++) {
        a[i].in();
    }
}

void tieuDe() {
    cout << setw(12) << "Ho ten" << setw(12) << "Lop" << setw(12) << "MSSV" << setw(12) << " Gioi tinh" << setw(12) << "Diem TP" << setw(12) << "Diem GK";
    cout << setw(12) << "Diem CK" << setw(12) << "Diem TB" << setw(12) << "Hoc Luc" << endl;
}

void XuatSV(SINHVIEN a[], int n) {
    cout << "Danh sach sinh vien: " << endl;
    tieuDe();
    for (int i = 0; i < n; i++) {
        a[i].Xuat();
    }
}

void themSV(SINHVIEN a[], int &n) {
    n++;
    int res = 0;
    do {
        cout << "Nhap thong tin cua sinh vien muon them: " << endl;
        a[n - 1].nhap();
        for (int i = 0; i < n - 1; i++) {
            if (a[i].mssv == a[n - 1].mssv) {
                cout << "Trung ma so sinh vien! Xin moi nhap lai" << endl;
                res++;
            }
        }
    } while (res != 0);
}

void xoa(SINHVIEN a[], int &n, int viTriXoa) {
    if (viTriXoa >= n - 1) {
        n--;
    } else {
        for (int i = viTriXoa; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;
    }
}

void xoaSV(SINHVIEN a[], int &n) {
    string socx;
    int res = 0;
    cout << "Nhap ma so sinh vien can xoa: ";
    cin >> socx;
    for (int i = 0; i < n; i++) {
        if (a[i].mssv == socx) {
            res++;
            xoa(a, n, i);
            break;
        }
    }
    if (res == 0) {
        cout << "Ma so sinh vien vua nhap khong ton tai!" << endl;
    } else {
        cout << "Da xoa thanh cong!" << endl;
    }
}

void chinhsua(SINHVIEN a[], int &n) {
    string socs;
    cout << "Nhap ma so sinh vien can chinh sua: ";
    cin >> socs;
    for (int i = 0; i < n; i++) {
        if (a[i].mssv == socs) {
            a[i].nhap();
        }
    }
}

float Max(SINHVIEN a[], int n) {
    float max = a[0].diemTB();
    for (int i = 1; i < n; i++) {
        if (a[i].diemTB() > max) {
            max = a[i].diemTB();
        }
    }
    return max;
}

void gpacaonhat(SINHVIEN a[], int n) {
    cout << "Danh sach sinh vien co diem trung binh cao nhat:\n";
    tieuDe();
    for (int i = 0; i < n; i++) {
        if (a[i].diemTB() == Max(a, n)) {
            a[i].Xuat();
        }
    }
}

float Min(SINHVIEN a[], int n) {
    float min = a[0].diemTB();
    for (int i = 1; i < n; i++) {
        if (a[i].diemTB() < min) {
            min = a[i].diemTB();
        }
    }
    return min;
}

void gpathapnhat(SINHVIEN a[], int n) {
    cout << "Danh sach sinh vien co diem trung binh thap nhat:\n";
    tieuDe();
    for (int i = 0; i < n; i++) {
        if (a[i].diemTB() == Min(a, n)) {
            a[i].Xuat();
        }
    }
}

void tksv(SINHVIEN a[], int n) {
    string mssv;
    int res = 0;
    cout << "Nhap ma so sinh vien can tim kiem: ";
    cin >> mssv;
    for (int i = 0; i < n; i++) {
        if (a[i].mssv == mssv) {
            a[i].in();
            res++;
            break;
        }
    }
    if (res == 0) {
        cout << "Ma so vua nhap khong co trong danh sach!" << endl;
    }
}

int main() {
    SINHVIEN a[1000];
    int n = 0;
    while (true) {
        cout << "=========================QUAN LI SINH VIEN=========================\n";
        cout << " 1. Nhap danh sach cua sinh vien\n";
        cout << " 2. Hien thi danh sach cua sinh vien\n";
        cout << " 3. Them thong tin 1 sinh vien\n";
        cout << " 4. Xoa thong tin 1 sinh vien\n";
        cout << " 5. Liet ke cac sinh vien co diem trung binh cao nhat\n";
        cout << " 6. Liet ke cac sinh vien co diem trung binh thap nhat\n";
        cout << " 7. Tim sinh vien bang ma so sinh vien\n";
        cout << " 0. Thoat\n";
        cout << "===================================================================\n";
        cout << "Moi nhap lua chon\n";
        int luaChon;
        cin >> luaChon;
        if (luaChon == 1) {
            nhapSVT(a, n);
        } else if (luaChon == 2) {
            inds(a, n);
        } else if (luaChon == 3) {
            themSV(a, n);
        } else if (luaChon == 4) {
            xoaSV(a, n);
        } else if (luaChon == 5) {
            gpacaonhat(a, n);
        } else if (luaChon == 6) {
            gpathapnhat(a, n);
        } else if (luaChon == 7) {
            tksv(a, n);
        } else if (luaChon == 0) {
            break;
        }
    }
    return 0;
}

