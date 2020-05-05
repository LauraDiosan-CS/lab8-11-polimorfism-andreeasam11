#pragma once
#include "Exceptions.h"
#include "Telefon.h"

class TelefonValidator {
public:
	TelefonValidator();
	void validate(Telefon);
	~TelefonValidator();
};