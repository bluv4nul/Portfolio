#include <stdlib.h>
#include <stdio.h>

typedef struct List{
    double number;

    struct List *next;
    struct List *prev;

} List;

void add_end(List **head, List **tail, double n){

    List *new_n = (List *)malloc(sizeof(List));
    new_n -> number = n;
    new_n -> next = NULL;
    new_n -> prev = NULL;

    if(*head == NULL){
       *head = new_n;
       *tail = new_n;
    } else {
        new_n -> prev = *tail;
        (*tail) -> next = new_n;
        *tail = new_n;
    }
}

void add_beginning(List **head, List **tail, double n){

    List *new_n = (List *)malloc(sizeof(List));
    new_n -> number = n;
    new_n -> next = NULL;
    new_n -> prev = NULL;

    if(*head == NULL){
       *head = new_n;
       *tail = new_n;
    } else {
        new_n -> next = *head;
        (*head) -> prev = new_n;
        *head = new_n;
    }
}

void print_forward(List *head){
    List* current = head;
    while(current!=NULL){
        printf("%.2lf ",current->number);
        current = current -> next;
    }
}

void print_backward(List *tail){
    List* current = tail;
    while(current!=NULL){
        printf("%.2lf ",current->number);
        current = current -> prev;
    }
}

int main(void){
    List *head = NULL;
    List *tail = NULL;

    add_end(&head, &tail, 10);
    add_end(&head, &tail, 20);
    add_end(&head, &tail, 30);

    print_forward(head);
    printf("\n");
    print_backward(tail);
    printf("\n");

    add_beginning(&head, &tail, 1);
    add_beginning(&head, &tail, 2);
    add_beginning(&head, &tail, 3);

    print_forward(head);
    printf("\n");
    print_backward(tail);
    printf("\n");

}