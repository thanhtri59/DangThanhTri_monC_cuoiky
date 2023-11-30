#include <iostream>
#include <cstring>
using namespace std;

class Bike {
private:
 	char* brand; // hiệu xe 
public:
	//constructor
	Bike(const char* brand = ""){
		this->brand = new char[strlen(brand)+1];
		strcpy(this->brand, brand);
	}
	//copy constructor 
	// Bike(const Bike& ptr){
	// 	brand = new char[strlen(ptr.brand)+1];
	// 	strcpy(brand, ptr.brand);
	// }


	 virtual void move(int t1) {
	 	cout << brand << ":" << t1*12 << " ";
	 } 
	 //destructor
	 virtual ~Bike(){
	 	delete[] brand;
	 }
};
class EBike : public Bike {
public: 
	//constructor
	EBike(const char* brand = "") : Bike(brand){}

 	void move(int t2) {
	 	Bike::move(t2*2);
	 }
};
void display(Bike& a, EBike& b) {
	 a.move(2);
	 b.move(2);
}
int main() {
	 // EBike b1("Mec"), b2("BMW"); 
	 EBike b1, b2; 
	 display(b1, b2);
	 return 0;
}