// linked list insert with positon
void LinkedListInsert(node *head, node *newNode, int position)
{
   
    for (int i = 1; i<position;i++)
    {
        newNode->next = head->next->next; 
        head=head->next;
    }

    head->next = newNode;

}


// linked list Nth node

int LinkedListNthNode(node *head, int position)
{
    int val;
    if (position ==0)
    {
        val = head->value;
        
    }
    else
    {
        for (int i = 0;i<position;i++)
        {
            head = head->next;
            val = head->value;
        }
    }
    return val;
}

 

// reverse linked list

node *ReverseLinkedList(node *head)
{
    node *temp = NULL;
    node *next = head;
    while(next != NULL)
    {
        next = head->next;
        head->next = temp;
        temp = head;
        head = next;
    }
    return temp;
}

// delete nodes

node *DeleteNode(node *head, int value)
{
    node *current=new node;
    while(head->value ==value)
    {\
    head = head->next;
    }
    current = head;
    while(current->next!=NULL)
    {
        if(current->value == value)
        {current->prev->next=current-> next;
        current->next->prev = current->prev;}
        current=current->next;
    
    
    }
    
    if(current->value==value){current->prev->next=NULL;}
    return head;
}

// linked list count
int LinkedListCount(node *head,int val)
{
    node *x = head;
    int *times = new int;
    int time = 0;
    while (x != NULL)
    {
        if(x->value == val)
        {
            time=time+1;
        }
        
    x = x->next;
    }

    *times = time;
    return *times;
}

// linked list find max

int LinkedListFindMax(node *head)
{
    int max = head->value;
    while (head != NULL)
    {
        if (head->value >= max)
        {
            max = head->value;
        }
        head = head->next;
    }
    return max;
}


// insert to center

void insertNode(node *head, int value)
{
    int num = 1;
    node *a = new node;
    a->value = value;
    while (head->next != NULL)
    {
        head = head->next;
        num = num + 1;
    }
    for (int i = 0; i < num-1;i++)
    {
        head = head->prev;
    }
    for(int o = 0; o<num/2-1;o++)
    {
        head = head->next;
    }
    a->next = head->next;
    head->next = a;
    a->prev = head;
}



////////////////


The function is a member of a class called Queue. Write the function definition only for enqueue. Given below is the class definition: 



struct node

{

    int value;

    node *next;

};



class Queue

{

    public:

        Queue(node *, node *);

        virtual ~Queue();

        void enqueue(node *newNode); 

        void displayQueue();

    protected:

    private:

        node *head;

        node *tail;

};

void Queue::enqueue(node *newNode)
{		
		tail->next = newNode;
        tail = tial->next;
        tail->next = NULL;
}

/////////////////////

Write a C++ function to remove all occurrences of a specified value from an array. Function should take three arguments, the array, the array length and the value being searched for. Each time the value is found, the array should be shifted to remove that value.



void arrayShift(int arr[],int length,int value);

For example:
