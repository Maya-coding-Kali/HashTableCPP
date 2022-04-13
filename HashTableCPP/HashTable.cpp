#include "HashTable.h"

HashTable::HashTable() 
{
	static const int hashGroups = 10;
}
HashTable::~HashTable()
{

}
bool HashTable:: isEmpty() const
{
	int sum{};
	for (int i{}; i < hashGroups; i++)
	{
		sum += table[i].size();
	}
	if (!sum)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
int HashTable::hashFunchtion(int key)
{
	return key % hashGroups; //key is not a 5 
}
void HashTable::insertItem(int key, string value)
{
	int hashValue = hashFunchtion(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (;  bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr->second = value;
			cout << "[WANRING] Key exists. Value replaced." << endl;
			break;
		}
	}
	if (!keyExists)
	{
		cell.emplace_back(key, value);
	}
	return;
}
void HashTable::removeItem(int key)
{
	int hashValue = hashFunchtion(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "[INFO] Item removed" << endl;
			break;
		}
	}
	if (!keyExists)
	{
		cout << "[WARNING] Key not found. Pair not removed." << endl;
	}
	return;
	
}
void HashTable::printTable()
{
	for (int i{}; i < hashGroups; i++)
	{
		if (table[i].size() == 0)
		{
			continue;
		}
		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++)
		{
			cout << "[INFO] Key:" << bItr->first << " Value:" << bItr->second << endl;
		}
	}
	return;
}