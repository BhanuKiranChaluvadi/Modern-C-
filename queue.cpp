#include <iostream>
#include <queue>

int main() {

	std::priority_queue<int> queue;

	queue.push(10);
	queue.push(40);
	queue.push(5);

	for (int i = 0; i < 3; i++) {
		std::cout << queue.top() << std::endl;
		queue.pop();
	} 
	return 0;
}