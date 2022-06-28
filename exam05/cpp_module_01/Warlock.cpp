#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) {
	_name = name;
	_title = title;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName() const {
	return _name;
}

std::string const &Warlock::getTitle() const {
	return _title;
}

void	Warlock::setTitle(std::string const &title) {
	_title = title;
}

void	Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spellPtr){
	if (spellPtr) {
		_arr.insert(std::pair<std::string, ASpell *>(spellPtr->getName(), spellPtr->clone()));
	}
}

void Warlock::forgetSpell(std::string name) {
	std::map<std::string, ASpell *>::iterator it = _arr.find(name);
	if (it != _arr.end()) {
		delete it->second;
	}
	_arr.erase(name);
}

void Warlock::launchSpell(std::string name, ATarget const &target) {
	ASpell *spell = _arr[name];
	if (spell) {
		spell->launch(target);
	}
}
