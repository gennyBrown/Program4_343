// Yusuf Pisan pisan@uw.edu

// 15 Jan 2018



// BST class

// Creates a BST to store values

// Uses Node which holds the Data

// Uses templates to store any type of Data

// binarysearchtreee.cpp file is included at the bottom of the .h file

// binarysearchtreee.cpp is part of the template, cannot be compiled separately



#ifndef BST_HPP

#define BST_HPP



#include <algorithm>

#include <cmath>

#include <iomanip>

#include <iostream>

#include <queue>

#include <sstream>

#include <string>



using namespace std;



template<class T>

class BST {

	// display BST tree in a human-readable format

	friend ostream& operator<<(ostream& Out, const BST& Bst) {

		Bst.printSideways(Out, Bst.Root);

		Out << endl;

		Bst.printVertical(Out, Bst.Root);

		return Out;

	}



private:

	// Node for BST

	struct Node {

		T Data;

		Node* Left;

		Node* Right;

	

		//constructor

		Node(T Data) : Data(Data), Left(nullptr), Right(nullptr) {}

		



		//==operator overload called by the class ==operator overload

		friend bool operator==(Node const& Lhs, Node const& Rhs) {

			return Lhs.Data == Rhs.Data

				&& ((Lhs.Left == 0 && Rhs.Left == 0)

					|| (Lhs.Left != 0 && Rhs.Left != 0 && *Lhs.Left == *Rhs.Left))

				&& ((Lhs.Right == 0 && Rhs.Right == 0)

					|| (Lhs.Right != 0 && Rhs.Right != 0 && *Lhs.Right == *Rhs.Right));

		}

	};



	// refer to data type "struct Node" as Node

	using Node = struct Node;



	// root of the tree

	Node* Root{ nullptr };

	

	// height of a Node, nullptr is 0, Root is 1, static, no access to 'this'

	static int getHeight(const Node* N) {

		

		if (N == nullptr) {

			return 0;

		}

		else {

			int RightHeight = getHeight(N->Right);

			int LeftHeight = getHeight(N->Left);



			if (LeftHeight > RightHeight) {

				return (LeftHeight + 1);

			} 

			else {

				return (RightHeight + 1);

			}

		}

	}

	

	/**

	 * print tree sideways with root on left

				  6

			  2

				  5

		  0

				  4

			  1

				  3

	 */

	static ostream& printSideways(ostream& Out, const Node* Curr, int Level = 0) {

		const static char SP = ' ';

		const static int ReadabilitySpaces = 4;

		if (!Curr)

			return Out;

		printSideways(Out, Curr->Right, ++Level);

		Out << setfill(SP) << setw(Level * ReadabilitySpaces) << SP;

		Out << Curr->Data << endl;

		printSideways(Out, Curr->Left, Level);

		return Out;

	}



	static ostream& centeredPrint(ostream& Out, int Space,

		const string& Str, char FillChar = ' ') {

		auto StrL = static_cast<int>(Str.length());

		int Extra = (Space - StrL) / 2;

		if (Extra > 0) {

			Out << setfill(FillChar) << setw(Extra + StrL) << Str;

			Out << setfill(FillChar) << setw(Space - Extra - StrL) << FillChar;

		}

		else {

			Out << setfill(FillChar) << setw(Space) << Str;

		}

		return Out;

	}



	/**

	 * print tree with the root at top

	 *

		_____0______

	 __1___      __2___

	3     4     5     6

	 *

	**/

	static ostream& printTreeLevel(ostream & Out, queue<const Node*> & Q,

		int Width, int Depth, int MaxDepth) {

		const static char SP = ' ';

		const static char UND = '_';

		int Nodes = 0;

		int MaxN = static_cast<int>(pow(2, Depth - 1));

		int SpaceForEachItem = static_cast<int>(Width * pow(2, MaxDepth - 1) / MaxN); // NOLINT

		string

			Bigspace = string(static_cast<uint64_t>(SpaceForEachItem / 4), SP);

		while (Nodes++ < MaxN) {

			const Node* Tp = Q.front();

			Node* TpL = nullptr;

			Node* TpR = nullptr;

			Q.pop();

			string Label = "N";

			if (Tp) {

				stringstream Ss;

				Ss << Tp->Data;

				Label = Ss.str();

				TpL = Tp->Left;

				TpR = Tp->Right;

			}

			char Filler = Depth == MaxDepth ? SP : UND;

			if (Depth == MaxDepth) {

				centeredPrint(Out, SpaceForEachItem, Label, Filler);

			}

			else {

				Out << Bigspace;

				centeredPrint(Out, SpaceForEachItem / 2, Label, Filler);

				Out << Bigspace;

				Q.push(TpL);

				Q.push(TpR);

			}

		}

		Out << endl;

		return Out;

	}



