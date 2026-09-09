//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#pragma hdrstop

#include "RegistrationForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyRegistrationForm *MyRegistrationForm;
//---------------------------------------------------------------------------
__fastcall TMyRegistrationForm::TMyRegistrationForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMyRegistrationForm::SaveButtonClick(TObject *Sender)
{
	fstream MyFile;
	MyFile.open("RegisteredUsers.txt",ios::app);

	if (MyFile.is_open()) {

		AnsiString name = NameEdit->Text;
		AnsiString number = ContactEdit->Text;
		AnsiString username = UsernameEdit->Text;
		AnsiString password = PasswordEdit->Text;

		MyFile<<name<<","<<number<<","<<username<<","<<password<<"\n";
		MyFile.close();
		this->Close();

	}
}
//---------------------------------------------------------------------------

