#!/usr/bin/env python

base = raw_input()

base = base.split(',')

while(len(base)!=1):
	tempbase = []
	for i in xrange(len(base)-1):
		tempbase.append(int(base[i])+int(base[i+1]))
	base = tempbase
	print len(base),base
	
