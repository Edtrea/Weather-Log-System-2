/**
 * @file BST.H
 * @author Lim Wen Chao
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * 
 */

#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

    /**
     * @brief Represents a node in a Bst
     * 
     * @tparam T 
     */
template <class T>
struct Node
{
    T value;
    Node<T>* leftNode = nullptr;
    Node<T>* rightNode = nullptr;
};

template <class T>
class Bst{
    public:
            /**
             * @brief Construct a new Bst object
             * 
             */
        Bst();
            /**
             * @brief Copy constructor
             * 
             * @param otherTree - The tree to copy from
             */
        Bst(const Bst<T>& otherTree);
            /**
             * @brief Destroy the Bst object
             * 
             */
        ~Bst();

            /**
             * @brief Destroys Bst
             * 
             */
        void DeleteTree();

            /**
             * @brief Operator overload of = that works the same as copy constructor
             * 
             * @param otherTree - the Tree to copy from
             * @return Bst<T>& - The tree to copy to
             */
        Bst<T>& operator = (const Bst<T>& otherTree);

            /**
             * @brief Search if a value exist in Bst
             * 
             * @param searchItem - The value to search for
             * @return true - If value is found
             * @return false - If value is not found
             */
        bool Search(const T& searchItem) const;
            /**
             * @brief Inserts a node with insertItem's value to Bst
             * 
             * 
             * @param insertItem - The value to insert
             */
        void Insert(const T& insertItem);
            /**
             * @brief Deletes a node with deleteItem's value in Bst
             * 
             * @param deleteItem - The value to delete
             */
        void DeleteNode(const T& deleteItem);
            /**
             * @brief Count the number of nodes in a tree
             * 
             * @return int - The total number of nodes
             */
        int TreeNodeCount() const;
        
            /**
             * @brief Traverse the bst in an in-order fashion and print the values
             * 
             */
        void InOrderTraversal() const;
            /**
             * @brief Traverse the bst in an pre-order fashion and print the values
             * 
             */
        void PreOrderTraversal() const;
            /**
             * @brief Traverse the bst in an post-order fashion and print the values
             * 
             */
        void PostOrderTraversal() const;

            /**
             * @brief Traverse the bst in an in-order fashion and pass node's value into the function
             * 
             * @param visit - A function pass as parameter
             */
        void InOrderTraversal(void (*visit) (T&)) const;
            /**
             * @brief Traverse the bst in an pre-order fashion and pass node's value into the function
             * 
             * @param visit - A function pass as parameter
             */
        void PreOrderTraversal(void (*visit) (T&)) const;
            /**
             * @brief Traverse the bst in an post-order fashion and pass node's value into the function
             * 
             * @param visit - A function pass as parameter
             */
        void PostOrderTraversal(void (*visit) (T&)) const;

            /**
             * @brief Find the highest value in a Bst. Function only for int/float values
             * 
             * @return float - The highest value
             */
        float InOrderGetMaxFloat() const;
            /**
             * @brief Find the highest value in Bst determined by function passed as parameter. This is only for int/float values
             * 
             * @param visit - Function passed as parameter. Returns float and accepts T as parameter
             * @return float - The highest value
             */
        float InOrderGetMaxFloat(float (*visit) (T&)) const;
            /**
             * @brief Get the total Value of bst. For int/float values only
             * 
             * @return float - the total value
             */
        float GetSumValueFloat()const;
            /**
             * @brief Get the total value of bst determined by function passed as parameter. For only int/float values
             * 
             * @param visit - Function passed as parameter. returns float and accepts T as parameter
             * @return float - The total value
             */
        float GetSumValueFloat(float (*visit) (T&))const;
            /**
             * @brief Get a string result of Bst based provided searchValue and function passed as parameter. 
             * 
             * @param visit - Function passed as parameter. returns string and accepts T and a float as parameter
             * @param searchValue - The value being passed into visit
             * @return string - The string result
             */
        string GetStringByFloatValue(string (*visit) (T&, float), float searchValue) const;

    private:
            /**
             * @brief The root Node of bst
             * 
             */
        Node<T> *root;

