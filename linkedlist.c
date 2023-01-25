// Modify this file
// compile with: gcc linkedlist.c -o linkedlist.out

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// TODO: Create your node_t type here

typedef struct node {
    
    int year;
    int wins;
    struct node* next;

}node_t;

node_t* new_node(int wins, int year, node_t* next) {

   node_t* newNode = (node_t*)malloc(sizeof(node_t)); // allocate a new node, we have to put it on the heap! 

   newNode->wins = wins;
   newNode->year = year;
   newNode->next = next; 

   return newNode;
}

void printNodes(node_t* node) {
    
    node_t* itr = node; //itr is an iterater variable. it equals &node 1 (address)
    while(itr != NULL) {
        printf("%d, %d wins \n", itr->year, itr->wins); // (&node1)->data
        itr = itr->next;  // itr = (&node1)-> next
    }
    printf("\n");
}

node_t* buildList(int* wins, int* years, int size) {

    int i;

    node_t* node = new_node(wins[size-1], years[size-1], NULL);
    for (i = size - 2; i >= 0; i--) {
        node = new_node(wins[i], years[i], node);
    }

    return node;
}

void free_list(node_t* node) {

    node_t* itr = node;
    node_t* temp;

    if (node == NULL) {
        return;
    }

    while(itr != NULL) {
        temp = itr->next;
        free(itr);
        itr = temp;
    }
}

node_t* find_year(node_t* node, int year) {
    
    if (node == NULL) {
        return NULL;
    }

    while (node != NULL){
        if (node->year == year){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

// TODO: Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

int main()
{
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    node_t* test;
    
    node_t* list = buildList(test_wins, test_years, 5);

    printNodes(list);
    test = find_year(list, 2016);
    
    printf("%d \n", test->year);

    free_list(list);

    // TODO: Implement me!

    return 0;
}