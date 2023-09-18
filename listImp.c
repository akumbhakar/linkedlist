/*
    --This is implementation file of the funtion that is declared in linkedlist.h file---+
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedList.h"

int nodeCount(struct node *copy_head){
    struct node *current = copy_head;
    int count = 0;
    while(current != NULL){
        count = count + 1;
        current = current->next;
    }

    return count;
}

int insert_node_at_end(struct node **head, struct consumer customer){
    /*
        This funtion add node at the end of the linkedlist.
    */

    struct node *tempo = *head;
    int count = 0;
    while(tempo != NULL){
        count = count + 1;
        if(tempo->next == NULL){
            break;
        }
        tempo = tempo->next;
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->customer = customer;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }
    else{
        tempo->next = newNode;
    }
    
    
    if (nodeCount(*head) == count){
        free(newNode);
        printf("Newnode not being assigned\n\n");
    }
    else{
        printf("Newnode assigned successfully.\n\n");
    }
    
    return 0;
    
    

}

int delete_list(struct node **head){
    /*
    
    this function Delete the entire list by freeing up memory 
    allocated for each node ,
    starting from head to tail,at the end it set the head to NULL....
    
    */
    struct node *auxiliaryNode = NULL, *iterator = NULL;
    iterator = *head;
    while(iterator != NULL){
        auxiliaryNode = iterator->next;
        free(iterator);
        iterator = auxiliaryNode;
    }

    *head = NULL;

    return 0;
}

int insert_node_at_head(struct node **head,struct consumer customer){
    /*
        This funtion insert a Node at head position of linkedlist updating
        the list.
    */

    int count = nodeCount(*head);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->customer = customer;
    newNode->next = *head;
    *head = newNode;

    if(nodeCount(*head)==count){
        free(newNode);
        printf("Failed to allocate NEWNODE!!!!!\n\n");
    }
    else{
        printf("allocation succesfull\n\n");
    }

    return 0;
}

int print_node(struct node *copy_head){
    /*
        This funtion print each node by taking its address if it is not NULL
    */
    if(copy_head != NULL){
        printf("    Customer ID: %s\n",copy_head->customer.consumer_ID);
        printf("    Name: %s\n",copy_head->customer.name);
        printf("    Addahar ID: %s\n",copy_head->customer.aadhar_ID);
        printf("    DOB: %s\n",copy_head->customer.DOB);
        printf("----------------------------------------------------------------\n");
    }
    else{
        printf("Can not print NULL pointer!!!\n");
    }
    return 0;
}

int search_node(struct node *copy_head, char* customer_ID){
    /*
        This funtion search a node and if it is found then it will
        print that node with a found massage.
    */
    struct node *tempo = copy_head;
    while(tempo != NULL){
        if(strcmp(tempo->customer.consumer_ID ,customer_ID) == 0){
            printf("FOUND!!!!!\n");
            print_node(tempo);
            break;
        }
        tempo = tempo->next;
    }
    if(tempo == NULL){
        printf("NOT FOUND!!!!!\n");
        
    }

    return 0;
    
}

int delete_node(struct node **head,char* customer_ID){
    /*
        This delete funtion delete node by checking the data value ID 
        like customer ID of any customer
        It will travarse through the list and when it find
        the specific node it will delete that node.
        If not found it will print customer not exist massage.
    */
    struct node *tempo = *head, *auxiliary = NULL, *prev = NULL;
    do{
        if(strcmp(tempo->customer.consumer_ID, customer_ID) == 0){
            if(tempo == *head){
                auxiliary = tempo->next;
                free(*head);
                *head = auxiliary;
                return 0;
            }
            else{
                auxiliary = tempo->next;
                free(tempo);
                prev->next = auxiliary;
                return 0;
            }
            
        }
        prev = tempo;
        tempo = tempo->next;
    }while(tempo != NULL);

    printf("Customer not exist!!\n");
    printf("......................................................\n");
    return 0;
}

int insert_at_index(struct node **head, int index, struct consumer customer){
    /*
        This funtion work as 1 based index....
        [index 1]->[index 2]->[index 3]->[index 4]-> NULL
    */
    struct node *tempo = *head;
    struct node *holder = NULL;
    int count = 0;
    int p_count = nodeCount(tempo);

    if(index > p_count || index <= 1){
        printf("Index out of range!!:(\n");
        return 0;
    }
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->customer = customer;
    newnode->next = NULL;
    
    while(tempo != NULL && count < (index - 1)){
        count = count + 1;
        holder = tempo;
        tempo = tempo->next;
    }
    holder->next = newnode;
    newnode->next = tempo;

    if(nodeCount(*head) == p_count){
        free(newnode);
        return 0;
    }


}

int delete_at_index(struct node **head, int index){
    /*
        This funtion work as 1 based index..
        [index 1]->[index 2]->[index 3]->[index 4]-> NULL
    */
    struct node *tempo = *head;
    struct node *holder = NULL;
    int count = 0;
    int p_count = nodeCount(tempo);
    if(index >p_count || index <= 1){
        printf("Index out of range!!:(");
        return 0;
    }
    while(tempo != NULL && count < (index - 1)){
        count = count + 1;
        holder = tempo;
        tempo = tempo->next;
    }
    struct node *auxiliary = tempo->next;
    free(holder->next);
    holder->next = auxiliary;



}


