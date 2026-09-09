//---------------------------------------------------------------------------

#ifndef HotelH
#define HotelH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ExtCtrls.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------
class THotelBookingform : public TForm
{
__published:	// IDE-managed Components
	TLabel *CityLabel;
	TPopupBox *CityPopupBox;
	TGroupBox *RoomGroupBox;
	TRadioButton *SingleRoomRadioButton;
	TRadioButton *DoubleRoomRadioButton;
	TLabel *HotelLabel;
	TGroupBox *ACnonACGroupBox;
	TRadioButton *ACRadioButton;
	TRadioButton *NonACRadioButton;
	TPopupBox *HotelPopupBox;
	TButton *PayButton;
	TLabel *StatusLabel;
	TButton *SaveButton;
	TButton *ClearButton;
	TLabel *BillLabel;
	TLabel *ErrorLabel;
	void __fastcall SavebuttonClick(TObject *Sender);
	void __fastcall PayButtonClick(TObject *Sender);
	void __fastcall ClearButtonClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall THotelBookingform(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THotelBookingform *HotelBookingform;
//---------------------------------------------------------------------------
#endif
