//---------------------------------------------------------------------------
#ifndef CObjectH
#define CObjectH

#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <stdio.h>
#include <math.h>
#include "CData.h"

using namespace std;
//----------------------------------------------------------------------------
class CObject
{
    long mantisa, por;
    int kol_coof;
    double coof_a[100], coof_b[100];
    int fd, fr[3], a[3], sm;
    double xfft1[4096], yfft1[4096];
    double xfft2[4096], yfft2[4096];
    double xfft3[4096], yfft3[4096];
    long zapas[1000];
    int data_in[10000], data_midle[10000], data_out[10000];
    CData coof_bd[100], coof_ad[100];
    int center, begin, sz, sz2;
    void Paint(TImage *image, int *data, TColor color, int cen);
    AnsiString DownTo(int end, int begin);
    AnsiString GetNumberBin(int n, int kol_bit);

    void FFT(int *in, double *x, double *y);
    void RunFFT();
    void RunFFT2();
    void PaintFFT(TImage *image, double *x, double *y, TColor color);

  public:
    CObject();
    CObject(FILE *f);
    CObject(const CObject &op);
    CObject operator=(const CObject &op);

    void SetRazrad(long r1, long r2) {mantisa = r1; por = r2;}
    void SetKoof(int k, double *ca, double *cb);
    void SetFd(int in_fd) {fd = in_fd;}
    void SetFAS(int *q1, int *q2, int q3);
    bool SaveToFile(FILE *f)const;

    long GetMantisa() {return mantisa;}
    long GetPor() {return por;}
    int GetKolCoof() {return kol_coof;}
    AnsiString GetCoofA();
    AnsiString GetCoofB();
    int GetFd() {return fd;}
    int GetFr(int n);
    int GetA(int n);
    int GetSm() { return sm;}
    void Paint(TImage *image, int s = 0);
    void PaintFFT(TImage *image, int s = 0);
    void SetBegin(int b) {begin = b;}
    void SetSz(int b) {sz = b;}
    void SetSz2(int b) {sz2 = b;}
    void Run();
    void RunVHDL(TMemo *memo, AnsiString name);
};
//---------------------------------------------------------------------------
#endif
