# -*- coding: UTF-8 -*-

import os, sys

SCRIPT_PATH = os.path.split(os.path.realpath(__file__))[0]

problems = ['easy', 'medium', 'hard']
result = {}
all = 0
for p in problems:
    result[p] = []
    for root, dirs, files in os.walk(os.path.join(SCRIPT_PATH, p)):
        for f in files:
            if f.find('.h') > 0 or f.find('.py') > 0 :
                with open(os.path.join(root, f), 'r') as fi:
                    content = fi.read()
                    if content.find('Runtime: ') > 0:
                        result[p].append(f)
                    else:
                        print(f)
    all += len(result[p])
    print(p, len(result[p]))
    print('')
print(all)