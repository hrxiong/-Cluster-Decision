#pragma once


#include"View.h"
#include"Database.h"



class Controller
{
	Database model;
	View  view;
public:
	void ControlLogic() ;
};
