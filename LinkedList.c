#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *first = NULL;
struct node *last = NULL;

//function prototypes :-
void insert(int);
int delete(int);
void print(void);
struct node *search(int);

int main(void)
{
    int num1,num2,choice;
    struct node *location;

    while(1)
    {
        printf("\n\nSelect an option\n");
        printf("\n1 - Insert");
        printf("\n2 - Delete");
        printf("\n3 - Search");
        printf("\n4 - Print");
        printf("\n5 - Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                printf("\nEnter the element to be inserted into the linked list:");
                scanf("%d",&num1);
                insert(num1);
                printf("\n%d Successfully inserted into the linked list!",num1);
                
                break;
            }

            case 2:
            {
                printf("\nEnter the element to be deleted from the linked list:");
                scanf("%d",&num1);
                num2 = delete(num1);
                if(num2==-9999)
                {
                    printf("\n\t%d is not present in the linkedlist\n\t",num1);
                }
                else
                {
                    printf("\n\tElement %d successfully deleted from the linked list\n\t",num2);
                }
                
                break;
            }

            case 3:
            {
                printf("\nEnter the element to be searched: ");
                scanf("%d",&num1);
                location = search(num1);
                if(location == NULL)
                {
                    printf("\n\t%d is not present in the linked list",num1);
                }
                else
                {
                    if(location == last)
                    {
                        printf("\n\tElement %d is the last element in the list",num1);
                    }
                    else
                    {
                        printf("\n\tElement %d is present before element %d in the linked list\n\t",num1,(location->next)->data);
                    }    
                }
                
                break;
            }
            
            case 4:
            {
                print(); 
            }

            case 5:
            {
                exit(1);
                break;
            }

            default:
            {
                printf("\nIncorrect choice. Please try again.");
                
                break;
            }
        }
    }
}

void insert(int value)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;
    
    if(first == NULL)
    {
        first = last = ptr;
        ptr->next = NULL;
    }
    else
    {
        last->next = ptr;
        ptr->next = NULL;
        last = ptr;
    }
}

int delete(int value)
{
    struct node *loc,*temp;
    int i;
    i = value;

    loc = search(i);

    if(loc == NULL)
    {
        return(-9999);
    }

    if(loc == first)
    {
        if(first == last)
        {
            first = last = NULL;
        }
        else
        {
            first = first->next;
        }
        return(value);
    }

    for(temp = first;temp->next!=loc;temp = temp->next)
    ;
    temp->next=loc->next;
    if(loc == last)
    {
        last = temp;
    }
    return(loc->data);
}


struct node *search(int value)
{
    struct node *ptr;

    if(first == NULL)
    {
        return(NULL);
    }

    for(ptr = first;ptr!=last;ptr = ptr->next)
    if(ptr->data==value)
    return(ptr);

    if(last->data==value)
    return(last);
    else
    return(NULL);
}


void print()
{
    struct node *ptr;
    if(first==NULL)
    {
        printf("\n\tEmpty List!!");
        return;
    }

    printf("\nLinked List elements:\n");
    if(first==last)
    {
        printf("\t%d",first->data);
        return;
    }

    for(ptr=first;ptr!=last;ptr=ptr->next)
    {
    printf("\t%d",ptr->data);
    }
    printf("\t%d",last->data);
}


