#pragma once

#include <iostream>
using namespace std;
namespace ariel{


    class TreeNode{
    public:
        TreeNode(int val);
        ~TreeNode();
        TreeNode* insert(int i);
        TreeNode* remove(int i);
        int size();
        bool contains(int i);
        int value();
        int parent(int i);
        int left(int i);
        int right(int i);
        void print();
        TreeNode* getByValue(int i);
        void RemoveChild();

    private:
        int _value;
        TreeNode* _left;
        TreeNode* _right;
        int minVal();
    };

    class Tree{
    public:
        Tree();
        ~Tree();
        Tree& insert(int i);
        Tree& remove(int i);
        int size();
        bool contains(int i);
        int root();
        int parent(int i);
        int left(int i);
        int right(int i);
        void print();

    private:
        TreeNode* _root;
    };
};
