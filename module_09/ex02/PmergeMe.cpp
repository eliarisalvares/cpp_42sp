#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
    *this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    this->vec = rhs.vec;
    this->deq = rhs.deq;
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidArg(char* arg) {
    std::string str = arg;

    if ((!str.empty() && str.find_first_not_of("0123456789") != std::string::npos) ||
        (atoi(arg) > INT_MAX)) {
        std::cout << "Error" << std::endl;
        return false;
    }
    return true;
}

void PmergeMe::fillContainer(char* arg) {
    vec.push_back(atoi(arg));
    deq.push_back(atoi(arg));
}

void PmergeMe::printOutput(char** arg) {
    double durationVec = ((double)(endVec - sttVec)) / CLOCKS_PER_SEC * 1000.0;
    double durationDeq = ((double)(endDeq - sttDeq)) / CLOCKS_PER_SEC * 1000.0;

    std::cout << "Before -> ";
    for (int i = 1; arg[i]; i++) {
        std::cout << arg[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "After -> ";
    for (size_t i = 0; i != vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector -> "
              << durationVec << " ms" << std::endl;

    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque -> "
              << durationDeq << " ms" << std::endl;
}
