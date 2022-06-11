
#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;


int pageFaults(int pages[], int n, int capacity)
{

	unordered_set<int> s;
	queue<int> indexes;

	int page_faults = 0;
	for (int i=0; i<n; i++)
	{
		//when set is not full
		if (s.size() < capacity)
		{
			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);
				page_faults++;
				indexes.push(pages[i]);
			}
		}

		// If the set is full then need to perform FIFO
		else
		{
			if (s.find(pages[i]) == s.end())
			{
				int val = indexes.front();
				indexes.pop();
				s.erase(val);
				s.insert(pages[i]);
				indexes.push(pages[i]);
				page_faults++;
			}
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
	cout <<  "Page Faults:" <<pageFaults(pages, n, capacity);
	return 0;
}
