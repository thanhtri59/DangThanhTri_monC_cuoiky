#include <math.h>
#include <stdio.h>
using namespace std;


class Function {
public:
	virtual double Value(double x)=0;
	virtual double Derive(double x)=0;
};

class Sin : public Function {
public:
	double Value(double x) {
		return sin(x);
	}
	double Derive(double x) {
		return cos(x);
	}
};

//----------------3b - code them class Cos--------------

class Cos : public Function {
public:
	double Value(double x) {
		return cos(x);
	}
	double Derive(double x) {
		return -sin(x); //dao ham cua cos(x) la -sin(x)
	}
};

//--------------------------------------

double DeriveProduct(Function* f, Function* g, double x)
{
	if (f != NULL && g != NULL) {
		return f->Derive(x)*g->Value(x) + f->Value(x)*g->Derive(x);
	}
	return 0;
}

double DeriveSum(Function* f, Function* g, double x)
{
	if (f != NULL && g != NULL) {
		return f->Derive(x) + g->Derive(x);
	}
	return 0;
}

double DeriveHamThuong(Function* f, Function* g, double x){
	if (f != NULL && g != NULL) {
		return (f->Derive(x)*g->Value(x) - f->Value(x)*g->Derive(x))/pow(g->Value(x),2);
	}
	return 0;
}

double DeriveHamHop(Function* f, Function* g, double x){
	if (f != NULL && g != NULL) {
		return f->Derive(g->Value(x))*g->Derive(x);
	}
	return 0;
}

//-------Ham Sin sau khi fix danh cho cau 3d-----------

// class Sin : public Function {
// private:
// 	Sin() {}
// 	static Sin* instance;

// public:
// 	static Sin* getInstance() {
// 	        if (!instance)
// 	            	instance = new Sin;
// 	        return instance;
// 	}

// 	double Value(double x) {
// 		return sin(x);
// 	}
// 	double Derive(double x) {
// 		return cos(x);
// 	}
// };

//-----------------------------------------------------------
// Sin* Sin::instance = 0;
int main() {
	double x = 3.14/6; // PI/6
	// Sin* s = Sin::getInstance();	
	Sin* s = new Sin();
	Cos* c = new Cos();
	double y = DeriveProduct(s, c, x);
	printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
	printf("cos(x) = %f; cos'(x) = %f\n", c->Value(x), c->Derive(x));
	printf("After DeriveProduct, y = %f\n", y);
	y = DeriveSum(s, c, x);
	printf("After DeriveSum, y = %f\n", y);
	y = DeriveHamThuong(s, c, x);
	printf("After DeriveHamThuong, y = %f\n", y);
	y = DeriveHamHop(s, c, x);
	printf("After DeriveHamHop, y = %f\n", y);
	delete s;
	delete c;
	return 0;
}