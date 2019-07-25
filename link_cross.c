
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

struct node *link_create(int index, int size) {
    int i = 0;
    int j = 0;
    struct node *pp = NULL;
    struct node *entry = NULL;
    struct node *p = NULL;
    struct node *cross = NULL;

    struct node *head = malloc(sizeof(struct node));
    head->value = 1 * index;
    head->next = NULL;
    pp = head;
    for (i = 0; i < size; i++) {
        p = malloc(sizeof(struct node));
        p->value = (i + 1) * index;
        p->next = NULL;
        pp->next = p;
        pp = pp->next;
        printf("p:%p value:%d\n", p, p->value);
    }
    return head;
}

struct node *find_tail(struct node *head) {
    struct node *p = head;
    while (p->next) {
        p = p->next;
    }
    return p;
}

int link_size(struct node *head) {
    int len = 0;
    struct node *p = head;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

int main(int argc, char *argv[]) {
    struct node * list1 = link_create(10, 7);
    struct node * list2 = link_create(100, 3);
    struct node * cross = link_create(1000, 5);
    struct node * tail1 = find_tail(list1);
    struct node * tail2 = find_tail(list2);
    struct node * p1 = list1;
    struct node * p2 = list2;
    int i = 0;
    tail1->next = cross;
    tail2->next = cross;

    int len1 = link_size(list1);
    int len2 = link_size(list2);
    int delta = 0;

    if (len1 > len2) {
        delta = len1 - len2;
        p1 = list1;
        for (i = 0; i < delta; i++) {
            p1 = p1->next;
        }
        while (p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        printf("p1:%p value:%d\n", p1, p1->value);
    }
    else {
        delta = len1 - len2;
        p2 = list2;
        for (i = 0; i < delta; i++) {
            p2 = p2->next;
        }
        while (p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        printf("p2:%p value:%d\n", p2, p2->value);
    }

    return 0;
}