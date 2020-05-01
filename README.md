# icode

There are some codes (including C/C++, Java, Python, ...) for algorithm, such as the solutions for leetcode

## For the naming rules under the leetcode folder

The .h file is name with the name of the question, whose spaces are replaced by '_'.<br/>
Moreover, And your username is added to the end of the file name<br/>

such as:
```
For the question "1. Two Sum"
The .h file is: "1_Two_Sum_username.h"
```

The .h file adds "#include "../base/icode.h" " in the first line.<br/>
The clase name in .h file is named to 'L' + the id of the question, and inherits the class "icode".<br/>
The run method is overrided in the class.<br/>

such as:
```
#include "../base/icode.h"

class L1 : public icode {
    ...
    void run() {
        ...
    }
};
```

The main file is [icode.cpp](https://github.com/Flians/icode/icode.cpp), where you can execute your solution.<br/>

## Factory mode

In the leetcode directory, create a file and name it as the problem name, such as '1. Two Sum'. <br/>

Then run script.py to change the file name.

``` bash
python .\rename.py
```

Finally, run script.py to create Factory.h.

``` bash
python .\rename.py make
```

When you wanna run a question, run icode.cpp and input the id of this question.
When you input the id <=0, the program ends.

``` bash
./build/icode.exe
78

1
2
1 2
3
1 3
2 3
1 2 3

-1
This question is not existed!
```
