/*
 * SimpleNameFactory.cpp
 *
 *  Created on: 2016年8月11日
 *      Author: admin
 */

#include "SimpleNameFactory.h"

/**
 * Creates a new <code>SimpleNameFactory</code> that generates mixed-case names.
 */
SimpleNameFactory::SimpleNameFactory() {
	this(true);
}
/**
 * Creates a new <code>SimpleNameFactory</code>.
 * @param generateMixedCaseNames a flag to indicate whether the generated
 *                               names will be mixed-case, or lower-case only.
 */
SimpleNameFactory::SimpleNameFactory(bool generateMixedCaseNames) {
	this.generateMixedCaseNames = generateMixedCaseNames;
}

SimpleNameFactory::~SimpleNameFactory() {
	// TODO Auto-generated destructor stub
}

// Implementations for NameFactory.

void SimpleNameFactory::reset() {
	index = 0;
}

String16 SimpleNameFactory::nextName() {
	return name(index++);
}

/**
 * Returns the name at the given index.
 */
String16 SimpleNameFactory::name(int index) {
	// Which cache do we need?
	vector<String16> cachedNames =
			generateMixedCaseNames ?
					cachedMixedCaseNames : cachedLowerCaseNames;

	// Do we have the name in the cache?
	if (index < cachedNames.size()) {
		return (String16) cachedNames.get(index);
	}

	// Create a new name and cache it.
	String16 name = newName(index);
	cachedNames.add(index, name);
	return name;
}

/**
 * Creates and returns the name at the given index.
 */
String16 SimpleNameFactory::newName(int index) {
	// If we're allowed to generate mixed-case names, we can use twice as
	// many characters.
	int totalCharacterCount = generateMixedCaseNames ? 2 * CHARACTER_COUNT : CHARACTER_COUNT;

	int baseIndex = index / totalCharacterCount;
	int offset = index % totalCharacterCount;

	char newChar = charAt(offset);
	String16 str1 = String16(newChar);
	String16 str2 = String16(name(baseIndex - 1));

	String16 newName = baseIndex == 0
			? str1
			: str2 + str1;

	return newName;
}

/**
 * Returns the character with the given index, between 0 and the number of
 * acceptable characters.
 */
char SimpleNameFactory::charAt(int index) {
	return (char) ((index < CHARACTER_COUNT ? 'a' - 0 : 'A' - CHARACTER_COUNT)
			+ index);
}

void SimpleNameFactory::testStart(int size) {
	printNameSamples(new SimpleNameFactory(true), size);
}

void SimpleNameFactory::printNameSamples(SimpleNameFactory factory, int count) {
	for (int counter = 0; counter < count; counter++) {
		cout << "  [" + factory.nextName() + "]" << endl;
	}
}
