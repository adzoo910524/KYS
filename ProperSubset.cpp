#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class IntegerSet
{

public:
	vector<int> intVector;

	IntegerSet() {}

	void getIntegerSet(int n[], int size) {
		for (int i = 0; i < size; i++)
			intVector.push_back(n[i]);
	}

	void printIntegerSet()
	{
		vector<int>::iterator i;
		cout << "[";
		for (i = intVector.begin(); i != intVector.end(); i++)
		{
			cout << *i;
			cout << ((i != intVector.end() - 1) ? ", " : "");
		}
		cout << "]" << endl;
	}
};

bool isProperSubset(const IntegerSet& a, const IntegerSet& b)
{
	if (a.intVector.size() < b.intVector.size())
		return (includes(b.intVector.begin(), b.intVector.end(), a.intVector.begin(), a.intVector.end())) ? true : false;

	return false;

	/*if (a.intVector.size() < b.intVector.size())
	{
		for (int i = 0; i < a.intVector.size(); i++)
		{
			if (a.intVector[i] != b.intVector[i])
				return false;
		}
		return true;
	}
	return false;*/
}

bool operator < (const IntegerSet& a, const IntegerSet& b) {
	
	if (isProperSubset(a, b)) return true;
	if (isProperSubset(b, a)) return false;

	if (a.intVector.size() != b.intVector.size()) return a.intVector.size() < b.intVector.size();
	return lexicographical_compare(a.intVector.begin(), a.intVector.end(), b.intVector.begin(), b.intVector.end());
}

bool compare(const IntegerSet& a, const IntegerSet& b)
{
	if (a < b)
		return true;
	else
		return false;
}
int main(void)
{

	//cout <<  << endl;

	vector<IntegerSet> integerSet;
	IntegerSet A1;
	int a[2]{ 1,2 };
	A1.getIntegerSet(a, sizeof(a)/sizeof(int));
	integerSet.push_back(A1);

	IntegerSet A2;
	int a2[2]{ 3,4 };
	A2.getIntegerSet(a2, sizeof(a2) / sizeof(int));
	integerSet.push_back(A2);

	IntegerSet A3;
	int a3[1]{ 2 };
	A3.getIntegerSet(a3, sizeof(a3) / sizeof(int));
	integerSet.push_back(A3);

	IntegerSet A4;
	int a4[3]{ 1,2,3 };
	A4.getIntegerSet(a4, sizeof(a4) / sizeof(int));
	integerSet.push_back(A4);

	sort(integerSet.begin(), integerSet.end(), compare);
	vector<IntegerSet>::iterator i;
	for (i = integerSet.begin(); i != (integerSet.end()); i++)
		i->printIntegerSet();

}
