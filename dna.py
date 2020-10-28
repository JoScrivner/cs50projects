from sys import argv, exit
import csv


def main():
    if len(argv) != 3:
        print("missing command-line argument")  # error message
        exit(1)
    emberek = []  # list for names
    szamok = []  # list for numbers
    with open (argv[1],'r') as csv_file:  # read csv file
        reader = csv.reader(csv_file)
        next(reader) # skip first row
        if argv[1] == "databases/small.csv":
            for row in reader:
                emberek.append(row[0])
                szamok.append(row[1] + ", " + row[2] + ", " + row[3])
        elif argv[1] == "databases/large.csv":
            for row in reader:
                emberek.append(row[0])
                szamok.append(row[1] + ", " + row[3] + ", " + row[6])

    with open(argv[2], 'r') as myfile:  # read txt file
        data = myfile.read()

    szoveg = data
    maxAGAT = szamol5(list(find_all(szoveg, 'AGATC')))
    maxAATG = szamol4(list(find_all(szoveg, 'AATG')))
    maxTATC = szamol4(list(find_all(szoveg, 'TATC')))
    max1 = checkiflist(maxAGAT)
    max2 = checkiflist(maxAATG)
    max3 = checkiflist(maxTATC)

    checknumber = f"{max1}, {max2}, {max3}"

    ind = -1

    for szam in szamok:  # look for match
        if szam == checknumber:
            ind = szamok.index(szam)

    nev = emberek[ind]

    if ind == -1:  # if not found
        print("No match")
    else:  # if found, print name
        print(nev)
    exit(0)

def checkiflist(mylist):
    if isinstance(mylist, list):
        elem = max(mylist)
    else:
        elem = mylist
    return elem


def find_all(wholestr, sub):  # function to find substrings
    start = 0
    while True:
        start = wholestr.find(sub, start)
        if start == -1:
            return
        yield start
        start += len(sub)


def szamol4(lista2):
    szamolasok = []
    if not lista2:
        return 0
    else:
        length = len(lista2)
        szamol = 1

        if length == 1:
            return 1
        else:

            for i in range(length-1):
                k = i
                while (lista2[k+1] - lista2[k]) == 4:
                    szamol = szamol + 1
                    if (k+1) != (length-1):
                        k = k + 1
                    else:
                        break
                szamolasok.append(szamol)
                szamol = 1
            return szamolasok


def szamol5(lista2):
    szamolasok = []
    if not lista2:
        return 0
    else:
        length = len(lista2)
        szamol = 1

        if length == 1:
            return 1
        else:

            for i in range(length-1):
                k = i
                while (lista2[k+1] - lista2[k]) == 5:
                    szamol = szamol + 1
                    if (k+1) != (length-1):
                        k = k + 1
                    else:
                        break
                szamolasok.append(szamol)
                szamol = 1
            return szamolasok


main()