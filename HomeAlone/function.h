#pragma once

//Enumeration of the possible functions in X10 protocol
enum class function {
	All_Units_Off,
	All_Units_On,
	On,
	Off,
	Dim,
	Bright,
	All_Lights_Off,
	Extended_Code,
	Hail_Request,
	Hail_Acknowledge,
	Pre_set_Dim,
	Extended_Code_Analog,
	Status_On,
	Status_Off,
	Status_Request
};