import numpy as np
import pandas as pd
import random

def encoding(x):
    x = str(x)
    if (x == '0'):
        y,z = 1,0
    elif (x == '1'):
        y,z = 0,1
    elif (x == 'x'):
        y,z = 1,1
    else:
        y,z = 0,0
    return y,z

def calc_weights(theset):
    theset_trps = np.array(theset).T
    #print("Input to calc_weights:", theset)
    #print("Input to calc_weights transposed:",theset_trps)
    colsums = []
    for i in range(len(theset_trps)):
        for j in range(len(theset_trps[i])):
            colsums.append(sum(theset_trps[i][j]))

    colsums = np.array(colsums)

    theset_mod = []
    weights = []
    for i in range(len(theset)):
        theset_mod.append([])
        for j in range(len(theset[i])):
            theset_mod[i] = theset_mod[i] + list(theset[i][j])

    for i in range(len(theset)):
        weights.append(np.dot(colsums,np.array(theset_mod[i])))
    #print(weights)
    return weights

def intersection(cube1, cube2):
    inter = []
    for i in range(len(cube1)):
        inter.append([])
        if (cube1[i] == (0,0) and cube2[i] == (0,0)):
            inter[i] = (0,0)
        elif (cube1[i] == (0,1) and cube2[i] == (0,0)):
            inter[i] = (0,0)
        elif (cube1[i] == (1,0) and cube2[i] == (0,0)):
            inter[i] = (0,0)
        elif (cube1[i] == (1,1) and cube2[i] == (0,0)):
            inter[i] = (0,0)
        elif (cube1[i] == (0,0) and cube2[i] == (0,1)):
            inter[i] = (0,0)
        elif (cube1[i] == (0,1) and cube2[i] == (0,1)):
            inter[i] = (0,1)
        elif (cube1[i] == (1,0) and cube2[i] == (0,1)):
            inter[i] = (0,0)
        elif (cube1[i] == (1,1) and cube2[i] == (0,1)):
            inter[i] = (0,1)
        elif (cube1[i] == (0,0) and cube2[i] == (1,0)):
            inter[i] = (0,0)
        elif (cube1[i] == (0,1) and cube2[i] == (1,0)):
            inter[i] = (0,0)
        elif (cube1[i] == (1,0) and cube2[i] == (1,0)):
            inter[i] = (1,0)
        elif (cube1[i] == (1,1) and cube2[i] == (1,0)):
            inter[i] = (1,0)
        elif (cube1[i] == (0,0) and cube2[i] == (1,1)):
            inter[i] = (0,0)
        elif (cube1[i] == (0,1) and cube2[i] == (1,1)):
            inter[i] = (0,1)
        elif (cube1[i] == (1,0) and cube2[i] == (1,1)):
            inter[i] = (1,0)
        else:
            inter[i] = (1,1)
    return inter

def supercube(cube1, cube2):
    inter = []
    for i in range(len(cube1)):
        inter.append([])
        if (cube1[i] == (0,0) and cube2[i] == (0,0)):
            inter[i] = (0,0)
        elif (cube1[i] == (0,1) and cube2[i] == (0,0)):
            inter[i] = (0,1)
        elif (cube1[i] == (1,0) and cube2[i] == (0,0)):
            inter[i] = (1,0)
        elif (cube1[i] == (1,1) and cube2[i] == (0,0)):
            inter[i] = (1,1)
        elif (cube1[i] == (0,0) and cube2[i] == (0,1)):
            inter[i] = (0,1)
        elif (cube1[i] == (0,1) and cube2[i] == (0,1)):
            inter[i] = (0,1)
        elif (cube1[i] == (1,0) and cube2[i] == (0,1)):
            inter[i] = (1,1)
        elif (cube1[i] == (1,1) and cube2[i] == (0,1)):
            inter[i] = (1,1)
        elif (cube1[i] == (0,0) and cube2[i] == (1,0)):
            inter[i] = (1,0)
        elif (cube1[i] == (0,1) and cube2[i] == (1,0)):
            inter[i] = (1,1)
        elif (cube1[i] == (1,0) and cube2[i] == (1,0)):
            inter[i] = (1,0)
        elif (cube1[i] == (1,1) and cube2[i] == (1,0)):
            inter[i] = (1,1)
        elif (cube1[i] == (0,0) and cube2[i] == (1,1)):
            inter[i] = (1,1)
        elif (cube1[i] == (0,1) and cube2[i] == (1,1)):
            inter[i] = (1,1)
        elif (cube1[i] == (1,0) and cube2[i] == (1,1)):
            inter[i] = (1,1)
        else:
            inter[i] = (1,1)
    return inter

def complement(theset):
    compset = []
    for i in theset:
        if i == (0,0):
            noti = (1,1)
        elif i == (0,1):
            noti = (1,0)
        elif i == (1,0):
            noti = (0,1)
        else:
            noti = (0,0)
        compset.append(noti)
    return compset

def expand(onset, choice):
    no_intersect_count=0
    inter=[]
    for i in range(len(onset[choice])):
        memory = onset[choice][i]
        onset[choice][i] = (1,1)
        inter.clear()
        no_intersect_count=0
        for j in range(len(offset)):
            inter.append(intersection(onset[choice], offset[j]))
            if((0,0) in inter[j]):
                no_intersect_count = no_intersect_count + 1
        if (no_intersect_count == len(offset)):
            useless = 0
            #print("Valid expansion!")
        else:
            #print("Invalid expansion...")
            onset[choice][i] = memory 
        #print("inter in expansion",inter)
        #print("count ", no_intersect_count)
    return onset

