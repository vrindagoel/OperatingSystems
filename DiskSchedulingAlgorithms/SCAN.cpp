// C++ program to demonstrate
// SCAN Disk Scheduling algorithm
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void SCAN(int arr[], int head, string direction,int size,int disk_size)
{
	int seek_count = 0;
	int distance, cur_track;
	vector<int> left, right;
	vector<int> seek_sequence;
	if (direction == "left")
		left.push_back(0);
	else if (direction == "right")
		right.push_back(disk_size - 1);

	for (int i = 0; i < size; i++) {
		if (arr[i] < head)
			left.push_back(arr[i]);
		if (arr[i] > head)
			right.push_back(arr[i]);
	}

	// sort
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
	int run = 2;
	while (run--) {
		if (direction == "left") {
			for (int i = left.size() - 1; i >= 0; i--) {
				cur_track = left[i];
				seek_sequence.push_back(cur_track);
				distance = abs(cur_track - head);
				seek_count += distance;
				head = cur_track;
			}
			direction = "right";
		}
		else if (direction == "right") {
			for (int i = 0; i < right.size(); i++) {
				cur_track = right[i];
				seek_sequence.push_back(cur_track);
				distance = abs(cur_track - head);
				seek_count += distance;
				head = cur_track;
			}
			direction = "left";
		}
	}

	cout << "Total number of seek operations = "
		<< seek_count << endl;

	cout << "Seek Sequence is" << endl;

	for (int i = 0; i < seek_sequence.size(); i++) {
		cout << seek_sequence[i] << endl;
	}
}

// Driver code
int main()
{
	int size,disk_size,head;
	cout<<"Enter the Number of disks";
	cin>>size;
	cout<<"Enter the size of the disk";
	cin>>disk_size;
	cout<<"Enter the head position";
	cin>>head;
	int* arr=new int[size];
	for(int i=0;i<size;i++)
	{
		cout<<"Enter the size of "<<i+1<<" disk: ";
		cin>>arr[i];
	}
	string direction;
	cout<<"Enter the direction of the disk: ";
	cin>>direction;
	SCAN(arr, head, direction,size,disk_size);

	return 0;
}
