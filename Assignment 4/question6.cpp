#include<bits/stdc++.h>
using namespace std;

struct Tree{
    int val;
    Tree* left;
    Tree* right;
    Tree(int v):val(v), left(nullptr), right(nullptr) {}
};

bool checkIsomorphic(Tree* t1, Tree* t2){
    if (t1 == nullptr && t2 == nullptr) {
        return true;
    }
    if (t1 == nullptr || t2 == nullptr) {
        return false;
    }
    else
        return ( checkIsomorphic(t1->left,t2->left) && checkIsomorphic(t1->right,t2->right) );
}

int main(){
    // Example 1
    // Tree* t1 = new Tree(1);
    // Tree* t2 = new Tree(10);

    // t1->left = new Tree(2);
    // t1->right = new Tree(3);

    // t1->left->left = new Tree(4);
    // t1->left->right = new Tree(5);
    // t1->right->right = new Tree(6);

    // t2->left = new Tree(9);
    // t2->right = new Tree(6);

    // t2->left->left = new Tree(2);
    // t2->left->right = new Tree(1);
    // t2->right->right = new Tree(7);

    // cout << checkIsomorphic(t1, t2) << endl;

    // Example 2
    Tree* t1 = new Tree(1);
    Tree* t2 = new Tree(1);

    t1->left = new Tree(2);
    t1->right = new Tree(3);

    t1->left->left = new Tree(4);
    t1->right->right = new Tree(5);

    t2->left = new Tree(2);
    t2->right = new Tree(3);

    t2->left->left = new Tree(5);
    t2->right->left = new Tree(4);

    cout << checkIsomorphic(t1, t2) << endl;

    // Example 3
    // Tree* t1 = new Tree(1);
    // Tree* t2 = new Tree(1);

    // t1->left = new Tree(2);
    // t1->right = new Tree(3);

    // t1->left->left = new Tree(4);
    // t1->left->right = new Tree(5);

    // t2->left = new Tree(2);
    // t2->right = new Tree(3);

    // t2->left->left = new Tree(4);
    // t2->right->left = new Tree(5);

    // cout << checkIsomorphic(t1, t2) << endl;
}