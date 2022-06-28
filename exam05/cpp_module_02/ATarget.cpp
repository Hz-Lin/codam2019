#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const &type) {
	_type = type;
}

ATarget::ATarget(ATarget const &obj) {
	*this = obj;
}

ATarget &ATarget::operator=(ATarget const &obj) {
	_type = obj._type;
	return *this;
}

ATarget::~ATarget() {}

std::string const &ATarget::getType() const {
	return _type;
}

void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}
