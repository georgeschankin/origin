#include "Safe_Queue.h"

template <typename B>
void Safe_Queue<B>::pop()
{
	//способ 1 (в таком случае нужны остальные методы класса)
	//std::unique_lock<std::mutex> l(m);
	//q.pop();

	//способ 2 (в таком случае остальные методы не нужны)
	std::unique_lock<std::mutex> l(m);
	c.wait(l, [&]);
	q.front();
	q.pop();
}

template <typename C>
void Safe_Queue<C>::front()
{
	std::unique_lock<std::mutex> l(m);
	q.front()();
}

template <typename D>
bool Safe_Queue<D>::empty()
{
	std::unique_lock<std::mutex> l(m);
	return q.empty();
}

template <typename E>
void Safe_Queue<E>::wait(std::unique_lock<std::mutex> l)
{
	//std::unique_lock<std::mutex> l(m);
	c.wait(l);
}
