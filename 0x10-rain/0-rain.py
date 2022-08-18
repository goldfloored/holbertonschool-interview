#!/usr/bin/python3
""" rain """


def rain(walls):
    """ rain """
    stop, i = len(walls) - 1, 0
    l = r = water = 0
    while stop > i:
        if walls[stop] > walls[i]:
            if l > walls[i]:
                water += l - walls[i]
            else:
                l = walls[i]
            i += 1
        else:
            if walls[stop] > r:
                r = walls[stop]
            else:
                water += r - walls[stop]
            stop -= 1
    return water
