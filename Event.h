#pragma once
#include <vector>

using namespace std;

class IEventHandler {
public:
	virtual void call() = 0;
};

class Event {
	vector<IEventHandler*> _observers;

public:
	void operator+=	(IEventHandler& pointer) {
		_observers.push_back(&pointer);
	}

	void invoke() {
		for (auto& item : _observers)
			item->call();
	}
};