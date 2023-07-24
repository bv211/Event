#pragma once
#include "Event.h"

class Counter {
	int _count{ 0 };

public:
	Event on_count_chaged_event;

	int get_count() const {
		return _count;
	}

	void set_count(int value) {
		_count = value;
		call_event();
	}

private:
	void call_event() {
		on_count_chaged_event.invoke();
	}
};