            /**
             * @brief Copies one tree's nodes into another tree
             * 
             * @param copiedTreeRoot - The tree being copied to
             * @param otherTreeRoot - The tree being copied from
             */
        void CopyTree(Node<T>* &copiedTreeRoot, Node<T>* otherTreeRoot);

            /**
             * @brief Inserts a node into tree. Checks if newNode's value is larger or smaller than parent node before inserting
             * 
             * @param newNode - The node to be inserted
             * @param parent - The existing Node being compared with newNode
             */
        void Insert(Node<T>* &newNode, Node<T>* &parent);
            /**
             * @brief Search the tree for a given value and return if it exist or not
             * 
             * @param root - The node being checked
             * @param searchItem - The value being searched
             * @return true - If searchItem found
             * @return false - If searchItem not found
             */
        bool Search(const Node<T>* root, const T& searchItem) const;
            /**
             * @brief Deletes the entire tree
             * 
             * @param p - The node to start deleting from
             */
        void Destroy(Node<T>* &p);
            /**
             * @brief Delete a Node from Tree and move all nodes up to replace the deleted node
             * 
             * @param p - The node to delete
             */
        void DeleteFromTree(Node<T>* &p);
            /**
             * @brief Count the number of node in tree
             * 
             * @param p - The node to start counting from
             * @return int - The total node count
             */
        int NodeCount(Node<T>* p) const;
            
            /**
             * @brief Traverse the tree in an in-order fashion and print the value
             * 
             * @param p - The node to start traversing from
             */
        void InOrder(Node<T>* p) const;
            /**
             * @brief Traverse the tree in an pre-order fashion and print the value
             * 
             * @param p - The node to start traversing from
             */
        void PreOrder(Node<T>* p) const;
            /**
             * @brief Traverse the tree in an post-order fashion and print the value
             * 
             * @param p - The node to start traversing from
             */
        void PostOrder(Node<T>* p) const;

            /**
             * @brief Traverses the tree in an in-order fashion and pass node value to given function
             * 
             * @param p - Node to start traversing from
             * @param visit - A function passed as parameter. accepts T as parameter
             */
        void InOrder(Node<T>* p, void(*visit)(T&)) const;
            /**
             * @brief Traverses the tree in an pre-order fashion and pass node value to given function
             * 
             * @param p - Node to start traversing from
             * @param visit - A function passed as parameter. accepts T as parameter
             */
        void PreOrder(Node<T>* p, void (*visit) (T&)) const;
            /**
             * @brief Traverses the tree in an post-order fashion and pass node value to given function
             * 
             * @param p - Node to start traversing from
             * @param visit - A function passed as parameter. accepts T as parameter
             */
        void PostOrder(Node<T>* p, void (*visit) (T&)) const;
            
            /**
             * @brief Get the highest value in tree. Only for int/float values
             * 
             * @param p - The node to start traversing from
             * @param highest - The starting value of highest value default 0
             * @return float - The highest value found
             */
        float GetMaxFloat(Node<T>* p, float highest) const;
            /**
             * @brief Get the highest value in tree based on given function. only for int/float values
             * 
             * @param p - The node to start traversing from
             * @param visit - function passed as parameter. accepts T as parameter.
             * @param highest - The starting value of highest value default 0
             * @return float - The highest value found
             */
        float GetMaxFloat(Node<T>* p, float(*visit)(T&), float& highest) const;
            /**
             * @brief Get the total value of tree. only for int/float values
             * 
             * @param p - the node to start traversing from
             * @param total - The starting total value default 0
             * @return float - The total value
             */
        float SumValueFloat(Node<T>* p, float& total) const;
            /**
             * @brief Get the total value of tree based on given function. Only for int/float values
             * 
             * @param p - The node to start traversing from
             * @param visit - a function passed as parameter. Accepts T as parameter
             * @param total - The starting total value default 0
             * @return float - The total value
             */
        float SumValueFloat(Node<T>* p, float(*visit)(T&), float& total) const;
            /**
             * @brief Get string value from Node by given function and search value. For int/float values
             * 
             * @param p - The node to start traversing from
             * @param visit - A function passed as parameter. Accepts T and a float value as parameter
             * @param searchValue - The value being passed into given function
             * @return string - The result
             */
        string StringByFloatValue(Node<T>* p, string (*visit) (T&, float), float searchValue) const;
}; 

