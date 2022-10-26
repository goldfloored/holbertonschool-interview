#!/usr/bin/python3
""" make change algo """


def makeChange(coins, total):
    """ make change algo """
    coins.sort(reverse=True)
    num = 0
    for each in coins:
        num += total // each
        total = total % each
    if not total:
        return num
    return -1
