//---------------------------------------------------------------------------

#ifndef RegistrationH
#define RegistrationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Menus.hpp>
#include <FMX.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TRegistrationForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *NameEdit;
	TEdit *ContactEdit;
	TEdit *UsernameEdit;
	TEdit *PasswordEdit;
	TButton *SaveButton;
	TLabel *ErrorLabel;
	void __fastcall SaveButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TRegistrationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRegistrationForm *RegistrationForm;
//---------------------------------------------------------------------------
#endif
