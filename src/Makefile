WWW = -Wall -Werror -Wextra
BUILD = -o ../build/

all: cla

cla: com_l_args.c
	gcc $(WWW) $(BUILD)com_arg com_l_args.c

s21_cat: cat/cat.c cat/cat_func.c
	gcc $(WWW) $(BUILD)s21_cat cat/cat.c cat/cat_func.c

clean:
	rm ../build/com_arg

rebuild: clean all