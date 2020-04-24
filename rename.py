import os
import re

root = './leetcode'

files = os.listdir(root)


def replace_name(name):
    if name.find(' ') != -1:
        name = '_'.join(list(filter(None,re.split('[ .]', name))))
    name=name+'.h'
    return name


for i, file in enumerate(files):
    OldName=os.path.join(root, file)
    if file.endswith('.cpp'):
        pass
    elif file.endswith('.h'):
        file=replace_name(file[0:-2])
    else:
        file=replace_name(file)
    NewName=os.path.join(root, file)
    os.rename(OldName, NewName)
