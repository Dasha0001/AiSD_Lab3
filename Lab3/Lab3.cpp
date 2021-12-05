

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Binary_Heap.h"


int main()
{
	
	Binary_Heap Heap(11);
	Iterator* dft;
	Heap.insert(10);
	Heap.insert(9);
	Heap.insert(8);
	Heap.insert(7);
	Heap.insert(6);
	Heap.insert(5);
	Heap.insert(4);
	Heap.insert(3);
	int arr1[9], i = 0;//FOR DFT
	dft = Heap.constructor_DFT();
	std::cout << "1 heap " << "\n";
	if (dft->has_next()) {
		while (dft->has_next()) { arr1[i++] = dft->next(); }
	}
	for (i=0; i<9;i++){
		std::cout << arr1[i] << "   ";
	
	}
	
	std::cout << "\n" <<"2-Heap" << "\n";
	Binary_Heap heap(0);
	Iterator* bft;
	int Arr2[9];

	heap.insert(1);//
	heap.insert(6);//
	heap.insert(2);//
	heap.insert(3);//
	heap.insert(8);
	heap.insert(7);//
	heap.insert(4);//
	heap.insert(5);//

	i = 0;
	bft = heap.constructor_BFT();
	if (bft->has_next()) {
		while (bft->has_next()) {
			Arr2[i++] = bft->next();
		}
	}
	for (i = 0; i < 9; i++) {
		std::cout << Arr2[i] << "   ";

	}






	heap.remove(5);
	heap.contains(5);



	system("pause");
	return 0;





}
