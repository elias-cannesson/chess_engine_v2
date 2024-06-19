#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;

/* Test class to run individual unit tests */
class Test {
public:
    Test(const string& name, function<void()> testFunc)
        : name(name), testFunc(testFunc) {}
        void run() {
            try {
                testFunc();
                cout << "[PASS] " << name << endl; } 
            catch (const exception& e) {
                cout << "[FAIL] " << name << " - " << e.what() << endl; } }
private:
    string name;
    function<void()> testFunc;
};

/* Runs each test in a given array of tests */
class TestRunner {
public:
    void addTest(const string& name, function<void()> testFunc) {
        tests.emplace_back(name, testFunc); }
    void runAllTests() {
        for (auto& test: tests) {
            test.run(); } }
private:
    vector<Test> tests;
};

/* Class to register and run tests */
class TestRegistry {
public:
    static TestRegistry& instance() {
        static TestRegistry instance;
        return instance; }

    bool addTest(const string& name, function<void()> testFunc) {
        test_runner.addTest(name, testFunc);
        return true; }

    void runAll() {
        test_runner.runAllTests(); }

private:
    TestRunner test_runner;
};

#endif // TEST_FRAMEWORK_H