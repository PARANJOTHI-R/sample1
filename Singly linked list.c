#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node* node;
node create(int data){
    node temp=(node)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
node insertbeg(struct node**head,int data){
    node newnode=create(data);
    newnode->next=*head;
    *head=newnode;
    printf("\t\tSuccessfully inserted\n");
    return *head;
}
node insertend(struct node**head,int data){
    node newnode=create(data);
    struct node*temp=*head;
    if(*head==NULL){
        *head=newnode;
        printf("\t\tSuccessfully inserted\n");
        return *head;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    printf("\t\tSuccessfully inserted\n");
    return *head;
}
node insertpos(struct node**head,int pos,int data){
    node newnode=create(data);
    if(pos==1){
        newnode->next=*head;
        *head=newnode;
        printf("\t\tSuccessfully inserted\n");
        return *head;
    }
    node temp=*head;
    int i=1;
    while(temp!=NULL && i<pos-1){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("\t\tpos out of range\n");
        return 0;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    printf("\t\tSuccessfully inserted\n");
    return *head;
}
node delend(struct node**head){
    if (*head==NULL){
        printf("\t\tThe list is empty\n");
        return NULL;
    }
    node temp=*head;
    node prev=NULL;
    if (temp->next==NULL){
        *head=NULL;
        free(temp);
        printf("\t\tSuccessfully deleted\n");
        return NULL;
    }
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    printf("\t\tSuccessfully deleted\n");
    return *head;
}
node delbeg(struct node**head){
    if (*head==NULL){
        printf("\t\tList is empty\n");
        return NULL;
    }
    node temp=*head;
    /*if(temp->next==NULL){
        *head=NULL;
        free(temp);
        printf("\t\tSuccessfully deleted\n");
        return NULL;
    }*/
    *head=temp->next;
    free(temp);
    printf("\t\tSuccessfully deleted\n");
    return *head;
}
node delpos(struct node**head,int pos){
    if (*head==NULL){
        printf("\t\tList is empty\n");
        return NULL;
    }
    node delnode=*head;
    node prev=NULL;
    if(pos==1){
        *head=delnode->next;
        free(delnode);
        printf("\t\tSuccessfully deleted\n");
        return *head;
    }
    int i=1;
    while(delnode!=NULL && i<pos){
        prev=delnode;
        delnode=delnode->next;
        i++;
    }
    if (delnode == NULL) {
        printf("\t\tPosition out of bounds\n");
        return *head;
    }
    if(delnode->next==NULL){
        prev->next=NULL;
        free(delnode);
        printf("\t\tSuccessfully deleted\n");
        return *head;
    }
    prev->next=delnode->next;
    free(delnode);
    printf("\t\tSuccessfully deleted\n");
    return *head;
}
int search(struct node**head,int key){
    node temp=*head;
    if(*head==NULL){
        printf("\t\tThe list is empty\n");
        return 0;
    }
    int i=1;
    while(temp!=NULL){
        if (temp->data==key){
            return i;
        }
        temp=temp->next;
        i++;
    }
    return 0;
}
node print(node*head){
    struct node*temp=*head;
    printf("\tList after operation:  ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }printf("\n");
}
int main(){
    struct node*head=NULL;
    printf("Enter the operation:\n1.insertion\n2.deletion\n3.searching\n4.Exit\n");
    int op;
    while(1){
        printf("Option:");
        scanf("%d",&op);
        int out=0;
        switch(op){
            int sub;
            case 1:
                printf("\tTo insert:\n\t\t1.At position\n\t\t2.At beginning\n\t\t3.At end\n\t\t4.Exit\n");
                while(!out){
                    printf("\tOption:");
                    scanf("%d",&sub);
                    switch(sub){
                        case 1:{
                            int data=0,pos=0;
                            printf("\t\tEnter the position:");
                            scanf("%d",&pos);
                            printf("\t\tEnter the data:");
                            scanf("%d",&data);
                            insertpos(&head,pos,data);
                            print(&head);
                            break;}
                        case 2:{
                            int data=0;
                            printf("\t\tEnter the data:");
                            scanf("%d",&data);
                            insertbeg(&head,data);
                            print(&head);
                            break;}
                        case 3:{
                            int data=0;
                            printf("\t\tEnter the data:");
                            scanf("%d",&data);
                            insertend(&head,data);
                            print(&head);
                            break;}
                        case 4:
                            out=1;
                            break;
                        }
                    }
                break;
            case 2:
                printf("\tTo delete:\n\t\t1.At position\n\t\t2.At beginning\n\t\t3.At end\n\t\t4.Exit\n");
                while(!out){
                    printf("\toption:");
                    scanf("%d",&sub);
                switch(sub){
                    case 1:{
                        int pos;
                        printf("\t\tEnter the position:");
                        scanf("%d",&pos);
                        delpos(&head,pos);
                        print(&head);
                        break;
                    }
                    case 2:
                        delbeg(&head);
                        print(&head);
                        break;
                    case 3:
                        delend(&head);
                        print(&head);
                        break;
                    case 4:
                        out=1;
                        break;
                    }
                }
                break;
            case 3:{
                int key;
                printf("\tEnter the search element:");
                scanf("%d",&key);
                int ans=search(&head,key);
                if (ans!=0){
                    printf("\tElement found at %dth position\n",ans);
                }else{
                    printf("\tElement not found\n");
                }
                break;
            }
            case 4:{
                exit(0);
                break;}
        }
    }
    return 0;
}