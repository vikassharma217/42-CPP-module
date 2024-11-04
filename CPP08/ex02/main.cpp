#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}


// int main() {
//     // Create a MutantStack of integers
//     MutantStack<int> mstack;

//     // Push elements onto the stack
//     mstack.push(5);
//     mstack.push(17);
//     mstack.push(3);
//     mstack.push(42);
//     mstack.push(9);

//     // Display top element
//     std::cout << "Top element: " << mstack.top() << std::endl;

//     // Pop the top element
//     mstack.pop();
//     std::cout << "Top element after pop: " << mstack.top() << std::endl;

//     // Iterate using iterators
//     std::cout << "Elements in stack: ";
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     // Test reverse iteration
//     std::cout << "Elements in reverse order: ";
//     for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
//         std::cout << *rit << " ";
//     }
//     std::cout << std::endl;

//     // Test const iterators
//     const MutantStack<int> const_mstack = mstack;
//     std::cout << "Elements in const stack: ";
//     for (MutantStack<int>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit) {
//         std::cout << *cit << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }