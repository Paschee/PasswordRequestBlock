//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <iostream>
#pragma hdrstop
using namespace std;

#include "PRB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form1->BorderStyle = None;
	WindowState = wsMaximized;
	Memo1->Text = "";
	MaskEdit1->Text = "••••";
	MaskEdit2->Text = "••••";

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	exit(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	/*Reboot*/
	system("system -r -5");
	Memo1->Lines->Append(">> Windows will reboot in 5 seconds.");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	/*Shutdown*/
	system("system -s");
	Memo1->Lines->Append(">> Windows will shudtown in 5 seconds.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	String PasswordCreateA, PasswordCreateB;

	/*Characterdetection*/
	if (MaskEdit1->Text == MaskEdit2->Text && MaskEdit1->Text.Length() >= 4 && MaskEdit2->Text.Length() >= 4
	    && MaskEdit1->Text.Length() <= 128 && MaskEdit2->Text.Length() <= 128)
	{
		PasswordCreateA = MaskEdit1->Text;
		TTextWriter *Speichern = new TStreamWriter("Password.txt", false);
		Speichern->WriteLine(MaskEdit1->Text);
		Speichern->Close();

		Memo1->Lines->Append("File was safed and created succesfully");
		Memo1->Lines->Append(">> You can now try to Log in !");
		ShowMessage("Password committed succesfully!");
	}
	else
	{
		Memo1->Lines->Append("Creating failed.");
		Memo1->Lines->Append(">> Click OK and repeat.");
		ShowMessage("Creating the Password has failed - What was the problem ?\n\n  • Less than 4 characters\n  • More than 128 characters\n  • The 2nd Password isn't the same as the 1st\n  • Look out for big and small characters ");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Change(TObject *Sender)
{
	/*Enter LogIn ? --> VK_RETURN*/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	/*Wenn PW mit gehashtem PW Übereinstimmt, tritt ein.*/
	exit(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1Change(TObject *Sender)
{
	/*Later*/
	Memo1->ReadOnly = true;

}
//-------------------------------------------------------------------------


void __fastcall TForm1::MaskEdit1Change(TObject *Sender)
{
	MaskEdit1->MaxLength = 128;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MaskEdit2Change(TObject *Sender)
{
	MaskEdit2->MaxLength = 128;
}
//---------------------------------------------------------------------------
