#!/usr/bin/env python3

import subprocess
import sys

def cmd(pivot, recur):
    return ['gcc', '-w', '-O2', '-D', pivot, '-D', recur, '-D', 'DEBUG', 'quickSort.c']

def mean(data):
    total = 0.0
    for i in data:
        total += i
    return total/len(data)

pivot_method = ['leftmost', 'median of three']
recur_method = ['original', 'longer first', 'shorter first']
tag = {
        'leftmost': 'DEFAULT', 
        'median of three': 'MEDIAN_OF_THREE', 
        'longer first': 'LONG', 
        'shorter first': 'SHORT', 
        'original': 'DEFAULT'
        }

test_times = 100

for i in range(len(pivot_method)):
    for j in range(len(recur_method)):
        # compile
        subprocess.check_output(cmd(tag[pivot_method[i]], tag[recur_method[j]]))
        # print(cmd(tag[pivot_method[i]], tag[recur_method[j]]))

        # run tests
        data = []
        for _ in range(test_times):
            output = subprocess.check_output('./a.out').strip().split(b' = ')[1]
            data.append(float(output))

        # calculate mean execution time
        data.sort();
        t = mean(data[1:-1])
        print('use {} and {} execution time = {:.5f}'.format(pivot_method[i], recur_method[j], t))
