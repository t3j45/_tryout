'''
Given a string, Finds all the permutations.
'''

#!/usr/bin/env python
import sys

if len(sys.argv)>1:
	string = sys.argv[1]
else:
	string = raw_input("Enter String: ")

def generate(string,sofar):
	if len(sofar)==len(string):
		print sofar
		return sofar
	for char in string:
		if char not in sofar:
			generate(string,sofar+char)
generate(sorted(string),"")
