#include <iostream>
#include <string>

using namespace std;

class BigInteger{
private:
	string chuoi;
public:
	//khoi tao mac dinh = 0
	BigInteger() : chuoi("0"){}
	//khoi tao tu chuoi
	BigInteger(const string& str){
		this->chuoi = str;
	}

	//so sanh bang nhau
	bool operator==(const BigInteger& ptr) const { //const de dam bao tinh toan ven cua du lieu sau khi so sanh, ngoai ra cung cho phep ham goi tren cac bien const
		return chuoi == ptr.chuoi;
	}
	//operator nhap >>
	friend istream& operator>>(istream& in, BigInteger& ptr){
		in >> ptr.chuoi;
		return in;
	}

};

int main() {
	 BigInteger n1("123456"); // Khởi tạo từ chuỗi.
	 BigInteger n2; // Khởi tạo mặc định = 0.
	 cout << "Input an integer = ";
	 cin >> n2;
	 if ( n1 == n2 ) // So sánh bằng nhau.
	 	cout << "Equal.\n";
	 else
	 	cout << "Not equal.\n";
}