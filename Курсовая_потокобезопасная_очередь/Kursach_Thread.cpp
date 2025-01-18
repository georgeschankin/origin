#include <iostream>
#include "Safe_Queue.h"
#include "Thread_Pool.h"

void fun1()
{
	std::cout << __FUNCTION__ << std::endl;
}

void fun2()
{
	std::cout << __FUNCTION__ << std::endl;
}

int main()
{
    int cores = std::thread::hardware_concurrency();
	Thread_Pool thread_pool(cores);	
	std::vector<std::function<void()>> fun {fun1, fun2};
	std::vector<std::thread> vectorThreads(fun.size());

	/*for (int i = 0; i < fun.size(); i++)
	{
		vectorThreads[i] = std::thread(&Thread_Pool::submit, &thread_pool, std::ref(fun[i])); //передаю задачи в цикле
	}

	for (auto& i : vectorThreads)
	{
		i.join();
	}*/

	for (int i = 0; i < fun.size(); i++)
	{
		thread_pool.submit(fun1);
		thread_pool.submit(fun2);
	}
	
	return 0;
}