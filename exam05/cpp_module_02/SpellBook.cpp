#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	std::map<std::string, ASpell *>::iterator itBegin = _arrSpell.begin();
	std::map<std::string, ASpell *>::iterator itEnd = _arrSpell.end();
	while (itBegin != itEnd) {
		delete itBegin->second;
		++itBegin;
	}
	_arrSpell.clear();
}

void SpellBook::learnSpell(ASpell *spellPtr) {
	if (spellPtr) {
		_arrSpell.insert(std::pair<std::string, ASpell *>(spellPtr->getName(), spellPtr->clone()));
	}
}

void SpellBook::forgetSpell(std::string const &name) {
	std::map<std::string, ASpell *>::iterator it = _arrSpell.find(name);
	if (it != _arrSpell.end()) {
		delete it->second;
	}
	_arrSpell.erase(name);
}

ASpell* SpellBook::createSpell(std::string const &name) {
	std::map<std::string, ASpell *>::iterator it = _arrSpell.find(name);
	if (it != _arrSpell.end()) {
		return _arrSpell[name];
	}
	return NULL;
}
