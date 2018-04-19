#include<iostream>
using namespace std;

class maxheap{
public:
int arr[100];
int size=0;

int insert (int key)
{ //enters value in the last position
  arr[size]=key;
  int i=size;
//checks weather the element is bigger than its parent and swaps  
while (arr[i]>arr[(i-1)/2])
   {int temp=0;
    temp=arr[i];
    arr[i]=arr[(i-1)/2];
    arr[(i-1)/2]=temp;
    //shifts to new position of the new element
    i=(i-1)/2;
   }
//size increases by one
size++;
}


void delroot ()
{int temp=0;
 int c;//c will store the value position of the child
arr[0]=arr[size-1];//copied the last element to the position required
 size--;//size decreased by one
 int i=0;//i variable moves down the heap swapping the elements and repositioning
 while((2*i+1)<size)//if the left child exists, otherwise there are no children
  {if((2*i+2)>=size)//if the right child does not exist, there is just one child
    {if(arr[i]<arr[(2*i+1)])//swaps if the child is bigger
      {
       c=2*i+1;
       temp=arr[i];
       arr[i]=arr[c];
       arr[c]=temp;
       i=c;//repositions
       }
      else
      {break;}
     }
   else//when there are two children
     {if(arr[2*i+1]>arr[2*i+2])//checks which one is bigger and stores in c
       c=2*i+1;
      else
       c=2*i+2;
      if(arr[i]<arr[c])//if the bigger child is bigger than the parent, swaps
       {temp=arr[i];
        arr[i]=arr[c];
        arr[c]=temp;
        i=c;//repositions
       }
      else       
      {break;
}}
   }
cout<<"Deletion complete \n"; 
}

void display()
{cout<<"//";
for(int i=0;i<size;i++)
 {cout<<arr[i]<<"  ";}
  cout<<"//\n";
}
};

int main()
{maxheap m;
cout<<"\nMENU";
 cout<<"\n1.INSERT";
 cout<<"\n2.DELETE ROOT";
 cout<<"\n3.DISPLAY";
 cout<<"\n4.SIZE\n5.EXIT";
int ch,x;
do{
  cout<<"\nEnter your choice (1-5): ";
  cin>>ch;
switch(ch){
case 1: cout<<"Enter the element you want to insert:\n";
        cin>>x;
        m.insert(x);break;
case 2: cout<<"Deleting root\n";
        m.delroot();break;
case 3: m.display();break;
case 4: cout<<"\n The size is "<<m.size;break;
case 5:break;
 default:cout<<"Enter a valid choice \n";break;
}
}while(ch!=5);
return 0;
}
