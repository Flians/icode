# icode

There are some codes (including C/C++, Java, Python, ...) for algorithm, such as the solutions for leetcode

## For the naming rules under the leetcode folder

The .h file is name with the name of the question, whose spaces are replaced by '_'.<br/>
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
