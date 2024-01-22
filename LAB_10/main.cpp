#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct node
{
    int data;
    node* nptr;
};

void BFS(string name[],int arry[15][15]);
void topological_sort(int indeg[],string name[], node* list_arry[]);

void add_node(node*& head, int data);
int main()
{   //Adjacency Matrix
   int matrix[15][15]={{0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0},{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,1,0,1,0,1,0,0,0,0,0,0,0},{0,0,0,0,1,0,1,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,1,0,0,0,1,0,0,1,0,0},{0,0,0,0,1,0,0,0,1,0,1,0,0,0,0},
                      {0,0,1,0,0,0,0,1,0,0,0,1,0,0,0},{0,0,0,0,0,0,1,0,0,1,0,0,1,0,0},
                      {0,0,0,0,0,0,0,1,0,1,0,1,0,0,0},{0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
                      {0,0,0,0,0,0,1,0,0,1,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
                      {0,1,1,1,0,0,0,0,0,0,0,1,0,1,0}};

   //Adjacency List
   node* head0=NULL;
   node* head1=NULL;
   node* head2=NULL;
   node* head3=NULL;
   node* head4=NULL;
   node* head5=NULL;
   node* head6=NULL;
   node* head7=NULL;
   node* head8=NULL;
   node* head9=NULL;
   node* head10=NULL;
   node* head11=NULL;
   node* head12=NULL;
   node* head13=NULL;
   node* head14=NULL;

   //populating the link-list
   add_node(head0,1);
   add_node(head0,2);
   add_node(head0,3);
   add_node(head2,8);
   add_node(head3,4);
   add_node(head4,5);
   add_node(head4,7);
   add_node(head5,6);
   add_node(head6,9);
   add_node(head6,12);
   add_node(head7,10);
   add_node(head7,8);
   add_node(head8,11);
   add_node(head9,10);
   add_node(head10,11);
   add_node(head11,14);
   add_node(head12,9);
   add_node(head12,13);
   add_node(head14,13);

   //arry of the head pointer
   node* arry[15];
   arry[0]=head0;
   arry[1]=head1;
   arry[2]=head2;
   arry[3]=head3;
   arry[4]=head4;
   arry[5]=head5;
   arry[6]=head6;
   arry[7]=head7;
   arry[8]=head8;
   arry[9]=head9;
   arry[10]=head10;
   arry[11]=head11;
   arry[12]=head12;
   arry[13]=head13;
   arry[14]=head14;

   //Indegree arry
   int indeg[15]={0,1,1,1,1,1,1,1,2,2,2,2,1,2,1};

   //using the index of the string arry as node representation
   string name[15];
   name[0]="PIEAS";
   name[1]="Chirah";
   name[2]="Mohara";
   name[3]="Thanda Pani";
   name[4]="Ali Pur";
   name[5]="Taramri";
   name[6]="Chatta Bakhtawar";
   name[7]="Jagiot";
   name[8]="Pind Begwal";
   name[9]="Kuri";
   name[10]="Malot";
   name[11]="Athal";
   name[12]="Chak Shahzad";
   name[13]="Bani Gala";
   name[14]="Bhara Kahu";

   BFS(name,matrix);

   topological_sort(indeg, name, arry);

}

void BFS(string name[], int arry[15][15])       //traversing using BFS
{
    cout<<"Graph traversing by BFS : \n\n";
    int v,row=0;
    bool flag[15]={false};
    queue<string> q1;
    q1.push(name[0]);
    flag[0]=true;
    while(!q1.empty())
    {
        cout<<q1.front()<<"\n";
        if(q1.front()=="PIEAS")
        {
            row=0;
        }
        else if(q1.front()=="Chirah")
        {
            row=1;
        }
        else if(q1.front()=="Mohara")
        {
            row=2;
        }
        else if(q1.front()=="Thanda Pani")
        {
            row=3;
        }
        else if(q1.front()=="Ali Pur")
        {
            row=4;
        }
        else if(q1.front()=="Taramri")
        {
            row=5;
        }
        else if(q1.front()=="Chatta Bakhtawar")
        {
            row=6;
        }
        else if(q1.front()=="Jagiot")
        {
            row=7;
        }
        else if(q1.front()=="Pind Begwal")
        {
            row=8;
        }
        else if(q1.front()=="Kuri")
        {
            row=9;
        }
        else if(q1.front()=="Malot")
        {
            row=10;
        }
        else if(q1.front()=="Athal")
        {
            row=11;
        }
        else if(q1.front()=="Chak Shahzad")
        {
            row=12;
        }
        else if(q1.front()=="Bani Gala")
        {
            row=13;
        }
        else if(q1.front()=="Bhara Kahu")
        {
            row=14;
        }
        q1.pop();
        for(int j=0;j<15;j++)
        {
            if(arry[row][j]==1 && flag[j]==false)
            {
                flag[j]=true;
                q1.push(name[j]);
            }
        }

    }
}

void topological_sort(int indeg[], string name[], node* list_arry[])
{
    int vertex;
    cout<<"\nGraph traversing by Topological  sort : \n\n";
    queue<string> q2;
    for(int i=0; i<15; i++)
    {
        if(indeg[i]==0)
        {
            q2.push(name[i]);
        }
    }
    while(!q2.empty())
    {
        cout<<q2.front()<<endl;
        if(q2.front()=="PIEAS")
        {
            vertex=0;
        }
        else if(q2.front()=="Chirah")
        {
            vertex=1;
        }
        else if(q2.front()=="Mohara")
        {
            vertex=2;
        }
        else if(q2.front()=="Thanda Pani")
        {
            vertex=3;
        }
        else if(q2.front()=="Ali Pur")
        {
            vertex=4;
        }
        else if(q2.front()=="Taramri")
        {
            vertex=5;
        }
        else if(q2.front()=="Chatta Bakhtawar")
        {
            vertex=6;
        }
        else if(q2.front()=="Jagiot")
        {
            vertex=7;
        }
        else if(q2.front()=="Pind Begwal")
        {
            vertex=8;
        }
        else if(q2.front()=="Kuri")
        {
            vertex=9;
        }
        else if(q2.front()=="Malot")
        {
            vertex=10;
        }
        else if(q2.front()=="Athal")
        {
            vertex=11;
        }
        else if(q2.front()=="Chak Shahzad")
        {
            vertex=12;
        }
        else if(q2.front()=="Bani Gala")
        {
            vertex=13;
        }
        else if(q2.front()=="Bhara Kahu")
        {
            vertex=14;
        }
        q2.pop();
        node* curr = list_arry[vertex];
        while(curr!=NULL)
        {
            indeg[curr->data]= indeg[curr->data]-1;
            if(indeg[curr->data]==0)
            {
                q2.push(name[curr->data]);
            }
            curr=curr->nptr;
        }

    }
}

void add_node(node*& head,int data)
{
    node* ptr;
    if(head==NULL)
    {
    ptr=new node;
    ptr->data=data;
    ptr->nptr=NULL;
    head=ptr;
    }
    else
    {
    node* curr=head;
    while(curr->nptr!=NULL)
    {
        curr=curr->nptr;
    }
    ptr=new node;
    ptr->data=data;
    ptr->nptr=NULL;
    curr->nptr=ptr;
    }
}
