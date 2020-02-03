# AKTerminal
### 便捷的，面向对象的 ASCII 终端游戏引擎。
#### 1.0版 Hydrogen Proton
## 基本结构
物体（object）为游戏内的物体，需要在编程中继承并自定义。

部件（widget）为游戏界面中的部件，通过 XML 添加于界面。

屏幕（screen）为不同游戏或游戏界面，需要在编程中继承并自定义，可以通过 XML 在其上添加部件。

对话框（dialog）可以看作是一个可以叠加在界面上的界面。

参数（param）用于添加配置变量或者其他特殊变量。

通过游戏流程前定义和流程中创建，五者便能组成游戏。
## 命名规则
“ Manager ”代表单例类。

“ Param ”代表参数类。

“ Tools ”代表全局函数和其他。

如果您在文件中找不到上面的任何单词，则意味着它是普通类。
## 鸣谢
本引擎由 AKCodeDev 开发。

特别感谢项目 [SuperTuxKart](https://supertuxkart.net/)。
