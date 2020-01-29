# AKTerminal
### Object-oriented, convenient ASCII terminal game engine by AKCodeDev. 
#### Version 1.0 "Hydrogen Proton"
#### 亲爱的中国同胞，请到这里：[中文](https://github.com/AKCodeDev/AKTerminal/blob/master/README-cn.md)。
## Basic Structure
The engine is designed to be object-oriented.

The main three part is: object, widget, screen.

Object is for things in the game.

Widget is for things in the menu or other GUI parts.

Screen is for switching different faces between different games or GUI parts.

Widgets are above; then objects; screens are underneath.

Dialog can be seen as a widget, but it's a little different because it's defined like screens.

There are other misc things in the engine.

The params are for configs or other special variables.

IO, tools are mainly for core engine.

Managers in "others" folder are useful utils.
## Naming Rules
"Manager" stands for singleton classes.

"Param" stands for parameter classes.

"Tools" stands for function sets and misc things.

If you can't find any words above in a file, it means it's an normal class.
## Credits
Developing by CodingJellyfish.

Especially thanks to project [SuperTuxKart](https://supertuxkart.net/).
