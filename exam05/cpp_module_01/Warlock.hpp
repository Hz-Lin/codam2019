#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
private:
	std::string _name;
	std::string _title;

	Warlock();
	Warlock(Warlock const &obj);
	Warlock &operator=(Warlock const &obj);

	std::map<std::string, ASpell *> _arr;

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
