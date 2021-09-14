all: test run
run: testfile
	./testfile
	./read
	./out
	./read
test: testfilecreator.c
	gcc -o testfile testfilecreator.c
	gcc -o out grades.c 
	gcc -o read readfile.c
