#pragma once
#include "NhanVien.h"
class NVChinhThuc :
    public NhanVien
{
protected:
    /*int m_vitri = 0;*/
    string m_donVi;
public:
    virtual void setDonVi(string donVi);
    virtual string getDonVi();

    virtual void setViTri(int viTri, string i);
    virtual void set();
    virtual string get();
    /*void print();*/

    NVChinhThuc();
    ~NVChinhThuc();
};

