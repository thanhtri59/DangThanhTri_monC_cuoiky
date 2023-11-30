#include <iostream>
using namespace std;

//lop truu tuong
class SucVat{
public:
	virtual void Keu() = 0; //khong co body {}
};

class Meo : public SucVat{
public:
	void Keu() override {
		cout << "Keu meo meo" << endl;
	}
};

class Cho : public SucVat{
public:
	void Keu() override {
		cout << "Keu gau gau" << endl;
	}
};

int main() {
    // SucVat a; //khong the tao truc tiep tren lop truu tuong, nen phan nay se sai
	//tao doi tuong tu lop dan xuat
    Meo b;
    b.Keu(); //goi ham keu()
    return 0;
}