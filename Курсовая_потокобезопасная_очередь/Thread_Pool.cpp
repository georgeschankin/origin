#include "Thread_Pool.h"

void Thread_Pool::work()
{	
	std::unique_lock<std::mutex> lock(m);
	s_queue.pop();
}

void Thread_Pool::submit(std::vector<std::function<void()>> fun)
{	
	for (int j = 0; j < fun.size(); ++j)
	{
		s_queue.push(fun.at(j));
	}				
}