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
	int straggler = 	-1;
	bool hasStraggler = false;

	if (seq.size() <= 1)
		return;

	for (size_t i = 0; i + 1 < seq.size(); i += 2) {
		
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
		straggler = seq[seq.size() - 1];
		hasStraggler = true;
	}

	std::vector<std::pair<int, int> >	pairs;
	for (size_t i = 0; i < winners.size(); i++)
		pairs.push_back(std::make_pair(winners[i], losers[i]));

	sortWithVector(winners);

	losers.clear();
	for (size_t i = 0; i < winners.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (pairs[j].first == winners[i]) {
				losers.push_back(pairs[j].second);
				break;
			}
		}
	}

	winners.insert(winners.begin(), losers[0]);

	for (size_t i = 1; i < losers.size(); i++) {

		std::vector<int>::iterator	pos = std::lower_bound(winners.begin(), winners.end(), losers[i]);
		winners.insert(pos, losers[i]);
	}

	if (hasStraggler) {
		std::vector<int>::iterator	pos = std::lower_bound(winners.begin(), winners.end(), straggler);
		winners.insert(pos, straggler);
	}

	seq = winners;
}

void	PmergeMe::sortWithDeque(std::deque<int> &seq) {
	
	std::deque<int>		winners;
	std::deque<int>		losers;
	int straggler = 	-1;
	bool hasStraggler = false;

	if (seq.size() <= 1)
		return;

	for (size_t i = 0; i + 1 < seq.size(); i += 2) {
		
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
		straggler = seq[seq.size() - 1];
		hasStraggler = true;
	}

	std::vector<std::pair<int, int> >	pairs;
	for (size_t i = 0; i < winners.size(); i++)
		pairs.push_back(std::make_pair(winners[i], losers[i]));

	sortWithDeque(winners);

	losers.clear();
	for (size_t i = 0; i < winners.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (pairs[j].first == winners[i]) {
				losers.push_back(pairs[j].second);
				break;
			}
		}
	}

	winners.insert(winners.begin(), losers[0]);

	for (size_t i = 1; i < losers.size(); i++) {

		std::deque<int>::iterator	pos = std::lower_bound(winners.begin(), winners.end(), losers[i]);
		winners.insert(pos, losers[i]);
	}

	if (hasStraggler) {
		std::deque<int>::iterator	pos = std::lower_bound(winners.begin(), winners.end(), straggler);
		winners.insert(pos, straggler);
	}

	seq = winners;
}