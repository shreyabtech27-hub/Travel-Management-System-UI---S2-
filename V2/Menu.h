//---------------------------------------------------------------------------

#ifndef MenuH
#define MenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMenuForm : public TForm
{
__published:	// IDE-managed Components
	TButton *CabBookingButton;
	TButton *HotelBookingButton;
	void __fastcall CabBookingButtonClick(TObject *Sender);
	void __fastcall HotelBookingButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMenuForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMenuForm *MenuForm;
//---------------------------------------------------------------------------
#endif
