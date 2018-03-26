//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Umain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
  M_newClick(Owner);
  SetSave(true);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::M_openClick(TObject *Sender)
{
m1:if(ButSave->Enabled)
    switch(MessageBox(0, "Информация не сохранена. Сохранить?", ChangeFileExt(file_name, "").c_str(),
           MB_ICONQUESTION | MB_YESNOCANCEL))
    {
      case IDYES: M_saveClick(Sender);
                  goto m1;
      case IDCANCEL: return;
    }
  if(OpenDialog->Execute())
  {
    FILE *f = fopen(OpenDialog->FileName.c_str(), "rb");
    if(f)
    {
      object = CObject(f);
      fclose(f);
      file_name = OpenDialog->FileName;
      file_name = ChangeFileExt(file_name, ".fil");
      Caption = "Фильтр - " + ChangeFileExt(file_name, "");
      MemoVhdl->Clear();
      PrintState();
      ButRunClick(Owner);
      TrackBar1Change(Owner);
      ScrollBar1Change(Owner);
      SetSave(true);
    }
    else
      MessageBox(0, "Не могу открыть файл.", "Открытие файла", MB_ICONSTOP | MB_TASKMODAL | MB_OK);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::M_saveClick(TObject *Sender)
{
  if(!SetState())
  {
    MessageBox(0, "Ерундистика...", "", MB_ICONSTOP | MB_TASKMODAL | MB_OK);
    return;
  }
  if(file_name == "Без имени.fil")
  {
    M_save_asClick(Sender);
    return;
  }
  FILE *f = fopen(file_name.c_str(), "wb");
  if(f)
  {
    object.SaveToFile(f);
    fclose(f);
    Caption = "Фильтр - " + ChangeFileExt(file_name, "");
    SetSave(true);
  }
  else
    MessageBox(0, "Не могу сохранить информацию.", "Сохранение", MB_ICONSTOP | MB_TASKMODAL | MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::M_save_asClick(TObject *Sender)
{
  if(SaveDialog->Execute())
  {
    if(SaveDialog->FileName == "")
      return;
    file_name = SaveDialog->FileName;
    file_name = ChangeFileExt(file_name, ".fil");
    M_saveClick(Sender);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::M_newClick(TObject *Sender)
{
m1:if(ButSave->Enabled)
    switch(MessageBox(0, "Информация не сохранена. Сохранить?", ChangeFileExt(file_name, "").c_str(),
           MB_ICONQUESTION | MB_YESNOCANCEL))
    {
      case IDYES: M_saveClick(Sender);
                  goto m1;
      case IDCANCEL: return;
    }
  MemoVhdl->Clear();
  object = CObject();
  SetSave(true);
  file_name = "Без имени.fil";
  Caption = "Фильтр - " + ChangeFileExt(file_name, "");
  TrackBar1Change(Owner);
  ScrollBar1Change(Owner);
  PrintState();
  ButRunClick(Owner);
}
//---------------------------------------------------------------------------
void TMainForm::SetSave(bool s)
{
  ButSave->Enabled = !s;
  M_save->Enabled = !s;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::M_exitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButRunClick(TObject *Sender)
{
  SetState();
  object.Run();
  PrintState();
  object.RunVHDL(MemoVhdl, ExtractFileName(ChangeFileExt(file_name, "")));
}
//---------------------------------------------------------------------------
bool TMainForm::SetState()
{
  long mantisa, por;
  int kol_coof = 0;
  double coof_a[100], coof_b[100];
  int fd, fr[3], a[3], sm;

  mantisa = CSpinEditMantisa->Value;
  por = CSpinEditPor->Value;
  kol_coof = CSpinEditKol->Value;

  GetInt(fd, EditFd->Text, "");
  GetInt(fr[0], EditFr1->Text, "");
  GetInt(a[0], EditA1->Text, "");
  GetInt(sm, EditSm->Text, "");
  GetInt(fr[1], EditFr2->Text, "");
  GetInt(a[1], EditA2->Text, "");
  GetInt(fr[2], EditFr3->Text, "");
  GetInt(a[2], EditA3->Text, "");
  GetDouble(kol_coof, coof_b, EditB->Text, "");
  GetDouble(kol_coof, coof_a, EditA->Text, "");
  object.SetKoof(kol_coof, coof_a, coof_b);
  object.SetRazrad(mantisa, por);
  object.SetKoof(kol_coof, coof_a, coof_b);
  object.SetFd(fd);
  object.SetFAS(fr, a, sm);
  return true;
}
//---------------------------------------------------------------------------
void TMainForm::PrintState()
{
  CSpinEditMantisa->Value = object.GetMantisa();
  CSpinEditPor->Value = object.GetPor();
  CSpinEditKol->Value = object.GetKolCoof();
  EditB->Text = object.GetCoofB();
  EditA->Text = object.GetCoofA();
  EditFd->Text = object.GetFd();
  EditFr1->Text = object.GetFr(0);
  EditA1->Text = object.GetA(0);
  EditSm->Text = object.GetSm();
  EditFr2->Text = object.GetFr(1);
  EditA2->Text = object.GetA(1);
  EditFr3->Text = object.GetFr(2);
  EditA3->Text = object.GetA(2);
  object.Paint(image);
  object.PaintFFT(imagefft);
}
//---------------------------------------------------------------------------
bool TMainForm::GetInt(int &c, AnsiString str, AnsiString err)
{
  AnsiString str2 = "";
  for(int i = 1; i <= str.Length(); i ++)
    if((str[i] >= '0') && (str[i] <= '9'))
      str2 += str[i];
  c = StrToIntDef(str2, -1);
  if(c <= 0)
  {
    if(err != "")
      MessageBox(0, "Ерундистика...", err.c_str(), MB_ICONSTOP | MB_TASKMODAL | MB_OK);
    return false;
  }
  return true;
}
//---------------------------------------------------------------------------
bool TMainForm::GetDouble(int kol, double *c, AnsiString str, AnsiString err)
{
  str += " ";
  int uk = 0;
  int as = str.Length();
  AnsiString str2 = "";
  int i = 1;
  while((str[i] == ' ') && (i <= str.Length())) i++;
  for(; i <= str.Length(); i ++)
  {
    if(str[i] != ' ')
    {
      if(str[i] == ',')
        str2 += '.';
      else
        str2 += str[i];
    }
    else
    {
      if(str2 == "")
        continue;
      c[uk++] = atof(str2.c_str());
      str2 = "";
    }
  }
  if(uk != kol)
  {
    if(err != "")
      MessageBox(0, "Ерундистика...", err.c_str(), MB_ICONSTOP | MB_TASKMODAL | MB_OK);
    for(int j = uk; j < kol; j ++)
      c[j] = 1;
    return false;
  }
  return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CSpinEditMantisaChange(TObject *Sender)
{
  SetSave(false);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TrackBar1Change(TObject *Sender)
{
  Label16->Caption = TrackBar1->Position;
  object.SetSz(TrackBar1->Position);
  object.Paint(image);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TrackBar2Change(TObject *Sender)
{
  if(TrackBar2->Position == 0)
    Label20->Caption = "1";
  else if(TrackBar2->Position > 0)
    Label20->Caption = TrackBar2->Position;
  else
    Label20->Caption = "1/" + IntToStr(abs(TrackBar2->Position));
  object.SetSz2(TrackBar2->Position);
  object.PaintFFT(imagefft);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ScrollBar1Change(TObject *Sender)
{
  object.SetBegin(ScrollBar1->Position);
  object.Paint(image);
  object.PaintFFT(imagefft);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButInClick(TObject *Sender)
{
  object.Paint(image, 1);
  object.PaintFFT(imagefft);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButMidleClick(TObject *Sender)
{
  object.Paint(image, 2);
  object.PaintFFT(imagefft);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButOutClick(TObject *Sender)
{
  object.Paint(image, 3);
  object.PaintFFT(imagefft);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::M_AbuotClick(TObject *Sender)
{
  AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

