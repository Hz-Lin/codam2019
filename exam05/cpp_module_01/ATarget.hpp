#pragma once

#include <iostream>

class ASpell;

class ATarget {
private:
	std::string _type;

public:
	ATarget();
	ATarget(std::string const &type);
	ATarget(ATarget const &obj);
	ATarget &operator=(ATarget const &obj);
	virtual ~ATarget();

	std::string const &getType() const;

	virtual ATarget *clone() const = 0;

	void getHitBySpell(ASpell const &spell) const;
};
