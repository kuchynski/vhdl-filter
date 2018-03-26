//---------------------------------------------------------------------------
#ifndef CDataH
#define CDataH

#include <math.h>
#include <stdio.h>
#include <Math.hpp>
//---------------------------------------------------------------------------
class CData
{
  private:
//    long kol_m, kol_p;
    //unsigned maska_m, maska_p;
  //  unsigned maskaz_m, maskaz_p;
    bool znak;
    unsigned mantisa, por;
    unsigned GetHexPor(int d);
    unsigned NormaMan(unsigned d);
    unsigned NormaPor(unsigned d);
    int GetIntPor(unsigned d);
  public:
    CData();
    CData(int d);
    CData(double d);
    CData operator=(const int &d);
    CData operator=(const double &d);
    CData operator+(const CData &d);
    CData operator-(const CData &d);
    CData operator*(const CData &d);

    int GetInt();
    double GetDouble();
    void SetMP(int m, int p);
    AnsiString GetZnak();
    AnsiString GetMon();
    AnsiString GetPor();
};
//---------------------------------------------------------------------------
#endif
