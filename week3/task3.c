
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

void print_list(struct Node *n){
    
    while (n!=NULL){
        printf("%d-> ", n->value);
        n = n->next;
    }
    printf("NULL \n");
}

void push(struct Node** head, int input_value){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->value = input_value;
    new_node->next = NULL;

    if (*head == NULL){
        *head = new_node;
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

void delete(struct Node **head, int key){
    struct Node* temp = *head, *prev;
    if (temp!=NULL && temp->value == key){
        *head = temp->next;
        free(temp);
    }
    
    while (temp!=NULL && temp->value!=key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);

}

int main(){
    struct Node* list = NULL;
    push(&list, 2);
    push(&list, 4);
    push(&list, 5);
    push(&list, 9);
    push(&list, 13);

    print_list(list);

    delete(&list, 1);
    delete(&list, 9);

    print_list(list);

    return 0;


}



