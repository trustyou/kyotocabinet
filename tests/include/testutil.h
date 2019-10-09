/*************************************************************************************************
 * Test utilites
 *                                                               Copyright (C) 2009-2012 FAL Labs
 *                                                               Copyright (C) 2013-2017 Cloudflare Inc.
 *                                                               Copyright (C) 2018-2019 TrustYou GmbH
 * This file is part of Kyoto Cabinet.
 * This program is free software: you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation, either version
 * 3 of the License, or any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *************************************************************************************************/

#ifndef _TESTUTIL_H                        // duplication check
#define _TESTUTIL_H

#include <string>

static const std::string check_in_file = "check.in";
static const std::string check_out_file = "check.out";

/**
 * Remove all files in the current working directory, whose names begin with "casket"
 */
void removeCasket();

/**
 * Call a test function, which accepts the (argc, argv) arguments with
 * command line parameters provided in a single string
 * @param testFunc the test function
 * @param params the command line parameters
 * @param inputFileName the name of the file which will substitute stdin (use stdin if "")
 * @param outputFileName the name of the file which will substitute stdout (use stdout if "")
 * @return the exit code of the test function
 */
int submitArgsToTestFunction ( int ( *testFunc ) ( int, char ** ), std::string params, std::string inputFileName = "", std::string outputFileName = "" );

#endif
