#pragma once


#include"GlobalVariable.h"
#include"View.h"
#include"Model.h"



class Controller
{
	Model model;
	View  view;
public:
	void ControlLogic() ;
};
