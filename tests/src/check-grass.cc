/*************************************************************************************************
 * The test cases of the cache tree database
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
#include "kcgrasstest.h"

// main routine
int main(int argc, char** argv) {
        removeCasket();

        assert ( submitArgsToTestFunction ( kcgrasstest, "order -etc -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcgrasstest, "order -th 4 -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcgrasstest, "order -th 4 -rnd -etc -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcgrasstest, "order -th 4 -rnd -etc -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcgrasstest, "order -th 4 -rnd -etc -tran -tc -bnum 5000 -pccap 10k -rcd 500" ) == 0 );
        assert ( submitArgsToTestFunction ( kcgrasstest, "wicked -bnum 5000 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcgrasstest, "wicked -th 4 -it 4 -tc -bnum 5000 -pccap 10k -rcd 1000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcgrasstest, "tran -bnum 500 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kcgrasstest, "tran -th 2 -it 4 -tc -bnum 5000 -pccap 10k -rcd 5000" ) == 0 );

        return 0;
}
