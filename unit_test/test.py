import test_mod
import types

items = [ item for item in dir(test_mod)	if type(getattr(test_mod, item)) == types.ClassType ]

dirived = []
for i in items:
	clas = getattr(test_mod, i).__bases__
	if getattr(test_mod, 'abc') in clas:
		dirived.append(i)

for clas in dirived:
	attr = dir(getattr(test_mod, clas))
	for i in attr:
		if type(getattr(getattr(test_mod, clas), i)) == types.MethodType:
			if i[:4] == 'test':
				getattr(getattr(test_mod, clas)(), i)()
