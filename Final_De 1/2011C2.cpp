#include <iostream>
using namespace std;


class MayXucTac{
private:
	float dongia = 80000;
	float congsuat;
	float congsuatthucte;
	float hoachat;
	float tgian;
public:
	static const float DON_GIA_HOA_CHAT;
	void setCongSuat(float cs){
		this->congsuat = cs;
	}
	float getCongSuat(){
		return this->congsuat;
	}
	void setHoaChat(float hc){
		this->hoachat = hc;
	}
	void setTgian(float time){
		this->tgian = time;
	}
	float getTgian(){
		return this->tgian;
	}
	void calCSTT(){
		if(this->getTgian() < 10)
			this->congsuatthucte = this->congsuat * (this->hoachat/100);
		else
			this->congsuatthucte = this->congsuat * (this->hoachat/100)/(this->getTgian()/10);
	}
	int TinhTien(){
		return this->dongia * this->getTgian() + this->hoachat * DON_GIA_HOA_CHAT;
	}
	float tinhLuongNuoc(){
		this->calCSTT();
		return this->congsuatthucte * this->getTgian();
	}
	void nhap(){
		float temp;
		cout << "Nhap cong suat: ";
		cin >> temp;
		setCongSuat(temp);
		cout << "Nhap luong hoa chat: ";
		cin >> temp;
		setHoaChat(temp);
		cout << "Nhap so gio thue: ";
		cin >> temp;
		setTgian(temp);
	}
};

const float MayXucTac::DON_GIA_HOA_CHAT = 10000;
int main() {
	cout << "Don gia hoa chat: " << MayXucTac::DON_GIA_HOA_CHAT << endl;
	MayXucTac m;
	m.nhap();
	cout << "Chi phi su dung may: " << m.TinhTien() << endl;
	cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << endl;
	return 0;
}