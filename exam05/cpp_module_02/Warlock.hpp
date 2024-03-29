#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
private:
	std::string _name;
	std::string _title;

	Warlock();
	Warlock(Warlock const &obj);
	Warlock &operator=(Warlock const &obj);

	SpellBook _book;

public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock();

	std::string const &getName() const;
	std::string const &getTitle() const;

	void setTitle(std::string const &title);

	void introduce() const;

	void learnSpell(ASpell *spellPtr);
	void forgetSpell(std::string name);
	void launchSpell(std::string name, ATarget const &target);
};
