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
#include "kcdirtest.h"
#include "kcdirmgr.h"

// main routine
int main(int argc, char** argv) {
    removeCasket();

    assert ( submitArgsToTestFunction ( kcdirmgr, "create -otr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "inform -st casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set -add casket duffy 1231" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set -add casket micky 0101" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set casket fal 1007" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set casket mikio 0211" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set casket natsuki 0810" ) == 0 );

    // Spaces at the end are intentional (empty parameter)
    assert ( submitArgsToTestFunction ( kcdirmgr, "set casket micky  " ) == 0 );

    assert ( submitArgsToTestFunction ( kcdirmgr, "set -app casket duffy kukuku" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "remove casket micky" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "list -pv casket", "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set casket ryu 1" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set casket ken 2" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "remove casket duffy" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set casket ryu syo-ryu-ken" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set casket ken tatsumaki-senpu-kyaku" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set -inci casket int 1234" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set -inci casket int 5678" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set -incd casket double 1234.5678" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set -incd casket double 8765.4321" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "get casket mikio" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "get casket ryu" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "import casket resources/numbers.tsv" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "list -pv -px casket", "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "copy casket casket-para" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "dump casket " + check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "load -otr casket " + check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "setbulk casket aa aaa bb bbb cc ccc dd ddd" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "removebulk casket aa bb zz" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "getbulk casket aa bb cc dd" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "inform -st casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "create -otr -otl -onr -tc casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "import casket", "resources/numbers.tsv" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set casket mikio kyotocabinet" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set -app casket tako ikaunini" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set -app casket mikio kyototyrant" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "set -app casket mikio kyotodystopia" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "get -px casket mikio", "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "list casket", "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "clear casket" ) == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction ( kcdirtest, "order -set casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "order -get casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "order -getw casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "order -rem casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "order casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "order -etc casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "order -th 4 casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "order -th 4 -rnd -etc casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "order -th 4 -rnd -etc -tran casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "order -th 4 -rnd -etc -oat casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "order -th 4 -rnd -etc -tc casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "queue casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "queue -rnd casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "queue -th 4 -it 4 casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "queue -th 4 -it 4 -rnd casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "wicked casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "wicked -th 4 -it 4 casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "wicked -th 4 -it 4 -oat casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "wicked -th 4 -it 4 -tc casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirmgr, "check -onr casket" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "tran casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "tran -th 2 -it 4 casket 500" ) == 0 );
    assert ( submitArgsToTestFunction ( kcdirtest, "tran -th 2 -it 4 -tc casket 500" ) == 0 );

    return 0;
}
