#pragma once
#include "NhanVien.h"


class Fresher :
    public NhanVien
{
protected:
    /*int m_vitri = 0;*/
    string m_lopHoc;
public:
    virtual void setLopHoc(string lopHoc);
    virtual string getLopHoc();

    virtual void setViTri(int viTri,string i);

    virtual void set();
    virtual string get();

    Fresher();
    ~Fresher();
};

