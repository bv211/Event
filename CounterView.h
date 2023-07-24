#pragma once
#include <iostream>
#include "Counter.h"

using namespace std;

class CounterView : public IEventHandler<int> {
	Counter& counter;

public:
	CounterView(Counter& counter) : counter(counter) {
		counter.on_count_chaged_event += *this;
	}

	virtual void call(int count) override {
		system("cls");
		cout << "value has been changed!" << endl
			<< "new value is:" << endl
			<< count << endl;
	}
};
