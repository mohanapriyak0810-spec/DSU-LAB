#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void create(int n) {
    struct node *p, *t;

    while (n--) {
        p = malloc(sizeof(*p));
        scanf("%d", &p->data);
        p->next = NULL;

        if (!head)
            head = p;
        else {
            t = head;
            while (t->next)
                t = t->next;
            t->next = p;
        }
    }
}
void traverse() {
    struct node *p = head;

    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}
void insert(int x) {
    struct node *p = malloc(sizeof(*p));

    p->data = x;
    p->next = head;
    head = p;
