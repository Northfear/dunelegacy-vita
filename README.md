# Dune Legacy port for PS Vita

## Install

1. Download and install dunelegacy.vpk. Extract content of dunelegacy_data.zip into `ux0:data/`.

https://github.com/Northfear/dunelegacy-vita/releases

2. The following PAK-files from the original Dune 2 are needed to play Dune Legacy:
HARK.PAK
ATRE.PAK
ORDOS.PAK
ENGLISH.PAK
DUNE.PAK
SCENARIO.PAK
MENTAT.PAK
VOC.PAK
MERC.PAK
FINALE.PAK
INTRO.PAK
INTROVOC.PAK
SOUND.PAK
GERMAN.PAK (for playing in German)
FRENCH.PAK (for playing in French)

Copy them into `ux0:data/dunelegacy` folder.

## Building

### Prerequisites
- VitaSDK
- SDL2
- SDL2-mixer

### Build
```
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake -DVITA=true
make
```

## Port info

### Controls

- Left analog stick - Cursor movement
- Right analog stick - Map scrolling
- × - Left mouse button
- ○ - Right mouse button
- □ - Attack
- △ - Stop (Guard)
- D-Pad Up/Right/Down/Left - 1/2/3/4 button
- L1 - Ctrl
- R1 - Shift (also used for cursor movement speedup)
- SELECT - Esc
- START - Space

Use L1 + D-Pad to create teams (1-4) and D-Pad to select them (same as Ctrl + 1-4 on keyboard).

You can change cursor movement speed by editing `ux0:data/dunelegacy/Dune Legacy.ini` and changing the `Controller Speed` option.

### Additional info

Multiplayer is not supported on PS Vita.

Vita port is currently having a critical bug and can crash/freeze the game sometimes while selecting units (Or more like during deselection, while some other unit/building is selected. Side UI panel with unit info is probably causing this somehow). GXM fails to start the scene because something goes wrong with rendertarget (`SCE libdbg LOG, LEVEL: error, COMPONENT: SceGxmDbg, FILE:context.c, LINE:1507 [SceGxmDbg]:Failed due to error in driver layer (00000096).`).

/-------------------------------\
| |
| Dune Legacy 0.96 readme |
| ----------------------- |
| |
\-------------------------------/


IMPORTANT:
This software is provided as is, and you are running it at your own risk. I'm not responsible if any harm results
from you aquiring, or running this software. If you distribute this software, make sure this readme file is included.
The program Dune Legacy is an modernized clone of the excellent Westwood Studios game "Dune 2". It is ridiculusly easy to find
Dune2 on the net anyways, but I won't provide it. I think you can still even buy it from Westwood studios, so do that.
There exists a mod called Superdune 2. The PAK-Files Superdune 2 provides are nearly the same except SCENARIO.PAK.
This program would not have been created without the use of the excellent SDL library and its extensions. Thanks guys :).


Getting Started
---------------

The following PAK-files from the original Dune 2 are needed to play Dune Legacy:
HARK.PAK
ATRE.PAK
ORDOS.PAK
ENGLISH.PAK
DUNE.PAK
SCENARIO.PAK
MENTAT.PAK
VOC.PAK
MERC.PAK
FINALE.PAK
INTRO.PAK
INTROVOC.PAK
SOUND.PAK
GERMAN.PAK (for playing in German)
FRENCH.PAK (for playing in French)

It depends on your system and installation where to put these files. LEGACY.PAK is supplied with Dune Legacy and is already
in the data directory. All the other files should be copied there too. If you are not allowed to copy files there you may
copy these files inside the dunelegacy configuration directory (e.g. ~/.config/dunelegacy/data/ on unix).

Linux:
It depends on how the game was compiled. Normally you should put these files under /usr/share/dunelegacy/ or /usr/local/share/dunelegacy/ .
Just look for LEGACY.PAK. If you do not have root access to your system you should put them in your home directory under ~/.config/dunelegacy/data/ .

Windows:
The installer has already asked for the files and put them in the installation directory. If not put the PAK-files inside your installation folder or
if you do not have administrator privileges you should put them to C:\Documents and Settings\<YourName>\Application Data\dunelegacy\data\ .


MAC OS X:
The PAK-files have to be copied inside the application bundle. If you have followed the steps in the supplied dmg you have already copied them there.
Otherwise just right-click on the bundle and select "Show Bundle Content". Then navigate into "Contents" and then into "Resources". There you will
find LEGACY.PAK. Put the other PAK-files there too. Alternativly you can put them in your home directory under ~/.config/dunelegacy/data/ but putting
them inside the application bundle is the preferred way.



Keyboard Shortcuts
------------------

General Keyboard Shortcuts:
Escape - Go to menu
Space - Pause game
Alt + Enter - Toggle fullscreen
Alt + Tab - Switch to other application
Print Key or Ctrl + P - Save screenshot as ScreenshotX.bmp with increasing numbers for X
Enter - Start/Stop chatting

Key F1 - Zoomlevel x1
Key F2 - Zoomlevel x2
Key F3 - Zoomlevel x3

Key T - Toggle display of current game time
Key F10 - Toggle sound effects and voice
Key F11 - Toggle music
Key F12 - Toggle display of FPS
Key Up, Down, Left or Right - Move on the map

Key G - Cycle through construction yards
Key F - Cycle through factories/other builders

Key F4 - Skip 10 seconds (only in singleplayer)
Key F5 - Skip 30 seconds (only in singleplayer)
Key F6 - Skip 2 minutes (only in singleplayer)
Key - - Decrease gamespeed (only in singleplayer)
Key + - Increase gamespeed (only in singleplayer)

Ctrl + (Key 1 to Key 9) - Save the list of selected units as unit group 1 to 9
Key 1 to Key 9 - Select units from unit group 1 to 9
Shift + (Key 1 to Key 9) - Add all units from unit group 1 to 9 to the list of currently selected units
Key 0 - Deselect all currently selected units
Ctrl + Key 0 - Remove currently selected units form all unit groups (group 1-9)

Key M - Order unit to move to some position
Key A - Order selected units to attack some unit, structure or position
Key C - Order selected infantry units to capture some structure
Key R - Repair selected structure or send selected units to repair yard
Key H - Return selected harvester
Key D - Request a carryall drop (only if this game option is enabled)
Key U - Upgrade selected structure
Key P - Place a structure (if a construction yard is selected)

Map Editor:
Print Key or Ctrl + P - Save a picture of the whole map as <Mapname>.bmp
Ctrl + Z - Undo last edit
Ctrl + Y - Redo last edit



Configuration file
------------------

If you want to fine tune the configuration of Dune Legacy you might want to take a look at the configuration file "Dune Legacy.ini". Depending on your system it
is either placed in ~/.config/dunelegacy (on Linux), ~/Library/Application Support/Dune Legacy (on Mac OS X) or in C:\Documents and Settings\<YourName>\Application Data\dunelegacy\ (on Windows).


Internet Game
-------------

To play online via Internet you have to manually enable port forwarding if you use a NAT Router. Forward the Dune Legacy Server Port (Default is 28747) from your NAT Router to your computer. Use the same port on your router as configured in Dune Legacy.
Example: If your machine has IP 192.168.123.1 and your using the default Dune Legacy Port, than forward port 28747 from your router to 192.168.123.1:28747.


--------------------------------------------------------------
IRC: #dunelegacy @ irc.freenode.net
Web: http://sourceforge.net/projects/dunelegacy


