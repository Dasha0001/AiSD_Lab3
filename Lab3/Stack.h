#ifndef STACK_H
#pragma once

#include <iostream>

template <class T>

/*  ++Stack() 
	++push(item)
	++pop()
	++peek()
	++isEmpty()
	++size(

	*/


class Stack {
private:

	class Stack_For_elements {
	private:
		T data;
		Stack_For_elements* next;

	public:

		Stack_For_elements(T  data = 0, Stack_For_elements* next = NULL) : next(next), data(data)
		{ }
		~Stack_For_elements() = default;

		void NewNext(Stack_For_elements* newnext) {
			this->next = newnext;
		}


		void NewData(T newdata) {
			this->data = newdata;
		}


		Stack_For_elements* getNext() {
			return this->next;
		}

		T getElemdata() {
			return this->data;
		}

		T getNextdata() {
			if (this->next == NULL) {
				return 0;
			}
			else
				return this->next->data;
		}

		Stack_For_elements* toNULL() {
			return this->next = NULL;
		}




	};

	Stack_For_elements* head, * last;

public:

	Stack();

	~Stack();

	void Stack_pop();

	void Stack_push(T data);

	bool Stack_isEmpty();

	T peek();
};


 template <class T> Stack<T>::Stack()
{
	head = NULL;
}

template <class T>
Stack<T>::~Stack()
{
	while (!Stack_isEmpty()) {
		Stack_pop();
	}
}


template <class T> void Stack<T>::Stack_push(T data) {
	if (head == NULL) {

		Stack_For_elements* cur = new Stack_For_elements(data);
		head = cur;
		last = head;
		
	}
	else {
		Stack_For_elements* tmp = new Stack_For_elements(data);
		Stack_For_elements* cur = head;
		this->head = tmp;
		this->head->NewNext(cur);
	}
};

template <class T> void Stack<T>::Stack_pop() { 
	if (head == NULL) {
		throw std::runtime_error("The list NULL\n"); 
	}
	else {
		Stack_For_elements* cur = head;
		head = head->getNext();
		delete cur;
	}
};

template <class T> T Stack<T>::peek() {
	
	if (Stack_isEmpty()) {
		throw std::out_of_range("error not found");
	}
	else {
		return head->getElemdata();
	}

};

template <class T> bool Stack<T>::Stack_isEmpty() { //CHECKING THE LIST FOR EMPTINESS
	if (head == NULL) { //IF THE LIST IS EMPTY
		return 1;
	}
	else {
		return 0;
	}
};

	/*size_t Stack_get_size() { // Geting size list
		Stack_For_elements* cur = head;
		int score = 0;
		while (cur != NULL) { //while the list is not over, we count the amount
			score++;
			cur = cur->getNext();
		}
		std::cout << score;
		return score;
	}*/










#endif // !STACK_H
