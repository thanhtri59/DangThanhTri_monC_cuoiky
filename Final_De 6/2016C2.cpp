#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;


class BenhNhan{
private:
	int msbn;
public:
	void addBenhNhan(int msbn){
		this->msbn = msbn;
	}
	int getMSBN(){
		return this->msbn;
	}
	virtual ~BenhNhan(){};
};

class KhamBenh : public BenhNhan
{
private:
	double tienkham;
public:
	KhamBenh(int msbn, double tienKham){
		addBenhNhan(msbn);
		this->tienkham = tienKham;
	}
	double calTong(){
		return tienkham;
	}
	void print(){
		cout << "BN[MSBN=" << getMSBN() << "] => VPTL = " << calTong() << " VND" << endl;
	}
	~KhamBenh(){};
	
};

class NhapVien : public BenhNhan
{
private:
	int ngaynhapvien;
	int songay = 0;
	int trangthai; //0 la da xuat vien, 1 la chua xuat vien
	double tienKhamMoiNgay;
	char loai;
public:
	NhapVien(int msbn, int ngay,double tienKham, char loai){
		addBenhNhan(msbn);
		this->ngaynhapvien = ngay;
		this->trangthai = 1;
		this->tienKhamMoiNgay = tienKham;
		this->loai = loai;
	}

	void Xuat(int ngay){
		this->trangthai = 0;
		this->songay = ngay - this->ngaynhapvien;
	}
	double calTong(){
		if(this->loai == 'A')
			return songay*(this->tienKhamMoiNgay + 1400000);
		if(this->loai == 'B')
			return songay*(this->tienKhamMoiNgay + 900000);
		if(this->loai == 'C')
			return songay*(this->tienKhamMoiNgay +600000);
		return 0;
	}
	void print(int ngay){
		if(this->trangthai == 0){
			cout << "BN[MSBN=" << getMSBN() << "] => VPTL = "<<fixed << setprecision(0)<<calTong() <<"VND" << endl;
		}
		else if (this->trangthai == 1){
			this->songay = ngay - this->ngaynhapvien;
			cout << "BN[MSBN=" << getMSBN() << "] da nam " << ngay - this->ngaynhapvien << " ngay o phong loai " << this->loai << " => VPTL = " <<fixed << setprecision(0)<< calTong() <<" VND" << endl;
		}
	}
	// int getTrangThai(){
	// 	return this->trangthai;
	// }
	~NhapVien(){};
	
};


void simulate(string filename)
{
	vector<BenhNhan*>benhvien;
	ifstream ss(filename);
	string ngay, MSBN, hd, money, loai;
	int ngaycuoicung;
	while(ss>>ngay>>MSBN>>hd){
		if(hd == "KB"){
			ss >> money;
		    	benhvien.push_back(new KhamBenh(stoi(MSBN), stod(money)));
		}
		else if(hd == "NV"){
			ss>>money>>loai;
		    	benhvien.push_back(new NhapVien(stoi(MSBN), stoi(ngay),stod(money), loai[0]));
		}
		else if(hd == "TKVP"){
			ngaycuoicung = stoi(ngay);
		}
	}
	int k = 0;
	ifstream st(filename);
	while(st>>ngay>>MSBN>>hd){
		if(hd == "KB"){
			st >> money;
		}
		else if(hd == "NV"){
			st>>money>>loai;
		}
		else if(hd == "XV"){
			NhapVien* xv = dynamic_cast<NhapVien*>(benhvien[k-1]);
			xv->Xuat(stoi(ngay));
		}
		k++;
	}
	double tongvienphi;
	int noitru = 0, ngoaitru = 0;
	for (int i = 0; i < benhvien.size(); i++)
	{
		NhapVien* nv = dynamic_cast<NhapVien*>(benhvien[i]);
		KhamBenh* kb = dynamic_cast<KhamBenh*>(benhvien[i]);
		if(nv != nullptr){
			nv->print(ngaycuoicung);
			tongvienphi += nv->calTong();
			// if(nv->getTrangThai()==1)
			noitru++;
		}
		else if(kb != nullptr){
			kb->print();
			tongvienphi += kb->calTong();
			ngoaitru++;
		}
	}
	cout << "==> Tong vien phi = " << tongvienphi << " VND." << endl;
	// //------------check noi tru va ngoai tru ----------------------
	// int noitru = 0, ngoaitru = 0;
	// for (int i = 0; i < benhvien.size(); i++)
	// {
	// 	NhapVien* nv = dynamic_cast<NhapVien*>(benhvien[i]);
	// 	KhamBenh* kb = dynamic_cast<KhamBenh*>(benhvien[i]);
	// 	if(nv != nullptr){
	// 		noitru++;
	// 	}
	// 	else if(kb != nullptr){
	// 		ngoaitru++;
	// 	}
	// }
	cout << "==> So luong benh nhan noi tru: " << noitru << ". So luong benh nhan ngoai tru: "<< ngoaitru << endl;
}

int main(){
	string fileName = "testcase.txt";
    	simulate(fileName);
	return 0;
}