#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"

int main(){
    int index;
    struct node *head = NULL;
    struct consumer customer[] = {  {"2130564528","GOBARDHAN KUMBHAKAR","123423561254","12/06/1950"},
                                    {"2130562536","MOUSUMI KUMBHAKAR","523156897854","02/05/1992"},
                                    {"2130564525","BAISHAKHI KUMBHAKAR","456823598659","02/05/1994"},
                                    {"2130568954","AKASH KUMBHAKAR","852434267065","18/06/2001"},
                                    {"2150569653","PRAKASH KUMBHAKAR","865945215632","30/12/2012"}
    
    };


    for(int i = 0; i < (sizeof(customer)/sizeof(customer[0])); i++){
        insert_node_at_end(&head,customer[i]);
    }

    struct node* current = head;
    while(current != NULL){
        print_node(current);

        current = current->next;
    }

    printf("Enter Index you want to delete:: ");
    scanf("%d",&index);
    delete_at_index(&head,index);
    printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    current = head;
    while(current != NULL){
        print_node(current);

        current = current->next;
    }
    
    delete_list(&head);
    
    
}