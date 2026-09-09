//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("Login.cpp", LoginForm);
USEFORM("Main.cpp", MainForm);
USEFORM("Menu.cpp", MenuForm);
USEFORM("Registration.cpp", RegistrationForm);
USEFORM("Cab.cpp", CabBookingForm);
USEFORM("Hotel.cpp", HotelBookingform);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TRegistrationForm), &RegistrationForm);
		Application->CreateForm(__classid(TLoginForm), &LoginForm);
		Application->CreateForm(__classid(TMenuForm), &MenuForm);
		Application->CreateForm(__classid(TCabBookingForm), &CabBookingForm);
		Application->CreateForm(__classid(THotelBookingform), &HotelBookingform);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
