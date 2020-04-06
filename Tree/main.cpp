#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

struct Node1
{
    char data;
    Node1* left;
    Node1* right;
    Node1(char x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};


void printPreorder(Node *root)
{
    if(!root)
        return;

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);

}

void inorder(Node *root)
{
    stack<Node*> s;
    while(1)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        if(s.empty())
            break;
        root=s.top();
        cout<<s.top()->data<<" ";
        s.pop();
        root=root->right;
    }
}


void postorder(Node *root)
{
    stack<Node*> s;
    Node* prev=NULL;
    while(1)
    {
        while(root)
        {
            s.push(root);
            prev=root;
            root=root->left;
        }
        while(root==NULL && !s.empty())
        {
            root=s.top();
            if(root->right==NULL ||root->right==prev)
            {
                cout<<root->data<<" ";
                s.pop();
                prev=root;
                root=NULL;
            }
            else
                root=root->right;
        }
        if(s.empty())
            break;
    }
}


void preorder(Node *root)
{
    stack<Node*> s;
    while(1)
    {
        while(root)
        {
            cout<<root->data<<" ";
            s.push(root);
            root=root->left;
        }
       if(s.empty())
            break;
        root=s.top();

        s.pop();
        root=root->right;
    }
}

void post2order(Node *root)
{
    stack<Node*> s;
    while(1)
    {
        while(root)
        {
            s.push(root);
            s.push(root);
            root=root->left;
        }
       if(s.empty())
            break;
        root=s.top();
        s.pop();

        if(!s.empty()&&root==s.top())
        {
            root=root->right;

        }
        else
        {
            cout<<root->data<<" ";
            root=NULL;
        }
    }
}



void printInorder(Node *root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}

void printPostorder(Node *root)
{
    if(!root)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";

}



void levelOrder(Node *root)
{
    queue<Node*> q;
    if(root==NULL)
        return;
    q.push(root);
    while(!q.empty())
    {
        root=q.front();
        q.pop();
        cout<<root->data<<" ";

        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
}

void maxEle(Node *root)
{
    stack<Node*> s;
    int max=0;
    while(1)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        if(s.empty())
            break;
        root=s.top();
        if(max<root->data)
            max=root->data;
        s.pop();
        root=root->right;
    }

    cout<<max;
}

int maxEleR(Node *root)
{
    if(!root)
        return 0;

   int max=root->data;
    int l=maxEleR(root->left);
    int r=maxEleR(root->right);
    if(l>max)
        max=l;
    if(r>max)
        max=r;

    return max;
}

bool search(Node *root,int x)
{
    stack<Node*> s;
    while(1)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        if(s.empty())
            break;
        root=s.top();

       if(s.top()->data==x)
        return true;
        s.pop();
        root=root->right;
    }
    return false;
}

bool searchR(Node *root,int x)
{
    if(!root)
        return false;

    bool a=searchR(root->left,x);
    if(a)
        return a;
    if (root->data==x)
        return true;
    bool b=searchR(root->right,x);

    return b;

}


void levelOrderInsert(Node *root,int x)
{
    queue<Node*> q;
    if(root==NULL)
        return;
    q.push(root);
    while(!q.empty())
    {
        root=q.front();
        q.pop();

        if(root->left)
            q.push(root->left);
        else
            {
                root->left=new Node(x);
                return;
            }
        if(root->right)
            q.push(root->right);
        else
            {
                root->right=new Node(x);
                return;
            }

    }
}

int size(Node *root)
{
    if(!root)
        return 0;
    return(size(root->left)+1+size(root->right));
}

int height(Node *root)
{
    int lht,rht;
    if(root==NULL)
        return 0;
    lht=height(root->left);
    rht=height(root->right);
    if(lht>rht)
        return lht+1;
    else
        return rht+1;
}

int heightNR(Node *root)
{
    queue<Node*> q;
    q.push(root);
    int ht=0;


    int nodect=0;
    nodect=1;
    while(!q.empty())
    {
        int ct=0;
        while(nodect--)
        {
            root=q.front();
            q.pop();
            if(root->left)
            {
                ct++;
                q.push(root->left);
            }
            if(root->right)
            {
                ct++;
                q.push(root->right);
            }
        }
        ht++;
        nodect=ct;
    }
    return ht;
}

Node* deepNode(Node *root)
{
    queue<Node*> q;
    if(root==NULL)
        return NULL;
    q.push(root);
    while(!q.empty())
    {
        root=q.front();
        q.pop();

        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
    return root;
}

void delNode(Node *root,int x)
{
    Node *temp=deepNode(root);
    int a=temp->data;


    queue<Node*> q;
    if(root==NULL)
        return ;
    q.push(root);
    while(!q.empty())
    {
        root=q.front();
        q.pop();
        if(root->left==temp)
            root->left=NULL;
        else if(root->right==temp)
            root->right=NULL;
        else if(root==temp)
            root=NULL;

        if(root->data==x)
        {
           root->data=a;

        }
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);

    }
}

