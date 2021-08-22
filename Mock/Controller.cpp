#include "Controller.h"

//Các hàm hỗ trợ
bool Controller::checkid(int id)
{
	for (auto i = listNV.begin(); i != listNV.end(); i++) {
		if ((*i)->getID() == id) return false;
	}
	return true;
}

void Controller::getNhanVienByString(string line)
{
	NhanVien* nv = new NhanVien();
	vector<string> x;
	string temp;
	temp = "";
	for (int i = 1, count = 0; i < line.size(); i++) {
		temp += line[i];
		if (line[i] == '|') {
			if (count == 7) {
				temp = temp.substr(0, temp.size() - 1);
				x.push_back(temp);
			}
			else {
				temp = temp.substr(1, temp.size() - 3);
				x.push_back(temp);
				temp = "";
				count++;
			}
		}
	}
	temp = "";

	if (stoi(x[2]) == 1) {
		/*static_cast<NVChinhThuc*>(nv)->setDonVi(x.at(3));*/
		nv = new NVChinhThuc();
		nv->setID(stoi(x[0]));
		nv->setHoTen(x[1]);
		nv->setViTri(stoi(x[2]), x[3]);
		nv->setTuoi(stoi(x[4]));
		nv->setChieuCao(stoi(x[5]));
		for (int i = 0; i < x.at(6).size(); i++) {
			temp += x.at(6)[i];
			if (x.at(6)[i] == ',') {
				temp = temp.substr(0, temp.size() - 1);

				nv->setMotSoThich(temp);
				i += 1;
				temp = "";
			}
		}
		nv->setMotSoThich(temp);
		temp = "";
		for (int i = 0; i < x[7].size(); i++) {
			temp += x.at(7)[i];
			if (x.at(7)[i] == ',') {
				temp = temp.substr(0, temp.size() - 1);

				nv->setMotBanBe(stoi(temp));
				i += 1;
				temp = "";
			}
		}
		nv->setMotBanBe(stoi(temp));
		temp = "";
	}
	else if (stoi(x.at(2)) == 0) {
		/*static_cast<Fresher*>(nv)->setLopHoc(x.at(3));*/
		nv = new Fresher();
		nv->setID(stoi(x[0]));
		nv->setHoTen(x[1]);
		nv->setViTri(stoi(x[2]), x[3]);
		nv->setTuoi(stoi(x[4]));
		nv->setChieuCao(stoi(x[5]));
		for (int i = 0; i < x[6].size(); i++) {
			temp += x.at(6)[i];
			if (x.at(6)[i] == ',') {
				temp = temp.substr(0, temp.size() - 1);

				nv->setMotSoThich(temp);
				i += 1;
				temp = "";
			}
		}
		nv->setMotSoThich(temp);
		temp = "";
		for (int i = 0; i < x[7].size(); i++) {
			temp += x.at(7)[i];
			if (x.at(7)[i] == ',') {
				temp = temp.substr(0, temp.size() - 1);

				nv->setMotBanBe(stoi(temp));
				i += 1;
				temp = "";
			}
		}
		nv->setMotBanBe(stoi(temp));
		temp = "";
	}
	listNV.push_back(nv);
}

void Controller::sortListtoID()
{
	/*sort(listNV[0]->getID(), listNV[listNV.size()-1]->getID());*/
	for (int i = 0; i < listNV.size(); i++) {
		for (int j = listNV.size() - 1; j > i; j--) {
			if (listNV[j]->getID() < listNV[i]->getID()) {
				swap(listNV[i], listNV[j]);
			}
		}
	}
}

//Các hàm chức năng của chương trình
//1
string Controller::readFile()
{
	ifstream file;
	string line = "";
	file.open("User.txt", ios::in); //đổi tên file thành User_long.txt
									//nếu muốn danh sách dữ liệu có nhiều nhân viên
	if (!file) return "\nKhong co file du lieu";
	//else if (file) {
	//	file.open("User1.txt", ios::in);
	//	if (!file) return "Khong co file du lieu:";
	//	else {
	//		while (!file.eof()) {
	//			getline(file, line);

	//			if (line[0] == '|') {
	//				getNhanVienByString(line);
	//			}
	//		}
	//		//for (int i = 0; i < listNV.size(); i++) {
	//		//	listNV[i]->get();
	//		//}
	//		return "Doc danh sach du lieu thanh cong";
	//	}
	//} Bỏ comment phần này nếu muốn chỉ đọc file dữ liệu gốc 
	//  đọc và thực hiện các hành động với file User1.txt
	else {
		while (!file.eof()) {
			getline(file, line);

			if (line[0] == '|') {
				getNhanVienByString(line);
			}
		}
		//for (int i = 0; i < listNV.size(); i++) {
		//	listNV[i]->get();
		//} hàm kiểm tra in toàn bộ những gì đã đọc từ file
		return "\nDoc danh sach du lieu thanh cong";
	}
}

