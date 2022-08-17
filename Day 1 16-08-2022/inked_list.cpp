#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
    int data;
    node *link;
};

void add_node(struct node *head, int data){
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void print_list(struct node *head){
    struct node *ptr = head;
    if(ptr == NULL){
        cout << "List is empty"<< endl;
    }
    while(ptr!=NULL){
        cout << ptr->data << endl;
        ptr = ptr->link;
    }
}

struct node* add_node_end(struct node *ptr, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}

struct node* add_node_begin(struct node *head, int data){
    struct node *ptr =(struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    return head;
}

void add_node_begin1(struct node **head, int data){
    struct node *ptr =(struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = *head;
    *head = ptr;
}

void add_node_position(struct node *head, int data, int pos){
    struct node *ptr = head;
    if(ptr == NULL){cout << "List is empty"<< endl;}
    struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
    ptr1->data=data;
    ptr1->link=NULL;
    pos=pos-1;
    while(pos--){
        ptr = ptr->link;
    }
    ptr1->link = ptr->link;
    ptr->link = ptr1;
}

struct node* delete_first_node(struct node *head){
    struct node *temp = head;
    head = head->link;
    free(temp);
    temp=NULL;
    return head;
}

void delete_last_node(struct node *head){
    struct node *ptr = head;
    while(ptr->link->link!=NULL){
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link=NULL;
}

void delete_position_node(struct node **head, int pos){
    struct node *ptr = *head;
    struct node *ptr1 = *head;
    if(pos==1){
        *head=ptr->link;
        free(ptr);
        ptr = NULL;
    }else{
        while(pos--){
            ptr = ptr1;
            ptr1 = ptr1->link;
        }
        ptr->link = ptr1->link;
        free(ptr1);
        ptr1 = NULL;
    }
}

int search_node(struct node *head, int x){  
    struct node *ptr = head;
    int a=0;
    while (ptr != NULL)  
    { if (ptr->data == x){ 
            return a;
        }
        ptr = ptr->link;
        a++;
    }  
    return -1;  
}  

int length_list(struct node *head){
    struct node *ptr = head;
    int a=0;
    while(ptr!=NULL){
        a++;
        ptr = ptr->link;
    }
    return a;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data=2;
    head->link=NULL;
    cout << "First element in list :"<<endl;
    print_list(head);
    
    add_node(head, 1);
    cout << "Adding node at end :\n";
    print_list(head);
    
    head = add_node_begin(head, 50);
    cout << "Adding node at begin :\n";
    print_list(head);
    
    add_node_begin1(&head, 100);
    cout << "Adding node at begin1 :\n";
    print_list(head);
    
    add_node_position(head, 66, 3);
    cout << "Adding node at position 3 :\n";
    print_list(head);
    
    
    cout <<"Length of list is "<< length_list(head) << endl;
    
    cout << "Position of 100 in list is : "<< endl;
    int b = search_node(head, 100);
    if(b==-1){
        cout<<"Not present"<<endl;
    }else{
        cout<<b<<endl;
    }
    
    cout << "Position of 1000 in list is : "<< endl;
    b = search_node(head, 99);
    if(b==-1){
        cout<<"Not present"<<endl;
    }else{
        cout<<b<<endl;
    }
    
    head=delete_first_node(head);
    cout << "Deleting first node :\n";
    print_list(head);
    
    delete_last_node(head);
    cout << "Deleting last node :\n";
    print_list(head);
    
    delete_position_node(&head, 2);
    cout << "Deleting node at position 2 :\n";
    print_list(head);
    return 0;
}
