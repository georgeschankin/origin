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
	return 0;
}