def irredundant(onset, choice):
    inter = []
    ttlgychk = []
    all_ones = []
    removed_stuff = []
    for i in range(len(onset)):
        if (i != choice):
            inter.append(intersection(onset[choice], onset[i]))
        else:
            inter.append("Dummy value")
    for i in range(len(onset)):
        if (i != choice):
            ttlgychk.append(supercube(complement(onset[i]), inter[i]))
        else:
            ttlgychk.append("Dummy value")

    nvar = len(onset[0])    
    all_ones = [(1,1) for i in range(nvar)]

    #print("Intersection:", inter)
    #print("Tautology check:", ttlgychk)
    #print("All ones", all_ones)

    for i in range(len(onset)):
        if (i != choice):
            if (ttlgychk[i] == all_ones):
                #print("There is redundancy, remove minterm",i)
                removed_stuff.append(onset[i])
            else:
                useless = 0
                #print("No redundancy here...")
    for i in removed_stuff:
        onset.remove(i)
    return onset

def reduce(onset, choice, counter):
    num = counter // 50
    count=0
    onset_inter=[]
    for i in range(len(onset[choice]) - num):
        if (onset[choice][i] == (1,1)):
            count=count+1
            onset[choice][i]=(0,1)
            new_term=onset[choice].copy()
            new_term[i]=(1,0)
            if(count>1):
                 for j in range(count-1):
                    onset_inter[j][i]=(0,1)
                 for j in range(count-1):
                    new_term1= onset_inter[j].copy()
                    new_term1[i]=(1,0)
                    onset_inter.append(new_term1)

            onset_inter.append(new_term)
            #print(onset_inter)

    if (len(onset_inter) != 0):
        for i in range(len(onset_inter)):        
            onset.append(onset_inter[i])
    return onset

def calc_cost(onset):
    cost = len(onset)
    max = 0
    for i in range(len(onset)):
        sum = 0
        for j in range(len(onset[i])):
            if onset[i][j] != (1,1):
                sum = sum + 1
        if (sum > max):
            max = sum      
    return cost + max

tt = pd.read_csv("logic.csv")

length = len(tt['f'])
width = int(np.log2(length))
max_count = int(width * 50)
tau = int(input("Enter target cost:"))

mat = []
for i in range(length):
    mat.append([])
    for j in range(width + 1):
        mat[i].append('00')

for i in range(length):
    for j in range(width):
        mat[i][j] = encoding(tt['x'+str(width-j-1)][i])
    mat[i][width] = tt['f'][i]

onset, offset, dcset = [], [], []
for i in range(length):
    if mat[i][-1] == '0':
        offset.append(mat[i][0:-1])
    elif mat[i][-1] == '1':
        onset.append(mat[i][0:-1])
    else:
        dcset.append(mat[i][0:-1])

#Expansion process
#print("Round 0")
weights = calc_weights(onset)
choice_exp = weights.index(min(weights))
#print("Expand the minterm of index", choice_exp , "in the on-set")
#print("onset before expansion",onset)
onset = expand(onset, choice_exp)
#print("Final onset after expansion-", onset)

#Irredundancy process
onset = irredundant(onset, choice_exp)
#print("Final onset after irredundacny-", onset)

#Cost calculation
cost = calc_cost(onset)
#print("Cost = ", cost)

count = 0
prev_cost = cost
sol_set = onset
prev_weights = weights

while (cost > tau and count < max_count):
    #print()
    #print("Round",(count+1))

    #Reduction process
    red_weights = calc_weights(onset)
    choice_red = red_weights.index(max(red_weights))
    #print("Reduce the minterm of index", choice_red , "in the on-set")
    onset = reduce(onset, choice_red, count)
    #print("Final onset after reduction-", onset)

    exp_weights = calc_weights(onset)
    #print("Current weights", exp_weights)
    #print("Previous weights", prev_weights)
    if (exp_weights == prev_weights):   
        choice_exp = random.choice([k for k in range(len(onset))])
    else:
        choice_exp = exp_weights.index(min(exp_weights))

    prev_weights = exp_weights
    
    #print("Expand the minterm of index", choice_exp , "in the on-set")
    #print("onset before expansion",onset)
    onset = expand(onset, choice_exp)
    #print("Final onset after expansion-", onset)

    #Irredundancy process
    onset = irredundant(onset, choice_exp)
    #print("Final onset after irredundacny-", onset)

    #Cost calculation
    cost = calc_cost(onset)
    #print("Cost = ", cost)

    if (cost < prev_cost):
        prev_cost = cost
        #print("Better solution found!")
        sol_set = onset

    count = count + 1

#print("Final solution:", sol_set)

sol_str = ''
for i in sol_set:
    count = 0
    sol_str = sol_str + '('
    another_count = 0
    for j in i:
        if (j == (0, 1)):
            another_count = another_count + 1
            if (another_count > 1):
                sol_str = sol_str + ' AND '
            sol_str = sol_str + "x["+str(count)+"]"
        elif (j == (1, 0)):
            another_count = another_count + 1
            if (another_count > 1):
                sol_str = sol_str + ' AND '
            sol_str = sol_str + "(NOT x["+str(count)+"])"
        count = count + 1    
    sol_str = sol_str + ') OR '
sol_str = sol_str[:-3]

print("Minimized Expression:")
print("f =", sol_str)
print("Final cost:", prev_cost)
