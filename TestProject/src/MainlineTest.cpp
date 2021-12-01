#include <ui/text/TestRunner.h>
#include <TestResult.h>
#include <TestResultCollector.h>
#include <BriefTestProgressListener.h>
#include <TestRunner.h>
#include <CompilerOutputter.h>

#include "LotteryTests.h"

// ----------------------------------------------------------------------------
int main()
{
	// Creates the test controller to manage tests.
	CppUnit::TestResult controller;

	// Creates and adds listeners to handle test results.
	CppUnit::TestResultCollector result;
	controller.addListener(&result);

	CppUnit::BriefTestProgressListener progressListener;
	controller.addListener(&progressListener);

	// Creates the test runner and assigns the test fixture.
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(LotteryTests::suite());

	// Runs the tests.
	std::cout << "\nRunning Lottery Unit Tests...\n\n";
	runner.run(controller);

	CppUnit::CompilerOutputter outputter(&result, std::cerr);
	outputter.write();

	std::cout << "\nPress enter to exit...";
	std::cin.get();

	return 0;
}

// ----------------------------------------------------------------------------