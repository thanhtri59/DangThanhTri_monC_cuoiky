#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class MayLoc
{
private:
	float m_tgian;
public:
	void setTgian(float t){
		this->m_tgian = t;
	}
	float getTgian(){
		return this->m_tgian;
	}
	MayLoc(){
		this->m_tgian = 0;
	}
	virtual ~MayLoc(){}
};

class LyTam : public MayLoc
{
private:
	float dongia = 50000;
	float congsuat;
	float haoxang;
public:
	LyTam(float congsuat, float haoxang){
		setCongSuat(congsuat);
		setHaoXang(haoxang);
	}
	void setCongSuat(float cs){
		this->congsuat = cs;
	}
	float getCongSuat(){
		return this->congsuat;
	}
	void setHaoXang(float hx){
		this->haoxang = hx;
	}
	float TinhTien(){
		return (this->dongia + this->haoxang)*this->getTgian();
	}
	float TinhLuongNuoc(){
		return this->congsuat * this->getTgian();
	}
};

class XucTac : public MayLoc{
private:
	float dongia = 80000;
	float congsuat;
	float congsuatthucte;
	float hoachat;
public:
	XucTac(float congsuat, float hoachat){
		setCongSuat(congsuat);
		setHoaChat(hoachat);
	}
	void setCongSuat(float cs){
		this->congsuat = cs;
	}
	float getCongSuat(){
		return this->congsuat;
	}
	void setHoaChat(float hc){
		this->hoachat = hc;
	}
	void calCSTT(){
		if(this->getTgian() < 10)
			this->congsuatthucte = this->congsuat * (this->hoachat/100);
		else
			this->congsuatthucte = this->congsuat * (this->hoachat/100)/(this->getTgian()/10);
	}
	float TinhTien(){
		return this->dongia * this->getTgian() + this->hoachat * 10000;
	}
	float TinhLuongNuoc(){
		this->calCSTT();
		return this->congsuatthucte * this->getTgian();
	}
};


int main(int argc, char const *argv[])
{
	int n;
	float a, b,c,nuoc;
	float h = 0, sum = 0;
	cout << "Nhap so luong may loc: ";
	cin >> n;
	cout << "Vui long nhap thong tin cho tung loai (Cong suat, toc do hao xang, hoa chat, thoi gian thue)," << endl;
	cout << "Neu la May loc Ly tam, nhap hoa chat = 0, neu la May loc Xuc tac, nhap toc do hao xang = 0"<< endl;
	vector<MayLoc*> maylocs;
	for (int i = 0; i < n; i)
	{
		cout << "May loc thu " << i+1 << endl;
		cout << "Nhap Cong suat: ";
		cin >> a;
		cout << "Nhap Toc do hao xang: ";
		cin >> b;
		cout << "Nhap Hoa chat: ";
		cin >> c;
		cout << "Nhap thoi gian thue: ";
		cin >> h;
		if(c == 0){
			maylocs.push_back(new LyTam(a,b));
			maylocs[i]->setTgian(h);
			i++;
		}else if(b == 0){
			maylocs.push_back(new XucTac(a,c));
			maylocs[i]->setTgian(h);
			i++;
		}else{
			cout << "Vui long nhap dung dinh dang!" << endl;
		}
	}
	cout << "Nhap vao luong nuoc: ";
	cin >> nuoc;
	//tinh tong chi phi va luong nuoc su dung
	float chiphi = 0, luongnuoc = 0;
	for (int i = 0; i < n; i++)
	{
		LyTam* lyTam = dynamic_cast<LyTam*>(maylocs[i]);
		XucTac* xucTac = dynamic_cast<XucTac*>(maylocs[i]);
		if (lyTam != nullptr)
		{
			chiphi += lyTam->TinhTien();
			luongnuoc += lyTam->TinhLuongNuoc();
		}
		else if (xucTac != nullptr)
		{
			chiphi += xucTac->TinhTien();
			luongnuoc += xucTac->TinhLuongNuoc();
		}
	}
	if(luongnuoc >= nuoc)
		cout << "Ao duoc loc het nuoc!" << endl;
	else 
		cout << "Ao khong duoc loc het nuoc, con du " << nuoc - luongnuoc << " met khoi nuoc!" << endl;
	cout << "Tong chi phi su dung la: " << fixed << setprecision(0) << chiphi<<" VND." << endl;
	//delete vector
	for (int i = 0; i < n; i++)
	{
		delete maylocs[i];
	}
	return 0;
}