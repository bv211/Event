#include <iostream>
#include "Event.h"
#include "Counter.h"
#include "CounterView.h"

using namespace std;

int main() {
	setlocale(0, "");

	Counter counter;
	CounterView view(counter);

	cout << "Введите значение" << endl;
	int n;
	cin >> n;
	counter.set_count(n);;

	return 0;
}