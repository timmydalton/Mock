#include<iostream>
#include"NhanVien.h"
#include"NVChinhThuc.h"
#include"Fresher.h"
#include"Controller.h"

int main() {
	Controller* c = new Controller();
	int m = -1;
	string trangThai = "\nKhoi dong ung dung";
	while (1) {
		system("cls");
		cout << "\n-------MANG XA HOI NHAN VIEN-----------------\n";
		cout << "\n--------Menu------------------------------: \n";
		cout << "\n1. Doc du lieu tu danh sach da luu---------";
		cout << "\n2. Ghi du lieu vao tep danh sach-----------";
		cout << "\n3. Xem thong tin toan bo nhan vien---------";
		cout << "\n4. Them nhan vien vao mang xa hoi----------";
		cout << "\n5. Tim kiem ten nhan vien------------------";
		cout << "\n6. Tim nhan vien theo so thich-------------";
		cout << "\n7. Liet ke ban cua nhan vien theo ID-------";
		cout << "\n8. Xoa nhan vien khoi mang xa hoi----------";
		cout << "\n9. Ket ban voi nhan vien khac--------------";
		cout << "\n0. Thoat-----------------------------------";
		cout << "\n-------------------------------------------\n";
		
		trangThai = (m == 4) ? ("\nTrang thai: " + trangThai) : ("\nTrang thai: " + trangThai + "\n");
		cout << trangThai;
		cout << "\n---------------------------------------------\n"
			<< "\nNhap lua chon: ";
		cin >> m;
		switch (m)
		{
		case 1: {
			trangThai = c->readFile();
			break;
		}
		case 2: {
			trangThai = c->writeFile();
			cin.ignore();
			break;
		}
		case 3: {
			trangThai = c->viewAllUser();
			cin.ignore();
			cin.ignore();
			break;
		}
		case 4: {
			trangThai = c->themNhanVien();
			c->sortListtoID();
			cin.ignore();
			break;
		}
		case 5: {
			trangThai = c->timNhanVien();
			cin.ignore();
			break;
		}
		case 6: {
			trangThai = c->timTheoSoThich();
			cin.ignore();
			break;
		}
		case 7: {
			trangThai = c->lietKeBanBe();
			cin.ignore();
			cin.ignore();
			break;
		}
		case 8: {
			trangThai = c->xoaNhanVien();
			break;
		}
		case 9: {
			int idBan;
			cout << "\n------------Them ban be-------------\n";
			cout << "\nNhap vao ID nguoi can ket ban: ";
			cin >> idBan;
			trangThai = c->themBanBe(idBan);
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			trangThai = "Nhap sai cu phap, moi nhap lai. ";
			break;
		}
		}
	}

	delete(c);
	return 0;
}