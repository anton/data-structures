CFLAGS=-Wall -pedantic
linked_list: linked_list.c
	gcc $(CFLAGS) -o linked_list linked_list.c
