run:
	gcc -o count count.c -lm
	gcc -o process1 process1.c -lm
	gcc -o process2 process2.c -lm
	gcc -o process3 process3.c -lm
	gcc -o main main.c -lm
	sudo taskset -c 0 ./main

clean:
	rm -f count process1 process2 process3 main