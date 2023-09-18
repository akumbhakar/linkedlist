#ifndef _LIST_H
#define _LIST_H

struct consumer{
    char *consumer_ID;
    char *name;
    char *aadhar_ID;
    char *DOB;
};

struct node{
    struct consumer customer;
    struct node *next;

}; 

int nodeCount(struct node *copy_head);
int insert_node_at_end(struct node **head, struct consumer customer);
int delete_list(struct node **head);
int insert_node_at_head(struct node **head,struct consumer customer);
int search_node(struct node *copy_head, char* customer_ID);
int print_node(struct node *copy_head);
int delete_node(struct node **head,char* customer_ID);
int insert_at_index(struct node **head, int index, struct consumer customer);
int delete_at_index(struct node **head, int index);


#endif