int numLeave(Node* root)
{
     queue<Node*> q;
     int ct=0;
    if(root==NULL)
        return 0;
    q.push(root);
    while(!q.empty())
    {
        root=q.front();
        q.pop();
        if(!root->left&&!root->right)
            ct++;

        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
    return ct;
}

int numLeaveR(Node *root)
{
    if(!root)
        return 0;
    if(!root->left&&!root->right)
        return 1;

    return (numLeaveR(root->left)+numLeaveR(root->right));
}

void sumLevel(Node* root)
{
    if(root==NULL)
        return;
    queue<Node* >q;
    q.push(root);
    int max=0;
    int nodeCt=1;
    while(!q.empty())
    {

        int ct=0;
        int sum=0;
        while(nodeCt--)
        {
            Node *root=q.front();
            q.pop();
            sum+=root->data;
            if(root->left)
            {
                ct++;
                q.push(root->left);
            }
            if(root->right)
            {
                ct++;
                q.push(root->right);
            }
        }
        nodeCt=ct;
        if(sum>max)
            max=sum;
    }
    cout<<"\nMax="<< max<<endl;
}

void printArr(int path[],int pathLen)
{
    for(int i=0;i<pathLen;i++)
        cout<<path[i]<<" ";
    cout<<endl;
}


void rootToLeaf(Node* root,int path[],int pathLen)
{
    if(root==NULL)
        return ;
    path[pathLen++]=root->data;

    if(!root->left&&!root->right)
        printArr(path,pathLen);

    rootToLeaf(root->left,path,pathLen);
    rootToLeaf(root->right,path,pathLen);
}

void checkSum(Node* root,int path[],int pathLen,int sum,int curr)
{
    if(root==NULL)
        return ;
    path[pathLen++]=root->data;
    curr+=root->data;
    if(sum==curr)
        printArr(path,pathLen);

    checkSum(root->left,path,pathLen,sum,curr);
    checkSum(root->right,path,pathLen,sum,curr);
}

void printVec(vector<int>& path)
{
    for(int i=0;i<path.size();i++)
        cout<<path[i]<<" ";
    cout<<endl;
}


bool findPath(Node* root,int a,vector<int>& path)
{
    if(root==NULL)
        return false;
    path.push_back(root->data);

    if(root->data==a)
    {
        return true;
    }

    if((root->left&&findPath(root->left,a,path))||(root->right&&findPath(root->right,a,path)))
        return true;

    path.pop_back();
    return false;
}

void LCA(Node* root,int a,int b)
{
    if(root==NULL)
        return;
    vector<int> path1;
    vector<int> path2;
    int temp=-1;

    if(!findPath(root,a,path1)||!findPath(root,b,path2))
    {
        cout<<"Not found"<<endl;
        return;
    }

    for(int i=0;i<path1.size();i++)
    {
        if(path1[i]!=path2[i])
            break;
        temp=path1[i];
    }
    cout<<"LCA="<<temp<<endl;
}

Node* LCAr(Node *root,int a,int b)
{
    if(root==NULL)
        return NULL;

    if(root->data==a||root->data==b)
        return root;

    Node* left=LCAr(root->left,a,b);
    Node* right=LCAr(root->right,a,b);

    if(left&&right)
        return root;
    return left?left:right;
}

Node1* buildTree(char in[],char pre[],int stIn,int endIn,unordered_map<char,int>& mp)
{
    static int preInd=0;
    char ch=pre[preInd++];
    Node1 *temp=new Node1(ch);

    int ind=mp[ch];

    if(stIn>endIn)
        return NULL;

    if(stIn==endIn)
        return temp;

    temp->left=buildTree(in,pre,stIn,ind-1,mp);
    temp->right=buildTree(in,pre,ind+1,endIn,mp);

    return temp;

}


Node1* buldTreeWrap(char in[],char pre[],int len)
{
    unordered_map<char,int> mp;
    for(int i=0;i<len;i++)
    {
        mp[in[i]]=i;
    }

    Node1 *r=buildTree(in,pre,0,len-1,mp);
    return r;

}
void inorder1(Node1 *root)
{
    stack<Node1*> s;
    while(1)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        if(s.empty())
            break;
        root=s.top();
        cout<<s.top()->data<<" ";
        s.pop();
        root=root->right;
    }
    cout<<endl;
}

void ances(Node* root,int path[],int pathLen,int k)
{
    if(root==NULL)
        return ;
    path[pathLen++]=root->data;

    if((root->left&&root->left->data==k)||(root->right&&root->right->data==k))
        printArr(path,pathLen);

    ances(root->left,path,pathLen,k);
    ances(root->right,path,pathLen,k);
}

