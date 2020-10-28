from cs50 import get_int
from cs50 import get_string


def main():
    text = get_string("Text: ")

    # using split()
    # to count words in string
    wordcount = len(text.split())
    L = count_letters(text) * (100 / wordcount)  # calculating L
    S = count_sentences(text) * (100 / wordcount)  # calculating S

    #L = (countletters * (100/countwords))
    #S = (countsentences * (100/countwords))

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if (index >= 1) and (index <= 16):  # if index is between 1-16
        print(f"Grade {index}\n")
    elif (index < 1):
        print("Before Grade 1\n")
    else:
        print("Grade 16+\n")


def count_letters(szoveg):  # function to count the number of letters
    length = 0
    low = 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'

    n = len(szoveg)
    for i in range(n):
        if (szoveg[i].lower() in low):  # if they are actual letters
            length = length + 1
    return length


def count_words(szoveg2):  # function to count the number of words
    length = 0
    if szoveg2 != "":  # if the sting is not empty, that's already 1 word
        length = length + 1

    strlen = len(szoveg2)
    for i in range(strlen):
        if szoveg2[i] == ' ':   # we count the number of spaces basically
            length = length + 1
    return length


def count_sentences(szoveg3):  # function to count the number of sentences
    length = 0
    upper = 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'

    strlen = len(szoveg3)
    for i in range(strlen-2):
        if (szoveg3[i] == '.') or (szoveg3[i] == '?') or (szoveg3[i] == '!'):
            if (szoveg3[i + 2] in upper):
                length = length + 1

    if (szoveg3[strlen - 1] == '.') or (szoveg3[strlen - 1] == '?') or (szoveg3[strlen - 1] == '!'):
        length = length + 1

    return length


main()
