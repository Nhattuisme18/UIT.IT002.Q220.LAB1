#include <iostream>
#include <string>

using namespace std;

struct hocsinh {
    string hoten;
    double diemtoan;
    double diemvan;
};

double diemtrungbinh(double a, double b) {
    return (a + b) / 2;
}

void InAndOut(hocsinh& hs) {
    cout << "Nhap ho va ten hoc sinh: ";
    getline(cin, hs.hoten);

    while (1) {
        cout << "Nhap diem toan cua hoc sinh: ";
        cin >> hs.diemtoan;
        if (hs.diemtoan >= 0 && hs.diemtoan <= 10) {
            break;
        }
        cout << "Diem khong hop le, xin moi nhap lai\n";
    }

    while (1) {
        cout << "Nhap diem van cua hoc sinh: ";
        cin >> hs.diemvan;
        if (hs.diemvan >= 0 && hs.diemvan <= 10) {
            break;
        }
        cout << "Diem khong hop le, xin moi nhap lai\n";
    }

    cout << "Diem TB cua hoc sinh la: " << diemtrungbinh(hs.diemtoan, hs.diemvan) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);

    hocsinh a;
    InAndOut(a);

    return 0;
}
