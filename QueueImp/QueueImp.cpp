#include <iostream>
#include <string>
#include "Queue.h"

// Driver code 
int main()
{
	Queue<int> q;

	while (true)
	{
		std::cout << "Input integer data to Enqueue: ";
		std::string ans;
		std::cin >> ans;
		if (ans == "stop") break;

		q.enqueue(std::stoi(ans));
	}

	std::cout << std::endl << "Choose the option below. Write 'print' to print a list." << std::endl;
	std::cout << "1. Enqueue." << std::endl;
	std::cout << "2. Dequeue." << std::endl;
	std::cout << "3. Swap." << std::endl;
	std::cout << "4. Reverse." << std::endl;
	std::cout << "5. Delete queue." << std::endl;
	std::cout << "6. Check if queue contains particular element." << std::endl;

	while (true)
	{
		std::cout << std::endl << "Your choice: ";

		std::string ans;
		std::cin >> ans;

		if (ans == "print")
		{
			q.print();
		}

		if (ans == "1")
		{
			std::cout << "Input integer to Enqueue: ";
			int n;
			std::cin >> n;

			q.enqueue(n);
			continue;
		}

		if (ans == "2")
		{
			q.dequeue();
			continue;
		}

		if (ans == "3")
		{
			q.swap();
			continue;
		}

		if (ans == "4")
		{
			q.reverse();
			continue;
		}

		if (ans == "5")
		{
			q.destroy();
			continue;
		}

		if (ans == "6")
		{
			std::cout << "Input integer to check: ";
			int n;
			std::cin >> n;

			if (q.contains(n))
				std::cout << "There is at least one element with value "
				<< n << "!" << std::endl;
			else
				std::cout << n << " is missing." << std::endl;
			continue;
		}
	}
	return 0;
}