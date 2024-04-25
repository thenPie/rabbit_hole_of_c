WWW = -Wall -Werror -Wextra

all: cal

run:
	../build/com_arg

cal: com_l_args.c
	gcc $(WWW) -o ../build/com_arg com_l_args.c

clean:
	rm ../build/com_arg

rebuild: clean all