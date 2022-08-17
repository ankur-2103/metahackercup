#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left=NULL;
    node* right=NULL;
};

node* newNode(int data){
    node* temp = new node;
    temp->data = data;
    return temp;
}

node* insert(node* root, int data){
    node* newnode = newNode(data);
    node* curr = root;
    node* prev = NULL;
    while(curr!=NULL){
        prev = curr;
        if(data<=curr->data){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }
    if(prev==NULL){
        prev = newnode;
    }else if(data <= prev->data){
        prev->left = newnode;       
    }else{
        prev->right = newnode;
    }
    return prev;
}

node* FindMin(node* root){
    while(root->left != NULL)root = root->left;
    return root;
}

node* Delete(node* root, int data){
    if(root==NULL)return root;
    else if(data < root->data)root->left = Delete(root->left, data);
    else if(data > root->data)root->right = Delete(root->right, data);
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
        }else if(root->left == NULL){
            node* temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == NULL){
            node* temp = root;
            root = root->left;
            delete temp;
        }else{
            node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void Inorder(node* root){
    if(root==NULL){
        return;
    }else{
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

void Preorder(node* root){
    if(root == NULL){
        return;
    }else{
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(node* root){
    if(root==NULL){
        return;
    }else{
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

void Levelorder(node* root){
    if(root==NULL)return;
    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        node* curr = q.front();
        cout << curr->data << " ";
        if(curr->left != NULL)q.push(curr->left);
        if(curr->right != NULL)q.push(curr->right);
        q.pop();
    }
}

int main(){
    node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 25);
    insert(root, 15);
    insert(root, 50);
    insert(root, 15);
    insert(root, 10000);
    insert(root, -1);
    insert(root, 3);
    insert(root, 0);
    cout << "Inorder : ";
    Inorder(root);
    cout << endl;
    root = Delete(root, 10);
    cout << "After Deleting Inorder : ";
    Inorder(root);
    cout << endl;
    cout << "Preorder : ";
    Preorder(root);
    cout << endl;
    cout << "Postorder : ";
    Postorder(root);
    cout << endl;
    cout << "Levelorder : ";
    Levelorder(root);
    cout << endl;
    return 0;
}