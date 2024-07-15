all :
		gcc -o shell shell.c
		gcc -o cat cat.c
		gcc -o ls ls.c
		gcc -o mkdir mkdir.c
		gcc -o rm rm.c
		gcc -o date date.c
		
clean :
		rm cat
		rm ls
		rm mkdir
		rm date
		rm rm
		rm shell
