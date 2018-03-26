//---------------------------------------------------------------------------
#ifndef UmainH
#define UmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>


#include "CObject.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include "CSPIN.h"
#include "AboutForm.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *M_file;
        TMenuItem *M_open;
        TMenuItem *M_save;
        TMenuItem *M_exit;
        TPageControl *PageControl1;
        TPanel *Panel2;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TBitBtn *ButNew;
        TBitBtn *ButLoad;
        TBitBtn *ButSave;
        TBitBtn *ButRun;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TMenuItem *M_new;
        TMemo *MemoVhdl;
        TMenuItem *M_save_as;
        TLabel *Label1;
        TGroupBox *GroupBox1;
        TCSpinEdit *CSpinEditMantisa;
        TLabel *Label3;
        TCSpinEdit *CSpinEditPor;
        TLabel *Label4;
        TLabel *Label2;
        TLabel *Label5;
        TEdit *EditB;
        TEdit *EditA;
        TLabel *Label6;
        TGroupBox *GroupBox2;
        TLabel *Label7;
        TEdit *EditFd;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TEdit *EditFr1;
        TEdit *EditFr2;
        TEdit *EditFr3;
        TEdit *EditA3;
        TEdit *EditA2;
        TEdit *EditA1;
        TEdit *EditSm;
        TCSpinEdit *CSpinEditKol;
        TLabel *Label14;
        TPanel *Panel1;
        TButton *ButIn;
        TButton *ButOut;
        TScrollBar *ScrollBar1;
        TButton *ButMidle;
        TPageControl *PageControl2;
        TTabSheet *TabSheet5;
        TTabSheet *TabSheet6;
        TImage *image;
        TImage *imagefft;
        TTrackBar *TrackBar1;
        TLabel *Label15;
        TTrackBar *TrackBar2;
        TLabel *Label17;
        TLabel *Label20;
        TLabel *Label16;
        TMenuItem *M_help;
        TMenuItem *M_Abuot;
        void __fastcall M_openClick(TObject *Sender);
        void __fastcall M_saveClick(TObject *Sender);
        void __fastcall M_newClick(TObject *Sender);
        void __fastcall M_exitClick(TObject *Sender);
        void __fastcall M_save_asClick(TObject *Sender);
        void __fastcall ButRunClick(TObject *Sender);
        void __fastcall CSpinEditMantisaChange(TObject *Sender);
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall ButInClick(TObject *Sender);
        void __fastcall ButOutClick(TObject *Sender);
        void __fastcall ScrollBar1Change(TObject *Sender);
        void __fastcall ButMidleClick(TObject *Sender);
        void __fastcall TrackBar2Change(TObject *Sender);
        void __fastcall M_AbuotClick(TObject *Sender);
private:	// User declarations
        AnsiString file_name;
        CObject object;

        void SetSave(bool s = false);
        bool GetInt(int &c, AnsiString str, AnsiString err);
        bool GetDouble(int kol, double *c, AnsiString str, AnsiString err);
        bool SetState();
        void PrintState();
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
