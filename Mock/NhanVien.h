#pragma once
#ifndef NHANVIEN_H
#define NHANVIEN_H
#endif
#include<string>
#include<set>
#include<vector>

using namespace std;

class NhanVien
{
protected:
    string m_hoten;
    int m_id, m_tuoi, m_chieuCao, m_viTri = 0;
    set<int> m_banbe;
    set<string> m_soThich;
public: 
    NhanVien();

    virtual void setID(int id);
    virtual int getID();

    virtual void setHoTen(string hoTen);
    virtual string getHoTen();

    virtual void setViTri(int viTri,string i);
    virtual int getViTri();

    virtual void setTuoi(int tuoi);
    virtual int getTuoi();

    virtual void setChieuCao(int chieuCao);
    virtual int getChieuCao();

    virtual void setMotSoThich(string st);
    virtual void setSoThich();
    virtual string getStringSoThich();
    virtual set<string> getSoThich();

    virtual void setMotBanBe(int ban);
    virtual string getStringBanBe();
    virtual set<int> getBanBe();
    virtual void xoaMotBanBe(int ban);

    virtual void set();
    virtual string get();

    ~NhanVien();
};

