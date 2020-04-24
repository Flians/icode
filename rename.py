import os
import re

root_path = './leetcode'


def makeInclude(root_path):
    files = os.listdir(root_path)
    files = [x for x in files if x[0].isdigit()]
    files.sort(key=lambda x: int(x.split('_')[0]))
    for file in files:
        print('#include "../leetcode/'+file+'"')
    for file in files:
        id = file.split('_')[0]
        print('case ' + id + ':return new L' + id + ';')


def rename(root_path):
    def replace_name(name):
        if name.find(' ') != -1:
            name = '_'.join(list(filter(None, re.split('[ .]', name))))
        name = name+'.h'
        return name

    files = os.listdir(root_path)
    for i, file in enumerate(files):
        OldName = os.path.join(root_path, file)
        if file.endswith('.cpp'):
            pass
        elif file.endswith('.h'):
            file = replace_name(file[0:-2])
        else:
            file = replace_name(file)
        NewName = os.path.join(root_path, file)
        os.rename(OldName, NewName)


rename(root_path)
# makeInclude(root_path)
