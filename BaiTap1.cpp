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
    else cout << ps.tu << "/" << ps.mau << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);    
    PhanSo ps;
    nhap(ps);
    rutgon(ps);
    cout << "Phan so sau khi rut gon: ";
    xuat(ps);

    return 0;
}
