#include<iostream>
#include"NhanVien.h"
#include"NVChinhThuc.h"
#include"Fresher.h"
#include"Controller.h"

int main() {
	Controller* c = new Controller();
	string rs = "\nKhoi dong ung dung";
	while (1) {
		int m;
		system("cls");
		cout << "\n------------MANG XA HOI NHAN VIEN------------\n";
		cout << "\n--------------------MENU---------------------\n";
		cout << "\n1.Doc du lieu tu danh sach da luu";
		cout << "\n2.Ghi du lieu vao tep danh sach";
		cout << "\n3.Xem thong tin toan bo nhan vien";
		cout << "\n4.Them nhan vien vao mang xa hoi";
		cout << "\n5.Tim kiem ten nhan vien";
		cout << "\n6.Tim nhan vien theo so thich";
		cout << "\n7.Liet ke ban cua nhan vien theo ID";
		cout << "\n8.Xoa nhan vien khoi mang xa hoi";
		cout << "\n9.Ket ban voi nhan vien khac";
		cout << "\n0.Thoat";
		cout << "\n---------------------------------------------\n";
		cout << "\nStatus: " << rs << endl;
		cout << "\n---------------------------------------------\n";
		cout << "\nNhap lua chon: "; cin >> m;
		switch (m)
		{
		case 1: {
			rs = c->readFile();
			break;
		}
		case 2: {
			rs = c->writeFile();
			break;
		}
		case 3: {
			rs = c->viewAllUser();
			cin.ignore();
			cin.ignore();
			break;
		}
		case 4: {
			rs = c->themNhanVien();
			c->sortListtoID();
			break;
		}
		case 5: {
			rs = c->timNhanVien();
			cin.ignore();
			break;
		}
		case 6: {
			rs = c->timTheoSoThich();
			cin.ignore();
			break;
		}
		case 7: {
			rs = c->lietKeBanBe();
			cin.ignore();
			cin.ignore();
			break;
		}
		case 8: {
			rs = c->xoaNhanVien();
			break;
		}
		case 9: {
			int idBan;
			cout << "\n---------------THEM BAN BE-----------------\n";
			cout << "\nNhap vao ID nguoi can ket ban: ";
			cin >> idBan;
			rs = c->themBanBe(idBan);
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			rs = "Nhap sai cu phap, moi nhap lai. ";
			break;
		}
		}
	}

	delete(c);
	return 0;
}