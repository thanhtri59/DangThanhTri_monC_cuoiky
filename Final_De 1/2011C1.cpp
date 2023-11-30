#include <iostream>
using namespace std;


class MayLoc {
private:
 	float m_tgian;
protected:
	virtual float congSuat(){
		return 0;
	}
 	void setTgian(float t){
	 	this->m_tgian = t;
	}
public:
	MayLoc() {
	 	this->m_tgian = 0;
	}
 	float tinhLuongNuoc() {
	 	return congSuat()* m_tgian;
	}
};
// float MayLoc::congSuat() {
//  	return 0;
// }

class MayLyTam: public MayLoc {
private:
 	float m_cs;
protected:
	float congSuat(){
		return this->m_cs;
	};
public:
 	MayLyTam(float cs, float t) {
	 	this->m_cs = cs;
		this->setTgian(t); /*1*/ // da duoc thay the cho this->m_tgian = t;
	}
};

// float MayLoc::congSuat() {
// 	return this->cs;
// }

int main() {
	 MayLoc *pm = new MayLoc(); //goi constructor cua class mayloc, cho con tro pm tro den doi tuong moi
	 // if (pm->congSuat() < 5) /*2*/
	 // {
		 MayLyTam ml(81.9, 10); //goi constructor cua Maylytam, duoi tuong ml duoc tao tren stack
		 delete pm;  //sau dong pm = &ml thi pm ko con tro den doi tuong duoc tao bang new, neu delete se sinh ra loi
		 pm = &ml; /*3*/
		 cout << "Luong nuoc = "
		 << pm->tinhLuongNuoc();
	 // }
	 // delete pm; /*4*/ //sau dong pm = &ml thi pm ko con tro den doi tuong duoc tao bang new, neu delete se sinh ra loi
	 return 0;
}