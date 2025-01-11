#include "Thread_Pool.h"

void Thread_Pool::work()
{	
	std::unique_lock<std::mutex> lock(m);	
	while (Safe_Queue.empty())
	{		
		Safe_Queue.wait(lock);
	}
	Safe_Queue.front();
	Safe_Queue.pop();		
}

void Thread_Pool::submit(std::vector<std::function<void()>> fun, int countSubmits)
{
	for (int i = 0; i < countSubmits; ++i)
	{
		for (int j = 0; j < fun.size(); ++j)
		{
			Safe_Queue.push(fun.at(j));
		}		
	}	
}