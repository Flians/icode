import os
import re
import sys

root_path = './leetcode'
factory_path = './base/Factory.h'

def makeFactory(root_path, factory_path):
    files = os.listdir(root_path)
    files = [x for x in files if x[0].isdigit()]
    files.sort(key=lambda x: int(x.split('_')[0]))
    with open(factory_path, 'w', encoding='utf8') as fp:
        fp.write('#include "icode.h"\n')
        for file in files:
            fp.write('#include "../leetcode/'+file+'"\n')
        fp.write('class Factory\n{\npublic:\n\ticode *problem(int i)\n\t{\n\t\tswitch (i)\n\t\t{\n')
        for file in files:
            id = file.split('_')[0]
            cn = 'L'+id
            if id=='146':
                cn = 'LRUCache'
            elif id=='155':
                cn = 'MinStack'
            fp.write('\t\tcase ' + id + ':\n\t\t\treturn new ' + cn + ';\n')
        fp.write('\t\tdefault:\n\t\t\tcout << "This question is not existed!" << endl;\n\t\t\texit(-1);\n\t\t\tbreak;\n\t\t}\n\t}\n};')

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


if __name__ == "__main__":
    if len(sys.argv) >= 2 and sys.argv[1] == 'make':
        makeFactory(root_path, factory_path)
    else:
        rename(root_path)