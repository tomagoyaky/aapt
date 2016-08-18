/*
 * NameFactory.h
 *
 *  Created on: 2016年8月10日
 *      Author: admin
 */

#ifndef NAMEFACTORY_H_
#define NAMEFACTORY_H_

#include <utils/String16.h>

using namespace android;

class NameFactory{
	void reset();
	String16 nextName();
};

#endif /* NAMEFACTORY_H_ */