template<class T>
Bst<T>::Bst()
{
    root = nullptr;
}

template<class T>
Bst<T>::Bst(const Bst<T>& otherTree)
{
        //Check if otherTree is empty
    if(otherTree.root == nullptr)
    {
        root = nullptr;
    }
    else
    {
        CopyTree(root, otherTree.root);
    }
}

template<class T>
Bst<T>::~Bst()
{
    Destroy(root);
}

template <class T>
void Bst<T>::DeleteTree()
{
    Destroy(root);
}

template<class T>
void Bst<T>::Destroy(Node<T>* &p)
{
        //Check if Node is empty
    if(p != nullptr)
    {
        Destroy(p->leftNode);
        Destroy(p->rightNode);
        delete p;
        p = nullptr;
    }
}

template<class T>
Bst<T>& Bst<T>::operator = (const Bst<T>& otherTree)
{
        //Check both tree are not the same
    if(this != &otherTree)
    {       
            //If the tree being copied to is not empty. Delete the tree
        if(root != nullptr)
        {
            Destroy(root);
        }
            //If otherTree is not empty then copy
        if(otherTree.root == nullptr)
        {
            root = nullptr;
        }
        else
        {
            CopyTree(root ,otherTree.root);
        }
    }

    return *this;
}

template <class T>
void Bst<T>::CopyTree(Node<T>* &copiedTreeRoot, Node<T>* otherTreeRoot)
{
    if(otherTreeRoot == nullptr)
    {
        copiedTreeRoot = nullptr;
    }
    else
    {
        copiedTreeRoot = new Node<T>;
        copiedTreeRoot->value = otherTreeRoot->value;
        CopyTree(copiedTreeRoot->leftNode, otherTreeRoot->leftNode);
        CopyTree(copiedTreeRoot->rightNode, otherTreeRoot->rightNode);
    }
}

template <class T>
bool Bst<T>::Search(const T& searchItem) const 
{
    return Search(root, searchItem);
}
template <class T>
bool Bst<T>::Search(const Node<T>* root ,const T& searchItem) const
{
    /*
    Node<T>* current;
    bool found = false;

    if(root == nullptr)
    {
        cout << "Cannot search an empty tree." << endl;
    }
    else
    {
        current = root;

        while(current != nullptr && !found)
        {
            if(current->value == searchItem)
            {
                found = true;
            }
            else if(current->value > searchItem)
            {
                current = current->leftNode;
            }
            else
            {
                current = current->rightNode;
            }
        }
    }
    return found;
    */

   if(root == nullptr)
   {
       return false;
   }
   else
   {
       if(root->value == searchItem)
       {
           return true;
       }
       else if(root->value > searchItem)
       {
           return Search(root->leftNode, searchItem);
       }
       else if(root->value < searchItem)
       {
           return Search(root->rightNode, searchItem);
       }
   }
    return false;
}

template <class T>
void Bst<T>::Insert(const T& insertItem)
{
    /*
	Get memory for a newNode
	Place new data in the newNode
	IF root is NULL
		root = newNode
	ELSE
		Insert (newNode, root)
	ENDIF
    */

    Node<T>* newNode = new Node<T>;
    newNode->value = insertItem;
    if(root == nullptr)
    {
        root = newNode;
    }
    else
    {
        Insert(newNode, root);
    }
}
template <class T>
void Bst<T>::Insert(Node<T>* &newNode, Node<T>* &parent)
{
    /*
    IF newNode’s data < parent.data
		IF parent has no left child
			parent.leftLink = newNode
		ELSE
			Insert (newNode, parent.leftLink)
		ENDIF
	ELSE
		IF parent has no right child
			parent.rightLink = newNode
		ELSE
			Insert (newNode, parent.rightLink)
		ENDIF
	ENDIF
    */

   if(newNode->value < parent->value)
   {
       if(parent->leftNode == nullptr)
       {
           parent->leftNode = newNode;
       }
       else
       {
           Insert(newNode,parent->leftNode);
       }
   }
   else
   {
       if(parent->rightNode == nullptr)
       {
           parent->rightNode = newNode;
       }
       else
       {
           Insert(newNode,parent->rightNode);
       }
   }

}

