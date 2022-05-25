#pragma once
#include <stdexcept>

using std::out_of_range;

template <class T>
class vector {
	private:
		T* elem;
		unsigned int size;
		unsigned int capacity;
	public:

		typedef T* iterator;

		//default contructor
		vector();
		vector(unsigned int size);
		vector(unsigned int size, const T& init);
		vector(const std::initializer_list<T>& list);

		//copy constructor
		vector(const vector<T>& v);

		//destructor
		~vector();

		//iterators
		iterator begin();
		iterator end();
		const iterator begin() const;
		const iterator end() const;
		const iterator cbegin() const;
		const iterator cend() const;
		T* data() noexcept { return elem; }

		T& at(int n);
		const T& at(int n) const;
		T& front();
		T& back();
		const T& front() const;
		const T& back() const;

		unsigned int mycapacity() const;
		unsigned int mysize() const;
		bool empty() const;
		
		void reserve(unsigned int capacity);
		void resize(unsigned int size);

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		vector<T>& operator=(const vector<T>&) ;
		bool operator==(const vector& v) const;
		bool operator!=(const vector& v) const;

		void push_back(const T& value);
		void pop_back();
		void shrink_to_fit();
		void clear();
};

template<class T>
vector<T>::vector() {
	capacity = 0;
	size = 0;
	elem = nullptr;
}

template<class T>
vector<T>::vector(unsigned int size) {
	capacity = size;
	this->size = size;
	elem = new T[size];
}

template<class T>
vector<T>::vector(unsigned int size, const T& init) {
	this->size = size;
	capacity = size;
	elem = new T[size];
	for (unsigned int i = 0; i < size; i++)
		elem[i] = init;
}

template<class T>
inline vector<T>::vector(const std::initializer_list<T>& list): size(0), capacity(list.size() + 5), elem(new T[capacity]) {
	this->size = size;
	capacity = size;
	elem = new T[size];
	for (auto i : list)
		push_back(i);
}

template<class T>
vector<T>::vector(const vector<T>& v) {
	this->size = v.size;
	this->capacity = v.capacity;
	T* newElem = new T[v.capacity];

	for (unsigned int i = 0; i < v.size; i++)
		newElem[i] = elem[i];
}

template<class T>
vector<T>& vector<T>::operator=(const vector<T>& v) {
	if (&v != this) {
		this->size = v.size;
		this->capacity = v.capacity;
		delete[] elem;
		elem = new T[size];
		for (unsigned int i = 0; i < size; i++)
			elem[i] = v.elem[i];
	}
	return *this;
}

template<class T>
bool vector<T>::operator==(const vector<T>& v) const {
	if (this->size != v.size)
		return false;
	for(unsigned int i = 0; i < size; ++i){
		if (elem[i] != v.elem[i])
			return false;
	}
	return true;
}

template<class T>
inline bool vector<T>::operator!=(const vector<T>& v) const {
	return !(*this == v);
}

template<class T>
bool vector<T>::empty() const {
	return (size == 0);
}

template<class T>
typename vector<T>::iterator vector<T>::begin() {
	return elem;
}

template<class T>
typename vector<T>::iterator vector<T>::end() {
	return elem + size;
}

template<class T>
typename const vector<T>::iterator vector<T>::begin() const{
	return elem;
}

template<class T>
typename const vector<T>::iterator vector<T>::end() const {
	return elem + size;
}

template<class T>
typename const vector<T>::iterator vector<T>::cbegin() const {
	return elem;
}

template<class T>
typename const vector<T>::iterator vector<T>::cend() const {
	return (elem + size);
}

template<class T>
T& vector<T>::front(){
	return elem[0];
}

template<class T>
inline const T& vector<T>::front() const {
	return elem[0];
}

template<class T>
T& vector<T>::back() {
	return elem[size-1];
}

template<class T>
inline const T& vector<T>::back() const {
	return elem[size - 1];
}

template<class T>
typename T& vector<T>::at(int n) {
	if (n >= size)
		throw std::out_of_range("vector::_M_range_check: __n (which is " + std::to_string(n) + " ) >= this->size() (which is " + std::to_string(n) + " )");
	else
		return elem[n];
}

template<class T>
typename const T& vector<T>::at(int n) const{
	if (n >= size || n < 0)
		throw std::out_of_range("vector::_M_range_check: __n (which is " + std::to_string(n) + " ) >= this->size() (which is " + std::to_string(n) + " )");
	else
		return elem[n];
}

template<class T>
void vector<T>::clear() {
	capacity = 0;
	size = 0;
	//delete[] elem;
}

template<class T>
vector<T>::~vector<T>() {
	clear();
}

template<class T>
void vector<T>::push_back(const T& v) {
	if (capacity == 0)
		reserve(1);
	else if (size == capacity)
		reserve(2 * capacity);

	elem[size] = v;

	++size;
}

template<class T>
void vector<T>::pop_back() {
	size--;
}

template<class T>
void vector<T>::reserve(unsigned int capacity) {
	if (elem == nullptr) {
		size = 0;
		this->capacity = 0;
	}
	T* newElem = new T[capacity];
	unsigned int newSize = capacity < size ? capacity : size;

	for (unsigned int i = 0; i < newSize; i++)
		newElem[i] = elem[i];

	this->capacity = capacity;
	delete[] elem;
	elem = newElem;
}

template<class T>
unsigned int vector<T>::mysize() const{
	return this->size;
}

template<class T>
unsigned int vector<T>::mycapacity() const {
	return this->capacity;
}

template<class T>
void vector<T>::resize(unsigned int size) {
	reserve(size);
	this->size = size;
}

template<class T>
void vector<T>::shrink_to_fit() {
	T* newElem = new T[size];
	for (int i = 0; i < size; i++) {
		newElem[i] = elem[i];
	}
	delete[] elem;
	elem = newElem;
	capacity = size;
}

template<class T>
T& vector<T>::operator[](unsigned int index){
	if (index < 0 || index >= size)
		throw "out of bounds element access";
	return elem[index];
}

template<class T>
const T& vector<T>::operator[](unsigned int index) const{
	if (index < 0 || index >= size)
		throw "out of bounds element access";
	return elem[index];
}