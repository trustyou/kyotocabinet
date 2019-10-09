/*************************************************************************************************
 * The test cases of the C language binding
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


#include <cassert>

#include "testutil.h"
#include "kclangctest.h"

// main routine
int main ( int argc, char **argv )
{
	removeCasket();

	assert ( submitArgsToTestFunction (kclangctest, "order casket.kch#bnum=5000#msiz=50000 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "order -etc casket.kch#bnum=5000#msiz=50000#dfunit=2 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "order -rnd -etc casket.kch#bnum=5000#msiz=50000#dfunit=2 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "order -rnd -etc -oat -tran casket.kch#bnum=5000#msiz=50000#dfunit=2#zcomp=arcz 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "index casket.kct#bnum=5000#msiz=50000 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "index -etc casket.kct#bnum=5000#msiz=50000#dfunit=2 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "index -rnd -etc casket.kct#bnum=5000#msiz=50000#dfunit=2 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "index -rnd -etc -oat casket.kct#bnum=5000#msiz=50000#dfunit=2#zcomp=arcz 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "map 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "map -etc -bnum 1000 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "map -etc -rnd -bnum 1000 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "list 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "list -etc 10000") == 0);
	assert ( submitArgsToTestFunction (kclangctest, "list -etc -rnd 10000") == 0);

	return 0;
}
