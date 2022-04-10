'''
Script que adiciona ao ficheiro DIRECTORY uma nova columa chamada COLUMN
na posição POSITION com valor DEFAULT_VALUE
'''

DIRECTORY = "../data/encomendas450.txt"
COLUMN = "priority"
POSITION = 1
DEFAULT_VALUE = 0

def addColumn():

    oldData = []
    header = ""
    with open(DIRECTORY, "r") as file:

        rawData = file.readlines()
        header = rawData[0].strip()
        oldData =[  [   int(element) 
                        for element in line.strip().split(" ")  ] 
                        for line in rawData[1:]                     ]
        file.close()

    newHeader = header.split(" ")
    newHeader.insert(POSITION, COLUMN)
    newData = [" ".join(newHeader)]
    
    for element in oldData:
        element.insert(POSITION, DEFAULT_VALUE)
        newData.append(" ".join(str(number) for number in element))

    with open(DIRECTORY, "w") as file:

        file.write(newData[0] + "\n")
        for line in newData[1:]: file.write(line + "\n")
        file.close()

if __name__ == "__main__":
    addColumn()