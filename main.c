#include <stdio.h>
#include <stdlib.h>

// link-list
typedef struct link_node{
    int w;
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
void insert(link_list *list, int w){
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

int main() {
    link_list *list = build();
    insert(list, 10);
    printList(list);


}
