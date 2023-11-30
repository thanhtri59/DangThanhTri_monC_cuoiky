#include <iostream>
using namespace std;

class SucVat{
public:
	virtual void Keu(){
		cout << "Dong vat keu ..." << endl;
	}
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
    SucVat* sucvat1 = new Meo();
    SucVat* sucvat2 = new Cho();
    sucvat1->Keu(); 
    sucvat2->Keu(); 
    delete sucvat1;
    delete sucvat2;
    return 0;
}