/*

O->A->B->D->T

O->A->B->E->D->T

O->C->E->D->T


Are	there	any	vertices	in	the	graph	that	won’t	be	marked	solved	before	T	is	solved?	
	
F	won’t	be	marked	as	solved.	There	is	never	an	iteration	of	the	algorithm	where	the	
path	O->A->F	is	the	shortest	distance.	


(G,0),	(B,1),	(E,1),	(A,2),	(F,2),	(H,2)	


6.	In	Question	2,	you	calculated	the	shortest	path	from	O	to	T	in	this	weighted	graph.	
Is	the	shortest	path	the	same	if	the	graph	were	unweighted?	
		
There	are	several	shortest	paths	in	the	unweighted	graph.	We	count	each	edge	as	a	
weight	of	1,	making	the	shortest	path	the	one	with	the	fewest	number	of	edges.	The	
paths:	
O-A-F-T	
O-B-E-T	
O-C-E-T	
O-B-D-T	
	
are	all	equivalent.	



*/

// Peng
/*

1. O A B C D E T
2. O A B D T 13
   O A D T 13
3. fewer in hashtable 
   because the time complexity of hastable is 1, and the time complexity of linked list is n, so hashtable require fewer 

*/

// 
[5,9,1,4,3,2,0] //origin

[5,9,9,4,3,2,0] 

[5,5,9,4,3,2,0]

[1,5,9,9,3,2,0]

[1,5,5,9,3,2,0]


// insertion sort

void insertion(int arr[],int length)
{
	int i;
	int key;
	for (int j = 1; j < length;j++)
	{
		key = arr[j];
		i = j-1;
		while(i >=0 && arr[i] >key)
		{
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=key;
		for (int aa = 0; aa< length;aa++)
		{
			cout << arr[aa] << " ";
		}
		cout << endl;
	}
}


// bubble sort

voidbubble_sort(inta[],intn)//n为数组a的元素个数
{
    inti,j,temp;
    for(j=0;j<n-1;j++)
        for(i=0;i<n-1-j;i++)
        {
            if(a[i]>a[i+1])//数组元素大小按升序排列
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
}


// quick sort

//1）设置两个变量i、j，排序开始的时候：i=0，j=N-1；
//2）以第一个数组元素作为关键数据，赋值给key，即key=A[0]；
//3）从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的值A[j]，将A[j]和A[i]互换；
//4）从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的A[i]，将A[i]和A[j]互换；
//5）重复第3、4步，直到i=j； (3,4步中，没找到符合条件的值，即3中A[j]不小于key,4中A[i]不大于key的时候改变j、i的值，使得j=j-1，i=i+1，直至找到为止。找到符合条件的值，进行交换的时候i，
// j指针位置不变。另外，i==j这一过程一定正好是i+或j-完成的时候，此时令循环结束）。

void sort(int *a, int left, int right)
{
    if(left >= right)/*如果左边的数组大于或者等于就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
     
    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
        /*而寻找结束的条件就是，1，找到一个小余或者大于key的数（大小取决于你想升
        序还是降序）2，没有符合的切i与j相遇*/ 
        {
            j--;/*向前寻找*/
        }
         
        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        a[0]，那么就是给key）*/
         
        while(i < j && key >= a[i])
        /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
        因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }
         
        a[j] = a[i];
    }
     
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
                       /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}



// recitation 8
// The function takes a starting vertex as the parameter. Whenever a vertex is enqueued, print the vertex.

void Graph::BFTraversal(string startingCity) {
    queue<vertex*> bfq;
    vertex v;
    int i = 0;
    for(i=0; i<vertices.size();i++) {
        if (startingCity==vertices[i].name) {
            v = vertices[i];
            break;
        }
    }
    cout<<v.name<<endl;
    vertices[i].visited = true;
    bfq.push(&vertices[i]);
    
    while (!bfq.empty()) {
        v = *bfq.front();
        bfq.pop();
        for(i=0;i<v.adj.size();i++) {
            if (v.adj[i].v->visited==false) {
                v.adj[i].v->visited = true;
                bfq.push(v.adj[i].v);
                cout<<v.adj[i].v->name<<endl;
            }
        }
    }
}

