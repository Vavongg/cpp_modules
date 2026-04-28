#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class	PmergeMe {

	private :
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::vector<int>	generateJacobsthal(int n);
		std::vector<int>	getInsertionOrder(int n);
	
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &copy);
		~PmergeMe();

		void	sortWithVector(std::vector<int> &seq);
		void	sortWithDeque(std::deque<int> &seq);

};

#endif