#include<iostream>
#include <cstring>
using namespace std;
#define INF 9999999
#define V 7
int index = 0;
int path[V];
int main();

void graphpath();
string vertices[7] = {"OFFICE", "F6", "G8", "E11", "H8", "D12","G5"};
string form[7] = {
    "OFFICE",
    "F6",
    "G8",
    "E11",
    "H8",
    "D12",
    "G5"};
int dist();
void time();
bool visited[7];
bool visited1[7];
int dis[7];
int f = 0;
int r = 0;
int add2[7][7];
int add1[7][7];
int add[7][7];
int parent[7];
int vertex[7];
int dis1[7];
int parent1[7];
int shortestpath(int start, int end, int v);
void path1(int pp);
void addEdge(int u, int v, int w);


void adminBlock();
void customerBlock();
void signup();
void adminSecurity();
void viewCancelList();
void showCancelledOrders();
struct Order{
	Order* next = NULL;
	Order* backward=NULL;
	int orderId;
	string currentLocation;
	string dropOffLocation;
	string productType;
	int weight;
	int charges;
};
struct signUp{
	string name;
	string gender;
	string phoneNumber;
	string address;
	int id;
	int password;
	signUp* right=NULL;
	signUp* left=NULL;
	Order* order = NULL;
	Order* priorityOrder=NULL;
	
};
struct complaintStack{
	int array[100];
	int top ;
};

struct signUpList{
	string name;
	string gender;
	string phoneNumber;
	string address;
	int id;
	int password;
	signUpList* forward=NULL;
	signUpList* backward=NULL;	
};
void AdminCancelOrder(signUp* );
void insert();
void deleteCustomer();
void showPlacedOrders();
void cancelOrder(signUp*);
void customerDashBoard(signUp *);
void viewOrderList(signUp* );
signUp* signIn();
void overAllDisplay(signUp*);
void onlyCustomerDisplay(signUp*);
signUp* rightRotate(signUp* );
signUp* leftRotate(signUp*);
int bf(signUp* );
int height(signUp*);
void feedbackCustomer();	
void allorder(signUp* root);
void enqueueSimpleOrder(signUp* );
void enqueueUrgentOrder(signUp* );
signUp* insertEnd(signUp*);
void cancelOrderAdminUrgent(Order* , Order* , signUp* );
void cancelOrderAdminSimple(Order* , Order* , signUp* );
int delCustomer(int );
signUp *search(int );
void deliverOrder(signUp* i);
void insertCancel(Order* i);
void AdminDeliverOrder(signUp* r);
void deliveredList();


void push(int );
void push2(int );
bool is_empty();
bool is_full();
int pop();
int id1=0;
int id=0;
int orderKms = 0;
int signUpId=1000;
int array[100];
int array2[100];
int top =-1;
int top2 = -1;
signUpList* firstlist = NULL;
signUpList* lastlist = NULL;
Order* front=NULL;
Order* rear=NULL;
Order* front2=NULL;
Order* rear2=NULL;
Order* frontCancel=NULL;
Order* rearCancel=NULL;
Order* frontdeliver=NULL;
Order* reardeliver=NULL;
Order* cancelFirst=NULL;
Order* cancelLast=NULL;
signUp* root=NULL;

int pricePerKg=100;

int main(){
	for(int i=0;i<=50;i++){
		cout<<"*";
	}
	cout<<""<<endl;
	cout<<" W E L C O M E  TO  S H I P M E N T  S Y S T E M"<<endl;
	for(int i=0;i<=50;i++){
		cout<<"*";
	}
	
	int opt;
	do{
		cout<<"\n\n1) ADMIN BLOCK\n2) CUSTOMER BLOCK"<<endl;
		cout<<"SELECT ANY ONE: "<<endl;
		cin>>opt;
		
		if(opt==0){
			cout<<"PROGRAM TERMINATED!!"<<endl;
			break;
		}else if(opt==1){
			adminSecurity();
		}
		else if(opt==2){
			customerBlock();
		}else{
			cout<<"ENTER A VALID OPTION!!"<<endl;
		}
		
	
	}while(opt!=0);
}

int dist()
{
  int d=0;
  cout << "Enter destination point" << endl;
  cin >> d;
 
  int g = shortestpath(0, d, 7);
  path1(d);
  cout << "\n";
  return d;
}

