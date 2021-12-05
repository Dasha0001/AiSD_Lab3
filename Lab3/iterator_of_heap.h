#ifndef ITERATOR_OF_HEAP_H
#pragma once


class Iterator {
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
	virtual ~Iterator() {};
};


#endif // !ITERATOR_OF_HEAP_H