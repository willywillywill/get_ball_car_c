#include <stdio.h>
#include <stdlib.h>
#include "math.h"


// link-list
typedef struct pos{
    int x,y;
}pos;
typedef struct link_node{
    pos node_pos;
    struct link_node *next, *ptr;
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

void insert(link_list *list, pos node_pos){
    list->size++;
    link_node *node = malloc(sizeof(link_node));
    if(list->tail != NULL){
        node->ptr = list->tail;
    }else{
        node->ptr = NULL;
    }
    node->node_pos = node_pos;
    node->next = NULL;
    if (list->head==NULL){
        list->head = node;
        list->tail = node;
    } else{
        list->tail->next = node;
        list->tail = node;
    }
}

void printList(link_list *list){
    link_node *next = list->head;
    while (next){
        if(next->ptr)
            printf("(%d,%d)-> ", next->ptr->node_pos.x, next->ptr->node_pos.y);
        else
            printf("NULL->");

        printf("(%d,%d)-> ", next->node_pos.x, next->node_pos.y);

        if(next->next)
            printf("(%d,%d)\n", next->next->node_pos.x, next->next->node_pos.y);
        else
            printf("NULL\n");
        next = next->next;
    }
    printf("\n");

}
float dw(pos sp, pos pv){
    return pow(pow(sp.x-pv.x,2)+pow(sp.y-pv.y,2),0.5);
}
pos pop_min_w(link_list *list, pos car_pos){
    // pos
    float now_w = 1e9;

    // node
    link_node *next = list->head;
    link_node *node;
    while(next){
        float w = dw(next->node_pos, car_pos);
        if (w < now_w){
            node = next;
            now_w = w;
        }
        next = next->next;
    }
    pos min_w_pos = node->node_pos;

    if (node==list->head){

    }

    return min_w_pos;
};

int main() {
    pos car_pos = {0,0};
    link_list *list = build();
    pos node_pos1 = {0,1};
    insert(list, node_pos1);

    pos node_pos2 = {0,3};
    insert(list, node_pos2);

    pos node_pos3 = {0,5};
    insert(list, node_pos3);

    printList(list);

    pop_min_w(list, car_pos);
    printList(list);

    //printf("%d,%d \n", node.x,node.y);
}
