# KB-Style-GC-Controller
Keyboard style gamecube controller with arduino, based on [NicoHood's library](https://github.com/NicoHood/Nintendo).\
It's written for Pro micro and got rid of input lag from original library.\
# Usage
Edit "keybind" function in "src/keybind.c" in case you want to change key bind.
Keep in mind it only has about 70 micro seconds room to work in "keybind" function.
