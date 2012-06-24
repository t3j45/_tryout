'''
Given two lists M and N of size m and n respectively, find repeated elements in list M in list N. 
Also returns the number of times a number is repeated.
For example,
			M = ['1','3','2','5']
			N = ['3','3','5']
			Output: 
				3 repeated 2 time(s)
				5 repeated 1 time(s)
				
Complexity of Algorithm is linear or O(k) where k = m>n?m:n.
'''

#!/usr/bin/env python
import sys

#Read List(s)
list1 = (sys.argv[1]).split(',')
list2 = (sys.argv[2]).split(',')

print list1
print list2

# Dictionary {number, # times repeated}
hashmap = {}

# Add items in list one to Dictionary, Ignore duplicates
for item in list1:
	if item not in hashmap.keys():
		hashmap[item] = 1

# Update dictionary from list two
for item in list2:
	if item in hashmap.keys():
		hashmap[item] = hashmap[item]+1

# Print the duplicates
for key in hashmap:
	if hashmap[key]!=1:
		print str(key)+" repeated "+str((hashmap[key]-1))+" time(s)"
