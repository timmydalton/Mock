#include "Fresher.h"
#include <iostream>
using namespace std;

void Fresher::setLopHoc(string lopHoc)
{
	this->m_lopHoc = lopHoc;
}

string Fresher::getLopHoc()
{
	return this->m_lopHoc;
}

void Fresher::setViTri(int viTri,string i)
{
	this->m_viTri = viTri;
	this->m_lopHoc = i;
}

void Fresher::set()
{
	NhanVien::set();
	cout << "Nhap ten lop hoc: ";
	getline(cin, this->m_lopHoc);
}

string Fresher::get()
{
	return "| " + to_string(m_id) + " | "
		+ m_hoten + " | "
		+ to_string(m_viTri) + " | "
		+ m_lopHoc + " | "
		+ to_string(m_tuoi) + " | "
		+ to_string(m_chieuCao) + " | "
		+ getStringSoThich() + " |"
		+ getStringBanBe() + "|"
		+ "\n";
}

Fresher::Fresher()
{
}

Fresher::~Fresher()
{
}
