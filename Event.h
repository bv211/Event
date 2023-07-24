#pragma once
#include <vector>

using namespace std;

template <class... TParams>
class IEventHandler {
public:
	virtual void call(TParams... params) = 0;
};

template <class... TParams>
class Event {
	using TEvent = IEventHandler<TParams...>;

	vector<TEvent*> _observers;

public:
	void operator+=	(TEvent& pointer) {
		_observers.push_back(&pointer);
	}

	void invoke(TParams... params) {
		for (auto& item : _observers)
			item->call(params...);
	}
};