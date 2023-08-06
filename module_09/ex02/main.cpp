#include "PmergeMe.hpp"

/**
 * @brief Main function to demonstrate parallel merge and insertion sort operations.
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return 0 on success, 1 on error.
 */
int main(int argc, char* argv[]) {
    PmergeMe pme;

    if (argc < 3) {
        std::cout << "ERROR: Invalid number of arguments" << std::endl;
        return 1;
    }

    for (int i = 1; argv[i]; i++) {
        if (!pme.isValidArg(argv[i]))
            return 1;
        pme.fillContainer(argv[i]);
    }

    pme.sttDeq = clock();
    pme.sort(pme.deq, 0, pme.deq.size() - 1);
    pme.endDeq = clock();

    pme.sttVec = clock();
    pme.sort(pme.vec, 0, pme.vec.size() - 1);
    pme.endVec = clock();

    pme.printOutput(argv);

    return 0;
}
