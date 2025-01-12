#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>

template <typename T>
class Safe_Queue
{
	private:
		std::queue<T> q; //для хранения задач
		std::mutex m; //для реализации блокировки
		std::condition_variable c; //для уведомлений

	public:	
		//метод push — записывает в начало очереди новую задачу. 
		//При этом захватывает мьютекс, а после окончания операции нотифицируется условная переменная;
		template <typename A>
		void push(A fun)
		{
			std::unique_lock<std::mutex> l(m);
			q.push(fun);
			c.notify_one();
		}
		
		//метод pop — находится в ожидании, пока не придёт уведомление на условную переменную. 
		//При нотификации условной переменной данные считываются из очереди;
		void pop();
};