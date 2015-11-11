'''
Given a number, prints (alphabetically) all the possible strings, on a cellphone keypad.
'''
#!/usr/bin/env python
import sys

keymap = [['0'],['1'],['a','b','c'],['d','e','f'],['g','h','i'],['j','k','l'],['m','n','o'],['p','q','r','s'],['t','u','v'],['w','x','y','z']]

words = []
final = ''
def getwords(telnumber,words):
	if len(telnumber)>0:
		ls = []
		for word in words:
			w = word
			for letter in keymap[int(telnumber[0])]:
				ls.append(w+letter)
		return getwords(telnumber[1:],ls)
	else:
		return words

if len(sys.argv)>1:
	test_cases = open(sys.argv[1],'r')
else:
	test_cases= [raw_input("Enter number: ")]
#test_cases = ['4155230']
for case in test_cases:
	final = ''
	case = case.replace('\n','')
	words = ['']
	final = sorted(getwords(case,words))
	print final
	
