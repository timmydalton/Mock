#include<iostream>
#include"NhanVien.h"
#include"NVChinhThuc.h"
#include"Fresher.h"
#include"Controller.h"

int main() {
	Controller* c = new Controller();
	int m = -1;
	string trangThai = "\nNhap lua chon: ";
	system("cls");
	cout << "\n-------MANG XA HOI NHAN VIEN-----------------\n";
	while (1) {
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
		
		cout << trangThai; cin >> m;
		switch (m)
		{
		case 1: {
			cout << c->readFile();
			break;
		}
		case 2: {
			cout << c->writeFile();
			break;
		}
		case 3: {
			cout << c->viewAllUser();
			break;
		}
		case 4: {
			cout << c->themNhanVien();
			c->sortListtoID();
			break;
		}
		case 5: {
			cout << c->timNhanVien();
			break;
		}
		case 6: {
			cout << c->timTheoSoThich();
			break;
		}
		case 7: {
			cout << c->lietKeBanBe();
			break;
		}
		case 8: {
			cout << c->xoaNhanVien();
			break;
		}
		case 9: {
			int idBan;
			cout << "\n------------Them ban be-------------\n";
			cout << "\nNhap vao ID nguoi can ket ban: ";
			cin >> idBan;
			cout << c->themBanBe(idBan);
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			cout << "Nhap sai cu phap, moi nhap lai. " << endl;
			break;
		}
		}
	}

	delete(c);
	return 0;
}