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
		//метод push Ч записывает в начало очереди новую задачу. 
		//ѕри этом захватывает мьютекс, а после окончани€ операции нотифицируетс€ условна€ переменна€;
		template <typename A>
		void push(A fun)
		{
			std::unique_lock<std::mutex> l(m);
			q.push(fun);
			c.notify_one();
		}
		
		//метод pop Ч находитс€ в ожидании, пока не придЄт уведомление на условную переменную. 
		//ѕри нотификации условной переменной данные считываютс€ из очереди;
		void pop();
		
		void front();
		
		bool empty();
		
		void wait(std::unique_lock<std::mutex> l);
};