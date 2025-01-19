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
		std::mutex m; //��� ���������� ����������
		Safe_Queue<std::function<void()>> s_queue; //��� ������������� ������� �� ������ Safe_Queue		

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

		//����� work � �������� �� ������� ��������� ������ � ��������� �. 
		//���� ����� ��������� ������������ ������� ��� ����������;
		void work();

		//����� submit � �������� � ������� ������.
		//� �������� ��������� ����� ����� ��������� ��� ������ ������� std::function, ��� ������ ������� package_task;
		void submit(std::function<void()> fun);


};