//2
string Controller::writeFile()
{
	if (listNV.empty()) {
		return "Khong co du lieu de ghi vao danh sach\n";
	}
	ofstream file;
	file.open("User1.txt", ios::out | ios::trunc);
	for (auto i = listNV.begin(); i != listNV.end(); i++) {
		file << (*i)->get();
	}
	return "\nDa ghi ra file du lieu thanh cong";
}

//3
string Controller::viewAllUser()
{
	if (listNV.empty()) {
		cout << "Khong co du lieu\n"
			<< "-> Nhan Enter de tro ve Menu...";
		return "\nKhong co du lieu";
	}
	else {
		cout << "\n-------------Danh sach nhan vien-----------\n\n";
		for (int i = 0; i < listNV.size(); i++) {
			cout << listNV[i]->get();
		}
		cout << "\n-------------Ket thuc danh sach------------\n"
			<< "\n-> Nhan Enter de tro ve Menu...";
		return "\nDa in ra tat ca nhan vien trong chuong trinh";
	}
	//hàm sau để đọc dữ liệu từ file nếu thực thi trên User.txt
	ifstream file;
	string line = "";
	file.open("User.txt", ios::in);
	if (!file) return "\nKhong co file du lieu";
	else {
		while (!file.eof()) {
			getline(file, line);
			cout << line << endl;
		}
	}
	file.close();
	return "\nDa in ra tat ca nhan vien trong file du lieu";
}

//4
string Controller::themNhanVien()
{
	NhanVien *nv = new NhanVien();
	int chon, id;
	/*for (int i = 0; i < n; i++) {*/
	cout << "\n----------Them mot nhan vien---------------\n";
	cout << "\nNhap thong tin nhan vien: " << endl;
	cout << "\n0.---Nhap thong tin fresher----------------";
	cout << "\n1.---Nhap thong tin nhan vien chinh thuc---";
	cout << "\n2.---Thoat---";
	cout << "\n-------------------------------------------\n";
	cout << "Nhap lua chon: "; cin >> chon;
	switch (chon)
	{
	case 0: {
		cout << "Nhap ID: "; cin >> id;
		while (!checkid(id)) {
			cout << "ID da co trong danh sach nguoi dung. Moi nhap lai: \n";
			cin >> id;
		}
		nv = new Fresher();
		nv->setViTri(0, "");
		nv->setID(id);
		nv->set();
		listNV.push_back(nv);
		themBanBe(nv->getID());
		//sortListtoID();
		return "\nNhan vien da nhap: \n" + nv->get();
		break;
	}
	case 1: {
		cout << "Nhap ID: "; cin >> id;
		while (!checkid(id)) {
			cout << "ID da co trong danh sach nguoi dung. Moi nhap lai: \n";
			cin >> id;
		}
		nv = new NVChinhThuc();
		nv->setViTri(1, "");
		nv->setID(id);
		nv->set();
		listNV.push_back(nv);
		themBanBe(nv->getID());
		//sortListtoID();
		return "\nNhan vien da nhap: \n" + nv->get();
		break;
	}
	case 2: {
		delete(nv);
		return "\nQuay lai menu...\n";
		break;
	}
	default:
		return "\nSai cu phap, quay lai menu...\n";
		break;
	}
	return "\nDa them nhan vien thanh cong";
	/*}*/
}

//5
string Controller::timNhanVien()
{
	cin.ignore();
	string ten = "";
	cout << "\n--------Tim kiem nhan vien theo ten--------\n";
	cout << "\nNhap vao ten nguoi can tim: \n";
	getline(cin, ten);
	cout << "\n--------Ket qua tim kiem: -----------------\n";
	for (auto i = listNV.begin(); i != listNV.end(); i++) {
		for (int j = 0; j < (*i)->getHoTen().size(); j++) {
			if (ten == (*i)->getHoTen().substr(j, j + ten.size())) {
				cout << (*i)->get();
			}
		}
	}
	cout << "\n--------Ket thuc danh sach-----------------\n"
		<< "\n-> Nhan Enter de tro ve Menu...";
	return "\nDa thuc hien tim kiem voi ten nhap vao";
}

