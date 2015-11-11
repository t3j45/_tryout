'''
A number is colorful if multiplication factors of its substrings are unique.
For example,
	Let number = 236
	Substrings for 236 = ['2','3','6','23','36']
	But product of '23' = 6, which is already one of the factors. Therefore, 236 is not colorful number!
'''
#!/usr/bin/env python
number = raw_input()

def getsubstrings(string):
	substring = []
	for i in xrange(len(string)):
		for j in xrange(i,len(string)):
			substring.append(string[i:j+1])
	return substring

def getproduct(string):
	product = 1
	for i in xrange(len(string)):
		product = product * int(string[i])
	return product

number = str(number)

substrings = getsubstrings(number)

#print substrings

pi = {}

for string in substrings:
	prd = getproduct(string)
	if prd in pi.keys():
		pi[prd] = pi[prd]+1
	else:
		pi[prd] = 1

dups = False
for value in pi.values():
	if 1 != value:
		dups = True
print pi
if dups == False:
	print 'Colourful'
else:
	print 'Not colorful'
