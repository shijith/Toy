_avl.so: avl.o avl_wrap.o
	ld -shared avl.o avl_wrap.o -o _avl.so

avl.o avl_wrap.o: avl.c avl_wrap.c
	gcc -c avl.c avl_wrap.c -I /usr/include/python2.6

avl_wrap.c:	avl.i
	swig -python avl.i

clean:
	rm -f avl.py _avl.so avl_wrap.c avl_wrap.o avl.o avl.pyc
