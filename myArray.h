/* 
 * File:   myArray.h
 * Author: Brett Noltkamper
 * Date Completed: October 18, 2017
 * Function:Header file for Array.cpp file
 * Input:N/A
 * Output:N/A
 * Compilation Status:
 */

#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using namespace std;

template <class T>
class myArray {
        template <class U>
	friend ostream & operator<<(ostream &lhs, const myArray &rhs);
        template <class U>
	friend istream & operator>>(istream &lhs, myArray &rhs);

public:
	myArray();
	myArray(int _size, T element);
	myArray(T *_arr, int _size);
	myArray(const myArray& orig);
	~myArray();

	void print() const;
	void expand();
	void init();

	int getSize() const;
	T getData(int index) const;

	void setData(int index, T value);
	bool equal(const myArray& rhs) const;
	bool operator==(const myArray& rhs) const;
	bool operator!=(const myArray& rhs) const;
	myArray operator=(const myArray& rhs);
	const myArray operator++(); //prefix ++Array
	const myArray operator++(int dummy); //postfix Array++
	const myArray operator+(const myArray & rhs) const;
	const myArray operator-() const;
	T operator[](int index) const;
	void printMyInfo() const;

private:
	T *data;	
	int size;
	void setSize(int value);
};

#endif /* MYARRAY_H */

