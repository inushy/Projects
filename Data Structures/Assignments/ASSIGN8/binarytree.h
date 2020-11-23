/* 
   	<Anushka Verma>(<Z1911937>)
	Assignment 07
	10/24/2020
	I certify that this is my own work and where appropriate an extension of the starter code provided for the assignment.
*/

#ifndef H_BINARYTREE
#define H_BINARYTREE

#include "node.h" //including the node header

template <class T> class BinaryTree; //prototyping the class BinaryTree

template <typename T> class BinaryTree{

public:
    BinaryTree() {root = NULL;};                         // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree
    typedef enum {left_side, right_side } SIDE;        //helps move nodes in their right location; even numbers will move right and odd will move left
    SIDE rnd(){return rand()%2 ? right_side : left_side;}// End of rnd()

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

//Building our public templates
template <class T>                                      //returns the size of the tree
unsigned BinaryTree<T>::getSize() const
{
	return _getSize(root);
}

template <class T>                                      //returns the height of the tree
unsigned BinaryTree<T>::getHeight() const
{
	return _getHeight(root);
}

template <class T>                                      //Calling the Insert function
void BinaryTree<T>::Insert(const T& x)
{
	_Insert(root, x);
}

template <class T>                                      //Calling the Inorder function
void BinaryTree<T>::Inorder(void (*function)(const T&))
{
	_Inorder(root, function);
}

//Building our private templates
template <class T>                                      //Used a pointer to a Node
unsigned BinaryTree<T>::_getSize(Node<T> *ptr) const
{
	if(ptr == NULL)
	{
		return 0;
	}
	return(_getSize(ptr->left) + 1 + _getSize(ptr->right)); //Returns the size of the tree
}

template <class T>
unsigned BinaryTree<T>::_getHeight(Node<T> *ptr) const
{
	if(!ptr)                                         //When there is no tree then it would return 0
	{
		return 0;
	}
	return 1 + max(_getHeight(ptr->left), _getHeight(ptr->right)); //Returns the height of the tree
}

template <class T>
void BinaryTree<T>::_Insert(Node<T> *&ptr, const T& x)
{
	if(ptr == NULL)
	{
		ptr = new Node<T>();                      //Pointer towards Node which would help create a new node
		ptr->right = NULL;                        //Places it towards the right side when equalled to NULL
		ptr->left = NULL;                         //Places it towards the left side when equalled to NULL
		ptr->data = x;
	}
	else if(rnd() == right_side)                      //We used rnd() to creat a new element which would get inserted into a tree
	{
		_Insert(ptr->right, x);
	}
	else
	{
		_Insert(ptr->left, x);
	}
}

template <class T>                                        //We use recursion to go through the tree
void BinaryTree<T>::_Inorder(Node<T> *ptr, void(*function)(const T&))
{
	if(ptr != NULL)
	{
		_Inorder(ptr->left, function);
		function(ptr->data);
		_Inorder(ptr->right, function);
	}
}
#endif // End of H_BINARYTREE
