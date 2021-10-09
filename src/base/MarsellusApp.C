#include "MarsellusApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MarsellusApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

MarsellusApp::MarsellusApp(InputParameters parameters) : MooseApp(parameters)
{
  MarsellusApp::registerAll(_factory, _action_factory, _syntax);
}

MarsellusApp::~MarsellusApp() {}

void
MarsellusApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"MarsellusApp"});
  Registry::registerActionsTo(af, {"MarsellusApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MarsellusApp::registerApps()
{
  registerApp(MarsellusApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MarsellusApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MarsellusApp::registerAll(f, af, s);
}
extern "C" void
MarsellusApp__registerApps()
{
  MarsellusApp::registerApps();
}
