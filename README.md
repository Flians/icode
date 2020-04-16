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

The main file is icode.cpp, where you can execute your solution.<br/>
