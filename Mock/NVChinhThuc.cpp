#include "NVChinhThuc.h"
#include<iostream>

using namespace std;

void NVChinhThuc::setDonVi(string donVi)
{
	this->m_donVi = donVi;
}

string NVChinhThuc::getDonVi()
{
	return this->m_donVi;
}

void NVChinhThuc::setViTri(int viTri, string i)
{
	this->m_viTri = viTri;
	this->m_donVi = i;
}

void NVChinhThuc::set()
{
	NhanVien::set();
	cout << "Nhap ten don vi lam viec: ";
	getline(cin, this->m_donVi);
}

string NVChinhThuc::get()
{
	return "| " + to_string(m_id) + " | "
		+ m_hoten + " | "
		+ to_string(m_viTri) + " | "
		+ m_donVi + " | "
		+ to_string(m_tuoi) + " | "
		+ to_string(m_chieuCao) + " | "
		+ getStringSoThich() + " |"
		+ getStringBanBe() + "|"
		+ "\n";
}

NVChinhThuc::NVChinhThuc()
{
}

NVChinhThuc::~NVChinhThuc()
{
}

