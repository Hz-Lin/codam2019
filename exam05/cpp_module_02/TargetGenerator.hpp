#pragma once

#include <iostream>
#include "ATarget.hpp"
#include <map>

class TargetGenerator {
private:
	std::map<std::string, ATarget *> _arrTarget;

	TargetGenerator(TargetGenerator const &obj);
	TargetGenerator &operator=(TargetGenerator const &obj);

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget *targetPtr);
	void forgetTargetType(std::string name);
	ATarget* createTarget(std::string const &name);
};
