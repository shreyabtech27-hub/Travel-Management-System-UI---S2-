//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#pragma hdrstop

#include "Registration.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TRegistrationForm *RegistrationForm;
//---------------------------------------------------------------------------
__fastcall TRegistrationForm::TRegistrationForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRegistrationForm::SaveButtonClick(TObject *Sender)
{
		 fstream MyFile;
		 MyFile.open("registeredUsers.txt",ios::app);

         AnsiString name = NameEdit->Text;
		 AnsiString contact = ContactEdit->Text;
		 AnsiString username = UsernameEdit->Text;
		 AnsiString password = PasswordEdit->Text;

		 bool exp =( (name!="")&&(contact!="")&&(username!="")&&(password!="") );

		 if ((!exp)) {
			ErrorLabel->Text = "All fields need to be filled!"  ;
		 }

		 if(  (MyFile.is_open()) && exp  ){

				MyFile<<name<<","<<contact<<","<<username<<","<<password<<"\n";

				NameEdit->Text = "" ;
				ContactEdit->Text = "" ;
				UsernameEdit->Text = "" ;
				PasswordEdit->Text = "" ;

				MyFile.close();
				this->Close();

		 }


}

