#include "Tree.hpp"
#include <iostream>

using namespace std;

ariel::Tree::Tree():_root(NULL) {}
ariel::Tree::~Tree(){
  delete _root;
}

int ariel::Tree::root() {
    if(_root == NULL) {throw std::invalid_argument("Exception,the tree is empty");} 
    return _root->value();
}


int ariel::Tree::left(int i) {
    if(!contains(i)){
      throw std::invalid_argument("Exception, i value not exist in this tree");
    }
    return _root->left(i);
}


int ariel::Tree::right(int i) {
    if(!contains(i)){
      throw std::invalid_argument("Exception, i value not exist in this tree");
    }
    return _root->right(i);
}


int ariel::Tree::size() {
    if(_root == NULL) return 0;
    return _root->size();
}



bool ariel::Tree::contains(int i) {
    if(_root == NULL || size() == 0) return false;
    else return _root->contains(i);
}



int ariel::Tree::parent(int i) {
    if(_root == NULL||_root->value()==i) {throw std::invalid_argument("Exception, no such element");}
    else return _root->parent(i);
}


ariel::Tree& ariel::Tree::insert(int i) {
    if(contains(i)) {throw std::invalid_argument("Exception,already exsists");}
    if(_root == NULL) _root = new TreeNode(i);
    else _root = _root->insert(i);
    return *this;
}

ariel::Tree& ariel::Tree::remove(int i) {
    if(!contains(i)){throw std::invalid_argument("Exception, i not exist in the tree");}
    else{
    // ariel::TreeNode* deleted = _root->getByValue(i);
    _root = _root->remove(i);
    // deleted->RemoveChild();
    // delete deleted;
    // deleted = NULL;
    }
    return *this;
}

void ariel::Tree::print() {
  if(_root != NULL){
      _root->print();
      cout<<""<<endl;
    }
    else{
      throw std::invalid_argument("Exception");
    }
}

ariel::TreeNode::TreeNode(int val):_value(val),_right(NULL),_left(NULL) {}
ariel::TreeNode::~TreeNode(){
  delete _right;
  delete _left;
}
int ariel::TreeNode::value() {return _value;}

bool ariel::TreeNode::contains(int i) {
    if(_value==i) return true;
    else if(i<_value){
        if(_left== NULL) return false;
        else return _left->contains(i);
    }
    else{
        if(_right == NULL) return false;
        else return _right->contains(i);
    }
}

int ariel::TreeNode::size() {
    int leftCount = 0;
    int rightCount = 0;
    if(_left!= NULL) leftCount = _left->size();
    if(_right!= NULL) rightCount = _right->size();
    return leftCount+rightCount+1;
}

ariel::TreeNode* ariel::TreeNode::insert(int i) {
  if(!contains(i)){
    if(i<_value){
        if(_left == NULL) _left = new TreeNode(i);
        else _left = _left->insert(i);
    }
    else{
        if(_right == NULL) _right = new TreeNode(i);
        else _right = _right->insert(i);
    }
    return this;
  }
  else{
    throw std::invalid_argument("Exception");
  }
}

ariel::TreeNode* ariel::TreeNode::remove(int i) {
	if(i<_value) _left = _left->remove(i);
	else if(i>_value) _right = _right->remove(i);
	else{
		if(_left == NULL && _right != NULL) return _right;
		else if(_right == NULL && _left != NULL) return  _left;
		else if( _right == NULL && _left == NULL){
			TreeNode* temp = this;
			delete temp;
			return this;
		}
		else{
			int minVal = _right->minVal();
			_value = minVal;
			setRight(_right->remove(minVal));
			 }
		}
	}
	return this;
}

int ariel::TreeNode::minVal() {
    if(_left == NULL) return _value;
    else return _left->minVal();
}


int ariel::TreeNode::parent(int i) {
	if(i<_value){
        if(_left->value() == i) return _value;
        else return _left->parent(i);
    }
    else{
        if(_right->value() == i) return _value;
        else return _right->parent(i);
    }
}

int ariel::TreeNode::left(int i) {
    if(_value == i) return _left->_value;
    else if(i<_value) return _left->left(i);
    else return _right->left(i);
}

int ariel::TreeNode::right(int i) {
    if(_value == i) return _right->_value;
    else if(i<_value) return _left->right(i);
    else return _right->right(i);
  }
}

ariel::TreeNode* ariel::TreeNode::getByValue(int i) {
  if(contains(i)){
    if(i==_value) return this;
    else if(i<_value) return _left->getByValue(i);
    else return _right->getByValue(i);
  }
  else{
    throw std::invalid_argument("Exception,i not exist in tree");
  }
}


void ariel::TreeNode::print() {
    if(_left!= NULL) _left->print();
    std::cout<<_value<<",";
    if(_right!= NULL) _right->print();
}


void ariel::TreeNode::RemoveChild() {
    _left= NULL;
    _right= NULL;
  }
