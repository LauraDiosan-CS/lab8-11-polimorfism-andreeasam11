#include "TelefonValidator.h"
#include<iostream>

TelefonValidator::TelefonValidator() {
}

void TelefonValidator::validate(Telefon telefon) {
	if (telefon.getUnitatiProduse() <= 100)
	{
		DomainException exc("unitatiProdus trebuie >100");
		throw exc;
	}
	if (telefon.getListaOperatoriGSM().size() == 0)
	{
		DomainException exc("Lista operatori gsm trebuie sa aiba cel putin un operator");
		throw exc;
	}
}

TelefonValidator::~TelefonValidator() {
}