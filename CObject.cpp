//---------------------------------------------------------------------------
#pragma hdrstop
#include "CObject.h"
//---------------------------------------------------------------------------
CObject::CObject()
{
  mantisa = 16;
  por = 8;
  kol_coof = 5;
  for(int i = 0; i < 100; i ++)
  {
    coof_a[i] = 1;
    coof_b[i] = 1;
  }
  fd = 1000;
  a[0] = 100;  fr[0] = 50;  sm = 0;
  a[1] = 200;  fr[1] = 100;
  a[2] = 500;  fr[2] = 1;
  center = 1;
  begin = 0;
  sz = 1;
}
//---------------------------------------------------------------------------
CObject::CObject(FILE *f)
{
  if(fread(&mantisa, sizeof(mantisa), 1, f) != 1)
    return;
  if(fread(&por, sizeof(por), 1, f) != 1)
    return;
  if(fread(&kol_coof, sizeof(kol_coof), 1, f) != 1)
    return;
  if(fread(&coof_a, sizeof(coof_a), 1, f) != 1)
    return;
  if(fread(&coof_b, sizeof(coof_b), 1, f) != 1)
    return;
  if(fread(&fd, sizeof(fd), 1, f) != 1)
    return;
  if(fread(&fr, sizeof(fr), 1, f) != 1)
    return;
  if(fread(&a, sizeof(a), 1, f) != 1)
    return;
  if(fread(&sm, sizeof(sm), 1, f) != 1)
    return;
  if(fread(zapas, sizeof(zapas), 1, f) != 1)
    return;
  center = 1;
  begin = 0;
  sz = 1;
}
//---------------------------------------------------------------------------
CObject::CObject(const CObject &op)
{
  por = op.por;
  mantisa = op.mantisa;
  kol_coof = op.kol_coof;
  fd = op.fd;
  for(int i = 0; i < 100; i ++)
  {
    coof_a[i] = op.coof_a[i];
    coof_b[i] = op.coof_b[i];
  }
  for(int i = 0; i < 3; i ++)
  {
    a[i] = op.a[i];
    fr[i] = op.fr[i];
  }
  sm = op.sm;
  center = op.center;
  begin = op.begin;
  sz = op.sz;
}
//---------------------------------------------------------------------------
CObject CObject::operator=(const CObject &op)
{
  if(this != &op)
  {
    por = op.por;
    mantisa = op.mantisa;
    kol_coof = op.kol_coof;
    fd = op.fd;
    for(int i = 0; i < 100; i ++)
    {
      coof_a[i] = op.coof_a[i];
      coof_b[i] = op.coof_b[i];
    }
    for(int i = 0; i < 3; i ++)
    {
      a[i] = op.a[i];
      fr[i] = op.fr[i];
    }
    sm = op.sm;
    center = op.center;
    begin = op.begin;
    sz = op.sz;
  }
  return *this;
}
//---------------------------------------------------------------------------
bool CObject::SaveToFile(FILE *f)const
{
  if(fwrite(&mantisa, sizeof(mantisa), 1, f) != 1)
    return false;
  if(fwrite(&por, sizeof(por), 1, f) != 1)
    return false;
  if(fwrite(&kol_coof, sizeof(kol_coof), 1, f) != 1)
    return false;
  if(fwrite(&coof_a, sizeof(coof_a), 1, f) != 1)
    return false;
  if(fwrite(&coof_b, sizeof(coof_b), 1, f) != 1)
    return false;
  if(fwrite(&fd, sizeof(fd), 1, f) != 1)
    return false;
  if(fwrite(&fr, sizeof(fr), 1, f) != 1)
    return false;
  if(fwrite(&a, sizeof(a), 1, f) != 1)
    return false;
  if(fwrite(&sm, sizeof(sm), 1, f) != 1)
    return false;
  if(fwrite(zapas, sizeof(zapas), 1, f) != 1)
    return false;
  return true;
}
//---------------------------------------------------------------------------
void CObject::SetFAS(int *q1, int *q2, int q3)
{
  for(int i = 0; i < 3;i ++)
  {
    fr[i] = q1[i];
    a[i] = q2[i];
  }
  sm = q3;
}
//---------------------------------------------------------------------------
void CObject::SetKoof(int k, double *ca, double *cb)
{
  kol_coof = k;
  for(int i = 0; i < kol_coof;i ++)
  {
    coof_a[i] = ca[i];
    coof_b[i] = cb[i];
  }
}
//---------------------------------------------------------------------------
AnsiString CObject::GetCoofA()
{
  AnsiString ret = "";
  for(int i = 0; i < kol_coof;i ++)
    ret += (FloatToStr(coof_a[i]) + " ");
  return ret;
}
//---------------------------------------------------------------------------
AnsiString CObject::GetCoofB()
{
  AnsiString ret = "";
  for(int i = 0; i < kol_coof;i ++)
    ret += (FloatToStr(coof_b[i]) + " ");
  return ret;
}
//---------------------------------------------------------------------------
int CObject::GetFr(int n)
{
  if((n >= 0) && (n < 3))
    return fr[n];
}
//---------------------------------------------------------------------------
int CObject::GetA(int n)
{
  if((n >= 0) && (n < 3))
    return a[n];
}
//---------------------------------------------------------------------------
void CObject::Run()
{
  for(int i = 0; i < 10000; i ++)
  {
    data_in[i] =
    (int)((double)sm + (double)a[0] * sin(2.0*M_PI*(double)fr[0]*(double)i/(double)fd)) +
    (int)((double)a[1] * sin(2.0*M_PI*(double)fr[1]*(double)i/(double)fd)) +
    (int)((double)a[2] * sin(2.0*M_PI*(double)fr[2]*(double)i/(double)fd));
  }
  double y[100], x[100];
  for(int i = 1; i < kol_coof; i ++)
  {
    y[i] = 0;
    x[i] = 0;
  }
  for(int j = 0; j < 10000; j ++)
  {
    x[kol_coof] = data_in[j];
    y[kol_coof] = 0;
    for(int i = 1; i < kol_coof; i ++)
    {
      y[kol_coof] = y[kol_coof] + coof_b[i] * x[kol_coof-i];
      y[kol_coof] = y[kol_coof] - coof_a[i] * y[kol_coof-i];
    }
    y[kol_coof] = y[kol_coof] + coof_b[0] * x[kol_coof];
    for(int i = 1; i < kol_coof; i ++)
    { x[i] = x[i+1]; y[i] = y[i+1]; }
    data_midle[j] = y[kol_coof];
  }
  CData xd[100], yd[100];
  for(int i = 0; i < kol_coof; i ++)
  {
    xd[i].SetMP(mantisa, por);
    yd[i] = 0.0;
    xd[i] = 0.0;
    coof_bd[i] = (double)coof_b[i];
    coof_ad[i] = (double)-coof_a[i];
  }
  for(int j = 0; j < 10000; j ++)
  {
    xd[kol_coof] = data_in[j];
//    xd[kol_coof] = -10000;
    yd[kol_coof] = 0;
    for(int i = 1; i < kol_coof; i ++)
    {
      yd[kol_coof] = yd[kol_coof] + coof_bd[i] * xd[kol_coof-i];
      yd[kol_coof] = yd[kol_coof] + coof_ad[i] * yd[kol_coof-i];
    }
    yd[kol_coof] = yd[kol_coof] + coof_bd[0] * xd[kol_coof];
    for(int i = 1; i < kol_coof; i ++)
    { xd[i] = xd[i+1]; yd[i] = yd[i+1]; }
    data_out[j] = yd[kol_coof].GetInt();
  }
}
//---------------------------------------------------------------------------
void CObject::RunVHDL(TMemo *memo, AnsiString name)
{
  memo->Clear();
//  memo->Lines->Add("--от Кучинского Андрея");
  memo->Lines->Add("library IEEE;");
  memo->Lines->Add("use IEEE.STD_LOGIC_1164.ALL;");
  memo->Lines->Add("use IEEE.STD_LOGIC_ARITH.ALL;");
  memo->Lines->Add("use IEEE.STD_LOGIC_UNSIGNED.ALL;");
//  memo->Lines->Add("library unisim;");
//  memo->Lines->Add("use unisim.vcomponents.all;");
  memo->Lines->Add("");
  memo->Lines->Add("entity " + name + " is");
  memo->Lines->Add("    Port (");
  memo->Lines->Add("           data_in : in std_logic_vector"+DownTo(mantisa-1,0)+";");
  memo->Lines->Add("           data_out : out std_logic_vector"+DownTo(mantisa-1,0)+";");
  memo->Lines->Add("           clk : in std_logic;");
  memo->Lines->Add("           clk_" + IntToStr(fd) + " : in std_logic;");
  memo->Lines->Add("           rst : in std_logic);");
  memo->Lines->Add("end " + name + ";");  //________________________________________________________________
  memo->Lines->Add("architecture arch of " + name + " is");//architecture
  memo->Lines->Add("   signal inm, outm : std_logic_vector"+DownTo(mantisa-2,0)+";");
  memo->Lines->Add("   signal inp : std_logic_vector"+DownTo(por-1,0)+";");
  memo->Lines->Add("   signal inz, outz : std_logic;");
  //ADD
  memo->Lines->Add("   signal addm1, addm2, addm3, addm4, addm5, addm7, addm : std_logic_vector"+DownTo(mantisa-2,0)+";");
  memo->Lines->Add("   signal addm6, addm61, addm62, addm8 : std_logic_vector"+DownTo(mantisa-1,0)+";");
  memo->Lines->Add("   signal addp1, addp2, addp3, addp : std_logic_vector"+DownTo(por-1,0)+";");
  memo->Lines->Add("   signal addpbm, addz1, addz2, addz3, addz4, addz : std_logic;");
  //MUL
  memo->Lines->Add("   signal mulm1 : std_logic_vector"+DownTo(2*(mantisa-1)-1,0)+";");
  memo->Lines->Add("   signal mulmi1, mulmi2, mulm2, mulm : std_logic_vector"+DownTo(mantisa-2,0)+";");
  memo->Lines->Add("   signal mulpi1, mulpi2, mulp1, mulp2, mulp : std_logic_vector"+DownTo(por-1,0)+";");
  memo->Lines->Add("   signal mulzi1, mulzi2, mulz : std_logic;");
  //AB REG
  for(int i = 1; i <= kol_coof; i ++)
  {
    memo->Lines->Add("   constant am"+IntToStr(i)+" : std_logic_vector"+DownTo(mantisa-2,0)+" := "+coof_ad[i-1].GetMon()+";");
    memo->Lines->Add("   constant az"+IntToStr(i)+" : std_logic := "+coof_ad[i-1].GetZnak()+";");
    memo->Lines->Add("   constant ap"+IntToStr(i)+" : std_logic_vector"+DownTo(por-1,0)+" := "+coof_ad[i-1].GetPor()+";");
    memo->Lines->Add("   constant bm"+IntToStr(i)+" : std_logic_vector"+DownTo(mantisa-2,0)+" := "+coof_bd[i-1].GetMon()+";");
    memo->Lines->Add("   constant bz"+IntToStr(i)+" : std_logic := "+coof_bd[i-1].GetZnak()+";");
    memo->Lines->Add("   constant bp"+IntToStr(i)+" : std_logic_vector"+DownTo(por-1,0)+" := "+coof_bd[i-1].GetPor()+";");
    memo->Lines->Add("   signal xm"+IntToStr(i)+" : std_logic_vector"+DownTo(mantisa-2,0)+";");
    memo->Lines->Add("   signal xz"+IntToStr(i)+" : std_logic;");
    memo->Lines->Add("   signal xp"+IntToStr(i)+" : std_logic_vector"+DownTo(por-1,0)+";");
    memo->Lines->Add("   signal ym"+IntToStr(i)+" : std_logic_vector"+DownTo(mantisa-2,0)+";");
    memo->Lines->Add("   signal yz"+IntToStr(i)+" : std_logic;");
    memo->Lines->Add("   signal yp"+IntToStr(i)+" : std_logic_vector"+DownTo(por-1,0)+";");
  }
  //YY
  memo->Lines->Add("   signal beg, work, work_end : std_logic;");
  int kol_bit_styy;
  switch(kol_coof)
  {
    case 1:kol_bit_styy = 1;break;
    case 2:kol_bit_styy = 2;break;
    case 3:case 4:kol_bit_styy = 3;break;
    case 5:case 6:case 7:case 8:kol_bit_styy = 4;break;
    case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:kol_bit_styy = 5;break;
    default:kol_bit_styy = 6;break;
  }
  memo->Lines->Add("   signal st : std_logic_vector"+DownTo(kol_bit_styy-1,0)+";");


  memo->Lines->Add("");

  memo->Lines->Add("begin"); //begin________________________________________________________________
  memo->Lines->Add("  inz <= data_in("+IntToStr(mantisa-1)+");");
  memo->Lines->Add("  with inz select inm <= data_in"+DownTo(mantisa-2,0)+" when '0'"+
                   ", ((not data_in"+DownTo(mantisa-2,0)+")+"+GetNumberBin(1, mantisa-1)+") when others;");
  memo->Lines->Add("  with data_in select inp <= (others=>'0') when "+GetNumberBin(0, mantisa)+
                   ", "+GetNumberBin(mantisa-1, por)+" when others;");
  memo->Lines->Add("  with yp"+IntToStr(kol_coof)+" select outm <= ym"+IntToStr(kol_coof)+" when "+GetNumberBin(mantisa-1, por)+", ");
  AnsiString str = "    ";
//  for(int i = 1; i < (mantisa-1); i++)
//    str = str + "ym"+IntToStr(kol_coof)+DownTo(mantisa-2-i,0)+"&"+GetNumberBin(0,i)+" when "+GetNumberBin((mantisa-1)+i, por)+", ";
//  memo->Lines->Add(str);
//  str = "    ";
  for(int i = 1; i < (mantisa-1); i++)
    str = str+GetNumberBin(0,i)+"&"+"ym"+IntToStr(kol_coof)+DownTo(mantisa-2,i)+" when "+GetNumberBin((mantisa-1)-i, por)+", ";
  memo->Lines->Add(str+GetNumberBin(0,mantisa-1)+" when others;");
  memo->Lines->Add("  with outm select outz <= '0' when "+GetNumberBin(0, mantisa-1)+", yz"+IntToStr(kol_coof)+" when others;");
  memo->Lines->Add("  with outz select data_out"+DownTo(mantisa-2,0)+"<= outm when '0', "+
                   "((not outm)+ "+GetNumberBin(1, mantisa-1)+") when others;");
  memo->Lines->Add("  data_out("+IntToStr(mantisa-1)+") <= outz;");

  //ADD
  memo->Lines->Add("  addpbm <= '1' when ((not mulp("+IntToStr(por-1)+")&mulp) > (not yp"+IntToStr(kol_coof)+"("+IntToStr(por-1)+") & yp"+IntToStr(kol_coof)+")) else '0';");
  memo->Lines->Add("p_addin: process (addpbm, mulm, mulp, mulz, ym"+IntToStr(kol_coof)+", yp"+IntToStr(kol_coof)+", yz"+IntToStr(kol_coof)+") begin");
  memo->Lines->Add("  if addpbm = '1' then addm1 <= mulm; addp1 <= mulp; addz1 <= mulz;");
  memo->Lines->Add("    addm2 <= ym"+IntToStr(kol_coof)+"; addp2 <= yp"+IntToStr(kol_coof)+"; addz2 <= yz"+IntToStr(kol_coof)+";");
  memo->Lines->Add("  else addm2 <= mulm; addp2 <= mulp; addz2 <= mulz;");
  memo->Lines->Add("    addm1 <= ym"+IntToStr(kol_coof)+"; addp1 <= yp"+IntToStr(kol_coof)+"; addz1 <= yz"+IntToStr(kol_coof)+";");
  memo->Lines->Add("  end if;");
  memo->Lines->Add("end process;");
  memo->Lines->Add("  addp3 <= addp1 - addp2;");
  memo->Lines->Add("p_add1: process (addp3, addm2) begin");
  memo->Lines->Add("  case addp3 is");
  for(int i = (mantisa-2); i > 0; i--)
    memo->Lines->Add("    when "+GetNumberBin(i, por)+" => addm3 <= "+GetNumberBin(0,i)+" & addm2"+DownTo(mantisa-2, i)+";");
  memo->Lines->Add("    when "+GetNumberBin(0, por)+" => addm3 <= addm2;");
  memo->Lines->Add("    when others => addm3 <= (others => '0');");
  memo->Lines->Add("    end case;");
  memo->Lines->Add("end process;");
  memo->Lines->Add("  addz3 <= '0' when addm3 = "+GetNumberBin(0, mantisa-1)+" else addz2;");
  memo->Lines->Add("p_add2: process (addm1, addm3, addz1, addz3) begin");
  memo->Lines->Add("  if addm1 > addm3 then addm4 <= addm1; addm5 <= addm3; addz4 <= addz1;");
  memo->Lines->Add("  else addm4 <= addm3; addm5 <= addm1; addz4 <= addz3; end if;");
  memo->Lines->Add("end process;");
  memo->Lines->Add("  addm61 <= '0'&addm4;");
  memo->Lines->Add("  addm62 <= '0'&addm5;");
  memo->Lines->Add("  addm6 <= addm61 + addm62;");
  memo->Lines->Add("  addm7 <= addm4 - addm5;");
  memo->Lines->Add("  addm8 <= addm6 when addz1 = addz3 else '0'&addm7;");

  memo->Lines->Add("p_add: process (addm8, addz4, addp1) begin");
  memo->Lines->Add("  if addm8 = "+GetNumberBin(0,mantisa-1)+" then");
  memo->Lines->Add("    addz <= '0';");
  memo->Lines->Add("    addm <= (others => '0');");
  memo->Lines->Add("    addp <= (others => '0');");
  memo->Lines->Add("  else");
  memo->Lines->Add("    addz <= addz4;");
  memo->Lines->Add("    if addm8("+IntToStr(mantisa-1)+") = '1' then addm <= addm8"+DownTo(mantisa-1,1)+"; addp <= addp1 + "+GetNumberBin(1,por)+";");
  memo->Lines->Add("    else if addm8("+IntToStr(mantisa-2)+") = '1' then addm <= addm8"+DownTo(mantisa-2,0)+"; addp <= addp1;");
  str = "end if; end if; ";
  for(int i = mantisa-3; i > 0; i--, str = str + "end if; ")
    memo->Lines->Add("    else if addm8("+IntToStr(i)+") = '1' then addm <= addm8"+DownTo(i, 0)+"&"+GetNumberBin(0,mantisa-2-i)+"; addp <= addp1 - "+GetNumberBin(mantisa-2-i,por)+";");
  memo->Lines->Add("    else addm <= addm8(0)&"+GetNumberBin(0,mantisa-2)+"; addp <= addp1 - "+GetNumberBin(mantisa-2,por)+";");
  memo->Lines->Add("    " + str);
  memo->Lines->Add("  end if;");
  memo->Lines->Add("end process;");
  //MUL
  str = "";
  for(int i = 1; i <= kol_coof; i ++)
    str = str + "xm"+IntToStr(i)+", xp"+IntToStr(i)+", xz"+IntToStr(i)+", ym"+IntToStr(i)+", yp"+IntToStr(i)+", yz"+IntToStr(i)+", ";
  memo->Lines->Add("p_mulin: process ("+str+"st) begin");
  memo->Lines->Add("  case st is");
  for(int i = 1; i < kol_coof; i ++)
  {
    memo->Lines->Add("    when "+GetNumberBin(2*i-1, kol_bit_styy)+" => mulmi1 <= bm"+IntToStr(kol_coof-i+1)+"; mulpi1 <= bp"+IntToStr(kol_coof-i+1)+"; mulzi1 <= bz"+IntToStr(kol_coof-i+1)+
                                                   "; mulmi2 <= xm"+IntToStr(i)+"; mulpi2 <= xp"+IntToStr(i)+"; mulzi2 <= xz"+IntToStr(i)+";");
    memo->Lines->Add("    when "+GetNumberBin(2*i, kol_bit_styy)+" => mulmi1 <= am"+IntToStr(kol_coof-i+1)+"; mulpi1 <= ap"+IntToStr(kol_coof-i+1)+"; mulzi1 <= az"+IntToStr(kol_coof-i+1)+
                                                 "; mulmi2 <= ym"+IntToStr(i)+"; mulpi2 <= yp"+IntToStr(i)+"; mulzi2 <= yz"+IntToStr(i)+";");
  }
  memo->Lines->Add("    when others => mulmi1 <= bm"+IntToStr(1)+"; mulpi1 <= bp"+IntToStr(1)+"; mulzi1 <= bz"+IntToStr(1)+
                                    "; mulmi2 <= xm"+IntToStr(kol_coof)+"; mulpi2 <= xp"+IntToStr(kol_coof)+"; mulzi2 <= xz"+IntToStr(kol_coof)+";");
  memo->Lines->Add("    end case;");
  memo->Lines->Add("end process;");
  memo->Lines->Add("  mulm1 <= mulmi1 * mulmi2;");
  memo->Lines->Add("  mulp1 <= mulpi1 + mulpi2;");
  str = "";
  memo->Lines->Add("p_mul1: process (mulm1, mulm2, mulp2) begin");
  for(int i = 2*(mantisa-1)-1; i >= mantisa-1; i--, str = str + "end if; ")
  {
    if(i == 2*(mantisa-1)-1)
      memo->Lines->Add("  if mulm1("+IntToStr(i)+") = '1' then mulm2 <= mulm1"+DownTo(i, i-mantisa+2)+"; mulp2 <= "+GetNumberBin(2*(mantisa-1)-1-i,por)+";");
    else
      memo->Lines->Add("  else if mulm1("+IntToStr(i)+") = '1' then mulm2 <= mulm1"+DownTo(i, i-mantisa+2)+"; mulp2 <= "+GetNumberBin(2*(mantisa-1)-1-i,por)+";");
  }
  memo->Lines->Add("  else mulm2 <= mulm1"+DownTo(mantisa-2, 0)+"; mulp2 <= "+GetNumberBin(mantisa-1,por)+";");
  memo->Lines->Add("  " + str);
  memo->Lines->Add("end process;");
  memo->Lines->Add("p_mul: process (mulm2, mulzi1, mulzi2, mulp1, mulp2) begin");
  memo->Lines->Add("  if mulm2 = "+GetNumberBin(0,(mantisa-1))+" then");
  memo->Lines->Add("    mulz <= '0';");
  memo->Lines->Add("    mulm <= (others => '0');");
  memo->Lines->Add("    mulp <= (others => '0');");
  memo->Lines->Add("  else");
  memo->Lines->Add("    mulz <= mulzi1 xor mulzi2;");
  memo->Lines->Add("    mulm <= mulm2;");
  memo->Lines->Add("    mulp <= mulp1 - mulp2;");
  memo->Lines->Add("  end if;");
  memo->Lines->Add("end process;");
  //REG
  for(int i = 1; i < kol_coof; i ++)
  {
    memo->Lines->Add("p_regx"+IntToStr(i)+": process (clk, rst) begin");
    memo->Lines->Add("  if rst = '1' then xm"+IntToStr(i)+" <= (others=>'0'); xp"+IntToStr(i)+" <= (others=>'0'); xz"+IntToStr(i)+" <= '0';");
    memo->Lines->Add("  else if clk = '1' and clk'event then if work='1' and st="+GetNumberBin(2*i-1, kol_bit_styy)+" then");
    memo->Lines->Add("    xm"+IntToStr(i)+" <= xm"+IntToStr(i+1)+"; xp"+IntToStr(i)+" <= xp"+IntToStr(i+1)+"; xz"+IntToStr(i)+" <= xz"+IntToStr(i+1)+";");
    memo->Lines->Add("  end if; end if; end if;");
    memo->Lines->Add("end process;");

    memo->Lines->Add("p_regy"+IntToStr(i)+": process (clk, rst) begin");
    memo->Lines->Add("  if rst = '1' then ym"+IntToStr(i)+" <= (others=>'0'); yp"+IntToStr(i)+" <= (others=>'0'); yz"+IntToStr(i)+" <= '0';");
    if(i == (kol_coof-1))
    {
      memo->Lines->Add("  else if clk = '1' and clk'event then if work='1' and st="+GetNumberBin(0, kol_bit_styy)+" then");
      memo->Lines->Add("    ym"+IntToStr(i)+" <= ym"+IntToStr(i+1)+"; yp"+IntToStr(i)+" <= yp"+IntToStr(i+1)+"; yz"+IntToStr(i)+" <= yz"+IntToStr(i+1)+";");
    }
    else
    {
      memo->Lines->Add("  else if clk = '1' and clk'event then if work='1' and st="+GetNumberBin(2*i, kol_bit_styy)+" then");
      memo->Lines->Add("    ym"+IntToStr(i)+" <= ym"+IntToStr(i+1)+"; yp"+IntToStr(i)+" <= yp"+IntToStr(i+1)+"; yz"+IntToStr(i)+" <= yz"+IntToStr(i+1)+";");
    }
    memo->Lines->Add("  end if; end if; end if;");
    memo->Lines->Add("end process;");
  }
  memo->Lines->Add("p_regx"+IntToStr(kol_coof)+": process (clk, rst) begin");
  memo->Lines->Add("  if rst = '1' then xm"+IntToStr(kol_coof)+" <= (others=>'0'); xp"+IntToStr(kol_coof)+" <= (others=>'0'); xz"+IntToStr(kol_coof)+" <= '0';");
  memo->Lines->Add("  else if clk = '1' and clk'event then if work='1' and st="+GetNumberBin(1, kol_bit_styy)+" then");
  memo->Lines->Add("    xm"+IntToStr(kol_coof)+" <= inm; xp"+IntToStr(kol_coof)+" <= inp; xz"+IntToStr(kol_coof)+" <= inz;");
  memo->Lines->Add("  end if; end if; end if;");
  memo->Lines->Add("end process;");
  memo->Lines->Add("p_regy"+IntToStr(kol_coof)+": process (clk, rst) begin");
  memo->Lines->Add("  if rst = '1' then ym"+IntToStr(kol_coof)+" <= (others=>'0'); yp"+IntToStr(kol_coof)+" <= (others=>'0'); yz"+IntToStr(kol_coof)+" <= '0';");
  memo->Lines->Add("  else if clk = '1' and clk'event then if work='1' then");
  memo->Lines->Add("    if st="+GetNumberBin(0, kol_bit_styy)+" then ym"+IntToStr(kol_coof)+" <= "+GetNumberBin(0, mantisa-1)+"; yp"+IntToStr(kol_coof)+" <= "+GetNumberBin(0, por)+"; yz"+IntToStr(kol_coof)+" <= '0';"+
                       "else ym"+IntToStr(kol_coof)+" <= addm; yp"+IntToStr(kol_coof)+" <= addp; yz"+IntToStr(kol_coof)+" <= addz; end if;");
  memo->Lines->Add("  end if; end if; end if;");
  memo->Lines->Add("end process;");
/*  memo->Lines->Add("p_reg: process (clk, rst) begin");
  memo->Lines->Add("  if rst = '1' then");
  for(int i = 1; i <= kol_coof; i ++)
  {
    memo->Lines->Add("    xm"+IntToStr(i)+" <= (others=>'0'); xp"+IntToStr(i)+" <= (others=>'0'); xz"+IntToStr(i)+" <= '0';");
    memo->Lines->Add("    ym"+IntToStr(i)+" <= (others=>'0'); yp"+IntToStr(i)+" <= (others=>'0'); yz"+IntToStr(i)+" <= '0';");
  }
  memo->Lines->Add("  else if clk = '1' and clk'event then if work='1' then");
  memo->Lines->Add("    if st="+GetNumberBin(0, kol_bit_styy)+" then ym"+IntToStr(kol_coof)+" <= "+GetNumberBin(0, mantisa-1)+"; yp"+IntToStr(kol_coof)+" <= "+GetNumberBin(0, por)+"; yz"+IntToStr(kol_coof)+" <= '0';"+
                   "else ym"+IntToStr(kol_coof)+" <= addm; yp"+IntToStr(kol_coof)+" <= addp; yz"+IntToStr(kol_coof)+" <= addz; end if;");
  memo->Lines->Add("    if st="+GetNumberBin(1, kol_bit_styy)+" then xm"+IntToStr(kol_coof)+" <= inm; xp"+IntToStr(kol_coof)+" <= inp; xz"+IntToStr(kol_coof)+" <= inz; end if;");
  for(int i = 1; i < kol_coof; i ++)
  {
    memo->Lines->Add("    if st="+GetNumberBin(2*i-1, kol_bit_styy)+" then xm"+IntToStr(i)+" <= xm"+IntToStr(i+1)+"; xp"+IntToStr(i)+" <= xp"+IntToStr(i+1)+"; xz"+IntToStr(i)+" <= xz"+IntToStr(i+1)+"; end if;");
    if(i == (kol_coof-1))
      memo->Lines->Add("    if st="+GetNumberBin(0, kol_bit_styy)+" then ym"+IntToStr(i)+" <= ym"+IntToStr(i+1)+"; yp"+IntToStr(i)+" <= yp"+IntToStr(i+1)+"; yz"+IntToStr(i)+" <= yz"+IntToStr(i+1)+"; end if;");
    else
      memo->Lines->Add("    if st="+GetNumberBin(2*i, kol_bit_styy)+" then ym"+IntToStr(i)+" <= ym"+IntToStr(i+1)+"; yp"+IntToStr(i)+" <= yp"+IntToStr(i+1)+"; yz"+IntToStr(i)+" <= yz"+IntToStr(i+1)+"; end if;");
  }
  memo->Lines->Add("  end if; end if; end if;");
  memo->Lines->Add("end process;");*/
  //YY
  memo->Lines->Add("p_beg: process (clk_" + IntToStr(fd) + ", work_end, rst) begin");
  memo->Lines->Add("  if rst = '1' or work_end = '1' then beg <= '0';");
  memo->Lines->Add("  else if clk_" + IntToStr(fd) + " = '1' and clk_" + IntToStr(fd) + "'event then");
  memo->Lines->Add("    beg <= '1';");
  memo->Lines->Add("  end if; end if;");
  memo->Lines->Add("end process;");
  memo->Lines->Add("p_work: process (clk, work_end, rst) begin");
  memo->Lines->Add("  if rst = '1' or work_end = '1' then work <= '0';");
  memo->Lines->Add("  else if clk = '1' and clk'event then");
  memo->Lines->Add("    if beg = '1' then work <= '1'; end if;");
  memo->Lines->Add("  end if; end if;");
  memo->Lines->Add("end process;");
  memo->Lines->Add("p_work_end: process (clk, work) begin");
  memo->Lines->Add("  if work = '0' then work_end <= '0';");
  memo->Lines->Add("  else if clk = '1' and clk'event then");
  memo->Lines->Add("    if st = "+GetNumberBin(2*kol_coof-1, kol_bit_styy)+" then work_end <= '1'; end if;");
  memo->Lines->Add("  end if; end if;");
  memo->Lines->Add("end process;");
  memo->Lines->Add("p_st: process (clk, work) begin");
  memo->Lines->Add("  if work = '0' then st <= (others => '0');");
  memo->Lines->Add("  else if clk = '1' and clk'event then");
  memo->Lines->Add("    st <= st + 1;");
  memo->Lines->Add("  end if; end if;");
  memo->Lines->Add("end process;");
  memo->Lines->Add("end arch;"); //end
}
//---------------------------------------------------------------------------
AnsiString CObject::DownTo(int end, int begin)
{
  if(end != begin)
    return "(" + IntToStr(end) + " downto " + IntToStr(begin) + ")";
  return "(" + IntToStr(end) + ")";
}
//---------------------------------------------------------------------------
AnsiString CObject::GetNumberBin(int n, int kol_bit)
{
  AnsiString ret = "";
  n = abs(n);
  for(int i = 0; i < kol_bit; i ++, n /= 2)
    ret = ((n % 2)? "1" : "0") + ret;
  return ((kol_bit > 1)? "\"" : "'") + ret + ((kol_bit > 1)? "\"" : "'");
}
//---------------------------------------------------------------------------
void CObject::Paint(TImage *image, int s)
{
  if(s)
    center = s;
  int cen = 0;
  image->Canvas->Brush->Color = clBlack;  //очищаем
  image->Canvas->FillRect(Rect(0, 0, image->Width, image->Height));
  if(center == 1)
  {
    for(int i = 0; i < image->Width; i += 10)
      cen += data_in[i+begin];
    cen /= (image->Width/10);
    Paint(image, data_midle, clRed, cen);
    Paint(image, data_out, clYellow, cen);
    Paint(image, data_in, clBlue, cen);
  }
  else if(center == 2)
  {
    for(int i = 0; i < image->Width; i += 10)
      cen += data_midle[i+begin];
    cen /= (image->Width/10);
    Paint(image, data_in, clBlue, cen);
    Paint(image, data_out, clYellow, cen);
    Paint(image, data_midle, clRed, cen);
  }
  else
  {
    for(int i = 0; i < image->Width; i += 10)
      cen += data_out[i+begin];
    cen /= (image->Width/10);
    Paint(image, data_in, clBlue, cen);
    Paint(image, data_midle, clRed, cen);
    Paint(image, data_out, clYellow, cen);
  }
}
//---------------------------------------------------------------------------
void CObject::Paint(TImage *image, int *data, TColor color, int cen)
{
  image->Canvas->Pen->Color = color;
  if(sz <= 0)
    sz = 1;
  image->Canvas->MoveTo(0,  (cen-data[begin])/sz + image->Height/2);
  for(int i = 1; i < image->Width; i ++)
    image->Canvas->LineTo(i, (cen-data[i+begin])/sz + image->Height/2);
  image->Canvas->Font->Size = 12;
  image->Canvas->Font->Color = color;
  image->Canvas->TextOutA(5, image->Height/2-12, IntToStr(cen));
}
//---------------------------------------------------------------------------
void CObject::RunFFT()
{
  FFT(data_in, xfft1, yfft1);
  FFT(data_midle, xfft2, yfft2);
  FFT(data_out, xfft3, yfft3);
}
//---------------------------------------------------------------------------
void CObject::FFT(int *in, double *x, double *y)
{
  int m = 9;
  int size = 512;
  for(int i = 0; i < size; i ++)
  {
    y[i] = 0;
    x[i] = in[i+begin];
  }
  for(int b = 0; b < m; b ++)
  {
    double e = 1 << (m-b);
    double f = e / 2;
    double u = 1;
    double v = 0;
    double z = 3.14159 / f;
    double c = cos(z);
    double s = -sin(z);
    for(int j = 0; j < f; j ++)
    {
      for(int i = j; i < size; i += e)
      {
        int g = i + f;
        double d1 = x[i] + x[g];
        double d2 = y[i] + y[g];
        double r = x[i] - x[g];
        double t = y[i] - y[g];
        x[i] = d1;
        y[i] = d2;
        x[g] = r*u - t*v;
        y[g] = t*u + r*v;
      }
      double w = u*c - v*s;
      v = (v*c + u*s);
      u = w;
    }
  }
  for(unsigned i = 1; i < size - 1; i++)
  {
    unsigned j = 0;
    for(unsigned k = 0; k < m; k++)
      if(i & (0x01 << k))
        j += (size >> k+1);
    if((i >= size) || (j >= size) || (j >= i))
      continue;
    double d = x[j]; x[j] = x[i]; x[i] = d;
    d = y[j]; y[j] = y[i]; y[i] = d;
  }
  for(int i = 0; i < size; i ++)
  {
    x[i] /= size;
    y[i] /= size;
  }
}
//---------------------------------------------------------------------------
void CObject::PaintFFT(TImage *image, int s)
{ 
  RunFFT();
  if(s)
    center = s;
  image->Canvas->Brush->Color = clBlack;  //очищаем
  image->Canvas->FillRect(Rect(0, 0, image->Width, image->Height));
  if(center == 1)
  {
    PaintFFT(image, xfft2, yfft2, clRed);
    PaintFFT(image, xfft3, yfft3, clYellow);
    PaintFFT(image, xfft1, yfft1, clBlue);
  }
  else if(center == 2)
  {
    PaintFFT(image, xfft1, yfft1, clBlue);
    PaintFFT(image, xfft3, yfft3, clYellow);
    PaintFFT(image, xfft2, yfft2, clRed);
  }
  else
  {
    PaintFFT(image, xfft1, yfft1, clBlue);
    PaintFFT(image, xfft2, yfft2, clRed);
    PaintFFT(image, xfft3, yfft3, clYellow);
  }
}
//---------------------------------------------------------------------------
void CObject::PaintFFT(TImage *image, double *x, double *y, TColor color)
{
  image->Canvas->Pen->Color = color;
  if(sz2 == 0)
    sz2 = 1;
  double sz3 = (sz2 <= 0)? 1/fabs(sz2) : sz2;
  for(int i = 1; i < image->Width/2; i ++)
  {
    double s = 2*sqrt(x[i]*x[i] + y[i]*y[i]);
    image->Canvas->MoveTo(2*i, image->Height);
    image->Canvas->LineTo(2*i, -(double)s/sz3 + image->Height);
    image->Canvas->MoveTo(2*i+1, image->Height);
    image->Canvas->LineTo(2*i+1, -(double)s/sz3 + image->Height);
  }
  image->Canvas->Font->Size = 8;
  image->Canvas->Font->Color = color;
  image->Canvas->TextOut(image->Width/4-10,image->Height-12,FloatToStrF((double)fd*1/8, ffFixed, 9, 2));
  image->Canvas->TextOut(image->Width/2-20,image->Height-12,FloatToStrF((double)fd*2/8, ffFixed, 9, 2));
  image->Canvas->TextOut(image->Width*3/4-20,image->Height-12,FloatToStrF((double)fd*3/8, ffFixed, 9, 2));
  image->Canvas->TextOut(image->Width-30,image->Height-12,FloatToStrF((double)fd*4/8, ffFixed, 9, 2));
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
