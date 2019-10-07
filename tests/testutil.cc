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

#include <iostream>
#include <fstream>
#include <sstream>

#include <stdio.h>
#include <dirent.h>

#include <string>
#include <vector>

#include "testutil.h"

/** The string "casket" */
const std::string casket = "casket";

/** The length of the string "casket" */
const int casketLength = casket.length();

/**
 * Remove all files in the current working directory, whose names begin with "casket"
 */
void removeCasket() {
	struct dirent *DirEntry;
	DIR* Dir = opendir(".");

	while (DirEntry = readdir(Dir)) { // @suppress("Assignment in condition")
		std::string filename = DirEntry->d_name;
		if (filename.compare(0, casketLength, casket) == 0) {
			remove(filename.c_str());
		}
	}
}

/**
 * Call a test function, which accepts the (argc, argv) arguments with
 * command line parameters provided in a single string
 * @param testFunc the test function
 * @param params the command line parameters
 * @return the exit code of the test function
 */
int submitArgsToTestFunction_private(int (*testFunc)(int, char**),
		std::string params) {

	std::vector<std::string> paramVector;
	paramVector.push_back("");

	std::istringstream iss(params);
	std::string s;
	while (getline(iss, s, ' ')) {
		paramVector.push_back(s);
	}

	int argc = paramVector.size();

	std::vector<char*> paramCharVector(paramVector.size());
	for (int i = 0; i < argc; i++) {
		paramCharVector[i] = (char *) paramVector[i].data();
	}

	return testFunc(argc, paramCharVector.data());
}

/**
 * Call a test function, which accepts the (argc, argv) arguments with
 * command line parameters provided in a single string. The standard output
 * of the test function will be redirected to a file.
 * @param testFunc the test function
 * @param params the command line parameters
 * @param inputFileName the input file name
 * @param outputFileName the output file name
 * @return the exit code of the test function
 */
int submitArgsToTestFunction(int (*testFunc)(int, char**), std::string params,
		std::string inputFileName, std::string outputFileName) {

	std::streambuf *coutbuf = std::cout.rdbuf();
	std::streambuf *cinbuf = std::cin.rdbuf();

	std::ostream * out =
			outputFileName.empty() ?
					&std::cout : new std::ofstream(outputFileName.c_str());
	std::cout.rdbuf(out->rdbuf());

	std::istream * in =
			inputFileName.empty() ?
					&std::cin : new std::ifstream(inputFileName.c_str());
	std::cin.rdbuf(in->rdbuf());

	int result = submitArgsToTestFunction_private(testFunc, params);
	
	if (!(inputFileName.empty())) {
		((std::ifstream*) in)->close();
	}

	if (!(outputFileName.empty())) {
		((std::ofstream*) out)->close();
	}

	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);

	return result;
}
