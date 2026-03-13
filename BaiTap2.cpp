#include <iostream>
#include <cmath>
using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

int UCLN (int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a*b != 0) {
        if (a<b) {
            b %= a;
        } else a %= b;
    }
    return a+b;
}

void rutgon(PhanSo& ps) {
    int UOCCHUNG = UCLN(ps.tu, ps.mau);
    ps.tu /= UOCCHUNG;
    ps.mau /= UOCCHUNG;

    if (ps.mau < 0) {
        ps.tu *= -1;
        ps.mau *= -1;
    }
}

void nhap(PhanSo &ps) {
    cout << "Nhap tu so: "; cin >> ps.tu;
    while(1){
        cout << "Nhap mau so (khac 0): ";
        cin >> ps.mau;
        if (ps.mau != 0) {
            break;
        }
        cout <<"Vui long nhap lai mau so\n";
    }
}

void xuat(PhanSo ps) {
    if (ps.mau == 1) cout << ps.tu;
    else if (ps.tu == 0) cout << 0;
    else cout << ps.tu << "/" << ps.mau;
}

void xuatLonNhat(PhanSo ps1, PhanSo ps2) {
    if (ps1.tu == ps2.tu && ps1.mau == ps2.mau) {
        cout << "Hai phan so bang nhau\n";
    } else if (ps1.tu * ps2.mau > ps2.tu * ps1.mau) {
        cout << "Phan so lon nhat la: ";
        xuat(ps1);
        cout << '\n';
    } else {
        cout << "Phan so lon nhat la: ";
        xuat(ps2);
        cout << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);

    PhanSo ps1, ps2;
    cout << "--- NHAP PHAN SO 1 ---\n";
    nhap(ps1);
    cout << "--- NHAP PHAN SO 2 ---\n";
    nhap(ps2);

    rutgon(ps1);
    rutgon(ps2);

    xuatLonNhat(ps1, ps2);
    return 0;
}
