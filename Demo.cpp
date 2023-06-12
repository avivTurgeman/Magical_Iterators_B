#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
int main() {
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    // Print container size
    std::cout << "Size of container: " << container.size() << std::endl;

    std::cout << "=================AscendingIterator operators=================" << std::endl;
    std::cout << "\033[1;34m"; // Set console text color to blue
    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;
    std::cout << "\033[0m" << std::endl; // Returning console text color to default

    MagicalContainer::AscendingIterator ascIter1(container);
    MagicalContainer::AscendingIterator ascIter2(container);

    std::cout <<std::boolalpha;
    std::cout << *ascIter1 << " is equal to " << *ascIter2 << "? " << "\033[1;32m" << (ascIter1 == ascIter2) << "\033[0m" <<std::endl;
    ++ascIter2;
    std::cout << *ascIter1 << " is before " << *ascIter2 << "? " << "\033[1;32m" << (ascIter1 < ascIter2) << "\033[0m" <<std::endl;
    ++(++ascIter1);
    std::cout << *ascIter1 << " is after " << *ascIter2 << "? " << "\033[1;32m" << (ascIter1 > ascIter2) << "\033[0m" <<std::endl;
    std::cout << *ascIter1 << " is not equal to " << *ascIter2 << "? " << "\033[1;32m" << (ascIter1 != ascIter2) << "\033[0m" <<std::endl;

    std::cout << "=================SideCrossIterator operators=================" << std::endl;
    std::cout << "\033[1;34m"; // Set console text color to blue
    // Use SideCrossIterator to display elements in crossing order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;
    std::cout << "\033[0m" << std::endl; // Returning console text color to default

    MagicalContainer::SideCrossIterator crossIter1(container);
    MagicalContainer::SideCrossIterator crossIter2(container);

    std::cout <<std::boolalpha;
    std::cout << *crossIter1 << " is not equal to " << *crossIter2 << "? " << "\033[1;31m" << (crossIter1 != crossIter2) << "\033[0m" <<std::endl;
    ++crossIter2;
    std::cout << *crossIter1 << " is before " << *crossIter2 << "? " << "\033[1;32m" << (crossIter1 < crossIter2) << "\033[0m" <<std::endl;
    ++(++crossIter1);
    std::cout << *crossIter1 << " is after " << *crossIter2 << "? " << "\033[1;32m" << (crossIter1 > crossIter2) << "\033[0m" <<std::endl;
    std::cout << *crossIter1 << " is equal to " << *crossIter2 << "? " << "\033[1;31m" << (crossIter1 == crossIter2) << "\033[0m" <<std::endl;

    std::cout << "=================PrimeIterator operators=================" << std::endl;
    std::cout << "\033[1;34m"; // Set console text color to blue
    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    std::cout << std::endl;
    std::cout << "\033[0m" << std::endl; // Returning console text color to default

    MagicalContainer::PrimeIterator primeIter1(container);
    MagicalContainer::PrimeIterator primeIter2(container);

    std::cout <<std::boolalpha;
    std::cout << *primeIter1 << " is not equal to " << *primeIter2 << "? " << "\033[1;31m" << (primeIter1 != primeIter2) << "\033[0m" <<std::endl;
    ++primeIter2;
    std::cout << *primeIter1 << " is after " << *primeIter2 << "? " << "\033[1;31m" << (primeIter1 > primeIter2) << "\033[0m" <<std::endl;
    ++(++primeIter1);
    std::cout << *primeIter1 << " is before " << *primeIter2 << "? " << "\033[1;31m" << (primeIter1 < primeIter2) << "\033[0m" <<std::endl;
    std::cout << *primeIter1 << " is equal to " << *primeIter2 << "? " << "\033[1;31m" << (primeIter1 == primeIter2) << "\033[0m" <<std::endl;

    std::cout << std::endl;

    // Remove an element from the container and display the size
    container.removeElement(9);
    std::cout << "Size of container after removing an element: " << container.size() << std::endl;

    return 0;
}
