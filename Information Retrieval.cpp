#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<windows.h>
#include<stdlib.h>
#include<cctype>
#include<conio.h>
#include<cstdio>
#include<bits/stdc++.h> 
using namespace std;

int siz;
string mycount[5];
int b=0;
bool isfound=false;
int result1[25]= {0} ;
int countingarrayresult=0;
 
void printIntersection(int arr1[], int arr2[], int m, int n)    // AND operator 
{ 
int i = 0, j = 0; 
bool isfound=false;

cout<<endl<<"Document Number in which your query is : ";
while (i < m && j < n) 
{ 
	
	if (arr1[i] < arr2[j]) 
	{
		i++;
	}
	 
	else if (arr2[j] < arr1[i])
	{
		j++;
	} 
	 
	else   
	{ 
		isfound=true;
		cout << arr2[j] << " "; 
		i++; 
		j++; 
	} 
}
	if(isfound==false)
	{
		cout<<"\nERROR ! No Document Match the Query Searched !! "<<endl;
	}
} 

void printnotIntersection(int arr1[], int arr2[], int m, int n)    //  AND NOT operator
{ 
int i = 0, j = 0; 
bool isfound=false;
cout<<endl<<"Document Number in which your query is : ";
while (i < m && j < n) 
{ 
	if (arr1[i] < arr2[j]) 
	{
		isfound=true;
		cout << arr1[i] << " "; 
		i++; 
	}
	else if (arr2[j] < arr1[i]) 
	{
		isfound=true;
		cout << arr2[j] << " "; 
		j++; 
	}
	else 
	{ 
		i++; 
		j++; 
	} 
}
	while(i<m)
	{
		cout<< arr1[i]<<" ";
		i++;
	}
	if(isfound==false)
	{
	
		cout<<"\nERROR ! No Document Match the Query Searched !! "<<endl;
	}
} 

void removeDuplicates(int arr[], int n) 
{ 
	int i; 
	set<int> s; 
	for (i = 0; i < n; i++) 
	{ 
		s.insert(arr[i]); 
	} 

	set<int>::iterator it;  
	for (it = s.begin(); it != s.end(); ++it) 
	{
		cout << *it << " ";
	}
	cout << "\n"; 
} 

void splitting(string str)
{
	string word = "";
	for (auto x : str)   //for whichever length of str
	{
		if(x == ' ')
		{
			mycount[b]=word;
			b++;
			word = "";
			
		}
		else
		{
		
			word = word + x;
		}
	}
	if(b>4)      // more than 4 words
	{
		cout<<"Error Incorrect Query Try again! in 5 seconds !";
		Sleep(5000);
		exit(0);
	}
	mycount[b]=word;  
	
}

class node
{
	public:
		string data;
		node *next;
		int frequencies;
		int docid;
		int post_curr= 0;
		int posting_list[5]={0};
		
		node()
		{
			data = " ";
			next = NULL;
		}
		
		node(string d,int doc, node *n)
		{
			data = d;
			next = n;
			docid =doc;
		}
		
		node(string d)
		{
			data = d;
			next = NULL;
		}
		
		node (string d, int doc)
		{
			data = d;
			docid = doc;
			next = NULL;
		}
		
};

class linklist
{
	public:
		node *head;
		node *tail;
		
		linklist ()
		{
			head = NULL;
			tail = NULL;
		}
		
		void insertion(string dat, int id)
		{
			node *n2;
			if (head == NULL)
			{
				head = new node(dat,id,NULL);
				tail=head;
			}
			else
			{
				node *n2 = new node(dat,id,NULL);
				tail->next = n2;
				tail = n2;
			}
		}
		
