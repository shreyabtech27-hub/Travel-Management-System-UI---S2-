//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Main.h"
#include "Login.h"
#include "Registration.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LoginButtonClick(TObject *Sender)
{
			  LoginForm->StatusLabel->Text = "";
			  LoginForm->UsernameEdit->Text = "";
			  LoginForm->PasswordEdit->Text = "";
			  LoginForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RegistrationButtonClick(TObject *Sender)
{
			   RegistrationForm->Show();
}
//---------------------------------------------------------------------------
