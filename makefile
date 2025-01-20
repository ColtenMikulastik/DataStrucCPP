
run: main.exe
	./main.exe

main.exe: driver.cpp
	g++ ./driver.cpp -o main.exe

clean: 
	rm -rf ./*.exe

debug: 
	g++ ./driver.cpp -g -o test.exe
	gdb ./test.exe