template <class T>
void Bst<T>::DeleteNode(const T& deleteItem)
{
    Node<T>* current;   //pointer to traverse the tree
    Node<T>* trailCurrent;  //pointer behind current
    bool found = false;

    if(root == nullptr)
    {
        cout << "Cannnot delete from an empty tree." << endl;
    }
    else
    {
            //Start traversing from root
        current = root;
        trailCurrent = root;

            //If current node is not empty and deleteItem not found
        while(current != nullptr && !found)
        {
                //Check if current Node's value is equal to 
                //If is equal then set found to be true
            if(current->value == deleteItem)
            {
                found = true;
            }
            else
            {
                    //Update trailCurrent to the same as current
                trailCurrent = current;
                    //Check if current node's value is more than deleteItem
                    //If current is more than delete, set current to current's leftnode to check it next loop
                    //Else set current to current's right node
                if(current->value > deleteItem)
                {
                    current = current->leftNode;
                }
                else
                {
                    current = current->rightNode;
                }
            }
        }

        if(current == nullptr)
        {
            cout << "The item to be deleted is not in the tree." << endl;
        }
        else if(found)
        {
                //Delete found node
            if(current == root)
            {
                DeleteFromTree(root);
            }
            else if(trailCurrent->value > deleteItem)
            {
                DeleteFromTree(trailCurrent->leftNode);
            }
            else
            {
                DeleteFromTree(trailCurrent->rightNode);
            }
        }
        else
        {
            cout << "The item to be deleted is not in the tree." << endl;
        }
    }
}
template <class T>
void Bst<T>::DeleteFromTree(Node<T>* &p)
{
    Node<T>* current;   //Pointer to traverse the tree
    Node<T>* trailCurrent;  //Pointer behind current
    Node<T>* temp;  //Pointer to delete the node

    if(p == nullptr)
    {
        cout << "Error: The Node to be deleted does not exist." << endl;
    }
    else if(p->leftNode == nullptr && p->rightNode == nullptr) //If both left and right node is empty then just delete node
    {
        temp == p;
        p = nullptr;
        delete temp;
    }
    else if(p->leftNode == nullptr) //If right node is not empty then move right node to deleted node's position
    {
        temp = p;
        p = temp->rightNode;
        delete temp;
    }
    else if(p->rightNode == nullptr) //If left node is not empty then move left node to deleted node's position
    {
        temp = p;
        p = temp->leftNode;
        delete temp;
    }
    else //If both left and right nodes are not empty
    {
            //Set current to delete node's left node
        current = p->leftNode;
        trailCurrent = nullptr;

            //Find the right bottom most node of current
        while(current->rightNode != nullptr)
        {
            trailCurrent = current;
            current = current->rightNode;
        }
            //Set node to be deleted's value to the right bottom most node of current
        p->value = current->value;

        if(trailCurrent == nullptr)
        {
            p->leftNode = current->leftNode;
        }
        else
        {
            trailCurrent->rightNode = current->leftNode;
        }
        delete current;
    }
}

template <class T>
int Bst<T>::TreeNodeCount() const
{
    return NodeCount(root);
}
template <class T>
int Bst<T>::NodeCount(Node<T>* p) const
{
    if (p == nullptr)
    {
        return 0;
    }
    return 1 + NodeCount(p->leftNode) + NodeCount(p->rightNode);
}



template <class T>
void Bst<T>::InOrderTraversal() const
{
    InOrder(root);
}
template <class T>
void Bst<T>::InOrder(Node<T>* p) const
{
    if(p != nullptr)
    {
        InOrder(p->leftNode);
        cout << p->value << " ";
        InOrder(p->rightNode);
    }
}
template <class T>
void Bst<T>::InOrderTraversal(void (*visit) (T& item)) const
{
    InOrder(root, *visit);
}
template <class T>
void Bst<T>::InOrder(Node<T>* p, void (*visit)(T& item)) const
{
    if(p != nullptr)
    {
        InOrder(p->leftNode, *visit);
        (*visit) (p->value);
        InOrder(p->rightNode, *visit);
    }
}


