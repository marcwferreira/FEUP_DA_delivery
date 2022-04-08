from random import randint as rd
from string import ascii_uppercase
from math import ceil, floor, round

'''
Script que gera N novas packages de acordo com os limites do dataset original
Coloca o resultado na pasta ./data, em formato "encomendas<N>.txt"
Garante que EXPRESS_PERCENTAGE % de todas as encomendas geradas são expresso
'''

ORIGINAL = "../data/encomendas450.txt"
HEADER = "express priority volume weight reward duration"
MAXIMUM = 100000
MINIMUM = -1
DEFAULT_PRIORITY = 0
EXPRESS_PERCENTAGE = 10

def getBounds():

    allData = []
    with open(ORIGINAL, 'r') as file:

        allData = [     [   int(element) 
                            for element in line.strip().split(" ")  ] 
                            for line in file.readlines()[1:]               ]
        file.close()
    
    minVolume, minWeight, minReward, minDuration = MAXIMUM
    maxVolume, maxWeight, maxReward, maxDuration = MINIMUM
    parameters = [minVolume, maxVolume, minWeight, maxWeight, minReward, maxReward, minDuration, maxDuration]

    for line in allData:
        for index in range (0, len(parameters) // 2, 1):
            parameters[index] = line[index+2] if line[index+2] < parameters[index] else parameters[index]
            parameters[index+1] = line[index+2] if line[index+2] > parameters[index+1] else parameters[index+1]

    return [max(floor(parameter), ceil(parameter), round(parameter), 0) for parameter in parameters]

def generate():

    #total = int(input("Quantas packages gerar? "))
    #print("total is: {}".format(total))

    print(getBounds())
    #minVolume, maxVolume, minWeight, maxWeight, minReward, maxReward = getBounds()


if __name__ == "__main__":
    generate()