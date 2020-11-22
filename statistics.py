# -*- coding: UTF-8 -*-

import os, sys, shutil

SCRIPT_PATH = os.path.split(os.path.realpath(__file__))[0]

problem_files = {}
result = {}
all = 0
for p in ['easy', 'medium', 'hard']:
    problem_files[p] = []
    result[p] = []
    todo = []
    for root, dirs, files in os.walk(os.path.join(SCRIPT_PATH, p)):
        for f in files:
            if f.find('.h') > 0 or f.find('.py') > 0 :
                fn, fe = os.path.splitext(f)
                fp = os.path.join(root, f)
                problem_files[p].append([fn.lstrip('0'), fp])
                with open(fp, 'r') as fi:
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
    todo = {}
    for _, ps in parser.problemStatistics.items():
        print(ps.Difficulty + ': ')
        print('    All:           ' + str(len(ps.All)))
        print('    Solved:        ' + str(len(ps.Solved)))
        print('    Attempted:     ' + str(len(ps.Attempted)))
        print('    Todo Locked:   ' + str(len(ps.TodoLocked)))
        print('    Todo Unlocked: ' + str(len(ps.TodoUnlocked)))
        
        cur_d = ps.Difficulty.lower()

        zeros = ['000', '00', '0', '']
        allNo = []
        for p in ps.All:
            allNo.append(str(p.No))
        for d, pfs in problem_files.items():
            for pf in pfs:
                if not pf[0].split('.')[0] in allNo:
                    continue
                if pf[1].find(cur_d + '/') > 0:
                    continue
                if pf[1].find(cur_d + '\\') > 0:
                    continue
                dst = pf[1].replace(d + '/', cur_d + '/').replace(d + '\\', cur_d + '\\')
                print(pf, dst)
                shutil.move(pf[1], dst)

        todo[cur_d] = []
        for p in ps.Attempted:
            todo[cur_d].append(zeros[len(str(p.No)) - 1] + str(p.No) + '. ' + str(p.Title))
        for p in ps.TodoUnlocked:
            todo[cur_d].append(zeros[len(str(p.No)) - 1] + str(p.No) + '. ' + str(p.Title))
        todo[cur_d].sort()

    print('')
    for d in ['easy', 'medium', 'hard']:
        print(d + ' ' + str(len(todo[d])))
        for p in todo[d]:
            print('    ' + p)
        print('')
        