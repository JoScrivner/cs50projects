from cs50 import get_int


def main():
    i = get_positive_int()  # getting a number between 1 and 8
    for m in range(i):
        spaces(i-m-1)
        hashtags(m+1)
        spaces(2)
        hashtags(m+1)
        print()


def hashtags(k):  # hashtag-printing funciton
    print('#' * k, end="")


def spaces(l):  # space-printing funciton
    print(' ' * l, end="")


def get_positive_int():  # funciton to check if number is between 1 an 8
    while True:
        n = get_int("Height: ")
        if n > 0:
            if n < 9:
                break
    return n


main()