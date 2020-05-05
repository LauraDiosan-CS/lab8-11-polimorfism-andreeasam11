#pragma once
#include "Exceptions.h"
#include "Drona.h"

class DroneValidator {
	public:
		DroneValidator();
		void validate(Drona);
		~DroneValidator();
};