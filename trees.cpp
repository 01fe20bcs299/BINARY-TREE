#include<iostream>
using namespace std;
#include <bits/stdc++.h>
#include<queue>
class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node *create(node *&root)
{
    int d;
    cout<<"enter d"<<endl;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    root=new node(d);
    root->left=create(root->left);
    root->right=create(root->right);
    return root;

}
void print(node *&root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<endl;
        print(root->left);
        print(root->right);
    }
}
int height(node *&root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}
void printklevel(node *&root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==1)
    {
        cout<<root->data<<endl;
    }
    printklevel(root->left,k-1);
    printklevel(root->right,k-1);

}
int countt(node *&root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lc=countt(root->left);
    int rc=countt(root->right);
    return lc+rc+1;
}
void bfs(node *&root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node *f=q.front();
        q.pop();
        cout<<f->data<<",";
        if(f->left!=NULL)
        {
            q.push(f->left);
        }
        if(f->right!=NULL)
        {
            q.push(f->right);
        }

    }
}
int diameter(node *&root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh+rh+1,max(ld,rd));
}
bool isBalanced(node *&root)
   {
       if(root == NULL)
       {
           return true;
       }
       bool left = isBalanced(root->left);
       bool right = isBalanced(root->right);
       bool diff = abs(height(root->left) - height(root->right)) <= 1;

       if(diff&&left&&right)
       {
           return true;
       }
       return false;
   }
void findparent(node *&root,int value,int parent)
   {
       if(root==NULL)
       {
           return;
       }
       if(root->data==value)
       {
           cout<<parent<<endl;
       }
       else
       {
       findparent(root->left,value,root->data);
       findparent(root->left,value,root->data);
       }


   }
int sum(node *&root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=sum(root->left);
    int rs=sum(root->right);
    return root->data+ls+rs;
}
int repsum(node *&root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return root->data;
    }
    int ls=repsum(root->left);
    int rs=repsum(root->right);
    int temp=root->data;
    root->data=ls+rs;
    return temp+root->data;
}
int main()
{
    node *root=NULL;
    create(root);
    create(root);
    create(root);
   // print(root);
   // cout<<height(root)<<endl;
   // printklevel(root,3);
  //bfs(root);
  //cout<<diameter(root);
 // repsum(root);
  //bfs(root);
// cout<<isBalanced(root)<<endl;
findparent(root,3, -1);

}
