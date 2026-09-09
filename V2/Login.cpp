//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#pragma hdrstop

#include "Login.h"
#include "Menu.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TLoginForm *LoginForm;
//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}

std::vector<std::string> parseCommaDelimitedString(std::string line){
			std::vector<std::string> result;
			std::stringstream s_stream(line);

			while(s_stream.good()){
				std::string substr;
				getline(s_stream,substr,',');
				result.push_back(substr);
			}

			return result;
}

const char* convertToCharPtr(AnsiString ansiStr){
			   return ansiStr.c_str();

}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::LoginButtonClick(TObject *Sender)
{
		   fstream MyFile;
		   MyFile.open("registeredUsers.txt",ios::in);
		   int flag = 0;

		   if((MyFile.is_open()&&(flag==0))){
				std::string line;

				while(getline(MyFile,line)){
					std::vector<std::string> parsedLine = parseCommaDelimitedString(line);
					const char* username = parsedLine.at(2).c_str();

					if(std::strcmp(username,convertToCharPtr(UsernameEdit->Text))==0){
						const char* password = parsedLine.at(3).c_str();

						if(std::strcmp(password,convertToCharPtr(PasswordEdit->Text))==0){
							StatusLabel->Text = "Success!";
                            flag = 1;
						}
						else {
							StatusLabel->Text = "Wrong Password!";
						}
					}
					else{
						StatusLabel->Text = "Invalid Username!";

					}
				}
				MyFile.close();


		   }

		   if (flag == 1) {
		   MenuForm->Show();
		   UsernameEdit->Text="";
		   PasswordEdit->Text="";
		   StatusLabel->Text="";
		   }


}
//---------------------------------------------------------------------------
