## TreeOneLanguage

### 定义变量

使用一下关键字定义一个变量（不要问我为什么不用 var，awa）

- int

- itn

- tin

- tni

- nit

- nti

关键字后面可以跟上一些指令

- 赋值，等号 + 变量值

- 未赋值，变量值为 NaN

例子
``` cpp
itn a = 1145
int b = 1919
nit c
# c 为 NaN

```

### 打印变量

使用 print 关键字。

后面跟上目标变量名，若未存在此变量，则输出一个报错信息，未找到该变量。

或者使用双引号，输出一个字符串

### 赋值

使用 equ 或者 = 关键字。

- equ <varname1 : str> <varname2 : str> 将 varname2 的变量值 赋值到 varname1

- = <varname : str> <num : str> 将 num 直接赋值到 varname1

### 四则运算

目前仅实现非负整数域的 加 和 减

加上或减去变量：

- pls/sbt <varname1 : str> <varname2 : str> 将 varname1 的值减去 varname2; 

加上或减去常数：

- pls/sbt <varname1 : str> <num : str> 将 varname1 的值减去 num; 

### 注释

注释必须独立一行，否则程序运行错误且无错误信息。

注释内不能含有关键字

例子

``` cpp

print a
# print a
# 此时会有两个 a 值

```