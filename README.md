# AKTerminal
### Object-oriented, convenient ASCII terminal game engine by AKCodeDev. 
#### Version 1.0 "Hydrogen Proton"
#### Other languages [`中文`](/README-cn.md)。
## Basic Structure
Object is for things in the game. It should be inherited and defined in your code.

Widget is for things in the interface. It can be added by XML in screen.

Screen is for switching different faces between different games or GUI parts.

Dialog can be considered as a screen, which can be added above screens.

The params are for configs or other special variables.

By defining these classes before main and creating them in main, it can form a game.
## Naming Rules
"Manager" stands for singleton classes.

"Param" stands for parameter classes.

"Tools" stands for function sets and misc things.

If you can't find any words above in a file, it means it's an normal class.
## Credits
Developing by AKCodeDev.

XML parser by Lee Thomason [TinyXML2](https://github.com/leethomason/tinyxml2).

Especially thanks to project [SuperTuxKart](https://supertuxkart.net/).
