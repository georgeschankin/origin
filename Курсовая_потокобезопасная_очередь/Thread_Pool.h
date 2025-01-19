#pragma once

#include "Safe_Queue.h"

#include <thread>
#include <vector>
#include <mutex>
#include <functional>

class Thread_Pool
{
	private:
		std::vector<std::thread> vec_th;
		std::mutex m; //дл€ реализации блокировки
		Safe_Queue<std::function<void()>> s_queue; //дл€ использовани€ функций из класса Safe_Queue		

	public:
		Thread_Pool(int cores)
		{			
			for (int i = 0; i < cores; ++i)
			{
				vec_th.push_back(std::thread(&Thread_Pool::work, this));
			}
		}

		~Thread_Pool()
		{
			for (auto& i : vec_th)
			{
				i.join();
			}
		}

		//метод work Ч выбирает из очереди очередную задачу и исполн€ет еЄ. 
		//Ётот метод передаЄтс€ конструктору потоков дл€ исполнени€;
		void work();

		//метод submit Ч помещает в очередь задачу.
		//¬ качестве аргумента метод может принимать или объект шаблона std::function, или объект шаблона package_task;
		void submit(std::function<void()> fun);


};