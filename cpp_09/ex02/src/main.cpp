#include "../include/PmergeMe.hpp"

int	main(int ac, char **av) {

	if (ac < 2) {

		std::cerr << RED << "Error" << RESET << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < ac; i++) {

		int num = atoi(av[i]);

		if (num < 0) {
			std::cerr << RED << "Error: negative value" << RESET << std::endl;
			return 1;
		}
		vec.push_back(num);
		deq.push_back(num);
	}

	PmergeMe sorter;

	//vector
	std::cout << "Before: " << std::endl;

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	clock_t start = clock();
	sorter.sortWithVector(vec);
	clock_t end = clock();
	double timeVec = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	//deque
	start = clock();
	sorter.sortWithDeque(deq);
	end = clock();
	double timeDeq = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;

    return 0;
}