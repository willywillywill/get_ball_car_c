#include <stdio.h>
#include <stdlib.h>


// link-list
typedef struct link_node{
    int w;
    int car_dw;
    int x,y;
    struct link_node *next;
} link_node;
typedef struct link_list{
    link_node *head;
    link_node *tail;
    int size;
} link_list;
link_list *build(){
    link_list *linkList = malloc(sizeof(link_list));
    linkList->head = NULL;
    linkList->tail = NULL;
    linkList->size = 0;
    return linkList;
}

void insert_tail(link_list *list, int w){
    list->size++;
    link_node *node = malloc(sizeof(link_node));
    node->w = w;
    node->next = NULL;
    if (list->head==NULL){
        list->head = node;
        list->tail = node;
    } else{
        list->tail->next = node;
        list->tail = node;
    }
}
link_node pop(link_list *list){
    if(list->size){
        link_node node = *list->head;
        list->head = list->head->next;
        list->size--;
        return node;
    }

}
void printList(link_list *list){
    link_node *next = list->head;
    while (next){
        printf("%d ", next->w);
        next = next->next;
    }
    printf("\n");
}

void insert_w(link_list *list, int w){
    link_node *node = list->head;
    link_node *ptr;
    while(node) {
        if (w < node->w) break;
        ptr = node;
        node = node->next;
    }
    link_node *new_node = malloc(sizeof(link_node));
    new_node->next = node;
    new_node->w = w;
    printf("%d \n", ptr->w);
    if (node == list->head) list->head = new_node;
    else                    ptr->next = new_node;
}

int main() {
    link_list *list = build();
    insert_tail(list, 20);
    insert_tail(list, 30);
    printList(list);

    insert_w(list, 25);
    printList(list);

    insert_w(list, 10);
    printList(list);


}
