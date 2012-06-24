'''
Given a sequence of keystrokes(numbers), prints the string output of a cellphone keypad.
'''

#!/usr/bin/env python

keymap = [['0'],['1'],['a','b','c','2'],['d','e','f','3'],['g','h','i','4'],['j','k','l','5'],['m','n','o','6'],['p','q','r','s','7'],['t','u','v','8'],['w','x','y','z','9']]

number = str(raw_input("Enter Number: "))
lastnumber = '#'
outstring = ''

def count(ind,string):
	cnt = 1
	for x in xrange(ind,len(string)-1):
		if string[x] == string[x+1]:
			cnt = cnt + 1
		else:
			return cnt
	return cnt
i = 0
while(i < len(number)):
	index = count(i,number)
	key = keymap[int(number[i])]
	if index > len(key):
		index = len(key)
	outstring = outstring+key[index-1]
	i = i + index

print outstring