// recitaion 9  Dijkstra 

void Graph::Dijkstra(string starting, string destination) {
    
        vector<vertex*> solved;
    vertex *start, *dest;
    for(int i=0; i<vertices.size();i++) {
                vertices[i].visited = false;
                vertices[i].previous = NULL;
                vertices[i].distance = INT_MAX;
        if (starting == vertices[i].name) {
            start = &vertices[i];
        }
                if (destination == vertices[i].name) {
            dest = &vertices[i];
        }


    }
    start->visited = true;
        start->distance = 0;
    solved.push_back(start);
    
    while (!dest->visited) {
                int minDistance = INT_MAX;
                vertex *minVertex, *prevVertex;
        for(int i = 0; i<solved.size(); i++)
                {
                        vertex *u = solved[i];
                        for(int j=0; j<u->adj.size(); j++) {
                                if (!u->adj[j].v->visited) {
                                        int distance = u->distance + u->adj[j].weight;
                                        if(minDistance > distance )
                                        {
                                                minDistance = distance;
                                                minVertex = u->adj[j].v;
                                                prevVertex = u;
                                        }
                                }
                        }
                }
                solved.push_back(minVertex);
                minVertex->distance = minDistance;
                minVertex->previous = prevVertex;
                minVertex->visited = true;
        }
        vector <string> path;
        vertex *temp = dest;
        cout<<"Shortest Path"<<endl;
        while(temp!= NULL)
        {
                path.push_back(temp->name);
                temp = temp->previous;
        }
        for(int i = path.size() - 1; i>=0; i--)
        {
                cout<<path[i];
                if(i!=0)
                cout<<" - ";
        }
        cout<<endl<<"Minimum Distance: "<<dest->distance<<endl;
}




// recitation 11    findMisplacedMovies

void HashTable::findMisplacedMovies() 
{ 
for (int i = 0; i < tableSize; i++) 
{ 
if (hashTable[i] != NULL) 
{ 
Movie *temp = hashTable[i]; 
while(temp!=NULL) 
{ 
int index = hashSum(temp­>title,tableSize); 
if(index!=i) 
cout<<temp­>title<<":"<<i<<":"<<index<<endl; 
temp = temp­>next; 
} 
} 
} 
 
}

// or or or or or

void HashTable::findMisplacedMovies()
{
    
    for(int i = 0; i<10; i++)
    {
    if(hashTable[i] == NULL)
    {
        break;
    }
    while(hashTable[i]->next != NULL)
    {
        if(hashSum(hashTable[i]->title, 10) != i)
        {
            cout << hashTable[i]->title << ":" << i << ":"<< hashSum(hashTable[i]->title, 10) << endl;
        }
        hashTable[i] = hashTable[i]->next;
        
    }
      if(hashSum(hashTable[i]->title, 10) != i)
        {
            cout << hashTable[i]->title << ":" << i << ":"<< hashSum(hashTable[i]->title, 10) << endl;
        }
    }
}

 
/////////////////////////////////////////////////////////////////////////  colorVertices

void Graph::colorVertices(string source) 
{ 
int i=0; 
//find the vertex index 
for(i = 0; i < vertices.size(); i++){ 
        if(vertices[i].name == source){ 
          break; 
        } 
    } 
queue<vertex *> queue; 
//enqueue the vertex 
vertices[i].visited = true; 
vertices[i].color = "Red"; 
queue.push(&vertices[i]); 
while(!queue.empty()) 
{ 
//dequeue 
vertex *curr = queue.front(); 
queue.pop(); 
//enqueue all unvisisted neighbors 
for(int j = 0; j < curr­>adj.size(); j++){ 
if(!curr­>adj[j].v­>visited) 
{ curr­>adj[j].v­>visited = true; 
if(curr­>color == "Red") 
curr­>adj[j].v­>color = "Black"; 
else 
curr­>adj[j].v­>color = "Red"; 
queue.push(curr­>adj[j].v); 
} 
} 
} 
} 

