/*
    <Anushka Verma>(<Z1911937>)
	Assignment 08
	11/01/2020
	I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "binarytree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};

template <class T>
void BinarySearchTree<T>::Insert(const T &x)
{
    _Insert(this->root, x);
}
template <class T>
void BinarySearchTree<T>::_Insert(Node<T> *&ptr, const T &x)   //Inserts nodes to the binary search trees
{
    if (ptr == NULL)
    {
       ptr = new Node<T>(x);        //Pointer towards Node which would help create a new node
    }
    else
    {
        if ( x < ptr -> data)
        {
            _Insert(ptr -> left, x);
        }
        else if ( x > ptr -> data)
        {
            _Insert(ptr -> right, x);
        }

    }
}
template <class T>
bool BinarySearchTree<T>::Search(const T &x) const //Bool used to help call the recursive method for the search function
{
    return _Search(this->root, x);  //Our return statement returns true when the x in our root is found and false when it is not found
}

template <class T>
bool BinarySearchTree<T>::_Search(Node<T> *ptr, const T &x) const
{
    if (ptr == NULL)
    {
        return false;
    }
    else
    {
        if ( x == ptr -> data && _Leaf(ptr))  //Checks to see if the data is correct AND it's a leaf, then it returns true
        {
            return true;
        }
        else if (x < ptr -> data)
        {
            return _Search(ptr -> left, x);
        }
        else
        {
            return _Search(ptr -> right, x);
        }
        
    }
}

template <class T>
bool BinarySearchTree<T>::Remove(const T &x)
{
  if (Search(x) == true)
  {
      _Remove(this->root, x);
      return true;
  }
  else
  {
      return false;
  }
}

template <class T>
void BinarySearchTree<T>::_Remove(Node<T> *&ptr, const T &x)  
{
    if (x == ptr -> data) //Setting my node to NULL
    {
        ptr = NULL;
    }
    else if (ptr == NULL || ptr -> data == x) //Checking to see it's NULL, if so, then it removes the node
    {
        _Remove(ptr, x);
    }
    else
    {
        if ( x < ptr -> data)
        {
            _Remove(ptr -> left, x);
        }
        else
        {
            _Remove(ptr -> right, x);
        }
        
    }
} 
template <class T>
bool BinarySearchTree<T>::_Leaf(Node<T> *node) const  //A leaf is a node which has no children, therefore, this function checks to see if the node has children
{
  if (node == NULL)
  {
      return false;
  }
  else
  {
      if ( node -> left == NULL && node -> right == NULL)
      {
          return true;
      }
      else 
      {
          return false;
      }
  }
}

#endif
