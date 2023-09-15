#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"

int main(){
    
    struct node *head = NULL;
    struct consumer customer1 = {"2130564528","GOBARDHAN KUMBHAKAR","123423561254","12/06/1950"};
    struct consumer customer2 = {"2130562536","MOUSUMI KUMBHAKAR","523156897854","02/05/1992"};
    struct consumer customer3 = {"2130564525","BAISHAKHI KUMBHAKAR","456823598659","02/05/1994"};
    struct consumer customer4 = {"2130568954","AKASH KUMBHAKAR","852434267065","18/06/2001"};
    struct consumer customer5 = {"2150569653","PRAKASH KUMBHAKAR","865945215632","30/12/2012"};


    insert_node_at_end(&head,customer1);
    insert_node_at_end(&head,customer2);
    insert_node_at_end(&head,customer3);
    insert_node_at_end(&head,customer5);
    insert_node_at_head(&head,customer4);

    struct node* current = head;
    while(current != NULL){
        print_node(current);

        current = current->next;
    }

    search_node(head,"2130568954");
    printf(".......................................\n");
    delete_node(&head,"2130568952");
    
    current = head;
    while(current != NULL){
        print_node(current);

        current = current->next;
    }
    
    
    
    delete_list(&head);
    
    
}