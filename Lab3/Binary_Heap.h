#ifndef  BINARY_HEAP_H
#pragma once

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "iterator_of_heap.h"


class Tree_Element {
private:
	
	
public:
	
	int data;
	Tree_Element* left_Element, * parent_of_Element, * right_Element;
	Tree_Element(int data = 0, Tree_Element *left_Element = NULL, Tree_Element *right_Element = NULL, Tree_Element* parent_of_Element = NULL) : data(data), left_Element(left_Element), right_Element(right_Element), parent_of_Element(parent_of_Element) {}
	~Tree_Element() = default;


};

class Binary_Heap {
	private:
	 Tree_Element* root_of_heap;
	 
	public:
		int hight_of_heap, quantity_Last_el;
		Iterator* constructor_DFT() {
			return new DFT_iterator(root_of_heap);
		}

		Iterator* constructor_BFT() {
			BFT_iterator* new_bft_iterator = new BFT_iterator(root_of_heap);
			new_bft_iterator->queue->enqueue(root_of_heap);
			return new_bft_iterator;
		}

		class DFT_iterator : public Iterator
		{
		public:

			friend class Heap;

			DFT_iterator(Tree_Element*);

			~DFT_iterator();

			bool has_next() override;

			int next() override;

		
		

			Stack<Tree_Element*>* stack;

			Tree_Element* cur;
		};
		
		class BFT_iterator : public Iterator
		{
		public:
			friend class Heap;

			BFT_iterator(Tree_Element*);

			~BFT_iterator();

			bool has_next() override;

			int next() override;


			
		
			
			Queue<Tree_Element*>* queue;
			Tree_Element* cur;

		};


	Binary_Heap() { // Making an empty list
		this->root_of_heap = NULL;
		
	}

	Binary_Heap (int data) { // Making a list with values
			Tree_Element* Element = new Tree_Element(data);
			this->root_of_heap = Element;//the root of the heap
			 hight_of_heap = 1; //heap height
			 quantity_Last_el = 1;//number of elements on the last level
			
    }

	
	/*
	1. bool contains(int); ++
    2. void insert(int); ++
	3. void remove(int); ++
	4. Iterator create_dft_iterator(); ++
	5. Iterator create_bft_iterator() ++
	*/

	void swapSift(Tree_Element* cur, Tree_Element* next) {
		int tmp = cur->data;
		cur->data = next->data;
		next->data = tmp;
	}

	Tree_Element* parent_search(int tmp ) {

		Tree_Element* ending_parent = root_of_heap;

		int tmp_lay = tmp;
		int tmp_Last = this->quantity_Last_el;

		if (this->quantity_Last_el > tmp) {
			tmp_lay = tmp_lay * 2;
		}

		while (tmp_lay != 2) {
			if (tmp_Last <= (tmp_lay / 2)) {

				ending_parent = ending_parent->left_Element;
				tmp_lay = tmp_lay / 2;
			}
			else {
				ending_parent = ending_parent->right_Element;
				tmp_Last = tmp_Last - tmp_lay / 2;
				tmp_lay = tmp_lay / 2;
			}
		}

		return ending_parent;
	}

	Tree_Element* findElem(int data) {
		Tree_Element* Elem = NULL;

		DFT_iterator* new_It;
		new_It = new DFT_iterator(root_of_heap);

		while (new_It->has_next()) {
			Elem = new_It->cur;
			if (new_It->next() == data) {
				delete new_It;
				return Elem;
			}
		}


		delete new_It;
		throw std::invalid_argument("error not found");
	}

	void siftDown(Tree_Element* tmp) {

		Tree_Element* wrong = tmp;


		if ((tmp->left_Element != NULL) && (tmp->right_Element != NULL)) {

				if ((tmp->data < tmp->right_Element->data) || (tmp->data < tmp->left_Element->data)) {

					if ((tmp->left_Element->data) > (tmp->right_Element->data)) {
						wrong = tmp->left_Element;
					}
					else {
						wrong = tmp->right_Element;
					}


				}
				else {
					return;
				}
			
		}
		else {
			if ((tmp->right_Element == NULL)&&(tmp->left_Element != NULL)) {
				if (tmp->data < tmp->left_Element->data) {
					wrong = tmp->left_Element;
				}
				else {
					return;
				}
			}
		
			return;
		}

		swapSift(tmp, wrong);
		siftDown(wrong);

	}


	void siftUp(Tree_Element* tmp) {
		if (tmp->parent_of_Element == NULL) {
			return;
		}
		else {
			if (tmp->data > tmp->parent_of_Element->data) {
				swapSift(tmp, tmp->parent_of_Element);
				siftUp(tmp->parent_of_Element);
			}
			else {
				return;
			}
		}
	}


