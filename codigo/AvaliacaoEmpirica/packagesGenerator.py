import sys
from random import randint as rd
from math import ceil as c

'''
Script que gera N novas packages de acordo com os limites do dataset original
Coloca o resultado na pasta ../input, em formato "encomendas<N>.txt"
Garante que EXPRESS_PERCENTAGE % de todas as encomendas geradas são expresso
'''

ORIGINAL = "../../input/encomendas450.txt"
HEADER = "id express priority volume weight reward duration"
MAXIMUM = 100000
MINIMUM = -1
DEFAULT_PRIORITY = 0
EXPRESS_PERCENTAGE = 10

def getBounds():

    allData = []
    with open(ORIGINAL, 'r') as file:

        allData = [     [   int(element) 
                            for element in line.strip().split(" ")[1:]  ] 
                            for line in file.readlines()[1:]               ]
        file.close()
    
    minVolume, minWeight, minReward, minDuration = MAXIMUM, MAXIMUM, MAXIMUM, MAXIMUM
    maxVolume, maxWeight, maxReward, maxDuration = MINIMUM, MINIMUM, MINIMUM, MINIMUM

    for (express, priority, volume, weight, reward, duration) in allData:
        minVolume = min(minVolume, volume)
        minWeight = min(minWeight, weight)
        minReward = min(minReward, reward)
        minDuration = min(minDuration, duration)
        maxVolume = max(maxVolume, volume) 
        maxWeight = max(maxWeight, weight)
        maxReward = max(maxReward, reward)
        maxDuration = max(maxDuration, duration)

    return [minVolume, maxVolume, minWeight, maxWeight, minReward, maxReward, minDuration, maxDuration]

def generate(total):

    minVolume, maxVolume, minWeight, maxWeight, minReward, maxReward, minDuration, maxDuration = getBounds()

    express = [0] * total
    qtdExpress = c(total * (EXPRESS_PERCENTAGE / 100))

    while (qtdExpress):
        index = rd(0, len(express)-1)
        if express[index] == 0: 
            express[index] = 1
            qtdExpress -= 1

    allData = [ 
            " ".join (
            str(element) for element in [
                x, express[x], DEFAULT_PRIORITY, rd(minVolume, maxVolume), rd(minWeight, maxWeight), rd(minReward, maxReward), rd(minDuration, maxDuration)
            ]
        ) for x in range(total) 
    ]

    with open("../../input/encomendas" + str(total) + ".txt", "w") as file:
        
        file.write(HEADER + "\n")
        for line in allData[:-1]: file.write(line + "\n")
        file.write(allData[-1])
        file.close()

if __name__ == "__main__":
    generate(int(sys.argv[1]))
