Vinctus-Arce
============
![Image of main menu](http://i.imgur.com/ToycrWi.jpg)

Vinctus-Arce is a RPG-Survival game placed in a fantasy world, and more precisely in a deep dungeon.

**The development has been put on hold until further notice.**

## Building

### CMake
Requires CMake 3.14+. 
To obtain it, either:
- download it from official distributor [here](https://cmake.org/download/)
- install it using pip `pip install cmake` or `pip install --user cmake` if you don't have root privilages
- build and install from [sources](https://github.com/Kitware/CMake)

To build and install Vinctus Arce, run in root project folder following commands:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
Vinctus Arce will then be built and installed to `PROJECT_ROOT/bin` directory and should be ready to be played.

#### Note for Windows users:
When running `cmake ..` command for generating build files, and you want to use MSVC to compile Vinctus Arce, 
you first have to run vcvarsall.bat ([see where to find it](https://social.msdn.microsoft.com/Forums/en-US/1071be0e-2a46-4c30-9546-ea9d7c4755fa/where-is-vcvarsallbat-file?forum=visualstudiogeneral)) in the shell you'll use and then choose one of the following generators using -G switch.
```bash
cmake -G"Visual Studio <VERSION> <RELEASE YEAR>" ..
cmake -G"NMake Makefiles" ..
cmake -G"NMake Makefiles JOM" .. // if you have jom build system installed
```
`"Visual Studio <VERSION> <RELEASE YEAR>"` can be for example `"Visual Studio 16 2019"`. To find out all generators available, type `cmake --help`.

[Find out more on Vinctus Arce wikia!](https://github.com/ArrowganceStudios/Vinctus-Arce/wiki)