		int nodeSize( )
        {
            int count = 1;
            node* temp = head;
            while(temp->next != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
        
		int occurence(string *s1)    
		{                                       
			node *current = head;               
			int count = 0, i;
			
			while (current!=NULL)
			{
				if(current->data == *s1)
				{
					count++;
					current = current->next;
				}
				else
				{
					current = current->next;
				}
			}
			return count;			
		}  
		
	    void swap(int i, int j)
        {
            if( head == NULL )
            {
                cout << "List is empty." <<endl;
                return;
            }
            else if( i > this->nodeSize() || j > this->nodeSize() || i <= 0 || j <= 0 )
            {
                cout << "Invalid node requested." << endl;
                return;
            }
            else if( i == j )
            {
               return;
            }
            else        //go to (n-1)th node
            {
                if(j == 1)
                {
                    j = i;
                    i = 1;
                }
                if(i == 1 ) //if i is the headnode
                {
                    if( j == 2) // head w/ next
                    {
                        node* temp = head;
                        node* homeJ = head->next;
                        node* nextJ = homeJ->next;
                        
                        head = homeJ;
                        head->next = temp;
                        head->next->next = nextJ;

                    }
                    else        //head w/ n
                    {
                        int count = 1;
                        node* prevJ = head; 
                        node* homeJ;
                        while(count != j-1)
                        {
                            prevJ = prevJ->next;
                            count++;
                        }
                        homeJ = prevJ->next;
                        //now swap 
                        node* temp;
                        node* tempNext;

                        temp = homeJ->next;
                        tempNext = head->next;

                        prevJ->next = head;
                        prevJ->next->next = temp;

                        head = homeJ;
                        homeJ->next = tempNext;
                    }
                }
                else // swap n
                {
                    if( j < i) // ensure that j is always greater than i
                    {
                        int t;
                        t = j;
                        j = i;
                        i = t;
                    }
                    int count = 1;
                    node* prevI = head;
                    while(count < i-1) 
                    {
                        prevI = prevI->next;
                        count++;
                    }
                    count = 1;
                    node* prevJ = head;
                    while(count != j-1)
                    {
                        prevJ = prevJ->next;
                        count++;
                    }
                    if( j == i +1 ) //swap n w/ n+1
                    {
                        node* homeI = prevI->next;              //homeI == prevJ. remember.
                        node* homeJ = homeI->next;              //store j
                        node* nextJ = homeJ->next;              //store j next 
                        
                        prevI->next = homeJ;                    //i j swap
                        homeJ->next = homeI;
                        homeJ->next->next = nextJ;
                    }
                    else            //swap n with N                    
                    {
                        node* homeI = prevI->next;
                        node* nextI = homeI->next;

                        node* homeJ = prevJ->next;
                        node* nextJ = homeJ->next;

                        prevI->next = homeJ;
                        prevI->next->next = nextI;

                        prevJ->next = homeI;
                        prevJ->next->next = nextJ;   
                    }
                }
                
            }
        }
		void bubblesort()
        {
            node* tempI = head;
            node* tempJ, *temp;
            int i = 1, j ;
            while(tempI != NULL)
            {
                tempJ = tempI->next;
                j = i+1;
                while(tempJ != NULL)
                {
                    if(tempI->data  > tempJ->data)
                    {
                        this->swap(i,j);
                        temp = tempI;
                        tempI = tempJ;
                        tempJ = temp;
                    }
                    j++;
                    tempJ = tempJ->next;
                }
                tempI = tempI->next;
                i++;
            }
        }
        
		void display()
		{
			node *temp = head;
			while(temp != NULL)
			{
			
				cout<<temp->data<<setw(15-temp->data.length())<<temp->docid<<endl;
				temp = temp->next;
			}
		}
		
		void searchinlist(string d)
		{
			isfound=false;
			node *temp = head;
			while (temp!= NULL && isfound==false)
			{
				if (temp->data == d)
				{
					isfound =true;
					for (int x =0 ; x<5; x++)    // 5 docs
				    {
						if(temp->posting_list[x]!=0)
						{
							result1[countingarrayresult]=temp->posting_list[x];
							countingarrayresult++;
						}
			     	}
				}
					temp = temp->next;
			}
			
		}
		
		void display2()
		{
			node *temp = head;
			while(temp != NULL)
			{
				cout<<temp->data<<setw(15-temp->data.length())<<temp->frequencies<<setw(4);
				if(temp->posting_list[0]!=0)
				{
					cout<<" "<<temp->posting_list[0];
				}
				if (temp->posting_list[1]!=0 )
				{
					cout<<" "<<temp->posting_list[1];
				}
				if (temp->posting_list[2]!=0)
				{
					cout<<" "<<temp->posting_list[2];
				}
				if (temp->posting_list[3]!=0)
				{
					cout<<" "<<temp->posting_list[3];
				}
				if (temp->posting_list[4]!=0)
				{
					cout<<" "<<temp->posting_list[4];
				}
				cout<<endl;
				temp = temp->next;
			}
		}
};

int main()
{
	linklist l1;
	cout.flush();
	fstream doc1,doc2,doc3,doc4,doc5;
	string ch1, ch2;
	string searchstring;

	doc1.open("doc1.txt");
	doc2.open("doc2.txt");
	doc3.open("doc3.txt");
	doc4.open("doc4.txt");
	doc5.open("doc5.txt");
	while(!doc1.eof() || !doc2.eof() || !doc3.eof() || !doc4.eof() || !doc5.eof())
	{
		if(!doc1.eof())
		{
			doc1>>ch1;
			transform(ch1.begin(), ch1.end(), ch1.begin(), ::tolower); 
			ch1.erase(remove_if(ch1.begin(), ch1.end(), [](char c) { return !isalnum(c); } ), ch1.end());
		    l1.insertion(ch1,1);
		}
		else if (!doc2.eof())
		{
			doc2>>ch1;
			transform(ch1.begin(), ch1.end(), ch1.begin(), ::tolower); 
			ch1.erase(remove_if(ch1.begin(), ch1.end(), [](char c) { return !isalnum(c); } ), ch1.end());
			l1.insertion(ch1,2);
		}
		else if (!doc3.eof())
		{
			doc3>>ch1;
			transform(ch1.begin(), ch1.end(), ch1.begin(), ::tolower); 
			ch1.erase(remove_if(ch1.begin(), ch1.end(), [](char c) { return !isalnum(c); } ), ch1.end());
			l1.insertion(ch1,3);
		}
		else if (!doc4.eof())
		{
			doc4>>ch1;
			transform(ch1.begin(), ch1.end(), ch1.begin(), ::tolower); 
			ch1.erase(remove_if(ch1.begin(), ch1.end(), [](char c) { return !isalnum(c); } ), ch1.end());
			l1.insertion(ch1,4);
		}
		else
		{
			doc5>>ch1;
			transform(ch1.begin(), ch1.end(), ch1.begin(), ::tolower); 
			ch1.erase(remove_if(ch1.begin(), ch1.end(), [](char c) { return !isalnum(c); } ), ch1.end());
			l1.insertion(ch1,5);
		}
	}
	cout<<"Dictionary"<<setw(6)<<"Freq"<<setw(10)<<"Postings"<<endl<<endl;
	l1.bubblesort();	
	
	linklist l2;
	string previous ="";
	node *temp = l1.head;
			while(temp != NULL)
			{
				if(previous==temp->data)
				{
					l2.tail->posting_list[temp->docid-1] = temp->docid; 
					l2.tail->post_curr+=1;
				}
				else
				{
					l2.insertion(temp->data,temp->docid);
					l2.tail->posting_list[temp->docid-1]=temp->docid; 
					l2.tail->post_curr+=1;
				}
	
			previous=temp->data;
			temp=temp->next;
			}

			node *temp3 = l2.head;
			int freq1=0;
			while(temp3 != NULL)
			{
				freq1=0;
				if(temp3->posting_list[0]!=0)
				{
					freq1++;
				}
				
				if(temp3->posting_list[1]!=0)
				{
					freq1++;
				}
				if(temp3->posting_list [2]!= 0 )
				{
					freq1++;
				}
				if (temp3->posting_list [3] != 0)
				{
					freq1++;
				}
				if (temp3->posting_list [4] != 0)
				{
					freq1++;
				}
				
				temp3->frequencies=freq1;
				temp3=temp3->next;
			}			
		
			
			l2.display2();
{
		
	system("color 3E");
	cout<<"\n---------------------------------------------------------------------------";
	cout<<"\n---------------------------------------------------------------------------";
	cout<<"\n                               	ONAMA                                   ";
	cout<<"\n---------------------------------------------------------------------------";
	cout<<"\n---------------------------------------------------------------------------";
	cout<<"\n";
}

	cout<<"Examples of Search query: "<<endl;
	cout<<"Apple AND Guava  // Apple OR Guava  //   Apple AND NOT Guava  // Guava"<<endl<<endl;
	cout<<"\nEnter your search query{Maximum 2 Words Connected by (AND)/(OR)/(NOT)  }: "<<endl;
	getline(cin, searchstring);
	transform(searchstring.begin(), searchstring.end(), searchstring.begin(), ::tolower);
	cout<<endl;

 	if(searchstring.length() > 25)
 	{
		cout<<"Error Incorrect Query Try again! in 5 seconds !";
		Sleep(5000);
		exit(0);
	}
	 
 	splitting(searchstring);
 	
int size1=0;
int size2=0;
int variablecount;
int word3[10];
bool yesfound = false;

if (b == 0 )
{
	node *temp = l2.head;
	while(temp != NULL)
	{
		if(temp->data == mycount[0])
		{
			yesfound=true;
			break;
		}
		temp=temp->next;
	}
	if(yesfound == false)
	{
		cout<<"\nERROR ! No Document Match the Query Searched !!!";
		
	}
	else
{

 l2.searchinlist(mycount[0]);
	
	

cout<<endl<<"Document Number in which your query is : ";
	for (int x =0; x<countingarrayresult;x++)
	{
		cout<<result1[x]<< " ";
	}
}
}
else if (b == 2 && mycount[1] == "or"  )
{
	
	node *temp = l2.head;
	while(temp != NULL)
	{
		if(temp->data == mycount[0] || temp->data == mycount[2])
		{
			yesfound=true;
			break;
		}
		temp=temp->next;
	}
	
	if(yesfound == false)
	{
		cout<<"\nERROR ! No Document Match the Query Searched !!";
		
	}
	else
	{
	l2.searchinlist(mycount[0]);
	l2.searchinlist(mycount[1]);
	l2.searchinlist(mycount[2]);
	cout<<endl<<"Document Number in which your query is : ";
	removeDuplicates(result1, countingarrayresult);
    }
}
else if (b == 2 && mycount[1] == "and")
{
	node *temp = l2.head;
	while(temp != NULL)
	{
		if(temp->data == mycount[0])
		{
			yesfound=true;
			break;
		}
		temp=temp->next;
	}
		if(yesfound == false)
	{
		cout<<"\nERROR ! No Document Match the Query Searched !!";
		
	}
	else
	{
	l2.searchinlist(mycount[0]);
	l2.searchinlist(mycount[2]);
	int firstone[temp->frequencies];
	int secondone[countingarrayresult-temp->frequencies];
	for (int x = 0; x<temp->frequencies;x++)
	{
		firstone[x]=result1[x];
	}
	int loop=0;
	for (int x =temp->frequencies; x<countingarrayresult;x++)
	{
		secondone[loop]=result1[x];
		loop++;
	}
	int n1 = sizeof(firstone) / sizeof(firstone[0]); 
	int n2 = sizeof(secondone) / sizeof(secondone[0]); 
	sort(firstone, firstone + n1);
	sort(secondone, secondone + n2);
	 
	printIntersection(firstone, secondone, n1, n2); 	
    }
}
else if (b == 3 && mycount[2] == "not")
{
	node *temp = l2.head;
	while(temp != NULL)
	{
		if(temp->data == mycount[0])
		{
			yesfound=true;
			break;
		}
		temp=temp->next;
	}
		if(yesfound == false)
	{
		cout<<"\nERROR ! No Document Match the Query Searched !!";
		
	}
	else{
	l2.searchinlist(mycount[0]);
	l2.searchinlist(mycount[3]);
	int firstone[temp->frequencies];
	int secondone[countingarrayresult-temp->frequencies];
	for (int x = 0; x<temp->frequencies;x++)
	{
		firstone[x]=result1[x];
	}
	int loop=0;
	for (int x =temp->frequencies; x<countingarrayresult;x++)
	{
		secondone[loop]=result1[x];
		loop++;
	}
		int n1 = sizeof(firstone) / sizeof(firstone[0]); 
	int n2 = sizeof(secondone) / sizeof(secondone[0]); 
	sort(firstone, firstone + n1);
	sort(secondone, secondone + n2);
	printnotIntersection(firstone, secondone, n1, n2); 
}

}
else
{
		cout<<"\nERROR ! No Document Match the Query Searched !!";
		
}
	doc1.close();
	doc2.close();
	doc3.close();
	doc4.close();
	doc5.close();
		
}

