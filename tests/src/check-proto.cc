/*************************************************************************************************
 * The test cases of the prototype database
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
#include "kcprototest.h"

// main routine
int main(int argc, char** argv) {
	removeCasket();

        assert ( submitArgsToTestFunction ( kcprototest, "order -etc 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "order -th 4 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "order -th 4 -rnd -etc 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "order -th 4 -rnd -etc -tran 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "wicked 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "wicked -th 4 -it 4 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "tran 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "tran -th 2 -it 4 10000" ) == 0 );

        removeCasket();

        assert ( submitArgsToTestFunction ( kcprototest, "order -tree -etc 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "order -tree -th 4 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "order -tree -th 4 -rnd -etc 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "order -tree -th 4 -rnd -etc -tran 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "wicked -tree 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "wicked -tree -th 4 -it 4 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "tran -tree 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcprototest, "tran -tree -th 2 -it 4 10000" ) == 0 );

        return 0;
}
