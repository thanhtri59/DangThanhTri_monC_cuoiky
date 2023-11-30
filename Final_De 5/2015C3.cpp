#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Sap
{
private:
	string ten;
	double sothutu, dientich, dichvudonglanh, doanhthu;
	double dongia = 40000000; //(vnd/m2/nam)
public:
	void Nhap(){
		cout << "HOP DONG THUE SAP" << endl;
		cout << "Nhap ten chu so huu: ";
		cin >> ws;
		getline(cin, ten);
		cout << "Nhap so thu tu sap: ";
		cin >> sothutu;
		cout << "Nhap dien tich sap: ";
		cin >> dientich;
		cout << "Nhap so tien tra cho dich vu dong lanh: ";
		cin >> dichvudonglanh;
	}
	string getTen(){
		return this->ten;
	}
	void inputDoanhThu(double dt){
		this->doanhthu = dt;
	}
	double getDoanhThu(){
		return this->doanhthu;
	}
	double getDonGia(){
		return this->dongia;
	}
	double getDienTich(){
		return this->dientich;
	}
	double getDVDL(){
		return this->dichvudonglanh;
	}
	void print(double tien){
		cout << "Sap thu "<< sothutu << " cua ong/ba " << ten << " phai tra so tien thue la: " << fixed << setprecision(0) << tien << " VND."<< endl;
	}
	virtual ~Sap(){};
};

class ThucPham : public Sap{
private:
	double thuedoanhthu = 5; //%
public:
	ThucPham(){
		Nhap();
	}
	double calTong(){
		return getDonGia()*getDienTich() + getDoanhThu()*(thuedoanhthu/100) + getDVDL();
	}
};

class QuanAo : public Sap{
private:
	double thuedoanhthu = 10; //%
public:
	QuanAo(){
		Nhap();
	}
	double calTong(){
		return getDonGia()*getDienTich() + getDoanhThu()*(thuedoanhthu/100)+ getDVDL();
	}
};

class TrangSuc : public Sap{
private:
	double thuedoanhthu; //%
public:
	TrangSuc(){
		Nhap();
	}
	double calTong(){
		if(getDoanhThu() < 100000000)
			this->thuedoanhthu = 20;
		else
			this->thuedoanhthu = 30;
		return getDonGia()*getDienTich() + getDoanhThu()*(this->thuedoanhthu/100)+ getDVDL();
	}
};


int main(){
	int n,temp;
	vector<Sap*>sap;
	cout << "Nhap so luong sap: "; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Vui long chon loai mat hang (1-Thuc pham, 2-Quan ao, 3-Trang suc): ";
		cin >> temp;
		switch (temp){
		case 1:
			sap.push_back(new ThucPham());
			break;
		case 2:
			sap.push_back(new QuanAo());
			break;
		case 3:
			sap.push_back(new TrangSuc());
			break;
		}
	}
	cout << "Nhap doanh thu: " << endl;
	double b;
	for (int i = 0; i < n; i++)
	{
		cout << "Chu so huu " << sap[i]->getTen() << endl;
		cout << "Doanh thu: ";
		cin >> b;
		sap[i]->inputDoanhThu(b);
	}
	for (int i = 0; i < n; i++)
	{
		ThucPham* tp = dynamic_cast<ThucPham*>(sap[i]);
		QuanAo* qa = dynamic_cast<QuanAo*>(sap[i]);
		TrangSuc* ts = dynamic_cast<TrangSuc*>(sap[i]);
		if(tp != nullptr)
			sap[i]->print(tp->calTong());
		else if(qa != nullptr)
			sap[i]->print(qa->calTong());
		else if(ts != nullptr)
			sap[i]->print(ts->calTong());
	}
	return 0;
}