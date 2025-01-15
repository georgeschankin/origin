#include "Safe_Queue.h"

template <typename B>
void Safe_Queue<B>::pop()
{
	std::unique_lock<std::mutex> l(m);
	while (!q.empty())
	{
		c.wait(l); //��������
		q.front(); //������ �������
		q.pop(); //�������� �� ������� �����
	}
}

template <typename A>
bool Safe_Queue<A>::empty()
{
	std::unique_lock<std::mutex> l(m);
	return q.empty();
}
