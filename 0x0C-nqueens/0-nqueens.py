#!/usr/bin/python3
"""
famous nqueens problem
"""
from sys import argv, exit


def attack(board, row, column):
    """ check not attacking """
    for col in range(column):
        if abs(board[col] - row) is abs(col - column) or board[col] is row:
            return True
    return False


def make_board(board, column):
    """ place queen """
    board_len = len(board)
    if column is board_len:
        print(str([[col, board[col]] for col in range(board_len)]))
        return
    for row in range(board_len):
        if not attack(board, row, column):
            board[column] = row
            make_board(board, column + 1)


if __name__ == "__main__":
    """ main """
    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    s = 0
    try:
        s = int(argv[1])
    except Exception:
        print("N must be a number")
        exit(1)
    if s < 4:
        print("N must be at least 4")
        exit(1)
    board = [0 for x in range(s)]
    make_board(board, 0)
    