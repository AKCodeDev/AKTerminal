# AKTerminal
### Object-oriented ASCII game engine. 
#### Version 1.0 "Hydrogen Proton"
#### Other languages [`中文`](/README-cn.md)。
## Basic Structure
#### Three main parts
##### Object
Object is for things in the game. It should be inherited and defined in your code. Its image is called "Sprite".
##### Widget
Widget is for things in the interface. It can be added by XML in screen.
##### Screen
Screen is for switching different faces between different games or GUI parts.
#### Other parts
##### Clock
Timer for game.
##### Dialog
Dialog can be considered as a screen, which can be added like an object above screens.
##### Path
Path can define a route for objects and dialogs to move along.
##### Parameters
The parameters are for configs or other special variables.

By defining these classes before main and creating them in main, it can form a game.

## Naming Rules
"Manager" stands for singleton classes.

"Param" stands for parameter classes.

"Tools" stands for global function sets.

If you can't find any words above in a file, it means it's an normal class.

## AKML
AKML is a kind of markup language for defining images and sprites.

It's grammar is like this:

```akml
[AKML version]
a   [label name]
    [its content]
    [another part of its content]
    [yet another part of its content]
a   [another label name]
...

```

Between each content line there is a line break added.

## Credits
Developing by AKCodeDev.

XML parser by Lee Thomason [TinyXML2](https://github.com/leethomason/tinyxml2).

Especially thanks to project [SuperTuxKart](https://supertuxkart.net/).
