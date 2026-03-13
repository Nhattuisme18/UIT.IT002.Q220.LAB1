#include <iostream>

using namespace std;

struct date {
    int d;
    int m;
    int y;
};

bool kiemtranamnhuan(int a) {
    if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) return true;
    return false;
}

int songaytrongthang(int month, int year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if (kiemtranamnhuan(year)) return 29;
            else return 28;
        default:
            return 0;
    }
}

bool kiemTraHopLe(date ngay) {
    if (ngay.y < 1) return false;
    if (ngay.m < 1 || ngay.m > 12) return false;
    if (ngay.d < 1 || ngay.d > songaytrongthang(ngay.m, ngay.y)) return false;
    return true;
}

void nhapngaythangnam(date& ngay) {
    while (1) {
        cout << "Nhap ngay: ";
        cin >> ngay.d;
        cout << "Nhap thang: ";
        cin >> ngay.m;
        cout << "Nhap nam: ";
        cin >> ngay.y;

        if (kiemTraHopLe(ngay)) {
            break;
        }
        cout << "Ngay khong hop le, vui long nhap lai!\n";
    }
}

void Thenextday(date& ngay) {
    ngay.d++;
    if (ngay.d > songaytrongthang(ngay.m, ngay.y)) {
        ngay.d = 1;
        ngay.m++;
        if (ngay.m > 12) {
            ngay.m = 1;
            ngay.y++;
        }
    }
    cout << "Ngay tiep theo la ngay: " << ngay.d << "/" << ngay.m << "/" << ngay.y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);

    date ngay;
    nhapngaythangnam(ngay);
    Thenextday(ngay);

    return 0;
}