//////or or or

void Graph::colorVertices(string sourceVertex)
{
    for(int i=0; i<vertices.size();i++) 
    {
        vertices[i].visited = false;
        if ("O" == vertices[i].name) 
        {
            vertices[i].color = "Red";
        }
	}
}

////////////////////////////////////////////////////////////////  countBFTraversal

void Graph::countBFTraversal() 
{ 
int count = 0; 
 for(int i = 0; i<vertices.size(); i++) 
 { 
if(!vertices[i].visited) 
{ 
BFTraversal(i); 
++count; 
} 
 } 
 cout<<count<<endl; 
} 
 
/////////////////////////////////////////////////////////// ifPathExists

bool Graph::ifPathExists(string v1, string v2){ 
    vertex *start = NULL; 
    vertex *dest = NULL; 
    for (int i=0; i<vertices.size(); i++){ 
        vertices[i].visited=false; 
        if (vertices[i].name == v1){ 
            start=&vertices[i]; 
        } 
        if (vertices[i].name == v2){ 
            dest=&vertices[i]; 
        } 
    } 
   start­>visited = true; 
   vertex *u; 
   queue<vertex*> theQueue; 
   theQueue.push(start); 
   while(!theQueue.empty()){ 
       u=theQueue.front(); 
       theQueue.pop(); 
       for (int i=0; i<u­>adj.size(); i++){ 
           if (u­>adj[i].v­>visited == false){ 
               u­>adj[i].v­>visited = true; 
               if (u­>adj[i].v­>name == dest­>name){ 
                   return true; 
               } 
               theQueue.push(u­>adj[i].v); 
           } 
       }   }
 return false; 
} 



// path existed

bool Graph::pathExisted(string path[]; int length)
{
	queue<vertex*> q;
	int count;
	for (int i = 0; i<vertices.size();i++)
	{
		vertices[i].visited = false;
	}
	for (int i = 0; i<vertices.size();i++)
	{
		if (vertices[i].name == path[0])
		{
			vertices[i].visited = true;
			q.push(&vertices[i]);
		}
	}
	count++;
	while (q.empty() != true)
	{
		vertex* u = q.front();
		q.pop();
		for(int i =0;i<u->adj.size();i++)
		{
			if (u->adj[i].v->visited == false && u->adj[i].v->name == path[count])
			{
				u->adj[i].v->visited = true;
				q.push(u->adj[i].v);
				count++;
			}
		}
	}
	if(vertices[length-1].visited == false)
	{
		return false;
	}
	else return true;
		
}


// hash table

// sum

int hashSum(string x, int s) //x is the string to hash, s is the array size
{    
	int sum = 0;
    for (int i = 0; i< x.size();i++)
        {sum =sum + x[i];}  //ascii value of ith character in the string
    //sum = sum % s;
    cout << sum << endl;
    return sum;
}


//

4.	Calculate	the	hash	code	for	The	Usual	Suspects	using	the	Multiplication	method	
given	in	the	lecture	notes.	(On	an	exam,	we’ll	give	you	the	ascii	table.)Use	A	=	13/32,	
and	m	=	1024.	
	
The	sum	of	the	ascii	values	for	The	Usual	Suspects	is	1733.	
1733	*	(13/32)	=	704.03125	
.03125	*	1024	=	32.	
The	hash	code	is	32.	
	
5.	Using	the	same	hash	function,	determine	if	The	Usual	Suspects	and	Zoolander	
produce	a	collision?	Explain	your	answer,	providing	the	hash	codes	for	each	movie	
title.	
	
The	sum	of	ascii	values	for	Zoolander	is	942.	
942	*	(13./32.)	=	382.6875	
.6875	*	1024	=	704.	
The	hash	code	is	704.	Since	the	two	movies	have	different	hash	codes,	there	is	not	a	
collision.	
	
