# Travel Booking System (C++Builder / FireMonkey)

An exploratory GUI project I built in my 2nd semester while trying out UI/UX design as a 
potential specialization. It's a simple desktop app for booking a cab or a hotel room, 
built with **Embarcadero C++Builder** using the **FireMonkey (FMX)** framework.

I've since decided not to pursue UI/UX further (partly because a lot of that workflow is 
being reshaped by AI tools), but I'm sharing this to document the GUI design experience 
I gained at the time.

## What it does

- **Home screen** → choose to Login or Register
- **Registration** → saves your name, phone, username, and password to a local text file
- **Login** → checks your credentials against that file
- **Menu** (after login) → choose to book a Cab or a Hotel room
- **Cab Booking** → pick source, destination, car type, AC/Non-AC → generates a bill
- **Hotel Booking** → pick city, hotel, room type, AC/Non-AC → generates a bill

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



## Notes

- This was a learning exercise, not production software — passwords are stored in 
  plaintext and there's no input validation beyond basic empty-field checks.
- Built and tested on Windows (Win32/Win64) only.
