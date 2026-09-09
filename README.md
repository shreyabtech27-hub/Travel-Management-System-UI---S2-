# Travel Booking System (C++Builder / FireMonkey)

An exploratory GUI project I built in my 2nd semester while trying out UI/UX design as a 
potential specialization. It's a simple desktop app for booking a cab or a hotel room, 
built with **Embarcadero C++Builder** using the **FireMonkey (FMX)** framework.

I've since decided not to pursue UI/UX further (partly because a lot of that workflow is 
being reshaped by AI tools), but I'm sharing this to document the GUI design experience 
I gained at the time.

## What it does

A 6-screen desktop app: Home → Login/Registration → Menu → Cab Booking / Hotel Booking.

- **Registration & Login** — registration validates all 4 required fields before 
  writing a record to a local file; login checks credentials against that file and 
  gives distinct feedback for each outcome (invalid username / wrong password / success).
  
- **Cab Booking** — validates 5 required fields individually (each with its own 
  error message), enforces a passenger-capacity rule for the EV option, and computes 
  the fare with conditional surcharges (AC, EV, and Innova each apply a different 
  markup) by looking up the base rate from a fares file.
  
- **Hotel Booking** — validates 4 required fields, then matches the selected 
  city + hotel + room type + AC/Non-AC combination against a rates file to pull the 
  exact price, and displays a GST-inclusive total.

- **Payment** is simulated — clicking "Pay" confirms the booking with a success message, 
  but no real payment gateway is integrated. Tax/surcharge calculations are illustrative 
  (fixed percentages for demonstration) rather than based on actual tax rules.
  
- **Menu** — resets all fields on both booking forms every time they're reopened, 
  so no stale data carries over from a previous booking.

Data (user records and booking rates) is stored in local `.txt` files rather than a 
real database. This project was about learning form design, multi-screen navigation, 
input validation, and event-driven logic in C++Builder — not backend architecture.

There's no real database — user records and bookings are stored in plain `.txt` files 
in the app folder. This was purely about learning form design, navigation between 
windows, and basic event handling, not backend architecture or security.

## Project structure

- `Cabbooking.cbproj` — the project file to open in the IDE
- `Cabbooking.cpp` — application entry point
- `Main`, `Login`, `Registration`, `Menu`, `Cab`, `Hotel` — the six screens (`.cpp` / `.h` / `.fmx` each)

## How to see it

This isn't a portable app — it needs Embarcadero's IDE to open and build:

1. Download **[C++Builder Community Edition](https://www.embarcadero.com/products/cbuilder/starter)** (free for individuals / small teams)
2. Open `Cabbooking.cbproj`
3. Build (**Ctrl+F9**) and Run (**F9**)

If you'd rather not install anything, check the screenshots/demo video below to see 
the app in action.

## Demo

<img width="1366" height="721" alt="Screenshot 2024-05-13 220653" src="https://github.com/user-attachments/assets/7aa13280-17c9-4767-adcd-e5455b828c6e" />

https://github.com/user-attachments/assets/1a4bacc8-0528-4369-a5c8-d983abb8bedf

## Notes

- Data is stored in local `.txt` files rather than a real database or hashed 
  credentials — fine for a learning project, not meant for production use.
- Built and tested on Windows (Win32/Win64) only.

## Versions

This repo has two folders reflecting how the project evolved:

- **`v1/`** — the initial exploratory build. Basic Login/Registration/Home screens, 
  mostly static UI with minimal working logic (a rough first pass at the forms).
- **`v2/`** — the completed, working version. This is the one described above and 
  shown in the demo — full Login → Menu → Cab/Hotel booking flow with file-based 
  data storage.

If you just want to see the finished project, go straight to **`v2/`**.
