#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects) {
	_name = name;
	_effects = effects;
}

ASpell::ASpell(ASpell const &obj) {
	*this = obj;
}

ASpell &ASpell::operator=(ASpell const &obj) {
	_name = obj._name;
	_effects = obj._effects;
	return *this;
}

ASpell::~ASpell() {}

std::string const &ASpell::getName() const {
	return _name;
}

std::string const &ASpell::getEffects() const {
	return _effects;
}

void ASpell::launch(ATarget const &target) const {
	target.getHitBySpell(*this);
}
