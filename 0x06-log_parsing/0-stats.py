#!/usr/bin/python3
""" Module for parsing logs """
import sys


def check_readme_format(line):
    """
    Checks for correct format
    """
    if "GET /projects/260 HTTP/1.1" in line:
        return(0)
    else:
        return(1)