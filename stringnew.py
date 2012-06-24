'''
Given a string, finds all the possible substrings
'''
#!/usr/bin/env python
import time

def get(string,limit):
	substrings = []
	for l in xrange(len(string)):
		substrings.append([])
	for x in xrange(len(string)):
		for y in xrange(x,len(string)):
			betterinsert(substrings,(string[x:y+1]))
	#		print substrings
	return substrings

def merge(ls1,ls2,lim):
	for i in xrange(lim):
		for item in ls2[i]:
			if item not in ls1[i]:
				ls1[i].append(item)

def betterinsert(ls,el):
	if el not in (ls[len(el)-1]):
		ls[len(el)-1].append(el)

def execute(inputs):
	set1 = []
	for string in inputs:
		if len(set1)<len(string):
			for l in xrange(len(string)-len(set1)):
				set1.append([])
		merge(set1,get(string,len(string)),len(string))
	#print set1
	subs = []
	for item in set1:
		for item1 in item:
			subs.append(item1)
	return sorted(subs)

count = raw_input()
inputs = []
for i in xrange(int(count)):
	s = raw_input()
	inputs.append(s)
a = time.clock()
output = execute(inputs)
b = time.clock()
print output
print b - a
