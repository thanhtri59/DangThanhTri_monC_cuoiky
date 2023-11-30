#include <iostream>
#include <vector>
#include <string>

using namespace std;

class KhachHang{
private:
	string Hovaten, address;
	int cmnd;
public:
	int dongiagoi = 1000; //(đ / phut)
	int dongiadata = 200; //(đ / MB)
	int thoigian,data;
	void NhapKhachHang(){
		cout << "HOP DONG" << endl;
		cout << "Nhap ho va ten: ";
		cin >> ws;
		getline(cin, Hovaten);
		cout << "Nhap so cmnd: ";
		cin >> cmnd;
		cout << "Nhap dia chi: ";
		cin >> ws;
		getline(cin, address);
	}
	void print(int tongtien){
		cout << "-------------------------------------------"<<endl;
		cout << "Khach Hang: "<< Hovaten << endl;
		cout << "So cmnd: " << cmnd << endl;
		cout << "Dia chi: "<< address << endl;
		cout << "Da su dung: " << data << " MB; goi dien thoai: " << thoigian <<" phut!" << endl;
		cout << "So tien phai tra la: " << tongtien << ", chuc quy khach mot ngay vui!" << endl;
		cout << "-------------------------------------------"<<endl;
	}
	void inputTimeandData(int t, int data){
		this->thoigian = t;
		this->data = data;
	}
	int calDienThoai(){
		return this->thoigian*this->dongiagoi;
	}
	int calData(){
		return this->data*this->dongiadata;
	}
	int getData(){
		return this->data;
	}
	string getTen(){
		return this->Hovaten;
	}
	virtual int calTong(){
		return 0;
	};
	virtual ~KhachHang(){};
};

class Basic : public KhachHang{
public:
	Basic(){
		NhapKhachHang();
	}
	int calTong(){
		int cuocdt = calDienThoai();
		int cuocdata = calData();
		return cuocdt + cuocdata + (cuocdt + cuocdata)*10/100;
	}
};

class VipPro : public KhachHang{
private:
	int cuocthuebao,datafree;
public:
	VipPro(){
		NhapKhachHang();
		int temp;
		cout << "Nguong luu luong mien phi quy dinh: ";
		cin >> temp;
		this->datafree = temp;
		cout << "Cuoc thue bao quy dinh: ";
		cin >> temp;
		this->cuocthuebao = temp;
	}
	int calTong(){
		int cuocdt = calDienThoai();
		if(getData()<=datafree)
			return cuocdt + this->cuocthuebao;
		else
			return cuocdt + this->cuocthuebao + (getData()-datafree)*dongiadata;
	}
};

class Vipfree : public KhachHang{
public:
	Vipfree(){
		NhapKhachHang();
	}
	int calTong(){
		int cuocdt = calDienThoai()-calDienThoai()*10/100;
		return cuocdt + 1000000;
	}
};


int main(int argc, char const *argv[])
{
	int n,temp;
	vector<KhachHang*>kh;
	cout << "Nhap so luong khach hang: "; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Vui long chon goi dang ky (1-Basic, 2-Vip Pro, 3-Vip Free): ";
		cin >> temp;
		switch (temp){
		case 1:
			kh.push_back(new Basic());
			break;
		case 2:
			kh.push_back(new VipPro());
			break;
		case 3:
			kh.push_back(new Vipfree());
			break;
		}
	}
	cout << "Nhap so phut goi va luong data da su dung sau 1 thang: " << endl;
	int b,c;
	for (int i = 0; i < n; i++)
	{
		cout << "Thue bao " << kh[i]->getTen() << endl;
		cout << "So phut goi: ";
		cin >> b;
		cout << "Luong data su dung: ";
		cin >> c;
		kh[i]->inputTimeandData(b,c);
	}
	for (int i = 0; i < n; i++)
	{
		Basic* bs = dynamic_cast<Basic*>(kh[i]);
		VipPro* vp = dynamic_cast<VipPro*>(kh[i]);
		Vipfree* vf = dynamic_cast<Vipfree*>(kh[i]);
		if(bs != nullptr)
			kh[i]->print(bs->calTong());
		else if(vp != nullptr)
			kh[i]->print(vp->calTong());
		else if(vf != nullptr)
			kh[i]->print(vf->calTong());
	}
	return 0;
}