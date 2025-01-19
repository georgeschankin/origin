#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>

template <typename T>
class Safe_Queue
{
	private:
		std::queue<T> q; //��� �������� �����
		std::mutex m; //��� ���������� ����������
		std::condition_variable c; //��� �����������

	public:	
		//����� push � ���������� � ������ ������� ����� ������. 
		//��� ���� ����������� �������, � ����� ��������� �������� �������������� �������� ����������;	
		void push(T fun)
		{
			std::unique_lock<std::mutex> l(m);
			q.push(std::move(fun));
			c.notify_one();
		}
		
		//����� pop � ��������� � ��������, ���� �� ����� ����������� �� �������� ����������. 
		//��� ����������� �������� ���������� ������ ����������� �� �������;
		void pop(T& value)
		{
			std::unique_lock<std::mutex> l(m);
			c.wait(l, [this] {return !q.empty();}); //��������
			value = std::move(q.front()); //������ �������
			q.pop(); //�������� �� ������� �����
		}

		bool empty()
		{
			std::unique_lock<std::mutex> l(m);
			return q.empty();
		}

		int size() const
		{
			return q.size();
		}
};