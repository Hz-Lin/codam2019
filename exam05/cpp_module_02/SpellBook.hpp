#pragma once

#include <map>
#include "ASpell.hpp"

class SpellBook {
private:
	std::map<std::string, ASpell *> _arrSpell;

	SpellBook(SpellBook const &obj);
	SpellBook &operator=(SpellBook const &obj);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell *spellPtr);
	void forgetSpell(std::string const &name);
	ASpell* createSpell(std::string const &name);
};
