

class abc():
	def fun(self):
			print "No"


class defi1(abc):
	def fun1(self):
			print "OK"


class defi2(abc):
	test_data = ((1, 1), (2, 4), (3, 9), (4, 16))
	def testfun(self):
			for a in self.test_data:
				if a[0] * a[0] != a[1]:
					print "testing error", a[0]*a[0], "!=", a[1]
					return
			print "testing success"

class defi3(defi1):
	def testfuns(self):
			print "nesting"
