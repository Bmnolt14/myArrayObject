/* 
 * File:   myArray.cpp
 * Author: Brett Noltkamper
 * Date Completed: October 18, 2017
 * Function: Operator overloading functions
 * Input: N/A
 * Output: N/A
 * Compilation Status: Compiles
 *
 */


#include "myArray.h"
#include <iostream>
using namespace std;

//Default constructor
template <class T>
myArray<T>::myArray(){
	size = 0;
	data = new T [size];
	for(int i=0; i < size; i++){
		data[i] = i;
    	}
}

//Alt Constructor 1, takes in size and element, sets array of size to element
template <class T>
myArray<T>::myArray(int _size, T element){
	size = _size;
    	data = new T [size];
    	for(int i = 0; i < size; i++){
        	data[i] = element;
    	}
}

//Alt Constructor 2, takes in array and size, sets data equal to array parameter
template <class T>
myArray<T>::myArray(T *_arr, int _size){
	size = _size;
	data = new T [size];
    	for(int i=0; i < size; i++) {
        	data[i] = _arr[i];
    	}	
}

//Copy Constructor
template <class T>
myArray<T>::myArray(const myArray& orig){
	setSize(orig.getSize());
    	data = new T [getSize()];
    	for(int i=0; i < getSize(); i++){
        	setData(i, orig.getData(i));
    	}	
}

//Destructor
template <class T>
myArray<T>::~myArray(){
    	delete [] data;
}

//returns size
template <class T>
int myArray<T>::getSize() const {
    	return size;
}

//sets size to value
template <class T>
void myArray<T>::setSize(int value){
    	if(value > 0){
        	size = value;
    	}
}

//sets array index to value
template <class T>
void myArray<T>::setData(int index, T value){
    	if((index >= 0) && (index < size)){
        	data[index] = value;
    	}else{
        	cout << "NO!" << endl;
    	}
}

//returns element at index
template <class T>
T myArray<T>::getData(int index) const {
    	if((index >= 0) && (index < size)){
        	return data[index];
    	}else{
        	return data[size - 1];
    	}
}

//returns element at index
template <class T>
T myArray<T>::operator[](int index) const {
    	if((index >= 0) && (index < getSize())){
        	return data[index];
    	}else{
        	return data[getSize()-1];
    	}
}

//prints array elements
template <class T>
void myArray<T>::print() const {
    	for(int i=0; i < size; i++){
        	cout << data[i] << " ";
    	}
    	cout << endl;
}

//expands array by one element
template <class T>
void myArray<T>::expand(){
    	double *localArray = new T [size + 1];

    	for(int i = 0; i < size; i++){
        	localArray[i] = data[i];
    	}
    	localArray[size] = size;

    	delete [] data;
    	setSize(size + 1);
    	data = localArray;
}

//takes in array and compares equality to data array
template <class T>
bool myArray<T>::equal(const myArray& rhs) const{
    	bool result(true);

    	if(getSize() != rhs.getSize()){
        	result = false;
    	}else{
        	for(int i=0; i < getSize(); i++){
            		if(getData(i) != rhs.getData(i)){
                		result = false;
            		}
        	}	
    	}
    	return result;
}

//initializes array to user input
template <class T>
void myArray<T>::init(){
	cout << "Please enter " << size << " elements to populate the array." << endl;
	for(int i=0; i < getSize(); i++){
		cin >> data[i];
	}
}

//replaces equal function
template <class T>
bool myArray<T>::operator==(const myArray& rhs) const {
    	bool result(true);

    	if(getSize() != rhs.getSize()){
        	result = false;
    	}else{
        	for(int i=0; i < getSize(); i++){
            		if(getData(i) != rhs.getData(i)){
                		result = false;
            		}
        	}
    	}
    	return result;
}

//checks if array is not equals to data array
template <class T>
bool myArray<T>::operator!=(const myArray& rhs) const {
    	bool result(false);

    	if(getSize() != rhs.getSize()){
        	result = true;
    	}else{

        	for(int i = 0; i < getSize(); i++){
            		if(data[i] != rhs[i]){
                		result = true;
            		}
        	}
    	}
    	return result;
}

//assignment operator overloaded, sets array to data array
template <class T>
myArray<T> myArray<T>::operator=(const myArray& rhs) {
    	delete [] data;
    	setSize(rhs.getSize());
    	data = new T [getSize()];
    	for(int i=0; i < size; i++){
        	data[i] = rhs[i];
    	}
	return *this;
}

//adds array elements index by index, cascade capable
template <class T>
const myArray<T> myArray<T>::operator+(const myArray & rhs) const {
    	myArray tempArray(rhs);  
    	if(getSize() != rhs.getSize()){
        	cout << "Exception." << endl;
    	}else{
        	for(int i = 0; i < (getSize()*2); i++){
                    if(i < getSize())
            		tempArray.setData(i, data[i]);
                    if(i >= getSize())
                        tempArray.setData(i, rhs[i]);
        	}
    	}
    	return tempArray;
}

//changes all array elements to negative
template <class T>
const myArray<T> myArray<T>::operator-() const {
	for(int i=0; i < getSize(); i++){
		data[i] = -data[i];
	}
	return *this;
}

//increments array elements by one
template <class T>
const myArray<T> myArray<T>::operator++(){
    	for(int i=0; i < getSize(); i++){
        	data[i]++;
    	}
    	return *this;
}

//returns array that is called
template <class T>
const myArray<T> myArray<T>::operator++(int dummy){
    	myArray temp(*this);
    
    	for(int i=0; i < getSize(); i++){
        	data[i]++;
    	}
    	return temp;
}

//pointer information
template <class T>
void myArray<T>::printMyInfo() const {
    	cout << "I am at: " << this << endl;
    	cout << "My data is at: " << &data << endl;
    	cout << "My size is at: " << &size << " with a value of : " << size << endl;
    	cout << "My data points to: " << data << endl;
    	cout << "The first item in data is: " << *data << endl;
}

//output operator
template <class U>
ostream & operator<<(ostream &lhs, const myArray<U> &rhs){
    	for(int i=0; i < rhs.getSize(); i++){
        	lhs << rhs[i] << " ";
    	}
    	cout << endl;
    	return lhs;
}

//input operator
template <class U>
istream & operator>>(istream &lhs, myArray<U> &rhs){
    	double temp;
    	for(int i=0; i < rhs.getSize(); i++){
        	lhs >> temp;
        	rhs.setData(i, temp);
    	}
    	return lhs;
}



