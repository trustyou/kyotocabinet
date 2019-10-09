/*************************************************************************************************
 * The test cases of the stash database
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
#include "kcstashtest.h"

// main routine
int main(int argc, char** argv) {
        removeCasket();

        assert ( submitArgsToTestFunction ( kcstashtest, "order -etc -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcstashtest, "order -th 4 -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcstashtest, "order -th 4 -rnd -etc -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcstashtest, "order -th 4 -rnd -etc -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcstashtest, "order -th 4 -rnd -etc -tran -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcstashtest, "wicked -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcstashtest, "wicked -th 4 -it 4 -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcstashtest, "tran -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcstashtest, "tran -th 2 -it 4 -bnum 5000 10000" ) == 0 );

        return 0;
}
