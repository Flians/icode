import os
import re
import sys

root_path = './leetcode'
factory_path = './base/Factory.hpp'


def makeFactory(root_path, factory_path):
    files = os.listdir(root_path)
    files = [x for x in files if x[0].isdigit()]
    files.sort(key=lambda x: int(x.split('_')[0]))
    with open(factory_path, 'w', encoding='utf8') as fp:
        fp.write('#include "icode.hpp"\n')
        for file in files:
            fp.write('#include "../leetcode/'+file+'"\n')
        fp.write(
            'class Factory\n{\npublic:\n\ticode *problem(int i)\n\t{\n\t\tswitch (i)\n\t\t{\n')
        for file in files:
            id = file.split('_')[0]
            cn = 'L'+id
            if id == '146':
                cn = 'LRUCache'
            elif id == '155':
                cn = 'MinStack'
            elif id == '208':
                cn = 'Trie'
            elif id == '901':
                cn = 'StockSpanner'
            fp.write('\t\tcase ' + id + ':\n\t\t\treturn new ' + cn + ';\n')
        fp.write('\t\tdefault:\n\t\t\tcout << "This question is not existed!" << endl;\n\t\t\texit(-1);\n\t\t\tbreak;\n\t\t}\n\t}\n};')


def rename(root_path):
    def replace_name(name, autoVS=False):
        flag = False
        if name.find(' ') != -1 or autoVS:
            flag = True
            name = '_'.join(list(filter(None, re.split('[ .-]', name))))
        name = name+'.hpp'
        return name, flag

    files = os.listdir(root_path)
    for i, file in enumerate(files):
        OldName = os.path.join(root_path, file)
        flag = False
        idNumber = -1
        if file.endswith('.cpp'):
            matchObj = re.match(r'^\d+\.[\w-]+\.cpp$', file)
            if matchObj:
                file, flag = replace_name(file[0:-4], True)
            pass
        elif file.endswith('.hpp'):
            file, flag = replace_name(file[0:-4])
            idNumber = re.split('[._]', file)[0]
        else:
            file, flag = replace_name(file)
        temp = re.split('[._]', file)[0].strip()
        if temp.isdigit():
            idNumber = int(temp)
        NewName = os.path.join(root_path, file)
        os.rename(OldName, NewName)
        if flag:
            with open(NewName, 'r+', encoding='utf8') as f:
                content = f.readlines()
                f.seek(0, 0)
                if idNumber != -1:
                    for i in range(len(content)):
                        matchObj = re.match(r'^class Solution$', content[i].strip())
                        if matchObj:
                            content[i] = 'class L' + str(idNumber) + ' : public icode\n'
                        else:
                            matchObj = re.match(r'^public:$', content[i].strip())
                            if matchObj:
                                content[i] = content[i] + '\tvoid run() {}\n\n'
                                break
                content.insert(0, '#include "../base/icode.hpp"\n')
                f.writelines(content)


if __name__ == "__main__":
    if len(sys.argv) >= 2 and sys.argv[1] == 'make':
        makeFactory(root_path, factory_path)
    else:
        rename(root_path)
