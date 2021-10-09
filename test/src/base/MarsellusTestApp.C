//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MarsellusTestApp.h"
#include "MarsellusApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
MarsellusTestApp::validParams()
{
  InputParameters params = MarsellusApp::validParams();
  return params;
}

MarsellusTestApp::MarsellusTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MarsellusTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MarsellusTestApp::~MarsellusTestApp() {}

void
MarsellusTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MarsellusApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MarsellusTestApp"});
    Registry::registerActionsTo(af, {"MarsellusTestApp"});
  }
}

void
MarsellusTestApp::registerApps()
{
  registerApp(MarsellusApp);
  registerApp(MarsellusTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MarsellusTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MarsellusTestApp::registerAll(f, af, s);
}
extern "C" void
MarsellusTestApp__registerApps()
{
  MarsellusTestApp::registerApps();
}
