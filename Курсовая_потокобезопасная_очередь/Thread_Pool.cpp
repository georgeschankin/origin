#include "Thread_Pool.h"

void Thread_Pool::work()
{	
	std::unique_lock<std::mutex> lock(m);
	while (true)
	{		
		//std::function<void()> task;
		if (!s_queue.empty())
		{
			s_queue.pop();
			//task(); task = s_queue.pop(); ���������� ��������� ����� pop (��� ���������� ����, ��� � ���������� ����� ��� void)
			//�� ����� ����� ����� ����� task
		}
		else
		{
			std::this_thread::yield();
		}		
	}
	lock.unlock();
}

void Thread_Pool::submit(std::vector<std::function<void()>> fun)
{	
	//for (int j = 0; j < fun.size(); ++j)
	//{
		s_queue.push(fun);
	//}				
}