//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#pragma hdrstop

#include "Cab.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TCabBookingForm *CabBookingForm;
//---------------------------------------------------------------------------
__fastcall TCabBookingForm::TCabBookingForm(TComponent* Owner)
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

int cflag=1;
void __fastcall TCabBookingForm::SaveButtonClick(TObject *Sender)
{

	  if(SourcePopupBox->ItemIndex == -1){
			 ErrorLabel->Text="Starting Point not selected!\n";
	  }

	  else if(DestinationPopupBox->ItemIndex == -1){
			 ErrorLabel->Text="Destination not selected!\n";
	  }

	  else if(PeoplePopupBox->ItemIndex == -1){
			 ErrorLabel->Text="No. of people not selected!\n";
	  }

	  else if(CarPopupBox->ItemIndex == -1){
			 ErrorLabel->Text="Car not selected!\n";
	  }

	  else if((NonACRadioButton->IsChecked == false)&&(ACRadioButton->IsChecked == false)){
			 ErrorLabel->Text="Car specification not selected!\n";
	  }

	  else{
		  ErrorLabel->Text="";
	  }

	  fstream MyFile;
	  MyFile.open("Cab.txt",ios::in);

	  UnicodeString ppl = PeoplePopupBox->Items->Strings[PeoplePopupBox->ItemIndex ]  ;
	  AnsiString pplAnsi = AnsiString(ppl.c_str());
	  int ppl_int = StrToInt(pplAnsi);

	  UnicodeString car = CarPopupBox->Items->Strings[CarPopupBox->ItemIndex ];
	  AnsiString carAnsi = AnsiString(car.c_str());


	   if (carAnsi=="Tata Tiago EV") {
			if(ppl_int>4){
			   ErrorLabel->Text = "Too many people!" ;
			}
	   }

	  UnicodeString start = SourcePopupBox->Items->Strings[SourcePopupBox->ItemIndex ]   ;
	  AnsiString startAnsi = AnsiString(start.c_str());

	  UnicodeString stop = DestinationPopupBox->Items->Strings[DestinationPopupBox->ItemIndex ]   ;
	  AnsiString stopAnsi = AnsiString(stop.c_str());
	  AnsiString ac = "Not Selected";

	  if (ACRadioButton->IsChecked) {
			 ac="AC";
	  }

	  if(NonACRadioButton->IsChecked){
			 ac="Non AC";
	  }


	  if(MyFile.is_open()){
			std::ifstream file("HotelBooking.txt");
			std::string line;


			if (carAnsi=="") {
			carAnsi = "Not Selected";
			}

			if (startAnsi=="") {
				startAnsi = "Not Selected";
			}

			if (stopAnsi=="") {
				   stopAnsi = "Not Selected";
			}

			if (pplAnsi=="") {
				   stopAnsi = "Not Selected";
			}

			while (std::getline(file, line)) {
					std::vector<std::string> parsedLine = parseCommaDelimitedString(line);
					const char* from = parsedLine.at(0).c_str();
					if (from == startAnsi) {
						const char* to = parsedLine.at(1).c_str();
							if (to == stopAnsi) {
								 const char* amt = parsedLine.at(2).c_str();
								 if (ac=="AC") {
									int amt_int = std::atoi(amt);
									amt_int+= 0.1*amt_int;
									AnsiString amt = IntToStr(amt_int);
								 }

								 if (carAnsi=="Tata Tiago EV") {
									 int amt_int = std::atoi(amt);
									 amt_int+= 0.2*amt_int;
									 AnsiString amt = IntToStr(amt_int);
								 }

								 if (carAnsi=="Toyota Innova") {
									 int amt_int = std::atoi(amt);
									 amt_int+= 0.5*amt_int;
									 AnsiString amt = IntToStr(amt_int);
								 }
							}
					}


			}



	  }

	  bool exp = ( (ac != "Not Selected")&&(startAnsi!= "Not Selected")&&(stopAnsi!= "Not Selected")&&(carAnsi!= "Not Selected" ) );
	  if(exp){
		  cflag=0;
          AnsiString text = "Starting Point: "+ startAnsi +"\nDestination: " + stopAnsi+"\nCar: "+carAnsi +"\nSpecification: "+ac;
		  BillLabel->Text = text;
		  PayButton->Visible = true;
	  }

	  MyFile.close();

}


//---------------------------------------------------------------------------


void __fastcall TCabBookingForm::ClearButtonClick(TObject *Sender)
{
				SourcePopupBox->ItemIndex = -1;
				PeoplePopupBox->ItemIndex = -1;
				CarPopupBox->ItemIndex = -1;
				DestinationPopupBox->ItemIndex = -1;
				NonACRadioButton->IsChecked = false;
				ACRadioButton->IsChecked = false;

				BillLabel->Text = "";
				StatusLabel->Text = "";
				PayButton->Visible = false;
				cflag=0;
}
//---------------------------------------------------------------------------
void __fastcall TCabBookingForm::PayButtonClick(TObject *Sender)
{
			if (cflag==0) {
			  StatusLabel->Text = "Payment Successful";
	   }
}
//---------------------------------------------------------------------------





