#include <iostream>
using namespace std;

class IFace {
public:
	 virtual void show()=0;
	 virtual IFace* clone()=0;
	 virtual ~IFace() {
	 }
};
class Face : public IFace {
private:
 	string shape;
protected:
 	string getShape();
public:
 	Face(string sh) : shape(sh) {}
	 virtual void show() {
	 	cout << "Shape: " << shape << endl;
	 }
	 //------fix 2b------
	 Face* clone(){
	 	return new Face(*this);
	 }
	 //-------------------
};
class EyedFace : public IFace{
private:
	string shape;
	int eyes;
public:
	//constructor
	EyedFace(string sh, int eyes){
		this->shape = sh;
		this->eyes = eyes;
		count ++; //2c muc 2
	}
	//phuong thuc show
	virtual void show(){
		cout << "Shape: " << shape << ", " << "eyes: " << eyes << endl;
	}
	//phuong thuc clone
	EyedFace* clone(){
		return new EyedFace(*this);
	}
	//----------2c muc 2---------------
	static int count;
	~EyedFace(){
		count--;
	}
	//-----------------------------------
};

void testFace(IFace* fc) {
	 IFace* a[3] = { fc, fc->clone(), fc->clone() };
	 for(int i=0; i<3; i++) {
	 	a[i]->show();
	 	delete a[i]; //cau 2c muc 1
	 }
	 cout << "The same 3 lines?";
}

int EyedFace::count = 0; //cau 2c muc 2

int main() {
	 // Face fc;
	 Face fc1("Rectangle"); 
	 testFace(&fc1);
	 cout << "\n";
	 cout << "So luong doi tuong EyedFace trong bo nho: " << EyedFace::count << endl; //cau 2c muc 2
	 return 0;
}