	// helper function for displaying tree sideways, works recursively

	static ostream& printVertical(ostream & Out, Node * Curr) {

		const static int WIDTH = 6;  // must be even

		if (!Curr)

			return Out << "[__]";

		// figure out the maximum depth which determines how wide the tree is

		int MaxDepth = getHeight(Curr);

		queue<const Node*> Q;

		Q.push(Curr);

		for (int Depth = 1; Depth <= MaxDepth; ++Depth) {

			printTreeLevel(Out, Q, WIDTH, Depth, MaxDepth);

		}

		return Out;

	}



public:

	// constructor, empty tree

	BST() {

		Root = nullptr;

	}

	

	// constructor, tree with root

	//the use of explict means the expression must evaluate to true

	explicit BST(const T & RootItem) {

		Root -> Data = RootItem;

		Root->Left = NULL;

		Root->Right = NULL;

	}

	

	// given an array of length n

	// create a tree to have all items in that array

	// with the minimum height (i.e. rebalance)

	// Assignment specification

	//Next line is for clang tidy

	// NOLINTNEXTLINE

	BST(const T Arr[], int N) {

		Arr[0] = Root->Data;

		for (int I = 1; I <= N; ++I) {

			if (Arr[I] > Root->Data) {

				Arr[I] = Root->Right;

			}

			else if (Arr[I] < Root->Data) {

				Arr[I] = Root->Left;

			}

		}



	}



// copy constructor;

	BST(const BST<T>& Bst) {

		this->Root = Bst.Root;



		//NewNode->Root = Bst.Root;

		copyRecursive(Bst.Root);

	}

//helper funtion for copy constructor

	Node* copyRecursive (const Node* Copy) {

		if (Copy == nullptr) {

			return nullptr;

		}

		else {

			Node* TempNode = new Node(Copy->Data);

			TempNode->Left = copyRecursive(Copy->Left);

			TempNode->Right = copyRecursive(Copy->Right);

		}

	}

	

// destructor

//must deal with pointers and dynamic memory to avoid memory leaks

	virtual ~BST() {

		recusiveDestroy(Root);

	}

//traverses a tree recusivly and deletes the nodes as it goes.

//helper function for deconstructor

	void recusiveDestroy(Node *Root){

		if(Root){

			recusiveDestroy(Root->Left);

			recusiveDestroy(Root->Right);

			delete Root;

		}

	}



// true if no nodes in BST

	bool isEmpty() const {

		if (Root == nullptr) {

			return true;

		}

		else

			return false;

	}	

	

// height of root is max height of subtrees + 1

//calls static getHeight function and passes node

	int getHeight() const {

		int HeightCounter = getHeight(this->Root);

		return HeightCounter;

	}



// Number of nodes in BST

	int numberOfNodes() const {

		if (Root == nullptr) {

			return 0;

		}

		else if (Root != nullptr && Root->Left == nullptr && Root->Right == nullptr) {

			return 1;

		}

		else {

			int number = (1 + (numberOfNodesRecursive(Root->Right) + (numberOfNodesRecursive(Root->Left))));

			return number;

		}

	}

	

//helper function for numberOfNodes

	int numberOfNodesRecursive(Node* Current) {

		int Count = 1;

		if (Current->Left != nullptr && Current->Right != nullptr) {

			Count += numberOfNodesRecursive(Current->Left);

			Count += numberOfNodesRecursive(Current->Right);

			return Count;

		}

	}

// add a new item, return true if successful

	bool add(const T& Item) {

		if (this->Root == nullptr) {

			this->Root = new Node(Item);

		}

		else {

			recusiveAdd(Root, Item);

		}

		return true;

	}

		

//recusivly adds nodes to the bst

//if no node, then create one

//helper function for add

	void recusiveAdd(Node* Current,  const T &Item) {

		if (Item == Current->Data) {

			cout << "Value is already in tree" << endl;

		}

		if(Item < Current->Data) {

			if (Current->Left == nullptr) {

				Current->Left = new Node(Item);

			}

			else {

				this->recusiveAdd(Current->Left, Item);

			}

		}

		else {

			if (Current->Right == nullptr) {

				Current->Right = new Node(Item);

			}

			else {

				this->recusiveAdd(Current->Right, Item);

			}

		}

	}

	

// remove item, return true if successful

	bool remove(const T& Item) {

		removeRecusive(this->Root, &Item);

		return true;

	}



//recursive helper function for remove

