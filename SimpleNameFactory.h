/*
 * SimpleNameFactory.h
 *
 *  Created on: 2016年8月11日
 *      Author: admin
 */

#ifndef SIMPLENAMEFACTORY_H_
#define SIMPLENAMEFACTORY_H_

#include "NameFactory.h"
#include <iostream>
#include <vector>

using namespace std;

class SimpleNameFactory: public NameFactory {
public:
	SimpleNameFactory();
	SimpleNameFactory(bool generateMixedCaseNames);

	void reset();
	String16 nextName();
	String16 name(int index);
	String16 newName(int index);
	char charAt(int index);
	void testStart(int size);
	void printNameSamples(SimpleNameFactory factory, int count);
	virtual ~SimpleNameFactory();

private:
	const int CHARACTER_COUNT = 26;
	const vector<String16> cachedMixedCaseNames;
	const vector<String16> cachedLowerCaseNames;

	const bool generateMixedCaseNames;
	int index = 0;
};
#endif /* SIMPLENAMEFACTORY_H_ */
