from Tkinter import *
from math import *

can = Canvas(height=400, width=400)
can.pack()

class turtle():
	"""My Tkinter turtle class"""
	def __init__(self, can):
		"""Initialisation of turtle"""
		self.can = can
		self.angle = 0
		self.hidden = 0
		self.x, self.y = 200, 200
		self.poly = can.create_polygon(195, 195, 195, 205, 210, 200)

	def go(self,a):
		"""Move the turtle forward n steps"""
		x1 = self.x + a * cos((self.angle/180.00)*3.14)
		y1 = self.y + a * sin((self.angle/180.00)*3.14)

		self.can.create_line(self.x, self.y, x1, y1)

		self.x = x1
		self.y = y1

		self.can.move(self.poly, a * cos((self.angle / 180.00) * 3.14), (a * sin((self.angle / 180.00) * 3.14)))


	def rotate(self, angle):
		"""Rotate the turtle by an angle"""
		self.angle = self.angle + angle
		self.can.delete(self.poly)

		x1 = self.x + 15 * cos((self.angle / 180.00) * 3.14)
		y1 = self.y +15 * sin((self.angle / 180.00) * 3.14)

		x2 = self.x + 5 * cos(((90 + self.angle) / 180.00) * 3.14)
		y2 = self.y +5 * sin(((90 + self.angle) / 180.00) * 3.14)

		x3 = self.x + 5 * cos(((270 + self.angle) / 180.00) * 3.14)
		y3 = self.y +5 * sin(((270 + self.angle) / 180.00) * 3.14)

		if not self.hidden:
				self.poly = self.can.create_polygon(x1, y1, x2, y2, x3, y3)

	def hide(self):
		"""Hide the turtle"""
		self.hidden = 1
		self.can.delete(self.poly)
		
	def show(self):
		"""Show the turtle"""
		self.hidden = 0
		x1 = self.x + 15 * cos((self.angle / 180.00) * 3.14)
		y1 = self.y +15 * sin((self.angle / 180.00) * 3.14)
		x2 = self.x + 5 * cos(((90 + self.angle) / 180.00) * 3.14)
		y2 = self.y +5 * sin(((90 + self.angle) / 180.00) * 3.14)
	
		x3 = self.x + 5 * cos(((270 + self.angle) / 180.00) * 3.14)
		y3 = self.y +5 * sin(((270 + self.angle) / 180.00) * 3.14)
		
		self.poly = self.can.create_polygon(x1, y1, x2, y2, x3, y3)

