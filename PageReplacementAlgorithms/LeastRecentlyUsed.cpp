//C++ implementation of above algorithm
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;


int pageFaults(int pages[], int n, int capacity)
{
	unordered_set<int> s;
	unordered_map<int, int> indexes;
	int page_faults = 0;
	for (int i=0; i<n; i++)
	{
		// Check if the set can hold more pages
		if (s.size() < capacity)
		{
			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);
				page_faults++;
			}
			indexes[pages[i]] = i;
		}
		else
		{
			if (s.find(pages[i]) == s.end())
			{
				int lru = INT_MAX;
                int val;
				for (auto it=s.begin(); it!=s.end(); it++)
				{
					if (indexes[*it] < lru)
					{
						lru = indexes[*it];
						val = *it;
					}
				}
				s.erase(val);
				s.insert(pages[i]);
				page_faults++;
			}
			indexes[pages[i]] = i;
		}
	}

	return page_faults;
}

int main()
{
	int n,capacity;
	cout<<"Enter the number of pages: ";
	cin>>n;
	int* pages=new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the page number: ";
		cin>>pages[i];
	}
	cout<<"Enter the capacity of the set: ";
	cin>>capacity;
	cout << "Page Faults:" <<pageFaults(pages, n, capacity);
	return 0;
}