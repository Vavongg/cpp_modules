#include "../include/Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : _maxSize(0) {
}

Span::Span(unsigned int n) : _maxSize(n) {

	_numbers.reserve(n);
}

Span::Span(Span const &copy) : _maxSize(copy._maxSize), _numbers(copy._numbers) {
}

Span &Span::operator=(Span const &copy) {

	if (this != &copy) {
		_maxSize = copy._maxSize;
		_numbers = copy._numbers;
	}
	return *this;
}

Span::~Span() {
}


void	Span::addNumber(int number) {

	if (_numbers.size() >= _maxSize) {
		throw std::length_error("Span is already full");
	}
	_numbers.push_back(number);
}

unsigned int	Span::shortestSpan() const {

	if (_numbers.size() < 2) {
		throw std::logic_error("Cannot find span with less than 2 numbers");
	}

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sorted.size(); i++) {
		unsigned int span = sorted[i] - sorted[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}

	return minSpan;
}

unsigned int	Span::longestSpan() const {

	if (_numbers.size() < 2) {
		throw std::logic_error("Cannot find span with less 2 numbers");
	}

	int	min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(max - min);
}

unsigned int	Span::size() const {
	return _numbers.size();
}
