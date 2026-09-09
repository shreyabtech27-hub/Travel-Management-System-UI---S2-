//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Menu.h"
#include "Cab.h"
#include "Hotel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMenuForm *MenuForm;
//---------------------------------------------------------------------------
__fastcall TMenuForm::TMenuForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMenuForm::CabBookingButtonClick(TObject *Sender)
{
				CabBookingForm->SourcePopupBox->ItemIndex = -1;
				CabBookingForm->PeoplePopupBox->ItemIndex = -1;
				CabBookingForm->CarPopupBox->ItemIndex = -1;
				CabBookingForm->DestinationPopupBox->ItemIndex = -1;
				CabBookingForm->NonACRadioButton->IsChecked = false;
				CabBookingForm->ACRadioButton->IsChecked = false;

				CabBookingForm->BillLabel->Text = "";
				CabBookingForm->StatusLabel->Text = "";
				CabBookingForm->PayButton->Visible = false;

				CabBookingForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMenuForm::HotelBookingButtonClick(TObject *Sender)
{
				HotelBookingform->CityPopupBox->ItemIndex = -1;
				HotelBookingform->HotelPopupBox->ItemIndex = -1;
				HotelBookingform->SingleRoomRadioButton->IsChecked = false;
				HotelBookingform->DoubleRoomRadioButton->IsChecked = false;
				HotelBookingform->NonACRadioButton->IsChecked = false;
				HotelBookingform->ACRadioButton->IsChecked = false;

				HotelBookingform->BillLabel->Text = "";
				HotelBookingform->StatusLabel->Text = "";
				HotelBookingform->PayButton->Visible = false;

				HotelBookingform->Show();
}
//---------------------------------------------------------------------------