void path1(int pp)
{
	orderKms = 0;
  cout << "The shortest distance to reach " << vertices[pp] << " from " << vertices[0] << " is ";

  while (top != -1)
  {
    pop();
  }
  cout << dis[pp] << " km" << endl;
  orderKms = dis[pp] ;
}
int shortestpath(int start, int end, int v)
{
  int wp = start;
  int j = 0;
  parent[start] = 0;
  dis[start] = 0;
  while (j < v)
  {
    visited[start] = true;
    for (int i = 0; i < v; i++)
    {
      if (add[start][i] > 0 && visited[i] == false)
      {
        if (dis[i] == 0)
        {
          dis[i] = dis[start] + add[start][i];
          parent[i] = start;
        }
        else
        {
          int t = dis[start] + add[start][i];
          if (t < dis[i])
          {
            dis[i] = t;
            parent[i] = start;
          }
        }
      }
    }
    int min;
    int index;
    for (int u = 0; u < v; u++)
    {
      if (visited[u] == true)
      {
      }
      else if (dis[u] == 0)
      {
      }
      else
      {
        min = dis[u];
        index = u;
        for (int p = u + 1; p < v; p++)
        {
          if (visited[p] == true)
          {
          }
          else if (dis[p] == 0)
          {
          }
          else
          {
            if (min > dis[p])
            {
              min = dis[p];
              index = p;
            }
          }
        }
        start = index;
        break;
      }
    }

    j++;
  }

  int pp = end;
  while (end != wp)
  {
    push(end);
    int p = parent[end];
    end = p;
  }
  int kp = wp;
  if (end == wp)
  {
    push(end);
  }

  cout << "\n";

  int g = dis[pp];
  for (int i = 0; i < 7; i++)
  {
    visited[i] = false;
  }
  return g;
}


