#include "NhanVien.h"
#include<iostream>

using namespace std;

NhanVien::NhanVien()
{
	m_id = m_tuoi = m_chieuCao = m_viTri = 0;
	m_hoten = ' ';
	m_banbe;
}

void NhanVien::setID(int id)
{
	this->m_id = id;
}

int NhanVien::getID()
{
	return this->m_id;
}

void NhanVien::setHoTen(string hoTen)
{
	this->m_hoten = hoTen;
}

string NhanVien::getHoTen()
{
	return this->m_hoten;
}

void NhanVien::setViTri(int viTri, string i)
{
	/*for (;;) {
		if (viTri == 0 || viTri == 1) {*/
			this->m_viTri = viTri;
	/*		break;
		}
		else {
			cout << "Khong dung cu phap, moi nhap lai \n";
		}
	}*/
}

int NhanVien::getViTri()
{
	return this->m_viTri;
}

void NhanVien::setTuoi(int tuoi)
{
	if (18 < tuoi < 100)
		this->m_tuoi = tuoi;
	else {
		cout << "Khong dung cu phap \n";
		return;
	}
}

int NhanVien::getTuoi()
{
	return this->m_tuoi;
}

void NhanVien::setChieuCao(int chieuCao)
{
	this->m_chieuCao = chieuCao;
}

int NhanVien::getChieuCao()
{
	return this->m_chieuCao;
}

void NhanVien::setMotSoThich(string st)
{
	m_soThich.insert(st);
}

void NhanVien::setSoThich()
{
	string tmp = "";
	while (tmp != ".") {
		getline(cin, tmp);
		if (tmp != "") if (tmp != ".") this->m_soThich.insert(tmp);
	}
}

string NhanVien::getStringSoThich()
{
	string soThich = "";
	for (auto i = this->m_soThich.begin(); i != this->m_soThich.end(); ++i) {
		if (i == this->m_soThich.begin()) {
		soThich +=  *i;
		}
		else soThich += ", " + *i;
	}
	return soThich;
}

set<string> NhanVien::getSoThich()
{
	return this->m_soThich;
}

void NhanVien::setMotBanBe(int ban)
{
	this->m_banbe.insert(ban);
}

string NhanVien::getStringBanBe()
{
	string banBe = "";
	for (auto i = this->m_banbe.begin(); i != this->m_banbe.end(); ++i){
		if (i == this->m_banbe.begin()) {
			banBe += to_string(*i);
		}
		else
			banBe += ", " + to_string(*i);
	}
	return banBe;
}

set<int> NhanVien::getBanBe()
{ 
	return this->m_banbe;
}

void NhanVien::xoaMotBanBe(int ban)
{
	this->m_banbe.erase(ban);
}

void NhanVien::set(){
	
	/*cout << "Nhap ID: ";
	cin >> this->m_id;*/
	cin.ignore();
	cout << "Nhap ho ten: ";
	getline(cin, this->m_hoten);
	/*cout << "Nhap vi tri: ";
	cin >> this->m_viTri;
	for (;;) {
		if (this->m_viTri == 0 || this->m_viTri == 1) {
			break;
		}
		else {
			cout << "Khong dung cu phap, moi nhap lai: \n";
			cin >> this->m_viTri;
		}
	}*/
	cout << "Nhap tuoi: ";
	cin >> this->m_tuoi;
	for(;;){
		if (18 < this->m_tuoi < 100)
			break;
		else {
			cout << "Khong dung cu phap, moi nhap lai \n";
			cin >> this->m_tuoi;
		}
	}
	cout << "Nhap chieu cao(cm): ";
	cin >> this->m_chieuCao;
	cout << "Nhap so thich, moi so thich cach nhau boi dau xuong dong (nhap dau . neu muon ket thuc):\n";
	this->setSoThich();
}

string NhanVien::get()
{
	return "";
}

NhanVien::~NhanVien()
{
	m_id = m_tuoi = m_chieuCao = m_viTri = 0;
	m_hoten = ' ';
	m_banbe.clear();
}
