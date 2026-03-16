#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <climits>

class Span {

	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;
	
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &copy);
		Span &operator=(Span const &copy);
		~Span();

		void			addNumber(int number);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		template <typename It>
		void	addRange(It begin, It end);

		unsigned int	size() const;

};

template <typename It>
void	Span::addRange(It begin, It end) {
	
	typename std::iterator_traits<It>::difference_type distance = std::distance(begin, end);

	if (_numbers.size() + distance > _maxSize) {
		throw std::length_error("Cannot add range: would exceed maximum size");
	}

	_numbers.insert(_numbers.end(), begin, end);
}

#endif