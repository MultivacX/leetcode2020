# -*- coding: UTF-8 -*-

import os, sys

SCRIPT_PATH = os.path.split(os.path.realpath(__file__))[0]

problems = ['easy', 'medium', 'hard']
result = {}
all = 0
for p in problems:
    result[p] = []
    todo = []
    for root, dirs, files in os.walk(os.path.join(SCRIPT_PATH, p)):
        for f in files:
            if f.find('.h') > 0 or f.find('.py') > 0 :
                with open(os.path.join(root, f), 'r') as fi:
                    content = fi.read()
                    if content.find('Runtime: ') > 0:
                        result[p].append(f)
                    else:
                        todo.append(f)
    all += len(result[p])
    print(p + ": " + str(len(result[p])))
print(all)
print('')



from html.parser import HTMLParser

class Problem:
    def __init__(self):
        self.No = None # 0
        self.Title = None # 1
        self.Acceptance = None # 2
        self.Difficulty = None # 3
        self.Data = []
        self.Status = None
        self.Locked = False
        # self.Status = None # 1
        # self.Locked = None # 9
        # self.Attrs = []

    def setData(self):
        self.No = self.Data[0]
        self.Title = self.Data[1]
        self.Acceptance = self.Data[-2]
        self.Difficulty = self.Data[-1]
        # self.Status = self.Attrs[1] if self.Attrs[1] != '[object Object]' else 'Todo'
        # self.Locked = 'Locked' if self.Attrs[9] != '[object Object]' else 'Unlocked'

    def printProblem(self):
        print(str(self.No) + ' ' + str(self.Title) + ' ' + str(self.Acceptance) + ' ' + str(self.Difficulty) + ' ' + str(self.Status) + ' ' + str(self.Locked) + ' ')

class ProblemStatistics:
    def __init__(self, Difficulty):
        self.Difficulty = Difficulty
        self.Solved = []
        self.Attempted = []
        self.TodoLocked = []
        self.TodoUnlocked = []
        self.All = []

    def addProblem(self, problem):
        self.All.append(problem)
        if problem.Status == 'ac':
            self.Solved.append(problem)
        elif problem.Status == 'notac':
            self.Attempted.append(problem)
        elif problem.Locked:
            self.TodoLocked.append(problem)
        else:
            self.TodoUnlocked.append(problem)

class MyHTMLParser(HTMLParser):
    def init(self):
        self.problem = None
        self.problemStatistics = {}

    def handle_starttag(self, tag, attrs):
        # print("Encountered a start tag:", tag)
        if self.problem != None:
            for a in attrs:
                # self.problem.Attrs.append(a[-1])
                for v in a:
                    if v == 'ac' or v == 'notac':
                        self.problem.Status = v
                    elif v == 'Subscribe to unlock':
                        self.problem.Locked = True
        elif tag == 'tr':
            self.problem = Problem()

    def handle_endtag(self, tag):
        # print("Encountered an end tag :", tag)
        if tag == 'tr':
            self.problem.setData()
            # self.problem.printProblem()
            if self.problemStatistics.get(self.problem.Difficulty) == None:
                self.problemStatistics[self.problem.Difficulty] = ProblemStatistics(self.problem.Difficulty)
            self.problemStatistics[self.problem.Difficulty].addProblem(self.problem)
            self.problem = None

    def handle_data(self, data):
        if self.problem != None:
            self.problem.Data.append(data)

with open(os.path.join(SCRIPT_PATH, 'problems.html'), 'r') as fi:
    parser = MyHTMLParser()
    parser.init()
    parser.feed(fi.read())
    for _, ps in parser.problemStatistics.items():
        print(ps.Difficulty + ': ')
        print('    All:           ' + str(len(ps.All)))
        print('    Solved:        ' + str(len(ps.Solved)))
        print('    Attempted:     ' + str(len(ps.Attempted)))
        print('    Todo Locked:   ' + str(len(ps.TodoLocked)))
        print('    Todo Unlocked: ' + str(len(ps.TodoUnlocked)))
        pass