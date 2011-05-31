/* bzflag
 * Copyright (c) 1993-2010 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

// interface header
#include "BZWError.h"

// implementation-specific system headers
#include <string>
#include <iostream>


BZWError::BZWError(const std::string& _location)
  : hadError(false)
  , hadWarning(false)
  , location(_location) {
}


BZWError::~BZWError() {
}


bool BZWError::fatalError(const std::string& msg, int line) {
  // set flag
  hadError = true;

  // sanity
  if (line < 0) {
    return false;
  }
  std::string errorMsg = msg;
  if (errorMsg == "") {
    errorMsg = "unspecified error";
  }

  // report error
  std::cerr << location << ": error";
  if (line != 0) {
    std::cerr << " (line " << line << ")";
  }
  std::cerr << ": " << errorMsg << std::endl << std::flush;
  return true;
}


bool BZWError::warning(const std::string& msg, int line) {
  // set flag
  hadWarning = true;

  // sanity
  if (line < 0) {
    return false;
  }
  std::string warningMsg = msg;
  if (warningMsg == "") {
    warningMsg = "unspecified warning";
  }

  // report warning
  std::cerr << location << ": warning";
  if (line != 0) {
    std::cerr << " (line " << line << ")";
  }
  std::cerr << ": " << warningMsg << std::endl << std::flush;

  return true;
}


// Local Variables: ***
// mode: C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: nil ***
// End: ***
// ex: shiftwidth=2 tabstop=8 expandtab