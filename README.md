# icode

There are some codes (including C/C++, Java, Python, ...) for algorithm, such as the solutions for leetcode

## For the naming rules under the leetcode folder

The .hpp file is name with the name of the question, whose spaces are replaced by '_'.<br/>
Moreover, And your username is added to the end of the file name<br/>

such as:
```
For the question "1. Two Sum"
The .hpp file is: "1_Two_Sum_username.hpp"
```

The .hpp file adds "#include "../base/icode.hpp" " in the first line.<br/>
The clase name in .hpp file is named to 'L' + the id of the question, and inherits the class "icode".<br/>
The run method is overrided in the class.<br/>

such as:
```
#include "../base/icode.hpp"

class L1 : public icode {
    ...
    void run() {
        ...
    }
};
```

The main file is [main.cpp](https://github.com/Flians/icode/main.cpp), where you can execute your solution.<br/>

## Factory mode

In the leetcode directory, create a file and name it as the problem name, such as '1. Two Sum'. <br/>

Then run script.py to change the file name.

``` bash
python .\script.py
```

Finally, run script.py to create Factory.hpp.

``` bash
python .\script.py make
```

When you wanna run a question, run icode.cpp and input the id of this question.
When you input the id <=0, the program ends.

``` bash
./build/main.exe
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
