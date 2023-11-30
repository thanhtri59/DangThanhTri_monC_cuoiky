#include <iostream>
#include <cmath>
using namespace std;


class Cang {
private:
	int a,b;
public:
	//constructor
	Cang(int a = 0, int b = 0){
		this->a = a;
		this->b = b;
	}
	//Nhap
	void Nhap(){
		cout << "Nhap a, b dang a + b(Cang7): ";
		cin >> a >> b;
	}

	//xuat
	void Xuat(){
		if(a==0 && b == 0)
			cout << "\n";
		else if(a==0 && b != 0)
			cout << b << "(Cang7)" << endl;
		else if(a != 0 && b == 0)
			cout << a << endl;
		else if(b<0)
			cout << a << b << "(Cang7)" << endl;
		else
			cout << a << "+" << b << "(Cang7)" << endl;
		// cout << a << "+" << b << "(Cang7)" << endl;
	}

	//Cong
	Cang operator+(const Cang& num){
		return Cang(a + num.a, b + num.b);
	}
	//Tru
	Cang operator-(const Cang& num){
		return Cang(a - num.a, b - num.b);
	}
	//Doi dau
	Cang operator-(){
		return Cang(-a, -b);
	}
	//Nhan
	Cang operator*(const Cang& num){
		return Cang(a * num.a + 7 * b * num.b, a * num.b + b * num.a);
	}
};

int main(){
	cout << "Nhap so thu 1: ";
	Cang c;
	c.Nhap();
	cout << "Nhap so thu 2: ";
	Cang e;
	e.Nhap();
	cout << "So thu nhat la: ";
	c.Xuat();
	cout << "So thu hai la: ";
	e.Xuat();
	Cang kq;
	cout << "So thu nhat + so thu hai = ";
	kq = c + e;
	kq.Xuat();
	cout << "So thu nhat - so thu hai = ";
	kq = c - e;
	kq.Xuat();
	cout << "So thu nhat * so thu hai = ";
	kq = c * e;
	kq.Xuat();
	cout << "So thu nhat doi dau = ";
	kq = -c;
	kq.Xuat();
}