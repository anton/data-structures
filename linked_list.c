#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *next;
    void *data;
} node;

typedef struct test {
    unsigned int one;
    char two[255];
    char *three;
    int four;
} test;

inline void insertafter(node *old, node *new) {
    new->next = old->next;
    old->next = new;
}

inline void cleanup(node *n) {
    node *next = n->next;
    if(n->data != NULL) {
	free(n->data);
    }
    free(n);
    if(next != NULL) {
	cleanup(next);
    }
}

int main(void) {
    test *t1;
    node *head, *tmp;

    t1 = (test *)malloc(sizeof(test));
    head = (node *) malloc(sizeof(node));
    head->next = NULL;
    head->data = t1;

    tmp = (node *) malloc(sizeof(node));
    tmp->data = NULL;

    insertafter(head, tmp);

    cleanup(head);

    return 0;
}