	void removeRecusive(Node* Current, const T &Item) {

		if (Current == nullptr) {

			cout << "Item not found in tree" << endl;

		}

		else if (Item == Current->Data) {

			Node* trash = nullptr;

			if (Current->Left == nullptr && Current->Right == nullptr) {

				trash = Current;

				Current = nullptr;

			}

			else if (Current->Left != nullptr && Current->Right == nullptr) {

				trash = Current;

				Current = Current->Left;

			}

			else if (Current->Left == nullptr && Current->Right != nullptr) {

				trash = Current;

				Current = Current->Right;

			}

			if (trash != nullptr) delete trash;

		}

		else if (Item < Current->Data) {

			this->removeRecusive(Item, Current->Left);

		}

		else if(Item > Current->Data) {

			this->removeRecusive(Item, Current->Left);

		}

	}



// true if item is in BST

	bool contains(const T& Item) const {

		if (Item == NULL) {

			return false;

		}

		else if (Item == Root->Data) {

			return true;

		}

		else if (Item < Root->Data) {

			return this->contains(Root->Left);

		}

		else if (Item > Root->Data) {

			return this->contains(Root->Right);

		}

	}



//mutators

	void setLeftChild(const T & Item) {

		LeftChild = Item->Left;

	}



	void setRightChild(const T & Item) {

		RightChild = Item->Right;

	}



//accessors

	T getLeftChild() {

		return LeftChild;

	}



	T getRightChild() {

		return RightChild;

	}



// inorder traversal: left-root-right

// takes a function that takes a single parameter of type T

	void inOrderTraverse(void Visit(const T & Item)) const {

		if (Root != nullptr) {

			inOrderTraverse(Visit(Root->Left));

			cout << Root->Data << " ";

			inOrderTraverse(Visit(Root->Right));

		}

	}



// preorder traversal: root-left-right

/*

	void preOrderTraverse(void Visit(const T & Item)) const {

		if (Root != nullptr) {

			cout << Root->Data << " ";

			preOrderTraverse(Visit(Root->Left));

			preOrderTraverse(Visit(Root->Right));

		}

	}

	*/

// postorder traversal: left-right-root

/*

	void postOrderTraverse(void Visit(const T &Item)) const {

		if (Root != nullptr) {

			postOrderTraverse(Visit(*Root.Left));

			postOrderTraverse(Visit(*Root.Right));

			cout << Root->Data << " ";

		}

	}

	*/

// create dynamic array, copy all the items to the array

// and then read the array to re-create this tree from scratch

// so that resulting tree is balanced

	void rebalance() {

		int Size = this->Current.getHeight();

		T* Array = new T[Size];



		T* NewArray = new T[copyToArray(Root, Array)];

		BST(NewArray, Size);

		/*

		while (Root.getLeftChild() != nullptr)

		{

			for (int I = 0; I < Size; ++I) {

				TempArray[I] = Root->Left;

			}

		}

		while (Root.getRightChild() != nullptr)

		{

			for (int I = 0; I < Size; ++I) {

				TempArray[I] = Root->Right;

			}

		}

		for (int I = 0; I < Size; ++I) {

			cout << "Rebalance check" << TempArray[I] << endl;

		}

		*/

		

		//T* CopyArray = new T [inOrderTraverseRebalance(Root)];







	}

	

	T* copyToArray(Node* Current, T* Array[]) {

		int Pos = 0;

		if (Current == nullptr) {

			return Array;

		}

		else {

			copyToArray(Root->Left, Array);

			Array[Pos++] = Current->Data;

			copyToArray(Root->Right, Array);

		}

		return Array;

	}

	

	/*

//helper function to copy the tree to an array and return the array

	T* inOrderTraverseRebalance(void Visit(const T& Item)) const {

		int Size = Root.getHeight();

		T* TempArray = new T[Size];



		if (Root != nullptr) {

			for (int I = 0; I < Size; ++I) {

				TempArray[I] = inOrderTraverseRebalance(Visit(Root->Left));

				TempArray[I + 1] = Root->Data;

				TempArray[I + 2] = inOrderTraverseRebalance(Visit(Root->Right));

			}

			

		}

		return TempArray;

	}

	*/

// delete all nodes in tree

	void clear() {

		recusiveDestroy(Root);

	}



// trees are equal if they have the same structure

// AND the same item values at all the nodes

//calls the friend operator overload in the struct Node

	bool operator==(const BST<T> & Other) const {

		return (Root == 0 && Other.Root == 0) || (Root != 0 && Other.Root != 0 && *Root == *Other.Root);

}



// not == to each other

	bool operator!=(const BST<T> & Other) const {

		return !operator==(Other);

	}



  private:

	  T LeftChild, RightChild;

};



#endif  // BST_HPP