bool is_full()
	{
		if(top2==100)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

bool is_empty()
	{
		if(top==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(int x)
	{
		if(is_full())
		{
			cout<<"\nNo space";
		}
		else
		{
			array[++top] =x;
		}
	}
	void push2(int x)
	{
		if(is_full())
		{
			cout<<"\nNo space";
		}
		else
		{
			array[++top] =x; 
			cout<<"THANKS FOR YOU TIME";
		}
	}
	int pop()
	{
		int x;
		if(is_empty())
		{
			cout<<"\nNothing to pop";
		}
		else
		{
			x = array[top--];
			return x;
		}
	}



void adminSecurity(){
	cout<<"\n*******************WELCOME TO ADMIN******************"<<endl;
	int inp;
	string username="Admin";
	string password="12345";
	string p;
	string u;
	
	int chances=1;
	cout<<"\n*****************************************************"<<endl;	
	cout<<"\t\t\tLOGIN"<<endl;
	cout<<"*****************************************************"<<endl;
	while(chances<=3){
		cout<<"\nUSERNAME: ";
		cin>>u;
		cout<<"\nPASSWORD: ";
		cin>>p;
		if(u==username&&p==password){
			cout<<"\nACCESS GRANTED!!"<<endl;
			adminBlock();
			
		}else {
			chances++;
		}
		
	}
	
}

void addEdge(int u, int v, int w)
{
  add[u][v] = w;
  add[v][u] = w;
  add2[u][v] = w;
}
void adminBlock(){
	int i;
	cout<<"\n1) DISPLAY CUSTOMER RECORDS\n2) DELETE CUSTOMER RECORDS\n3) SHOW ALL THE ORDERS EVER PLACED\n4) SHOW UNDELIVERED ORDERS\n5) SHOW LOCATIONS\n6) CANCEL ORDERS\n7) SHOW CANCELLED ORDERS\n8) SHOW DELIVERED ORDERS\n9) DELIVER ORDER \n10)CHECK FEEDBACKS\n 0) EXIT"<<endl;
	cout<<"\n Enter any option: "<<endl;
	cin>>i;
	if(i==0){
		main();
	}
	else if(i==1)
	{
		overAllDisplay(root);
		adminBlock();
	}
	else if(i==2)
	{
		onlyCustomerDisplay(root);
		deleteCustomer();
		adminBlock();
	}
	else if(i==3)
	{
		showPlacedOrders();
		adminBlock();
	}
	else if(i==4){
		allorder(root);
		adminBlock();
	}
	else if(i==5)
	{
		graphpath();
		dist();
		adminBlock();
	}
	else if(i==6){
		if(root==NULL)
		{
			cout<<"No customer record exists";
			return;
		}
		AdminCancelOrder(root);
		adminBlock();
	}
	else if(i==7)
	{
		showCancelledOrders();
		adminBlock();
	}
	
	else if(i==8){
		deliveredList();
		adminBlock();
	}
	else if(i==9){
		
		cout<<"Following are the Pending Orders"<<endl;
		AdminDeliverOrder(root);
		adminBlock();
	}
	else if(i==10){
		
		cout<<"**********ALL FEEDBACKS**********"<<endl;
			while(top!=-1)
			{
				int value = pop();
				if(value==1)
				{
					cout<<"\nVERY GOOD\n";
				}
				else if(value==2)
				{
					cout<<"GOOD\n";
				}
				else if(value==3)
				{
					cout<<"AVERAGE\n";
				}
				else if(value==4)
				{
					cout<<"POOR\n";
				}
				else if(value==5)
				{
					cout<<"VERY POOR\n";
				}
						
			}
			
		
		adminBlock();
		
		
	}
	else {
		cout<<"Enter a valid option"<<endl;
		adminBlock();
	}
}
void graphpath()
{
		cout<<"*********************\n";
		  int n;
		  for (int k = 0; k < V; k++)
		  {
		    vertex[k] = k;
		  }
		  for (int gk = 0; gk < 7; gk++)
		  {
		    cout<<"Press\t"<<vertex[gk] <<"\tfor\t"<<vertices[gk]<< " \n";
		  }
		  cout << "\n";
		  
		  addEdge(0, 3, 4);
		  addEdge(0, 1, 2);
		  addEdge(0, 5, 5);
		  addEdge(0, 3, 4);
		  addEdge(1, 3, 1);
		  addEdge(1, 4, 3);
		  addEdge(3, 4, 2);
		  addEdge(1, 2, 7);
		  addEdge(2, 4, 10);
		  addEdge(1, 5, 8);
		  addEdge(1, 6, 4);
		  addEdge(5, 6, 1);
		  addEdge(6, 2, 6);
		  
		  
}
void showCancelledOrders(){
	if(frontCancel==NULL){
		cout<<"No orders available to display!!"<<endl;
		adminBlock();
	}else {
		Order* p=frontCancel;
		while(p!=NULL){
			cout<<"ID: "<<p->orderId<<endl;
			cout<<"Product type: "<<p->productType<<endl;
			cout<<"Current location: "<<p->currentLocation<<endl;
			cout<<"Drop off location: "<<p->dropOffLocation<<endl;
			cout<<"Weight: "<<p->weight<<endl;
			cout<<"Charges: "<<p->charges<<endl;
			cout<<"**************************\n"<<endl;
			p=p->next;
		}
	}
}
void showPlacedOrders(){
	Order* p=cancelFirst;
	if(cancelFirst==NULL){
		cout<<"No orders available to display!!"<<endl;
	}else {
		while(p!=NULL){
			cout<<"ID: "<<p->orderId<<endl;
			cout<<"Product type: "<<p->productType<<endl;
			cout<<"Current location: "<<p->currentLocation<<endl;
			cout<<"Drop off location: "<<p->dropOffLocation<<endl;
			cout<<"Weight: "<<p->weight<<endl;
			cout<<"Charges: "<<p->charges<<endl;
			cout<<"**************************\n"<<endl;
			p=p->next;
		}
	}
}

void customerBlock(){
	int i;
	cout<<"\n1) SIGN UP\n2) SIGN IN\n0) EXIT"<<endl;
	cout<<"\n Enter any option: "<<endl;
	cin>>i;
	if(i==1){
		insert();
	}
	else if(i==2){
		signUp* f = signIn();
		customerDashBoard(f);
		
	}else if(i==0){
		main();
	}

	else {
		cout<<"Enter a valid option!!"<<endl;
		customerBlock();
	}
}

void customerDashBoard(signUp* i){
	int o;
	cout<<"\n1) PLACE ORDER\n2) PLACE ORDER ON URGENT BASIS\n3) CANCEL ORDER\n4) VIEW ORDERS\n5) GIVE FEEDBACK\n6)RETURN TO CUSTOMER BLOCK"<<endl;
	cin>>o;
	if(o==1){
		enqueueSimpleOrder(i);
		cout<<"ORDER PLACED SUCCESSFULLY!!"<<endl;
		customerDashBoard(i);
	}
	else if(o==2)
	{
		enqueueUrgentOrder(i);
		cout<<"ORDER PLACED SUCCESSFULLY!!"<<endl;
		customerDashBoard(i);
	}
	else if(o==4)
	{
		viewOrderList(i);
		customerDashBoard(i);
	}
	else if(o==3)
	{
		cancelOrder(i);	
		customerDashBoard(i);
	}
	else if(o==5){
	feedbackCustomer();	
	customerDashBoard(i);
	}
	else if(o==6){
		customerBlock();	
	} 
	
	else{
		cout<<"Enter a valid option!!"<<endl;
		customerDashBoard(i);
	}

}
void feedbackCustomer()
{
	int x;
	cout<<"\n*******************"<<endl;
	cout<<"     FEEDBACK ";
	cout<<"\n*******************"<<endl;
	cout<<"HOW WAS YOUR EXPERIENCE?"<<endl;
	cout<<"1) VERY GOOD\n2) GOOD\n3)AVERAGE\n4) POOR\n5) VERY POOR\n";
	cin>>x;
	if(x==1)
	{
		push2(1);
	}
	else if(x==2)
	{
		push2(2);
	}
	else if(x==3)
	{
		push2(3);
	}
	else if(x==4)
	{
		push2(4);
	}
	else if(x==5)
	{
		push2(5);
	}
	
	
}
void AdminDeliverOrder(signUp* r)
{
	if(root==NULL)
	{
		cout<<"No customer record exists";
		return;
	}
	int p;
	cout<<"-----------------ALL ORDERS-----------------";
	overAllDisplay(root);
	cout<<"ENTER THE ORDER ID OF THE CUSTOMER WHOSE ORDERS YOU WANT TO DELIVER";
	cin>>p;
	
	int pass = delCustomer(p);
	signUp *q = search(pass);
	if(q->order==NULL && q->priorityOrder==NULL)
	{
		cout<<"THIS CUSTOMER HAVEN'T PLACED ANY ORDERS";
		adminBlock();
	}
	deliverOrder(q);
}


void AdminCancelOrder(signUp* r)
{
	
	int p;
	cout<<"-----------------ALL ORDERS-----------------";
	overAllDisplay(root);
	cout<<"ENTER THE ORDER ID OF THE CUSTOMER WHOSE ORDERS YOU WANT TO CANCEL";
	cin>>p;
	
	int pass = delCustomer(p); 
	signUp *q = search(pass);
	if(q->order==NULL && q->priorityOrder==NULL)
	{
		cout<<"THIS CUSTOMER HAVEN'T PLACED ANY ORDERS";
		adminBlock();
	}
	cancelOrder(q);
}


void onlyCustomerDisplay(signUp* root){
	
	if(root!=NULL){
		
		
		cout<<"\n*******************"<<endl;
		cout<<"     CUSTOMER ";
		cout<<"\n*******************"<<endl;
		
		cout<<"Id: "<<root->id<<endl;
		cout<<"Name: "<<root->name<<endl;
		cout<<"Gender: "<<root->gender<<endl;
		cout<<"Phone Number: "<<root->phoneNumber<<endl;
		cout<<"Address: "<<root->address<<endl; 
		onlyCustomerDisplay(root->left);
		onlyCustomerDisplay(root->right);
			
	}
	

}
void allorder(signUp* root)
{
	if(root!=NULL){
		Order* l=root->priorityOrder;
		if(l==NULL){
		cout<<"\nURGERT ORDERS = NULL "<<endl;
			
		}else{
			cout<<"\n*******************"<<endl;
			cout<<"   URGENT ORDERS ";
			cout<<"\n*******************"<<endl;
			
			while(l!=NULL){
				
				cout<<"ID: "<<l->orderId<<endl;
				cout<<"Product type: "<<l->productType<<endl;
				cout<<"Current location: "<<l->currentLocation<<endl;
				cout<<"Drop off location: "<<l->dropOffLocation<<endl;
				cout<<"Weight: "<<l->weight<<endl;
				cout<<"Charges: "<<l->charges<<endl;
				cout<<"**************************"<<endl;
			
				l=l->next;
			} 
		}
		Order* l2=root->order;
		
		if(l2==NULL){
		cout<<"\nSIMPLE ORDERS = NULL "<<endl;
	
			
		}else {
			cout<<"\n*******************"<<endl;
			cout<<"   SIMPLE ORDERS";
			cout<<"\n*******************"<<endl;
			
			while(l2!=NULL){
			
				cout<<"ID: "<<l2->orderId<<endl;
				cout<<"Product type: "<<l2->productType<<endl;
				cout<<"Current location: "<<l2->currentLocation<<endl;
				cout<<"Drop off location: "<<l2->dropOffLocation<<endl;
				cout<<"Weight: "<<l2->weight<<endl;
				cout<<"Charges: "<<l2->charges<<endl;
				
				cout<<"**************************"<<endl;
				l2=l2->next;
			
			}
		}
		
		allorder(root->left);
		allorder(root->right);
		return;
	}
		
}
void overAllDisplay(signUp* root){
	if(root!=NULL){
		
		cout<<"\n*******************"<<endl;
		cout<<"     CUSTOMER ";
		cout<<"\n*******************"<<endl;
		
		cout<<"Id: "<<root->id<<endl;
		cout<<"Name: "<<root->name<<endl;
		cout<<"Gender: "<<root->gender<<endl;
		cout<<"Phone Number: "<<root->phoneNumber<<endl;
		cout<<"Address: "<<root->address<<endl; 
		
		
		Order* l=root->priorityOrder;
		if(l==NULL){
			cout<<"\nURGERT ORDERS = NULL "<<endl;
			
		}else{
			cout<<"\n*******************"<<endl;
			cout<<"   URGENT ORDERS ";
			cout<<"\n*******************"<<endl;
			
			while(l!=NULL){
				cout<<"ID: "<<l->orderId<<endl;
				cout<<"Product type: "<<l->productType<<endl;
				cout<<"Current location: "<<l->currentLocation<<endl;
				cout<<"Drop off location: "<<l->dropOffLocation<<endl;
				cout<<"Weight: "<<l->weight<<endl;
				cout<<"Charges: "<<l->charges<<endl;
				cout<<"**************************"<<endl;
			
				l=l->next;
			} 
		}
		
		Order* l2=root->order;
		
		if(l2==NULL){
			
			cout<<"\nSIMPLE ORDERS = NULL"<<endl;
			
		}else {
			cout<<"\n*******************"<<endl;
			cout<<"   SIMPLE ORDERS";
			cout<<"\n*******************"<<endl;
			
			while(l2!=NULL){
				cout<<"ID: "<<l2->orderId<<endl;
				cout<<"Product type: "<<l2->productType<<endl;
				cout<<"Current location: "<<l2->currentLocation<<endl;
				cout<<"Drop off location: "<<l2->dropOffLocation<<endl;
				cout<<"Weight: "<<l2->weight<<endl;
				cout<<"Charges: "<<l2->charges<<endl;
				
				cout<<"**************************"<<endl;
				l2=l2->next;
			
			}
		}
		
		overAllDisplay(root->left);
		overAllDisplay(root->right);
	}
}
void insertList(string n, string gender, string ph, string ad, int pass, int id){
	signUpList* newNode = new signUpList();
	newNode->name = n;
	newNode->gender = gender;
	newNode->phoneNumber = ph;
	newNode->address = ad;
	newNode->password = pass;
	newNode->id = id;
	if(firstlist==NULL)
	{
		firstlist = lastlist = newNode;
	}
	else
	{
		lastlist->forward = newNode;
		lastlist = newNode;
	}
}
void insert(){
	signUpId++;
	string n,gender,ph,add;
	int pass;
	signUp* newSignUp=new signUp();
	cout<<"Enter name: "<<endl;
	cin>>n;
	
	cout<<"Enter gender: "<<endl;
	cin>>gender;
	
	cout<<"Enter phone number: "<<endl;
	cin>>ph;
	
	cout<<"Enter address: "<<endl;
	cin>>add;
	
	cout<<"Enter pass: "<<endl;
	cin>>pass;
	insertList(n,gender,ph,add,pass, signUpId);
	newSignUp->name=n;
	newSignUp->gender=gender;
	newSignUp->phoneNumber=ph;
	newSignUp->address=add;
	newSignUp->password=pass;
	newSignUp->id=signUpId;
	
	if(root==NULL){
		root=newSignUp;
	}else{
		signUp* p=root;
		signUp* k;
		while(p!=NULL){
			k=p;
			if(pass>p->password){
				p=p->right;
			}else{
				p=p->left;
			}
		}
		if(pass>k->password){
			k->right=newSignUp;
		}else{
			k->left=newSignUp;
		}
		
	}
	customerBlock();
}



signUp* signIn(){
	signUp* i=root;
	signUp* p=i;
	string name;
	int pass;
	cout<<"Enter your name: "<<endl;
	cin>>name;
	cout<<"Enter your password: "<<endl;
	cin>>pass;
	
	while(i!=NULL&&i->password!=pass){
		p=i;
		if(i->password<pass){
			i=i->right;
		}else{
			i=i->left;
		}
	}
	if(i==NULL){
		cout<<"MATCH NOT FOUND!!"<<endl;
		cout<<"You have to sign up first!"<<endl;
		customerBlock();
	}
	else if(i!=NULL)
	{
		if(i->password == pass&&i->name == name)
		{
			cout<<"SUCCESSFULLY LOGGED IN!"<<endl;
			customerDashBoard(i);
		}
		else if(i->password==pass&& i->name!=name)
		{
			cout<<"MATCH NOT FOUND!!"<<endl;
			customerBlock();
		}
		else if(i->password!=pass||i->name!=name)
		{
			cout<<"MATCH NOT FOUND!!"<<endl;
			customerBlock();
		}
		return i;
		
	}
	} 
	
	

void viewCancelList()
{
	Order *p = frontCancel;
	if(frontCancel==NULL)
	{
		cout<<"NO CANCELLED ORDERS";
	}
	while(p!=NULL)
	{
		cout<<"\nORDER ID: "<<p->orderId<<endl;
		cout<<"PRODUCT TYPE: "<<p->productType<<endl;
		cout<<"CURRENT LOCATION: "<<p->currentLocation<<endl;
		cout<<"DROP OFF LOCATION: "<<p->dropOffLocation<<endl;
		cout<<"WEIGHT OF ORDER:	"<<p->weight<<endl;
		cout<<"CHARGES OF ORDER: "<<p->charges<<endl;
		p=p->next;
	}
}
void viewOrderList( signUp* i){
	
	Order* f = i->order;
	Order* p = i->priorityOrder;
	cout<<"\n************** URGENT ORDERS **************"<<endl;
	if(p == NULL){
		cout<<"NO URGENT ORDERS"<<endl;
	}
	else{
		while(p!=NULL)
		{
			cout<<"\nORDER ID: "<<p->orderId<<endl;
			cout<<"PRODUCT TYPE: "<<p->productType<<endl;
			cout<<"CURRENT LOCATION: "<<p->currentLocation<<endl;
			cout<<"DROP OFF LOCATION: "<<p->dropOffLocation<<endl;
			cout<<"WEIGHT OF ORDER:	"<<p->weight<<endl;
			cout<<"CHARGES OF ORDER: "<<p->charges<<endl;
		
			for(int l=0;l<=50;l++){
				cout<<"-";
			}
			p=p->next;
		}
	}

	
	cout<<"\n************** SIMPLE ORDERS **************"<<endl;
	
	if(f == NULL ){
		cout<<"NO SIMPLE ORDERS"<<endl;
	}else{
		while(f!=NULL){
			cout<<"\nORDER ID: "<<f->orderId<<endl;
			cout<<"PRODUCT TYPE: "<<f->productType<<endl;
			cout<<"CURRENT LOCATION: "<<f->currentLocation<<endl;
			cout<<"DROP OFF LOCATION: "<<f->dropOffLocation<<endl;
			cout<<"WEIGHT OF ORDER:	"<<f->weight<<endl;
			cout<<"CHARGES OF ORDER: "<<f->charges<<endl;
		
			
			for(int q=0;q<=50;q++){
				cout<<"-";
			}
			
			f=f->next;
		
		}
	}
	
}

void enqueueSimpleOrder(signUp* i){
	
	Order* newOrder=new Order();
	Order* new2Order=new Order();
	string p,curr,drop;
	int w;
	string sourceNode,destination;
	sourceNode="OFFICE";
	
	newOrder->orderId = id++;
	new2Order->orderId = id;
		
	cout<<"Enter your product type: "<<endl;
	string product;
	cin>>product;
	
	newOrder->productType=product;
	new2Order->productType=product;
	graphpath();
	int tem=dist();
	
	cout<<"Enter weight of the product in kgs: "<<endl;
	
	cin>>w;
	newOrder->weight=w;
	new2Order->weight=w;	
			
	
	if(i->order==NULL)
	{
		i->order = newOrder;
		front = rear = newOrder;
	}
	else
	{
		rear->next=newOrder;
		newOrder->backward=rear;
		rear = newOrder;
	}
	if(cancelFirst == NULL)
	{
		cancelFirst=cancelLast=new2Order;
	}
	else
	{
		cancelLast->next=new2Order;
		cancelLast=new2Order;
	}
	

	int priceOfWeight=0;
	priceOfWeight=w*5;

	int charges=0;
	charges=(orderKms*100)+priceOfWeight;
	
	newOrder->charges=charges;
	new2Order->charges=charges;
	if(tem==0){
		destination="OFFICE";
		
	}else if(tem==1){
		destination="F6";
	}else if(tem==2){
		destination="G8";
	}else if(tem==3){
		destination="E11";
		
	}else if(tem==4){
		destination="H8";
		
	}else if(tem==5){
		destination="D12";
	}else if(tem==6){
		destination="G5";
	}
	
	
	newOrder->currentLocation=sourceNode;
	newOrder->dropOffLocation=destination;
	new2Order->currentLocation=sourceNode;
	new2Order->dropOffLocation=destination;
	cout<<"DESTINATION\t\tKMS\t\tPRICE"<<endl;
	cout<<destination<<"\t\t\t"<<orderKms<<"\t\t"<<charges<<endl;
}

void enqueueUrgentOrder(signUp* i){
	Order* newOrder=new Order();
	Order* new2Order=new Order();
	
	string p,curr,drop;
	int w;
	string sourceNode,destination;
	sourceNode="OFFICE";
	newOrder->orderId = id++;
	new2Order->orderId = id;
	
	cout<<"Enter your product type: "<<endl;
	string product;
	cin>>product;
	
	newOrder->productType=product;
	new2Order->productType=product;
	
	graphpath();
	int tem=dist();
	
		
	cout<<"Enter weight of the product in kgs: "<<endl;
	
	cin>>w;
	newOrder->weight=w;
	new2Order->weight=w;	
	int priceOfWeight=w*5;
			
	if(i->priorityOrder==NULL){
		i->priorityOrder = newOrder;
		front2=rear2=newOrder;
	}else{
		rear2->next=newOrder;
		newOrder->backward=rear2;
		rear2=newOrder;
	}
	
	
	if(cancelFirst == NULL)
	{
		cancelFirst=cancelLast=new2Order;
	}
	else
	{
		cancelLast->next=new2Order;
		cancelLast=new2Order;
	}
	
	int priceOfWeight_U=0;
	priceOfWeight_U=w*5;

	int chargesU=0;
	chargesU=(orderKms*100)+priceOfWeight_U + 100;
	
	newOrder->charges=chargesU;
	new2Order->charges=chargesU;
	if(tem==0){
		destination="OFFICE";
		
	}else if(tem==1){
		destination="F6";
	}else if(tem==2){
		destination="G8";
	}else if(tem==3){
		destination="E11";
		
	}else if(tem==4){
		destination="H8";
		
	}else if(tem==5){
		destination="D12";
	}else if(tem==6){
		destination="G5";
	}
	
	newOrder->currentLocation=sourceNode;
	newOrder->dropOffLocation=destination;
	new2Order->currentLocation=sourceNode;
	new2Order->dropOffLocation=destination;
	
	cout<<"DESTINATION\t\tKMS\t\tPRICE"<<endl;
	cout<<destination<<"\t\t\t"<<orderKms<<"\t\t"<<chargesU<<endl;
	
}


signUp *search(int key)
{
	signUp *p = root;
	while(p->password!=key && p!=NULL)
	{
		if(p->password<key)
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}
	}
	if(p==NULL)
	{
		cout<<"Id Does not match";
		return p;
	}
	else if(p->password==key)
	{
		return p;
	}
	
	
}
int delCustomer(int del_id)
{
	int password;
	signUpList *p=firstlist;
	while(p->id!=del_id && p!=NULL)
	{
		p=p->forward;
	}
	if(p==NULL)
	{
		cout<<"id not found";
		adminBlock();
	}
	else
	{
		if(p->id==del_id)
		{
			password = p->password;
		}
		else if(p->id!=del_id)
		{
			cout<<"id not found";
			adminBlock();
		}
	}

}
void deleteCustomer() {
	if(root==NULL)
	{
		cout<<"No customer record exists";
		return;
	}
	cout<<"Enter the id which you want to delete";
	int f;
	cin>>f;
	int password;
	password = delCustomer(f);
	signUp *w;
	signUp *q = search(password);
	if(q==root && q->left==NULL && q->right==NULL)
	{
		root = NULL;
		delete(q);
		cout<<"NO MORE CUSTOMERS";
		return;
	}
	if(q == NULL)
	{
		cout<<"\nValue not found";
		return;
	}
	else
	{
		signUp *z = root;
		w = z;
		while(z->password!=q->password && z!=NULL) // finding the 2nd last of the node which we want to delete
		{
			if(z->password<q->password)
			{
				w = z;
				z = z->right;
			}
			else
			{
				w = z;
				z = z->left;
			}	
		}
	}

	if(q==root && q->left == NULL && q->right == NULL) // root is the only node in tree
	{
		delete(q);
		return;
	}
	else if(q->left == NULL && q->right == NULL) //DELETING LEAF NODE
	{
		if(w->left == q )
		{
			w->left = NULL;
			delete(q);
			return;
		}
		if(w->right == q )
		{
			w->right = NULL;
			delete(q);
				return;
		}
	}
	else if(q->left == NULL || q->right == NULL) //DELETING NODE HAVING ONE CHILD
	{
		if(q==root && q->left == NULL || q->right == NULL)
		{
			if(q->right != NULL && q->left==NULL)
			{
				signUp* l = q->right;
				root = l ; 
				delete(q);
				l->right=NULL;
			}
			if(q->right == NULL && q->left!=NULL)
			{
				signUp* l = q->left;
				root = l ; 
				delete(q);
				l->left=NULL;
			}
			
		}
		else if(w->right == q)
		{
			if(q->right!=NULL)
			{
				w->right = q->right;
				delete(q);
				return;
			}
			else
			{
				w->right = q->left; 
				delete(q);
				return;
			}
		}
		else if(w->left == q)
		{
			if(q->left!=NULL)
			{
				w->left = q->left;
				delete(q);
				return;
			}
			else
			{
				w->left = q->right;
				delete(q);
				return;
			}
		}
		
	}
	else if(q->left != NULL && q->right != NULL) //DELETING NODE HAVING TWO CHILD
	{
		signUp *q2 = q;
		signUp *f = q;
		q2 = q2->right;
		while(q2->left!=NULL)
		{
			f = q2;
			q2 = q2->left;
		}
		q->id = q2->id;
		q->name = q2->name;
		q->gender = q2->gender;
		q->password = q2->password;
		q->phoneNumber = q2->phoneNumber;
		q->address = q2->address;
		if(q2->password == f->password && q2->right==NULL )
		{
			q->right =NULL;
			delete(q2);
			return;
		}
		else if(q2->password == f->password )
		{
			q->right = q2->right;
			delete(q2);
			return;
		}
		else if(q2->right!=NULL)
		{
			f->left = q2->right;
			delete(q2);
			return;
		}
		else
		{
			f->left= NULL;
			delete(q2);	
			return;		
		}	
	}
	
}
void insertCancel(Order* i)
{
		Order *newCancel = new Order();
		newCancel = i;
		if(frontCancel == NULL)
		{
			frontCancel = rearCancel = newCancel;
		}
		else
		{
			rearCancel->next = newCancel;
			rearCancel = newCancel;
		}
		
		
}
void cancelOrder(signUp* i)
{
	Order* f = i->order;
	Order* g = i->priorityOrder;
	int p;
	front = f;
	cout<<"\n-----------------YOUR ORDERS-----------------"<<endl;
	viewOrderList(i);
	cout<<"ENTER THE ORDER ID WHICH YOU WANT TO CANCEL: ";
	cin>>p;
	while(f!=NULL && f->orderId!=p )
	{
		f = f->next;
	}
	if(f == NULL)
	{
		cout<<"Id not found in simple orders list\n";
	}
	else if(f->orderId==p) 
	{		
		Order* forward = f->next;
		Order* previous = f->backward;
		
		if(f->orderId == front->orderId && f->next ==NULL)
		{
			i->order = NULL;
			front = NULL;
			f->next = NULL;
			insertCancel(f);
			delete(f);
			cout<<"-------No orders placed---------";
			return;
		}
		if(f->next==NULL && f->orderId ==rear->orderId)
		{
		    
			previous->next = NULL;
			f->next = NULL;
			insertCancel(f);
			delete(f);
			return;
		}
		
		else if(f->orderId == front->orderId )
		{
			i->order =  forward;
			forward->backward = i->order;
			f->next = NULL;
			insertCancel(f);
			delete(f);
			return;
		}
		
		else
		{
			previous->next = forward;
			f->next = NULL;
			insertCancel(f);
		}
		
		
		
		cout<<"-----------------Deleted successfully-----------------\n";
		return;
		
	}
	
	
	while(g!=NULL && g->orderId!=p )
	{
		
		g = g->next;
	}
	if(g == NULL)
	{
		cout<<"Id not found in urgent orders list";
	}
	else if(g->orderId==p) 
	{				
		Order* forward = g->next;
		Order* previous = g->backward;
		
		if(g->orderId == front2->orderId && g->next ==NULL)
		{
			i->priorityOrder = NULL;
			front2 = NULL;
			g->next = NULL;
			insertCancel(g);
			delete(g);
			cout<<"-------No orders placed---------";
			return;
		}
		else if(g->next==NULL && g->orderId ==rear2->orderId)
		{
		    cout<<rear2->orderId;
			g->backward->next = NULL;
			g->next=NULL;
			insertCancel(g);
			delete(g);
			return;
		}
		
		else if(g->orderId == front2->orderId )
		{
			i->priorityOrder =  forward;
			forward->backward = i->priorityOrder;
			g->next=NULL;
			insertCancel(g);
			delete(g);
			return;
		}
		
		else
		{
			previous->next = forward;
			g->next=NULL;
			insertCancel(g);
		}
		
	
		
		cout<<"-----------------Deleted successfully-----------------";
		return;
		
	}
	return;
		
}

void insertDeliver(Order* i)
{
	Order *newdel = new Order();
	newdel = i;
	i->next = NULL;
	if(frontdeliver == NULL)
	{
		frontdeliver = reardeliver = newdel;
	}
	else
	{
		reardeliver->next = newdel;
		reardeliver = newdel;
	}
	return;
}
void deliverOrder(signUp* i)
{	
	Order* f = i->order;
	Order* g = i->priorityOrder;
	int p;
	front = f;
	cout<<"\n-----------------YOUR ORDERS-----------------"<<endl;
	viewOrderList(i);
	cout<<"ENTER THE ORDER ID WHICH YOU WANT TO DELIVER: ";
	cin>>p;
	while(f!=NULL && f->orderId!=p )
	{
		f = f->next;
	}
	if(f == NULL)
	{
		cout<<"Id not found";
	}
	else if(f->orderId==p) 
	{		
		Order* forward = f->next;
		Order* previous = f->backward;
		
		if(f->orderId == front->orderId && f->next ==NULL)
		{
			i->order = NULL;
			front = NULL;
			f->next = NULL;
			insertDeliver(f);
			delete(f);
			cout<<"-------No orders placed---------";
			return;
		}
		if(f->next==NULL && f->orderId ==rear->orderId)
		{
		    
			previous->next = NULL;
			f->next = NULL;
			insertDeliver(f);
			delete(f);
			return;
		}
		
		else if(f->orderId == front->orderId )
		{
			i->order =  forward;
			forward->backward = i->order;
			f->next = NULL;
			insertDeliver(f);
			delete(f);
			return;
		}
		
		else
		{
			previous->next = forward;
			f->next = NULL;
			insertDeliver(f);
		}

		
		cout<<"-----------------Deleted successfully-----------------";
		return;
		
	}
	
	
	while(g!=NULL && g->orderId!=p )
	{
		
		g = g->next;
	}
	if(g == NULL)
	{
		cout<<"Id not found";
	}
	else if(g->orderId==p) 
	{				
		Order* forward = g->next;
		Order* previous = g->backward;
		if(g->orderId == front2->orderId && g->next ==NULL)
		{
			i->priorityOrder = NULL;
			front2 = NULL;
			g->next = NULL;
			insertDeliver(g);
			delete(g);
			cout<<"-------No orders placed---------";
			return;
		}
		else if(g->next==NULL && g->orderId ==rear2->orderId)
		{
		    cout<<rear2->orderId;
			g->backward->next = NULL;
			g->next=NULL;
			insertDeliver(g);
			delete(g);
			return;
		}
		else if(g->orderId == front2->orderId )
		{
			i->priorityOrder =  forward;
			forward->backward = i->priorityOrder;
			g->next=NULL;
			insertDeliver(g);
			delete(g);
			return;
		}
		else
		{
			previous->next = forward;
			g->next=NULL;
			insertDeliver(g);
		}
		cout<<"-----------------Deleted successfully-----------------";
		return;
		
	}
	return;
		
}

void deliveredList(){
	if(frontdeliver==NULL){
		cout<<"No orders available to display!!"<<endl;
		adminBlock();
	}else {
		Order* p=frontdeliver;
		while(p!=NULL){
			cout<<"ID: "<<p->orderId<<endl;
			cout<<"Product type: "<<p->productType<<endl;
			cout<<"Current location: "<<p->currentLocation<<endl;
			cout<<"Drop off location: "<<p->dropOffLocation<<endl;
			cout<<"Weight: "<<p->weight<<endl;
			cout<<"Charges: "<<p->charges<<endl;
			cout<<"**************************\n"<<endl;
			p=p->next;
		}
	}
}




