//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#pragma hdrstop

#include "Hotel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
THotelBookingform *HotelBookingform;
//---------------------------------------------------------------------------
__fastcall THotelBookingform::THotelBookingform(TComponent* Owner)
	: TForm(Owner)
{
}

std::vector<int> parseIntegersFromCommaDelimitedString(const std::string& line) {
    std::vector<int> result;
    std::stringstream s_stream(line);

    while (s_stream.good()) {
        std::string substr;
        getline(s_stream, substr, ',');
        int value = std::stoi(substr); // Convert substring to integer
        result.push_back(value);
    }

    return result;
}
//---------------------------------------------------------------------------

int flag = 0;
void __fastcall THotelBookingform::SavebuttonClick(TObject *Sender)
{
    if (CityPopupBox->ItemIndex == -1) {
        ErrorLabel->Text = "City not selected!\n";
        return; // Exit the function early if city is not selected
    }

    if (HotelPopupBox->ItemIndex == -1) {
        ErrorLabel->Text = "Hotel not selected!\n";
        return; // Exit the function early if hotel is not selected
    }

    int room;
    int ac;
    int amt;

    if (SingleRoomRadioButton->IsChecked) {
        room = 1;
    } else if (DoubleRoomRadioButton->IsChecked) {
        room = 2;
    } else {
        ErrorLabel->Text = "Room type not selected!\n";
        return; // Exit the function early if room type is not selected
    }

    if (NonACRadioButton->IsChecked) {
        ac = 0;
    } else if (ACRadioButton->IsChecked) {
        ac = 1;
    } else {
        ErrorLabel->Text = "Room specification not selected!\n";
        return; // Exit the function early if room specification is not selected
    }

    fstream MyFile;
    MyFile.open("HotelBooking.txt", ios::in);

    int city = CityPopupBox->ItemIndex;
    int hotel = HotelPopupBox->ItemIndex;

    if (MyFile.is_open()) {
        std::ifstream file("HotelBooking.txt");
        std::string line;
        AnsiString s_city;
        AnsiString s_hotel;
        AnsiString s_room = "Not Selected";
        AnsiString s_ac;

        if (room == 1) {
            s_room = "Single Room";
        } else if (room == 2) {
            s_room = "Double Room";
        }

        if (ac == 0) {
            s_ac = "Non-AC ";
        } else if (ac == 1) {
            s_ac = "AC ";
        } else {
            s_ac = "Not Selected";
        }

        if (city == 0) {
            s_city = "Kochi";
        } else if (city == 1) {
            s_city = "Trivandrum";
        } else if (city == 2) {
            s_city = "Kottayam";
        } else {
            s_city = "Not Selected";
        }

        if (hotel == 0) {
            s_hotel = "Le Meridian";
        } else if (hotel == 1) {
            s_hotel = "Brindhavan Gardens";
        } else {
            s_hotel = "Not Selected";
        }

        while (std::getline(file, line)) {
            std::vector<int> integers = parseIntegersFromCommaDelimitedString(line);

            if (integers.size() == 5) { // Ensure there are enough elements in the line
                if (integers[0] == city && integers[1] == hotel && integers[2] == room && integers[3] == ac) {
                    amt = integers[4];
                    flag = 1; // Set the flag only if details are found
                    break; // Exit the loop once details are found
                }
            }
        }

        if (flag == 1) {
            AnsiString s1 = "City: " + s_city;
            AnsiString s2 = "\nHotel Name: " + s_hotel;
            AnsiString s3 = "\nRoom type : " + s_room;
            AnsiString s4 = "\nRoom specification: " + s_ac;
            AnsiString s5 = "\nTotal Payable amount(Including GST): ";
            AnsiString str = IntToStr(amt);

            BillLabel->Text = s1 + s2 + s3 + s4 + s5 + str;
            PayButton->Visible = true;
            ErrorLabel->Text = ""; // Clear any previous error messages
        } else {
            ErrorLabel->Text = "Details not found in the file!\n";
        }
    }

    MyFile.close();
}
//---------------------------------------------------------------------------

void __fastcall THotelBookingform::ClearButtonClick(TObject *Sender)
{
    CityPopupBox->ItemIndex = -1;
    HotelPopupBox->ItemIndex = -1;
    SingleRoomRadioButton->IsChecked = false;
    DoubleRoomRadioButton->IsChecked = false;
    NonACRadioButton->IsChecked = false;
    ACRadioButton->IsChecked = false;

    BillLabel->Text = "";
    ErrorLabel->Text = "";
    StatusLabel->Text = "";
    PayButton->Visible = false;
    flag = 0;
}
//---------------------------------------------------------------------------

void __fastcall THotelBookingform::PayButtonClick(TObject *Sender)
{
    if (flag == 1) {
        StatusLabel->Text = "Payment Successful";
    }
}
//---------------------------------------------------------------------------

