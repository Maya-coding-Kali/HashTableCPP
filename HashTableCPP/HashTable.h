#pragma once
#include <iostream>
#include <list>
#include <cstring>
using namespace std;
class HashTable
{
private:
	static const int hashGroups = 10;
	list<pair<int, string>> table[hashGroups];//List 1, Index 0, List 2, Index 1
public:
	HashTable();
	~HashTable();
	bool isEmpty() const;
	int hashFunchtion(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();


};

