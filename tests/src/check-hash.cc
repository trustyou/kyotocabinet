/*************************************************************************************************
 * The test cases of the file hash database
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
#include "kchashtest.h"
#include "kchashmgr.h"

// main routine
int main(int argc, char** argv) {
    removeCasket();

    assert ( submitArgsToTestFunction ( kchashmgr, "create -otr -apow 1 -fpow 2 -bnum 3 casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "inform -st casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set -add casket duffy 1231" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set -add casket micky 0101" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set casket fal 1007" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set casket mikio 0211" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set casket natsuki 0810" ) == 0 );

    // Spaces at the end are intentional (empty parameter)
    assert ( submitArgsToTestFunction ( kchashmgr, "set casket micky  " ) == 0 );

    assert ( submitArgsToTestFunction ( kchashmgr, "set -app casket duffy kukuku" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "remove casket micky" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "list -pv casket", "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set casket ryu 1" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set casket ken 2" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "remove casket duffy" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set casket ryu syo-ryu-ken" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set casket ken tatsumaki-senpu-kyaku" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set -inci casket int 1234" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set -inci casket int 5678" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set -incd casket double 1234.5678" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set -incd casket double 8765.4321" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "get casket mikio" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "get casket ryu" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "import casket resources/numbers.tsv" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "list -pv -px casket", "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "copy casket casket-para" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "dump casket " + check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "load -otr casket " + check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "defrag -onl casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "setbulk casket aa aaa bb bbb cc ccc dd ddd" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "removebulk casket aa bb zz" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "getbulk casket aa bb cc dd" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "inform -st casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "create -otr -otl -onr -apow 1 -fpow 3 -ts -tl -tc -bnum 1 casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "import casket", "resources/numbers.tsv" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set casket mikio kyotocabinet" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set -app casket tako ikaunini" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set -app casket mikio kyototyrant" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "set -app casket mikio kyotodystopia" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "get -px casket mikio", "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "list casket", "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "clear casket" ) == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction ( kchashtest, "order -set -bnum 5000 -msiz 50000 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "order -get -msiz 50000 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "order -getw -msiz 5000 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "order -rem -msiz 50000 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "order -bnum 5000 -msiz 50000 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "order -etc -bnum 5000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "order -th 4 -bnum 5000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "order -th 4 -rnd -etc -bnum 5000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "order -th 4 -rnd -etc -tran -bnum 5000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "order -th 4 -rnd -etc -oat -bnum 5000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "order -th 4 -rnd -etc -apow 2 -fpow 3 -ts -tl -tc -bnum 5000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "queue -bnum 5000 -msiz 50000 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "queue -rnd -bnum 5000 -msiz 50000 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "queue -th 4 -it 4 -bnum 5000 -msiz 50000 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "queue -th 4 -it 4 -rnd -bnum 5000 -msiz 50000 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "wicked -bnum 5000 -msiz 50000 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "wicked -th 4 -it 4 -bnum 5000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "wicked -th 4 -it 4 -oat -bnum 5000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "wicked -th 4 -it 4 -apow 2 -fpow 3 -ts -tl -tc -bnum 10000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "tran casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "tran -th 2 -it 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kchashtest, "tran -th 2 -it 4 -apow 2 -fpow 3 -ts -tl -tc -bnum 10000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );

    return 0;
}
