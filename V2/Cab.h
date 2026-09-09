//---------------------------------------------------------------------------

#ifndef CabH
#define CabH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ExtCtrls.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TCabBookingForm : public TForm
{
__published:	// IDE-managed Components
	TPopupBox *DestinationPopupBox;
	TLabel *DestinationLabel;
	TPopupBox *PeoplePopupBox;
	TLabel *PeopleLabel;
	TPopupBox *CarPopupBox;
	TLabel *CarLabel;
	TGroupBox *ACnonACGroupBox;
	TRadioButton *ACRadioButton;
	TRadioButton *NonACRadioButton;
	TButton *SaveButton;
	TButton *ClearButton;
	TLabel *ErrorLabel;
	TLabel *BillLabel;
	TButton *PayButton;
	TLabel *StatusLabel;
	TPopupBox *SourcePopupBox;
	TLabel *SourceLabel;
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall ClearButtonClick(TObject *Sender);
	void __fastcall PayButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCabBookingForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCabBookingForm *CabBookingForm;
//---------------------------------------------------------------------------
#endif
