#ifndef  QUEUE_H
#pragma once
#include <iostream>


template <class T> 


class Queue {
private:
	class Queue_For_elements {
	

	public:
		T data;;
		Queue_For_elements* next;
		Queue_For_elements* head, * last;
		Queue_For_elements(T data = 0, Queue_For_elements* next = NULL, Queue_For_elements* last = NULL, Queue_For_elements* head = NULL) : next(next), data(data), last(last), head(head)
		{ }
		~Queue_For_elements() = default;

		void NewNext(Queue_For_elements* newnext) {
			this->next = newnext;
		}


		void NewData(T newdata) {
			this->data = newdata;
		}


		Queue_For_elements* getNext() {
			return this->next;
		}


		T getdata() {
			return this->data;
		}

		T getNextdata() {
			if (this->next == NULL) {
				return 0;
			}
			else
				return this->next->data;
		}

		Queue_For_elements* toNULL() {
			return this->next = NULL;
		}

		T haveHead() {

			return head->data;
		}




	};
	Queue_For_elements* head, * last;

public:
	

	Queue();

	~Queue();

	void dequeue();

	void enqueue(T);

	bool Queue_isEmpty();

	T front();



};


template <class T> Queue<T>::Queue()
{
	head = NULL;
	last = NULL;
}

template <class T> Queue<T>::~Queue()
{
	while (!Queue_isEmpty()) {
		dequeue();
	}
}

template <class T> void Queue<T>::enqueue(T data) {
	if (head == NULL) {

		Queue_For_elements* cur = new Queue_For_elements(data);
		head = cur;
		last = head;

	}
	else {
		Queue_For_elements* cur = new Queue_For_elements(data);

		last->next = cur;
		last = cur;
	}
}

template <class T> void Queue<T>::dequeue() { 
	if (head == NULL) {
		throw std::runtime_error("The list NULL\n"); 
	}
	else {
		Queue_For_elements* cur = head;
		head = head->next;
		delete cur;
	}
}

template <class T> bool Queue<T>::Queue_isEmpty() { //CHECKING THE LIST FOR EMPTINESS
	if (head == NULL) { //IF THE LIST IS EMPTY
		return 1;
	}
	else {
		return 0;
	}
}

template <class T> T Queue<T>::front() {
	if (Queue_isEmpty()) {
		throw std::out_of_range("The list NULL\n");

	}
	else {

		//Queue_For_elements* haveHead();
		
			return head->data;
		

	}
}

/*size_t Queue_get_size() { // Geting size list
	Queue_For_elements* cur = head;
	int score = 0;
	while (cur != NULL) { //while the list is not over, we count the amount
		score++;
		cur = cur->getNext();
	}
	std::cout << score;
	return score;
}*/

/*Queue() { // Making an empty list
		this->head = NULL;
		this->last = this->head;
	}

	Queue(int data) { // Making a list with values
		Queue_For_elements* elem = new Queue_For_elements(data);
		this->head = elem;
		this->last = elem;
	}*/



	/*
		++enqueue(item)
		++ dequeue()
		++isEmpty()
		++ size()

		- head
		--
		---
		----  last

		*/


#endif // !QUEUE_H