int ancestor(Node* root,int k)
{
    if(root==NULL)
        return 0;
    if(root->data==k)
    return 1;

    if(ancestor(root->left,k)||ancestor(root->right,k))
    {
        cout<<root->data<<" ";
        return 1;
    }
    return 0;

}

void zigzag(Node* root)
{
    if(root==NULL)
        return;
    queue<Node* > q;
    q.push(root);
    stack<int> s;
    int nodeCt=1,ct, flag=0;
    while(!q.empty())
    {
        ct=0;
        while(nodeCt--)
        {
            Node* temp=q.front();
            q.pop();
            if(flag==0)
            {
                cout<<temp->data<<" ";
            }
            else
            {
                s.push(temp->data);
            }

            if(temp->left)
            {
                q.push(temp->left);
                ct++;
            }
            if(temp->right)
            {
                q.push(temp->right);
                ct++;
            }
        }
        if(flag==0)
            flag=1;
        else
        {
            flag=0;
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
            }

        }
        nodeCt=ct;
    }

}

void printVO(Node *root,int col,unordered_map<int,int>& mp)
{
    if(root==NULL)
    return;
    mp[col]+=root->data;

    printVO(root->left,col-1,mp);
    printVO(root->right,col+1,mp);
}

void verticalSumOrder(Node *root)
{
    unordered_map<int,int> mp;
    int i;
    for(i=-5;i<5;i++)
    mp[i]=0;

    printVO(root,0,mp);
    for(i=-5;i<5;i++)
    {
        if(mp[i]>0)
        {
            cout<<mp[i]<<" ";
        }
    }
    cout<<endl;

}


void printVO(Node *root,int col,map<long,vector<long>>& mp)
{
    if(root==NULL)
    return;

    mp[col].push_back(root->data);

    printVO(root->left,col-1,mp);
    printVO(root->right,col+1,mp);
}



void verticalOrder(Node *root)
{
    //Your code here
    map<long,vector<long>> mp;

    printVO(root,0,mp);
    map< long,vector<long> > :: iterator i;

    for(i=mp.begin();i!=mp.end();i++)
    {
        for(int j=0;j<i->second.size();j++)
        {
            cout<<i->second[j]<<" ";
        }
    }
    cout<<endl;
}


int main()
{
    Node *root=NULL;
    Node* temp1=new Node(1);
    Node* temp2=new Node(2);
    Node* temp3=new Node(3);
    Node* temp4=new Node(8);
    Node* temp5=new Node(5);
    Node* temp6=new Node(6);
    Node* temp7=new Node(7);
    root=temp1;
    root->left=temp2;
    root->right=temp3;
    root->left->left=temp4;
    root->left->right=temp5;
    root->right->left=temp6;
    root->right->right=temp7;

    printPreorder(root);
    cout<<endl;
    printInorder(root);
    cout<<endl;
    printPostorder(root);
    cout<<endl;

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    post2order(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;

    maxEle(root);
    cout<<endl;

    cout<<maxEleR(root)<<endl;

    if(search(root,59))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;


    if(searchR(root,5))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
    cout<<"height ="<<height(root)<<endl;
    cout<<"height ="<<heightNR(root)<<endl;


    levelOrderInsert(root,100);
    levelOrder(root);

    cout<<endl;

    cout<<"size="<<size(root)<<endl;

    cout<<"height ="<<height(root)<<endl;
    cout<<"height ="<<heightNR(root)<<endl;
    cout<<"deepestNode= "<<deepNode(root)->data<<endl;

    delNode(root,3);
    levelOrder(root);
    cout<<endl;
    cout<<"No of leafs="<<numLeave(root)<<endl;
    cout<<"No of leafs="<<numLeaveR(root)<<endl;

    levelOrder(root);
    cout<<endl;
    sumLevel(root);
    cout<<endl;

    int path[1000];
    rootToLeaf(root,path,0);

    checkSum(root,path,0,101,0);

    LCA(root,7,6);

    cout<<"LCA=" <<LCAr(root,8,7)->data<<endl;


    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);

    Node1* root1 = buldTreeWrap(in, pre, len);

    /* Let us test the built tree by printing
      Insorder traversal */
    printf("Inorder traversal of the constructed tree is \n");
    inorder1(root1);


    ances(root,path,0,8);
    ancestor(root,8);
    cout<<endl;
    zigzag(root);
    cout<<endl;

    verticalSumOrder(root);
    verticalOrder(root);


    int pr[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);

    // construct the above tree
//    root = constructTree (pre, preLN, n);

    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder (root);



    cout << "Hello world!" << endl;
    return 0;
}
