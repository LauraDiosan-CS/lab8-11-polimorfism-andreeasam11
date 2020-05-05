#include "DronaValidator.h"
#include<iostream>

DroneValidator::DroneValidator() {
}

void DroneValidator::validate(Drona drona) {
	if (drona.getUnitatiProduse() <= 100)
	{
		DomainException exc("unitatiProdus trebuie >100");
		throw exc;
	}
}

DroneValidator::~DroneValidator() {
}