//6
string Controller::timTheoSoThich()
{
	set<string> soThich;
	string input = "";
	cout << "\n-----Tim nhan vien theo so thich--------\n";
	cout << "\nNhap vao so thich can tim, moi so thich cach nhau 1 dong\n"
		<< "nhap dau . sau khi nhap xong so thich: \n";
	while (input != ".") {
		getline(cin, input);
		soThich.insert(input);
	}
	if (soThich.empty()) return "Tro ve menu...\n";
	cout << "-----Danh sach ket qua--------------------\n";
	for (auto i = listNV.begin(); i != listNV.end(); i++) {
		set<string> dsSoThichTheoNV = (*i)->getSoThich();
		bool status = false;
		for (auto k = dsSoThichTheoNV.begin(); k != dsSoThichTheoNV.end(); k++) {
			for (auto j = soThich.begin(); j != soThich.end(); j++) {
				if ((*j) == (*k)) {
					cout << (*i)->get();
					status = true;
					break;
				}
			}
			if (status) break;
		}
	}
	cout << "\n-----Ket thuc danh sach-----------------\n"
		<< "\n-> Nhan Enter de tro ve Menu...";
	return "\nDa thuc hien tim kiem voi so thich";
}

//7
string Controller::lietKeBanBe()
{
	int id;
	cout << "\n---------Liet ke danh sach ban be----------\n";
	cout << "\nNhap vao ID nguoi can liet ke (nhap -1 de thoat): \n";
	cin >> id;
	if (id == -1) {
		cout << "Ban da chon thoat khoi chuc nang \n"
			<< "-> Nhan Enter de tro ve Menu...";
		return "\nQuay lai menu";
	}
	else if (checkid(id)) {
		cout << "ID khong hop le.\n"
			<< "\n-> Nhan Enter de tro ve Menu...";
		return "\nID khong hop le";
	}
	else {
		cout << "\n------Danh sach ban be cua " << id << ": -------\n";
		for (auto i = listNV.begin(); i != listNV.end(); i++) {
			if ((*i)->getID() == id) {
				set<int> temp = (*i)->getBanBe();
				cout << (*i)->getStringBanBe() << endl;
				for (auto j = temp.begin(); j != temp.end(); j++) {
					for (auto k = listNV.begin(); k != listNV.end(); k++) {
						if ((*k)->getID() == (*j)) {
							cout << (*k)->get();
						}
					}
				}
				cout << "\n--------Ket thuc danh sach-----------------\n"
					<< "\n-> Nhan Enter de tro ve Menu...";
				return "\nDa liet ke danh sach ban be";
			}
		}
	}
	//return string();
}

//8
string Controller::xoaNhanVien()
{
	int id;
	cout << "\n--------------Xoa nhan vien----------------\n";
	cout << "\nNhap vao ID nguoi can xoa (nhap -1 de thoat): \n";
	cin >> id;
	if (id == -1) return "\nQuay lai menu";
	else if (checkid(id)) return "\nID khong hop le";
	else {
		for (auto i = listNV.begin(); i != listNV.end(); i++) {
			if ((*i)->getID() == id) {
				set<int> temp = (*i)->getBanBe();
				for (auto j = temp.begin(); j != temp.end(); j++) {
					for (auto k = listNV.begin(); k != listNV.end(); k++) {
						if ((*k)->getID() == (*j)) {
							(*k)->xoaMotBanBe(id);
						}
					}
				}
				listNV.erase(i);
				return "\nDa xoa nhan vien voi ID " + to_string(id);
			}
		}
	}
}

//9
string Controller::themBanBe(int idNguoiKB)
{
	int id = -1, index = -1;
	if (checkid(idNguoiKB)) return "\nID khong hop le";
	for (int i = 0; i < listNV.size(); i++) {
		if (listNV[i]->getID() == idNguoiKB) {
			index = i;
			break;
		}
	}
	cout << "Nhap ID ban be (Nhap ID chinh minh neu muon ket thuc): \n";
	while (id != idNguoiKB){
		cin >> id;
		if (!checkid(id)) {
			if (id == idNguoiKB) continue;
 			listNV[index]->setMotBanBe(id);
			for (int i = 0; i < listNV.size(); i++) {
				if (listNV[i]->getID() == id) {
					listNV[i]->setMotBanBe(listNV[index]->getID());
					break;
				}
			}
		}
		else cout << "\nID khong ton tai. Moi nhap lai. \n";
	}
	return "\nDa them ban be thanh cong!";
}
