#include "Safe_Queue.h"

template <typename B>
void Safe_Queue<B>::pop()
{
	std::unique_lock<std::mutex> l(m);
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
