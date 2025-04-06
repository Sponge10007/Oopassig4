本次作业使用了多文件编程。
diary.cpp和diary.h定义了个人日记的数据类型和操作，而User.cpp则负责系统交互，命令的输入和判断。

运行方式为：
在命令行中打开当前文件夹，并且使用
g++ -o diary User.cpp diary.cpp
./diary
然后就可以在命令行中进行操作

文件夹里也给出了三个样例，sample1展示了所有操作，sample2和sample3展示了一些错误操作会导致系统给出什么样的提示。