/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/12 14:19:24 by spyun         #+#    #+#                 */
/*   Updated: 2025/06/12 15:41:46 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Tester
{
private:
    int testCount;
    int passedTests;

    void createTestFile(const std::string& filename, const std::string& content);
    bool fileExists(const std::string& filename);
    std::string readFile(const std::string& filename);
    bool runCommand(const std::string& command);
    void printTestResult(const std::string& testName, bool passed);

public:
    Tester();
    ~Tester();

    void runBasicTests();
    void runErrorTests();
    void runEdgeCaseTests();
    void printSummary();
    void cleanup();
};

Tester::Tester() : testCount(0), passedTests(0)
{
    std::cout << YELLOW << "=== ex04 Executable Test Program ===" << RESET << std::endl;
    std::cout << std::endl;
}

Tester::~Tester()
{
}

void Tester::createTestFile(const std::string& filename, const std::string& content)
{
    std::ofstream file(filename.c_str());
    if (file.is_open())
    {
        file << content;
        file.close();
    }
}

bool Tester::fileExists(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    return file.good();
}

std::string Tester::readFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string content;
    std::string line;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            content += line + "\n";
        }
        file.close();
    }
    return content;
}

bool Tester::runCommand(const std::string& command)
{
    return system(command.c_str()) == 0;
}

void Tester::printTestResult(const std::string& testName, bool passed)
{
    testCount++;
    if (passed)
    {
        passedTests++;
        std::cout << GREEN << "✓ " << RESET << testName << std::endl;
    }
    else
    {
        std::cout << RED << "✗ " << RESET << testName << std::endl;
    }
}

void Tester::runBasicTests()
{
    std::cout << YELLOW << "[Basic Functionality Tests]" << RESET << std::endl;

    // Test 1: Basic string replacement
    createTestFile("test1.txt", "Hello world\nHello again\nGoodbye world");
    bool test1 = runCommand("./ex04 test1.txt Hello Hi > /dev/null 2>&1");
    test1 = test1 && fileExists("test1.txt.replace");
    if (test1)
    {
        std::string result = readFile("test1.txt.replace");
        test1 = (result.find("Hi world") != std::string::npos &&
                 result.find("Hi again") != std::string::npos);
    }
    printTestResult("Basic string replacement", test1);

    // Test 2: Multiple occurrences in one line
    createTestFile("test2.txt", "aaa bbb aaa ccc aaa");
    bool test2 = runCommand("./ex04 test2.txt aaa xxx > /dev/null 2>&1");
    test2 = test2 && fileExists("test2.txt.replace");
    if (test2)
    {
        std::string result = readFile("test2.txt.replace");
        test2 = (result == "xxx bbb xxx ccc xxx\n");
    }
    printTestResult("Multiple occurrences in one line", test2);

    // Test 3: No matches
    createTestFile("test3.txt", "This is a test\nNothing here");
    bool test3 = runCommand("./ex04 test3.txt xyz abc > /dev/null 2>&1");
    test3 = test3 && fileExists("test3.txt.replace");
    if (test3)
    {
        std::string original = readFile("test3.txt");
        std::string result = readFile("test3.txt.replace");
        test3 = (original == result);
    }
    printTestResult("No matches (file unchanged)", test3);

    // Test 4: Special characters
    createTestFile("test4.txt", "I love C++!\nC++ is great");
    bool test4 = runCommand("./ex04 test4.txt \"C++\" Python > /dev/null 2>&1");
    test4 = test4 && fileExists("test4.txt.replace");
    if (test4)
    {
        std::string result = readFile("test4.txt.replace");
        test4 = (result.find("Python") != std::string::npos &&
                 result.find("C++") == std::string::npos);
    }
    printTestResult("Special characters (C++)", test4);

    std::cout << std::endl;
}

void Tester::runErrorTests()
{
    std::cout << YELLOW << "[Error Handling Tests]" << RESET << std::endl;

    // Test 5: Wrong number of arguments
    bool test5 = !runCommand("./ex04 > /dev/null 2>&1");
    printTestResult("Wrong number of arguments", test5);

    // Test 6: Non-existent file
    bool test6 = !runCommand("./ex04 nonexistent.txt hello hi > /dev/null 2>&1");
    printTestResult("Non-existent input file", test6);

    // Test 7: Empty search string
    createTestFile("test7.txt", "Some content here");
    bool test7 = !runCommand("./ex04 test7.txt \"\" replacement > /dev/null 2>&1");
    printTestResult("Empty search string", test7);

    std::cout << std::endl;
}

void Tester::runEdgeCaseTests()
{
    std::cout << YELLOW << "[Edge Case Tests]" << RESET << std::endl;

    // Test 8: Empty file
    createTestFile("test8.txt", "");
    bool test8 = runCommand("./ex04 test8.txt hello hi > /dev/null 2>&1");
    test8 = test8 && fileExists("test8.txt.replace");
    printTestResult("Empty file handling", test8);

    // Test 9: File with only newlines
    createTestFile("test9.txt", "\n\n\n");
    bool test9 = runCommand("./ex04 test9.txt hello hi > /dev/null 2>&1");
    test9 = test9 && fileExists("test9.txt.replace");
    printTestResult("File with only newlines", test9);

    // Test 10: Overlapping patterns
    createTestFile("test10.txt", "aaaa\naaaaa");
    bool test10 = runCommand("./ex04 test10.txt aa b > /dev/null 2>&1");
    test10 = test10 && fileExists("test10.txt.replace");
    if (test10)
    {
        std::string result = readFile("test10.txt.replace");
        test10 = (result.find("bb") != std::string::npos);
    }
    printTestResult("Overlapping patterns", test10);

    std::cout << std::endl;
}

void Tester::printSummary()
{
    std::cout << YELLOW << "=== Test Summary ===" << RESET << std::endl;
    std::cout << "Passed: " << GREEN << passedTests << RESET << "/" << testCount << std::endl;

    if (passedTests == testCount)
    {
        std::cout << GREEN << "All tests passed! ✓" << RESET << std::endl;
    }
    else
    {
        std::cout << RED << "Some tests failed. Check your implementation." << RESET << std::endl;
    }
    std::cout << std::endl;
}

void Tester::cleanup()
{
    std::cout << "Cleaning up test files..." << std::endl;
    system("rm -f test*.txt test*.txt.replace > /dev/null 2>&1");
    std::cout << "Cleanup complete." << std::endl;
}

int main()
{
    if (system("test -f ./ex04") != 0)
    {
        std::cout << RED << "Error: ./ex04 executable not found!" << RESET << std::endl;
        std::cout << "Please compile your program first: make" << std::endl;
        return 1;
    }

    Tester tester;

    tester.runBasicTests();
    tester.runErrorTests();
    tester.runEdgeCaseTests();
    tester.printSummary();
    tester.cleanup();

    return 0;
}
