#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>

template <typename T>
class Safe_Queue
{
	private:
		std::queue<T> q;
		std::mutex m;
		std::condition_variable c;

	public:	
		template <typename A>
		void push(A fun)
		{
			std::unique_lock<std::mutex> l(m);
			q.push(fun);
			c.notify_one();
		}
		
		void pop();
		
		void front();
		
		bool empty();
		
		void wait(std::unique_lock<std::mutex> l);
};