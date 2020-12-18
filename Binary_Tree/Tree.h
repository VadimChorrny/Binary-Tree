
#pragma once

#include <iostream>


using namespace std;


template<typename T>
class Tree
{
public:
	Tree() = default;
	void print() const;
	void add(const T& data);
	bool isEmpty() const;
	size_t getSize() const;
	const bool findElement(const T& search);
	const T max();
	const T min();
	//void printBigger(const T& data);
	void clear();
	~Tree();
	//const T& max() const;
	//bool find(const T& data);
private:
	// simple struct



	struct Node
	{
		T data;
		Node* left;
		Node* right;
		Node* parent;
		Node(const T& data = T(), Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr)
			:data(data),left(left), right(right),parent(parent)
		{}
	};



	Node* root = nullptr;

	size_t size = 0;

	void printHelper(Node* node) const;

	void clear(Node*);

};

//template<typename T>
//inline Tree<T>::~Tree()
//{
//	clear();
//}

template<typename T>
inline void Tree<T>::print() const
{
	cout << "Tree : \t";
	printHelper(root);
}

template<typename T>
inline void Tree<T>::add(const T& data)
{

	Node* addNode = new Node(data);
	++size;
	if (isEmpty())
	{
		root = addNode;
		return;
	}
	bool found = false;
	Node* tmp = root;
	while (!found)
	{
		if (data > tmp->data)
		{
			if (tmp->right == nullptr)
			{
				tmp->right = addNode;
				addNode->parent = tmp;
				found = true;
			}
			else
			{
				tmp = tmp->right;
			}
		}
		else
		{
			if (tmp->left == nullptr)
			{
				tmp->left = addNode;
				addNode->parent = tmp;
				found = true;
			}
			else
			{
				tmp = tmp->left;
			}
		}

	}
}

template<typename T>
inline bool Tree<T>::isEmpty() const
{
	return root == nullptr;
}

template<typename T>
inline size_t Tree<T>::getSize() const
{
	return size;
}

template<typename T>
 inline bool const Tree<T>::findElement(const T& search)
{
	 Node* found = root;
	 while (!found)
	 {
		 if (data >= search)
		 {

			 while (true)
			 {

			 }

		 }
	 }
	 
	

}

template<typename T>
inline const T Tree<T>::max()
{
	Node* tmp = root;
	if (isEmpty())
	{
		cout << "def" << endl;
		return T();
	}
	while(tmp->right != nullptr)
	{
		tmp = tmp->right;
	}
	return tmp->data;
}

template<typename T>
inline const T Tree<T>::min()
{
	Node* min = root;
	if (isEmpty())
	{
		cout << "def" << endl;
		return T();
	}
	while (min->left != nullptr)
	{
		min = min->left;
	}
}

template<typename T>
inline void Tree<T>::clear()
{
	clear(root);
	root = nullptr;
	size = 0;
}

template<typename T>
inline Tree<T>::~Tree()
{
	clear();
}

template<typename T>
inline void Tree<T>::printHelper(Tree<T>::Node* node) const
{
	if (node != nullptr)
	{
		printHelper(node->left);
		cout << node->data << endl;
		printHelper(node->right);
	}
}

template<typename T>
inline void Tree<T>::clear(Node* node)
{
	if (node!= nullptr)
	{
		clear(node->left);

		clear(node->right);
		cout << "________DELETED______" << node->data << endl;
		delete node;
	}
}
