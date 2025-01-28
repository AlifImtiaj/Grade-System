all:
    gcc -g -Wall -Wextra -o GradeSoftware main.c grade.c
	cls
	./GradeSoftware
run:
	./GradeSoftware
warn:
	gcc -g -Wall -Wextra -o GradeSoftware main.c grade.c