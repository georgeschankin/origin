#include "Thread_Pool.h"

void Thread_Pool::work()
{	
	std::function<void()> task;
	if (!s_queue.empty())
	{
		s_queue.pop(task);
		task();
	}
}

void Thread_Pool::submit(std::function<void()> fun)
{	
	s_queue.push(fun);				
}