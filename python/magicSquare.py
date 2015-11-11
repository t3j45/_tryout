'''
Constructs magic square. Property of magic square is that the sums of all rows and columns are equal.
'''

#!/usr/bin/env python

size = 0
while(size%2==0):
	size = int(raw_input("Enter ODD number: "))

Matrix = []
for i in xrange(size):
	row = []
	for j in xrange(size):
		row.append(0)
	Matrix.append(row)

curPos = [0,size/2]
Matrix[curPos[0]][curPos[1]] = 1

for number in xrange(2,(size*size)+1):
	if (Matrix[(curPos[0]-1)%size][(curPos[1]+1)%size]==0):
		Matrix[(curPos[0]-1)%size][(curPos[1]+1)%size] = number
		curPos[0] = (curPos[0]-1)%size
		curPos[1] = (curPos[1]+1)%size
	else:
		Matrix[(curPos[0]+1)%size][(curPos[1])%size] = number
		curPos[0] = (curPos[0]+1)%size

for i in xrange(size):
	sum = 0
	for j in xrange(size):
		sum = sum + Matrix[i][j]
	print Matrix[i],sum
