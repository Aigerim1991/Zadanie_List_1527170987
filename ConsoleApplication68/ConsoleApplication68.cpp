// ConsoleApplication68.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <clocale>
#include <list>
#include <stack>
#include <stdio.h>
#include <cmath>
using namespace std;
//Используя стандартную реализацию. #include <list>	// Стандартная реализация очереди из stl
//Реализуйте стек в виде односвязного списка.Требуется реализовать типичные операции по работе со стеком.
//При переполнении стека нужно увеличивать его размер.
template <typename TElement>
struct TNode {
	TElement data;
	TNode <TElement> *next;

	TNode(TElement newData, TNode <TElement> *nextNode) {
		data = newData;
		next = nextNode;
	}
};
//Реализация стека на базе линейного списка
template <typename TElement>
class stackInList {
private:
	unsigned int sizeOfStack;
	TNode <TElement> *currentTop;

public:
	stackInList() {
		sizeOfStack = 0;
		currentTop = NULL;
	}

	~stackInList() {
		while (size())
			pop();
	}

	void push(const TElement element) // положить элемент на вершину стека;
	{
		TNode <TElement> *node = new TNode <TElement>(element, currentTop);
		sizeOfStack++;
		currentTop = node;
	}

	void pop()// убрать элемент с вершины;
	{
		sizeOfStack--;
		TNode <TElement> *node = currentTop;
		currentTop = currentTop->next;
		delete node;
	}

	TElement top()//вернуть элемент на вершине, не убирая его оттуда;
	{
		return currentTop->data;
	}

	unsigned int size() //вернуть размер стека.
	{
		return sizeOfStack;
	}
};
//Реализация стека на базе массива
template <typename TElement>
class stackInArray {
private:
	unsigned int sizeOfStack;
	TElement *array;

public:
	stackInArray(const unsigned int maxSize) {
		sizeOfStack = 0;
		array = new TElement[maxSize];
	}

	~stackInArray() {
		delete[] array;
	}

	void push(const TElement newElement) {
		array[sizeOfStack] = newElement;
		sizeOfStack++;
	}

	void pop() {
		sizeOfStack--;
	}

	TElement top() {
		return array[sizeOfStack - 1];
	}

	unsigned int size() {
		return sizeOfStack;
	}
};



int main()
{
	srand(time(NULL));
	unsigned int testStackSize = 90000000;
	stackInArray<int> arrayStack(testStackSize);
	stackInList<int> listStack;
	stack<int> stlStack;
	clock_t time;

	cout << "Stack size: " << testStackSize << endl;

	cout << "Test for stack in array:" << endl;

	time = clock();
	for (unsigned int i = 0; i < testStackSize; i++) {
		arrayStack.push(rand() % RAND_MAX);
	}

	time = clock() - time;
	cout << "push for stack in array end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

	time = clock();
	while (arrayStack.size()) {
		arrayStack.pop();
	}

	time = clock() - time;
	cout << "pop for stack in array end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

	cout << "Test for stack in array end." << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Test for stack in list:" << endl;

	time = clock();
	for (unsigned int i = 0; i < testStackSize; i++) {
		listStack.push(rand() % RAND_MAX);
	}

	time = clock() - time;
	cout << "push for stack in list end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

	time = clock();
	while (listStack.size()) {
		listStack.pop();
	}

	time = clock() - time;
	cout << "pop for stack in list end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

	cout << "Test for stack in list end." << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Test for STL stack:" << endl;

	time = clock();
	for (unsigned int i = 0; i < testStackSize; i++) {
		stlStack.push(rand() % RAND_MAX);
	}

	time = clock() - time;
	cout << "push for STL stack end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

	time = clock();
	while (stlStack.size()) {
		stlStack.pop();
	}

	time = clock() - time;
	cout << "pop for STL stack end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

	cout << "Test for STL stack end." << endl;
    return 0;
}

