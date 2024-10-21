# include "Bureaucrat.hpp"
# include <iostream>

/*unit test for creation with valid grade*/
void testBureaucratCreation()
{
    try
    {
       Bureaucrat b("TEST", 100);
       std::cout << "Test Passed: Bereaucrat " << b.getName() << " created with grade " 
                << b.getGrade() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << "Test Failed: Exception caught " << e.what() << std::endl;
    }
    
}

/*unit test for grade increment*/
void testGradeIncreament()
{
    try
    {
       Bureaucrat b ("testIncremenr", 2);
       b.gradeIncreament(); // grade shud be 1
       std::cout << "Test Passed: grade is now "<< b.getGrade() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr <<"Test Failed: Exception caught " <<  e.what() << std::endl;
    }

    try {
        Bureaucrat b("TestIncrementFail", 1);
        b.gradeIncreament();  // This should throw GradeTooHighException
        std::cerr << "Test Failed: Exception not thrown on grade increment beyond limit." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Passed: Caught exception for too high grade increment: " << e.what() << std::endl;
    }
    
}

/* Unit test for grade decrement */
void testGradeDecrement() {
    try {
        Bureaucrat b("TestDecrement", 149);
        b.gradeDecreament();  // Grade becomes 150 (valid)
        std::cout << "Test Passed: Decrement successful, grade is now " << b.getGrade() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test Failed: Exception caught - " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("TestDecrementFail", 150);
        b.gradeDecreament();  // This should throw GradeTooLowException
        std::cerr << "Test Failed: Exception not thrown on grade decrement beyond limit." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Passed: Caught exception for too low grade decrement: " << e.what() << std::endl;
    }
}

/* Unit test for invalid Bureaucrat creation */
void testInvalidBureaucratCreation() {
    try {
        Bureaucrat b("InvalidTest", 151);  // Invalid grade
        std::cerr << "Test Failed: Exception not thrown on invalid Bureaucrat creation." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Passed: Caught exception for invalid Bureaucrat creation: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("InvalidTestTooHigh", 0);  // Invalid grade
        std::cerr << "Test Failed: Exception not thrown on invalid Bureaucrat creation." << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Test Passed: Caught exception for invalid Bureaucrat creation: " << e.what() << std::endl;
    }
}