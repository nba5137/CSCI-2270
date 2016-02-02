Cost for Algorithms: Number of instructions for different input sizes and values.
General relationship between input and instructions.
General relationship: algorithm’s complexity.
Example 1: Write an algorithm to determine the index of a specified value in an array.
Pseudocode: findItem(A,v) //A is the array, v is the value
index = -1                  1
for i = 1 to A.length   4
if A[i] == v                  4
index = i                     2
return index                1
Final cost of: 12
Pseudocode conventions:
	Not concerned about types
	Indexing starts at 1.
Assume every line has a cost of 1
What is cost of A = <45, 34, 32, 34>
findItem(A,34)
A= <45, 34, 32, 34, 56, 23, 12>
findItem(A, 34)
Takeaway: Size of the for loop matters the most
index = -1 = constant
What input pattern of A will be worst case (most expensive).
All elements are what you’re looking for
Pseudocode
findItem(A,v)
index = -1               1
for i=1 to A.length    11
if A[i] == v                 11
return i                       1        
return index               /6
A=<45,34,32,34>
findItem(A,34)
What is the worst case input? Item not found 

Example 2: Write alg that finds a specified value in an array, removes by shifting array to fill empty spot.
<54, 34, 45, 23, 90, 91> Remove 45
<54, 34, 23, 90, 91, 0>
removeItem(A,v)
for i=1 to A.length
if A[i] == v
for i = i to A.length -1
A[i] = A[A+1]
A[length] = 0
return A

Lecture 1/16/15
Each iteration = 1
Each line has its own cost, cost depends on technology, language.
Lang. independent, technology independent.
Suppose we have inventory system.
10000ms to read initial data, 10ms for each line in file.
Process n transactions in 10000 + 10n ms
Big-oh notation
How do 2 functions grow as n → infinity
let n be the size of programs input, can be words, ints, bits.
T(n) be a function that represents alg. precise running time for given input of size n
Let f(n) be a simple growth function, f(n) = n.
Can express growth rate of T(n) by relating to another function.
If T(n) is growing no faster than f(n), then we say T(n) is in O(f{n))
or T(n) is in O(n)
if and only if 
T(n) <= c * f(n), c is constant whenever n is big, for some large c.
Inventory:
T(n) = 10000+10n
f(n) = n
T(n) <= c*f(n), as n → infinity.
20n f(n) * 20 (in powerpoint)
10000 + 10n = T(n)
T(n) will grow faster than c*f(n)
Large n, startup cost may be worth
Otherwise, less efficient algorithm may be better.
Going from cost to Big-oh notation T(n). We care about what grows the fastest.
T(n) we care about the fastest T(n) = 5n^3 + 3n^2 + n + %
IF mult terms, keep term with the largest growth rate, 5n^3
Discard constants.

1/21/2015
Dynamic memory allocation - Read from file, don’t know size.
Stack - local  variables, memory management done for you. 
Heap - large pool of memory, dynamically allocated variables go.

1/23/2015
Bit is 1 at position, include that value in value of byte.
128 64 32 16 8 4 0 2 1
2^7 2^62^52^42^32^22^1
Hexadecimal: Base 16 number system
0-9
A = 10
B= 11
C = 12
D = 13
E = 14
F = 15
	
8   4   2   1  8  4  2  1
1   1   1   1  1  1  1  1

128  64  32  16  8  4  2  1
  1    1    1    1    1  1  1  1
128 + 64 + 32 + 16 + 8 + 4 + 2 + 1 = 255

int i = 1000;
With hex, there are 9 more terms^
32768  16384  8192  4096  2048  1024  512  256  128  64  32  16  8  4  2  1
                       A                 l                         9         l           6           l        D
int: 4 bytes
Char: 1 byte
float: 4 bytes
double: 8 bytes

Addr            Value
OxFFo3       
OxFF03     o5
OxFF02     A2
OxFF01     Ac
OxFF00     AA

What is 011011100111 in hex?
	     6	  E    7
#include <iostream>
using namespace std;
struct item{
string name;
int price;
bool forSale;

int main()
{
	//pointers
	int *a = new int[5];
	//free memory
	delete []a;
	int b = 5; // not a point
	int *ptrB = &b;
	cout << “address of b: “ << &b << endl;
	cout << “what ptrB points to: “ << ptrB << endl;
cout < “value that ptrB points to: “ << *ptrB << endl;
b = 10;
cout << “value that ptrB points to: “ << *ptrB << endl;
item myItem;
myItem.forSale = true;
myItem.name = “chicken”;
myItem.price = 10;
item *ptrItem = &myItem
cout << ptrItem -> price << endl;
cout << (*ptrItem).price << endl;
changeStructValue(ptrItem);
cout << ptrItem -> price << endl;
//cout << “hello world” << endl;
return 0;
}

Midterm code:
	void deleteNode(TreeNode *node, int key)
{
    TreeNode*toDelete = node;
    TreeNode*replacement;
    while(toDelete->key != key)
    {
        if(key < toDelete->key)
        {
            toDelete = toDelete->left;
        }
        else if(key > toDelete->key)
        {
            toDelete = toDelete->right;
        }
    }
    toDelete = toDelete->left;
    if(toDelete->right != NULL && toDelete->left != NULL)
    {
        replacement = node->left;
        while(replacement->right != NULL)
        {
            replacement = replacement->right;
        }
        toDelete->key = replacement->key;
        if(replacement->left != NULL)
        {
            replacement->parent->right = replacement->left;
            replacement->left->parent = replacement->parent;
        }
        else replacement->parent->right = NULL;
        delete replacement;
    }
    else
    {
        if(toDelete->parent->right == toDelete)
        {
            toDelete->parent->right = NULL;
            delete toDelete;
        }
        else
        {
            toDelete->parent->left = NULL;
            delete toDelete;
        }
    }

}

Code:

void deleteNode(TreeNode *node, int key)
{
    while(node->key != key)
    {
        if(node->key < key)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
    TreeNode * leftTree = node->left;
    while(leftTree->right != NULL)
    {
        leftTree = leftTree->right;
    }
    if(node->parent->right == node)
    {
        node->parent->right = leftTree;
    }
    else{
        node->parent->left = leftTree;
    }
    leftTree->right = node->right;
    if(leftTree->left != NULL)
    {
        leftTree->parent->right = leftTree->left;
    }
    if(node->left != leftTree)
    {
        leftTree->left = node->left;
        leftTree->parent->right = NULL;
        leftTree->parent = node->parent;
    }
    else
    {
        leftTree->parent = node->parent;
    }
    delete node;
}
