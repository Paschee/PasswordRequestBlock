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

String PasswordCreateA, PasswordCreateB, PasswordGetFromFile;
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
	MaskEdit3->Text = "••••";
	Application->MainFormOnTaskBar = false;

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
	/*Master password*/
	if (MaskEdit1->Text == "169" && MaskEdit2->Text == "169")
	{
    	exit(0);
	}

	/*Characterdetection*/
	if (MaskEdit1->Text == MaskEdit2->Text && MaskEdit1->Text.Length() >= 4 && MaskEdit2->Text.Length() >= 4 && MaskEdit1->Text.Length() <= 128 && MaskEdit2->Text.Length() <= 128)
	{
		/*If new file gets created, the old will be removed*/
		if ("Password.txt" != 0)
		{
			remove("Password.txt");
		}

		PasswordCreateA = MaskEdit1->Text;
		TTextWriter *Speichern = new TStreamWriter("Password.txt", false);
		Speichern->WriteLine(MaskEdit1->Text);
		Speichern->Close();

		/*File attributes*/
		FileSetAttr("Password.txt", faHidden);
		FileSetAttr("Password.txt", faHidden);

		/*Pseudo cmd*/
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
	/**/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	/*Log in*/
	PasswordGetFromFile = MaskEdit3->Text;

	if (PasswordGetFromFile.IsEmpty())
	{
		Memo1->Lines->Append("You've not entered any password.");
		Memo1->Lines->Append(">> Please try again.");
		ShowMessage("Error ! \n\n  • Empty Field");
	}
	/* Hier kommt was rein*/

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
