from string import ascii_uppercase
import random

def do():

    directory = "carrinhas.txt"

    with open (directory, "r") as file:

        allData = file.readlines()

        print("matricula " + allData[0], end = "")

        for line in allData[1:]:

            L1 = ascii_uppercase[random.randint(0, len(ascii_uppercase)-1)]
            L2 = ascii_uppercase[random.randint(0, len(ascii_uppercase)-1)]
            N1 = str(random.randint(0, 9))
            N2 = str(random.randint(0, 9))
            L3 = ascii_uppercase[random.randint(0, len(ascii_uppercase)-1)]
            L4 = ascii_uppercase[random.randint(0, len(ascii_uppercase)-1)]

            print("{}{}-{}{}-{}{} ".format(L1, L2, N1, N2, L3, L4) + line, end = "")

    file.close()

if __name__ == "__main__":
    do()