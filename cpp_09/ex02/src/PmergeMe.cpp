#include "../include/PmergeMe.hpp"

//canonical form

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(PmergeMe const &copy) {
	_vec = copy._vec;
	_deq = copy._deq;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy) {

	if (this != &copy) {
		_vec = copy._vec;
		_deq = copy._deq;
	}

	return *this;
}

PmergeMe::~PmergeMe() {

}

//method

void	PmergeMe::sortWithVector(std::vector<int> &seq) {
	
	std::vector<int>	winners;
	std::vector<int>	losers;

	for (int i = 0; i < seq.size(); i += 2) {
		
		if (seq[i] > seq[i + 1]) {
			winners.push_back(seq[i]);
			losers.push_back(seq[i + 1]);
		}
		else {
			winners.push_back(seq[i + 1]);
			losers.push_back(seq[i]);
		}
	}

	if (seq.size() % 2 != 0) {
		(seq.size() - 1);
	}
}

void	PmergeMe::sortWithDeque(std::deque<int> &seq) {
	
	std::deque<int>	winners;
	std::deque<int>	losers;

	for (int i = 0; i < seq.size(); i += 2) {
		
		if (seq[i] > seq[i + 1]) {
			winners.push_back(seq[i]);
			losers.push_back(seq[i + 1]);
		}
		else {
			winners.push_back(seq[i + 1]);
			losers.push_back(seq[i]);
		}
	}

	if (seq.size() % 2 != 0) {
		(seq.size() - 1);
	}
}