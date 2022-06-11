// #include <bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

// to check whether a page exists in a frame or not
bool search(int key, vector<int>& frames)
{
	for (int i = 0; i < frames.size(); i++)
		if (frames[i] == key) return true;
	return false;
}

// Function to find the frame that will not be used recently in future
int predict(int Pages[], vector<int>& frames, int n, int index)
{
	// Store the index of pages which are going to be used recently in future
	int res = -1, farthest = index;
	for (int i = 0; i < frames.size(); i++) {
		int j;
		for (j = index; j < n; j++) {
			if (frames[i] == Pages[j]) {
				if (j > farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}
		// If a page is never referenced in future,return it.
		if (j == n)
			return i;
	}
	// If all of the frames were not in future,return any of them, we return 0. Otherwise we return res.
	return (res == -1) ? 0 : res;
}

int pageFaults(int Pages[], int n, int capacity)
{
	// Create an array for given number of
	// frames and initialize it as empty.
	vector<int> frames;

	// Check for miss and hit.
	int hit = 0;
	for (int i = 0; i < n; i++) {

		// Page found in a frame : HIT
		if (search(Pages[i], frames)) {
			hit++;
			continue;
		}
		// If there is space available in frames.
		if (frames.size() < capacity)
			frames.push_back(Pages[i]);

		// Find the page to be replaced.
		else {
			int j = predict(Pages, frames, n, i + 1);
			frames[j] = Pages[i];
		}
	}
	return (n-hit);
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
	cout << "Page Faults:" << pageFaults(pages, n, capacity);
	return 0;
}


