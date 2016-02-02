// Array Dynamic Allocation

int *ArrayDynamicAllocation(int array[], int size, int number)
{
    for (int i=0; i<=number; i++)
    {
        int *arr2 = new int[size*2];
        for(int i=0; i < size; i++)
        {
            arr2[i]= array[i];
            arr2[i+size] = array[i]*2;
        }
        size=size*2;
        delete []array;
        array = arr2;
    }
    return array;
}

 
//delete in array

int *arrayShift(int arr[],int length, int value)
{
	int newlength =0;
	for (int test = 0;test<length;test++)
    {
        if (arr[test] != value)
        {
            newlength++;
            
        }
    }
    
    int *arrr = new int[newlength];

    int p = 0;
    for (int i = 0;i<length;i++)
    {
        if (arr[i] != value)
        {
            arrr[p]=arr[i];
            p++;
        }
    }
    
    return arrr;
}

// a shit delete void

void arrayShift(int arr[],int length, int value)
{
	int newlength =0;
	for (int test = 0;test<length;test++)
    {
        if (arr[test] != value)
        {
            newlength++;
            
        }
    }
    
    int arrr[newlength];

    int p = 0;
    for (int i = 0;i<length;i++)
    {
        if (arr[i] != value)
        {
            arrr[p]=arr[i];
            p++;
        }
    }
    
    for (int replace =0; replace<newlength;replace++)
    {
        arr[replace] = arrr[replace];
    }
    
}


//most repeating

int maxRepeatingElement(int arr[], int length)
{
	int most;
    int number = 0;
    int temp = 0;
    int temp2 = 0;
    int a;
	for (int j = 0;j < length;j++)
    {
		if (number > temp2)  // temp2 is the biggest repeat time
		{
			temp2 = number;
		}

		number = 0;
        a= arr[j];
        
		for (int k = 0;k < length;k++)
        {
            if(arr[k]==a)
            {
                number++;
            }
        }
        if (number>temp)
        {
            most  = a ;
        }
        temp = number;
    }
    return most;
}

// second largest

int secondLargest(int arr[],int size)
{
    
    int current=-9999;
    int max=-9999;
    int newarr[size-1];
    
    for (int i = 0; i<size;i++)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
        }
    }
    
    int p = 0;
    for (int a = 0; a<size;a++)
    {
        if (arr[a] != max)
        {
            newarr[p++]= arr[a];
        }
    }
    for (int q = 0; q<size-1;q++)
    {
        if (newarr[q] >= current)
        {
            current = newarr[q];
        }
    }
    return current;
}



// bubbles

int final = 5; 
for(int index = 0; index < final; index++){  if(A[index] == 12){
 int temp = A[index];
 A[index] = A[index+1]; 
 A[index+1] = temp; 
} 
}


// change

int didXChange(int *x2){ 
 *x2= *x2 + 1;
 return *x2; 
} 
int main(){ 
 int b; 
 int *x = new int; 
 *x = 5; 
 b = didXChange(x); 
 
 
} 
The	value	of	*x	and	b	are	both	6.	

// array reverse

int *arrayReverse(int arr[],int length)
{
    int *arrr = new int[length];
    int p = length-1;
    for(int i=0; i<length;i++)
    {
        arrr[p] = arr[i];
        p--;
    }
    return arrr;
}

