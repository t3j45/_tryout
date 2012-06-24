'''
additivePrime is a prime that passes additive function.
For example, if f(n) = 2n
Then additive primes x and y should pass the following test,
				f(x+y) = f(x) + f(y)
'''

#!/usr/bin/env python
def generatePrimes(limit):
	primes = []
	for i in xrange(limit):
		isPrime = False
		if ((i%2) != 0):
			isPrime = True
			for j in xrange(3,i/2):
				if i%j == 0:
					isPrime = False
		if isPrime == True:
			primes.append(i)
	return primes

def generatePairs(someList):
	pairs = []
	for i in xrange(len(someList)):
		for j in xrange(i,len(someList)):
			pairs.append([someList[i],someList[j]])
	return pairs

def isAdditive(x,y):
	if (secret(x+y) == (secret(x)+secret(y))):
		return True
	return False

def secret(n):
	return n

# Program Starts Here
pairs = generatePairs(generatePrimes(100))
additiveflag = True

for pair in pairs:
	if not isAdditive(pair[0],pair[1]):
		additiveflag = False

print additiveflag
