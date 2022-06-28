#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	std::map<std::string, ATarget *>::iterator itBegin = _arrTarget.begin();
	std::map<std::string, ATarget *>::iterator itEnd = _arrTarget.end();
	while (itBegin != itEnd) {
		delete itBegin->second;
		++itBegin;
	}
	_arrTarget.clear();
}

void TargetGenerator::learnTargetType(ATarget *targetPtr) {
	if (targetPtr) {
		_arrTarget.insert(std::pair<std::string, ATarget *>(targetPtr->getType(), targetPtr->clone()));
	}
}

void TargetGenerator::forgetTargetType(std::string name) {
	std::map<std::string, ATarget *>::iterator it = _arrTarget.find(name);
	if (it != _arrTarget.end()) {
		delete it->second;
	}
	_arrTarget.erase(name);
}

ATarget* TargetGenerator::createTarget(std::string const &name) {
	std::map<std::string, ATarget *>::iterator it = _arrTarget.find(name);
	if (it != _arrTarget.end()) {
		return _arrTarget[name];
	}
	return NULL;
}