	void Heapify(Tree_Element* tmp) {
		if (tmp->parent_of_Element == NULL) {
			siftDown(tmp);
		}
		else
			if ((tmp->data) > (tmp->parent_of_Element->data)) {
				siftUp(tmp);
			}
			else {
				siftDown(tmp);
			}
	}
	
	void insert(int key) 
	{

		if (root_of_heap == NULL) { //++if the heap is empty, then the root is assigned the insertion value
			Tree_Element* elem = new Tree_Element(key);
			this->root_of_heap = elem;
			this->quantity_Last_el = 1;
			this->hight_of_heap = 1;

		}
		else {
			Tree_Element* tmp = new Tree_Element(key);
			Tree_Element* cur = root_of_heap;

			int last_layer = 1;
			this->quantity_Last_el++;

			for (int index = 0; index < hight_of_heap-1 ; index++) {
				last_layer = last_layer * 2; 
			}

			if (last_layer < this->quantity_Last_el) {
				this->quantity_Last_el = 1;
				this->hight_of_heap++;
				last_layer = last_layer * 2;
			}

			cur = parent_search(last_layer);

			if (cur->left_Element == NULL) {
				cur->left_Element = tmp;
				tmp->parent_of_Element = cur;
			}
			else {
				cur->right_Element = tmp;
				tmp->parent_of_Element = cur;
			}

			Heapify(tmp);
		}
	}

	void remove(int key) {

		Tree_Element* delete_elem = findElem(key);


		if (root_of_heap->left_Element == NULL && root_of_heap->right_Element == NULL) {
			delete root_of_heap;
			root_of_heap = NULL;
			hight_of_heap = 0; quantity_Last_el = 0;
		}

		int last_layer = 1;

		for (int index = 0; index < hight_of_heap - 1; index++) {
			last_layer = last_layer * 2; 
		}

		Tree_Element* last_elem = parent_search(last_layer);

		if (last_elem->right_Element != NULL) {
			last_elem = last_elem->right_Element;
			last_elem->parent_of_Element->right_Element = NULL;
			quantity_Last_el--;
		}
		else {
			last_elem = last_elem->left_Element;
			last_elem->parent_of_Element->left_Element = NULL;
			quantity_Last_el--;
		}




		if (quantity_Last_el == 0) {
			quantity_Last_el = 1;
			hight_of_heap--;
			for (int index = 0; index < hight_of_heap - 1; index++) {
				quantity_Last_el = quantity_Last_el * 2;
			}

		}
		if (delete_elem == last_elem) { delete last_elem; }
		else {
			
			
			swapSift(last_elem, delete_elem);
			delete last_elem;
			Heapify(delete_elem);
		}

	}

	bool contains(int data) {
		try {
			findElem(data);
			return true;
		}
		catch (std::invalid_argument) {
			return false;
		}
	}


	



};


Binary_Heap::DFT_iterator::DFT_iterator(Tree_Element* root_of_heap) {
	cur = root_of_heap;
	 stack = new Stack<Tree_Element*>();
}
bool Binary_Heap::DFT_iterator::has_next() {
	return cur != NULL;
}

int Binary_Heap::DFT_iterator::next() {
	if (!has_next()) {
		throw std::out_of_range("error not found");
	}

	int tmp = cur->data;

	if (cur->right_Element != NULL) {
		stack->Stack_push(cur->right_Element);
	}

	if (cur->left_Element != NULL) {
		cur = cur->left_Element;
	}
	else {
		try {
			cur = stack->peek();
			stack->Stack_pop();
		}
		catch (std::out_of_range) {
			cur = NULL;
		}
	}

	return tmp;
}

Binary_Heap::DFT_iterator::~DFT_iterator() {
	delete stack;
}

Binary_Heap::BFT_iterator::BFT_iterator(Tree_Element* root_of_heap) {
	cur = root_of_heap;
	 queue = new Queue<Tree_Element*>();
}

bool Binary_Heap::BFT_iterator::has_next() {
	return cur != NULL;
}

int Binary_Heap::BFT_iterator::next() {
	if (!has_next()) {
		throw std::out_of_range("error not found");
	}

	int tmp = cur->data;

	if (cur->left_Element != NULL) {
		queue->enqueue(cur->left_Element);
	}

	if (cur->right_Element != NULL) {
		queue->enqueue(cur->right_Element);
	}

	queue->dequeue();

	try {
		cur = queue->front();


	}
	catch (std::out_of_range) {
		cur = NULL;
	}

	return tmp;
}

Binary_Heap::BFT_iterator::~BFT_iterator() {
	delete queue;
}




#endif // BINARY_HEAP_H
