//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include <Registry.hpp>
#pragma hdrstop
using namespace std;

#include "PRB.h"

// Deklarationen Jeff
AnsiString getProgramDir();
void RegisterAPP(AnsiString ExePath);
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

String PasswordCreateA, PasswordGet, ThePassword;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form1->KeyPreview = true; // Keyhook
	Form1->BorderStyle = None;
	WindowState = wsMaximized;
	Memo1->Text = "";
	MaskEdit1->Text = "";
	MaskEdit2->Text = "";
	MaskEdit3->Text = "";
	MaskEdit4->Text = "";
	MaskEdit4->Color = clHighlight;
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
	Memo1->Lines->Append(">> Windows will reboot now.");
	system("shutdown.exe -r -t 0");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	/*Shutdown*/
	system("shutdown -s -t 0");
	Memo1->Lines->Append(">> Windows will shudtown now.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	// Password = Hallo
	if (FileExists("Password.txt"))
	{
		/*Characterdetection*/
		if (MaskEdit1->Text == MaskEdit2->Text && MaskEdit4->Text.Length() >= 4 && MaskEdit4->Text.Length() <= 128 && MaskEdit1->Text.Length() >= 4 && MaskEdit2->Text.Length() >= 4 && MaskEdit1->Text.Length() <= 128 && MaskEdit2->Text.Length() <= 128)
		{
			TTextReader *Open = new TStreamReader("Password.txt");
			PasswordGet = Open->ReadLine();
			Open->Free();

			if (PasswordGet == MaskEdit4->Text)
			{
				PasswordCreateA = MaskEdit4->Text;
				TTextWriter *Speichern = new TStreamWriter("Password.txt", false);
				Speichern->WriteLine(MaskEdit1->Text);
				Speichern->Free();

				Memo1->Lines->Append("Change was Succesful.");
				Memo1->Lines->Append("You can now try to log in.");
			}
			else
			{
				Memo1->Lines->Append("An Error has occured, please try again.");
            }
		}
		else
		{
			Memo1->Lines->Append("An Error has occured, please try again.");
		}
	 }
	 else
	 {
		if (MaskEdit1->Text == MaskEdit2->Text && MaskEdit1->Text.Length() >= 4 && MaskEdit2->Text.Length() >= 4 && MaskEdit1->Text.Length() <= 128 && MaskEdit2->Text.Length() <= 128)
		{
			/*Create new Password File*/
			PasswordCreateA = MaskEdit1->Text;
			TTextWriter *Speichern = new TStreamWriter("Password.txt", false);
			Speichern->WriteLine(MaskEdit1->Text);
			Speichern->Free();

			/*File attributes*/
			//FileSetAttr("C:\Password.txt", faHidden);

			/*Pseudo cmd positive result*/
			Memo1->Lines->Append("File was safed and created succesfully");
			Memo1->Lines->Append(">> You can now try to Log in !");
			ShowMessage("Password committed succesfully!");
		}
		else
		{
			/*Pseudo cmd negative result*/
			Memo1->Lines->Append("Creating failed.");
			Memo1->Lines->Append(">> Please repeat.");
			// ShowMessage("Creating the Password has failed - What was the problem ?\n\n  • Less than 4 characters\n  • More than 128 characters\n  • The 2nd Password isn't the same as the 1st\n  • Look out for big and small characters ");
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    /*Log in*/
	ThePassword = MaskEdit3->Text;

	/*Input Error*/
	if (ThePassword.IsEmpty())
	{
		Memo1->Lines->Append("No insert, please try again.");
		ShowMessage("An error has occurred.");
	}

	/*Check input*/
	if (ThePassword.Length() >= 4 && FileExists("Password.txt"))
	{
		Memo1->Lines->Append("Input gets checked ...");
		TTextReader *Open = new TStreamReader("Password.txt");
		PasswordGet = Open->ReadLine();
		Open->Free();

		/*Compare input with safed data*/
		if (PasswordGet == ThePassword)
			{
				Memo1->Lines->Append("Log in was succesful, enjoy your session");
				ShowMessage("Press OK to enter your computer.");
				exit(0);
			}
			else
			{
				Memo1->Lines->Append("Log in was not succesful.");
			}
	}
	else
	{
		Memo1->Lines->Append("Illegal Input or No Password created yet.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1Change(TObject *Sender)
{
	Memo1->ReadOnly = true;
}
//---------------------------------------------------------------------------
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
void __fastcall TForm1::MaskEdit3Change(TObject *Sender)
{
	MaskEdit3->MaxLength = 128;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Key(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_LWIN) // Linke Win taste
	{
        exit(0);
		// Ignorieren
	}
}
//---------------------------------------------------------------------------
AnsiString getProgramDir()
{
	TRegistry *reg = new TRegistry(KEY_READ);
	//char *res = (char*)malloc(256);
	AnsiString res;

	try
	{
		reg->RootKey = HKEY_LOCAL_MACHINE;
		reg->OpenKey("Software\\Microsoft\\Windows\\CurrentVersion\\", false);
		res = reg->ReadString("ProgramFilesDir");
		reg->Free();
	}
	catch(...)
	{
		throw ("Get Program files directory didn't work.");
	}
	return res + AnsiString("\\");
}
//---------------------------------------------------------------------------
void RegisterAPP(AnsiString ExePath)
{
	TRegistry *reg = new TRegistry(KEY_WRITE);

	try
	{
		reg->RootKey = HKEY_CURRENT_USER;
		if ( reg->OpenKey("Software\\Microsoft\\Windows\\CurrentVersion\\Run\\", true) )
			reg->WriteString("PRB", ExePath);
		reg->CloseKey();
		reg->Free();
		Form1->Memo1->Lines->Append("Registry worked fine.");
		// MessageDlg("Alles lief gut. Du bist registriert :-D.", mtInformation, TMsgDlgButtons()<<mbOK, 0);
	}
	catch(...)
	{
		throw("A problem has occured. Please try again.");
    }
}
//--------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	RegisterAPP(ExtractFilePath(Application->ExeName));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	ShowMessage("Programmverzeichnis : " + AnsiString( getProgramDir() ));
}
//---------------------------------------------------------------------------