template <class T>
void Bst<T>::PreOrderTraversal() const
{
    PreOrder(root);
}
template <class T>
void Bst<T>::PreOrder(Node<T>* p) const
{
    if(p != nullptr)
    {
        cout << p->value << " ";
        PreOrder(p->leftNode);
        PreOrder(p->rightNode);
    }
}
template <class T>
void Bst<T>::PreOrderTraversal(void (*visit) (T& item)) const
{
    PreOrder(root, *visit);
}
template <class T>
void Bst<T>::PreOrder(Node<T>* p, void (*visit)(T& item)) const
{
    if(p != nullptr)
    {
        (*visit) (p->value);
        PreOrder(p->leftNode, *visit);
        PreOrder(p->rightNode, *visit);
    }
}

template <class T>
void Bst<T>::PostOrderTraversal() const
{
    PostOrder(root);
}
template <class T>
void Bst<T>::PostOrder(Node<T>* p) const
{
    if(p != nullptr)
    {
        PostOrder(p->leftNode);
        PostOrder(p->rightNode);
        cout << p->value << " ";
    }
}
template <class T>
void Bst<T>::PostOrderTraversal(void (*visit) (T& item)) const
{
    PostOrder(root, *visit);
}
template <class T>
void Bst<T>::PostOrder(Node<T>* p, void (*visit)(T& item)) const
{
    if(p != nullptr)
    {
        PostOrder(p->leftNode, *visit);
        PostOrder(p->rightNode, *visit);
        (*visit) (p->value);
    }
}

template <class T>
float Bst<T>::InOrderGetMaxFloat() const
{
    float highest = -1;
    return GetMaxFloat(root, highest);
}
template <class T>
float Bst<T>::GetMaxFloat(Node<T>* p, float highest) const
{
    float value;
    if(p != nullptr)
    {
        value = GetMaxFloat(p->leftNode, highest);
            if(value > highest)
            {
                highest = value;
            }
        value = p->value;
            if(value > highest)
            {
                highest = value;
            }
            
        value = GetMaxFloat(p->rightNode, highest);
            if(value > highest)
            {
                highest = value;
            }
    }
    
    return highest;
}
template <class T>
float Bst<T>::InOrderGetMaxFloat(float (*visit) (T& item)) const
{
    float highest = -1;
    return GetMaxFloat(root, *visit, highest);
}
template <class T>
float Bst<T>::GetMaxFloat(Node<T>* p, float(*visit)(T&), float& highest) const
{
    float value;
    if(p != nullptr)
    {
        value = GetMaxFloat(p->leftNode, *visit, highest);
            if(value > highest)
            {
                highest = value;
            }
        value = (*visit) (p->value);
            if(value > highest)
            {
                highest = value;
            }
            
        value = GetMaxFloat(p->rightNode, *visit, highest);
            if(value > highest)
            {
                highest = value;
            }
    }
    
    return highest;
}

template <class T>
float Bst<T>::GetSumValueFloat()const
{
    float total = 0;
    return SumValueFloat(root, total);
}
template <class T>
float Bst<T>::SumValueFloat(Node<T>* p, float& total) const
{
    if(p != nullptr)
    {
        SumValueFloat(p->leftNode, total);
        total += p->value;
        SumValueFloat(p->rightNode, total);

        return total;
    }
    
    return 0;
}
template <class T>
float Bst<T>::GetSumValueFloat(float (*visit) (T&))const
{
    float total = 0;
    return SumValueFloat(root, *visit, total);
}
template <class T>
float Bst<T>::SumValueFloat(Node<T>* p, float(*visit)(T&), float& total) const
{
    if(p != nullptr)
    {
        SumValueFloat(p->leftNode, *visit, total);
        total += (*visit) (p->value);
        SumValueFloat(p->rightNode, *visit, total);

        return total;
    }
    
    return 0;
}

template <class T>
string Bst<T>::GetStringByFloatValue(string (*visit) (T&, float), float searchValue) const
{
    return StringByFloatValue(root, *visit, searchValue);
}
template <class T>
string Bst<T>::StringByFloatValue(Node<T>* p, string (*visit) (T&, float), float searchValue) const
{
    string result;
    if(p != nullptr)
    {
        result += StringByFloatValue(p->leftNode, *visit, searchValue);
        result += (*visit) (p->value, searchValue);
        result += StringByFloatValue(p->rightNode, *visit, searchValue);

        return result;
    }
    
    return "";
}

#endif