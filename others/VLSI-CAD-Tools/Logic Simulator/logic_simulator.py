import circuit_modules

#Open required file and read line by line
with open('simple_ckt.txt') as f:
    lines = f.readlines()
    
#First line specifies inputs, Second line specifies outputs
input_nodes = lines[0].split()[1:]
output_nodes = lines[1].split()[1:]

ckt_nodes = []

#Rest of the lines describe the circuit connections
for i in range(2,len(lines)):
	ckt_nodes.append(lines[i].split())

#Take user inputs for the inputs of the circuit	and store in input vector
input_vector = ''
for i in range(len(input_nodes)):
    x = input("Enter input " + str(i) + " : ")
    input_vector = input_vector + x

#Call ckt function from circuit modules, assign the result to output vector
output_vector = circuit_modules.ckt(input_nodes, input_vector, ckt_nodes, output_nodes)

#Display the outputs
print()
print("Outputs are: ")
for i in range(len(output_nodes)):
    print(output_vector[i])

