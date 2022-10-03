#!/usr/bin/python3
"""
Count the number of appearances of keywords within
reddit hot titles
"""
import requests
from collections import Counter, defaultdict


def count_words(subreddit, wordlist, count=None, after=None):
    """
    make a request to reddit hot titles and check number of
    appearances of keyword
    """
    url = 'https://www.reddit.com/r/{}/hot.json'
    response = requests.get(
            url.format(subreddit),
            headers={'User-Agent': 'Mozilla/5.0'},
            params={'after': after, 'limit': 100},
            allow_redirects=False,
        )
    if response.status_code == 200:
        data = response.json().get('data')
        if not count:
            count = defaultdict(int)
        page = Counter(w for s in data.get('children')
                       for w in s.get('data').get('title').casefold().split())
        for each in wordlist:
            if each.casefold() in page:
                count[each.casefold()] += page.get(each.casefold())
        if data.get('after'):
            count_words(subreddit, wordlist, count, data.get('after'))
        else:
            for k, v in sorted(sorted(count.items(),
                               key=lambda x: x[0]), key=lambda x: x[1],
                               reverse=True):
                print(f"{k}: {v}")
