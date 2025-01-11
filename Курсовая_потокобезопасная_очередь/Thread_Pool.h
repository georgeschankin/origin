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
		std::mutex m;

	public:
		Thread_Pool(int cores)
		{
			for (int i = 0; i < cores; ++i)
			{
				vec_th.push_back(std::thread(&Thread_Pool::work, this));
			}
		}

		void work();

		void submit(std::vector<std::function<void()>> fun, int countSubmits);
};