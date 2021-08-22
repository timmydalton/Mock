#pragma once
#include"NhanVien.h"
#include"Fresher.h"
#include"NVChinhThuc.h"
#include<fstream>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

class Controller
{
public:
	vector <NhanVien*> listNV;
	map<string, set<int>> listSoThich_ID;

	bool checkid(int id);
	string themNhanVien();

	void sortListtoID();

	void getNhanVienByString(string line);

	string readFile();
	string writeFile();
	string viewAllUser();
	
	//void updateUser();
	string timNhanVien();
	string lietKeBanBe();
	string xoaNhanVien();
	string timTheoSoThich();
	string themBanBe(int idNguoiKB);
};
