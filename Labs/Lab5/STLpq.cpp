#include<queue>
#include<string>
#include<iostream>
using namespace std;

void FillQueue(priority_queue<string>& pq);
void PrintQueue(priority_queue<string>& pq);

int main()
{
	priority_queue<string> pq;

	FillQueue(pq);

	PrintQueue(pq);

	return 0;
}
void FillQueue(priority_queue<string>& pq)
{
	pq.push("Ian");	
	pq.push("Natalie");	
	pq.push("Max");	
	pq.push("Luke");	
	pq.push("Adam");	
	pq.push("Ben");	
	pq.push("Zach");	
	pq.push("James");	
	pq.push("Oscar");	
	pq.push("Peter");	

}
void PrintQueue(priority_queue<string>& pq)
{
	priority_queue<string> localpq = pq;

	for(int i = 0; i < pq.size(); i+=0)
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}
