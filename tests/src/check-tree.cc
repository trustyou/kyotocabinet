/*************************************************************************************************
 * The test cases of the file tree database
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
#include "kctreetest.h"
#include "kctreemgr.h"

// main routine
int main(int argc, char** argv) {
        removeCasket();

        assert ( submitArgsToTestFunction ( kctreemgr, "create -otr -apow 1 -fpow 2 -bnum 3 casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "inform -st casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set -add casket duffy 1231" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set -add casket micky 0101" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set casket fal 1007" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set casket mikio 0211" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set casket natsuki 0810" ) == 0 );

        // Spaces at the end are intentional (empty parameter)
        assert ( submitArgsToTestFunction ( kctreemgr, "set casket micky  " ) == 0 );

        assert ( submitArgsToTestFunction ( kctreemgr, "set -app casket duffy kukuku" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "remove casket micky" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "list -pv casket", "", check_out_file ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set casket ryu 1" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set casket ken 2" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "remove casket duffy" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set casket ryu syo-ryu-ken" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set casket ken tatsumaki-senpu-kyaku" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set -inci casket int 1234" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set -inci casket int 5678" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set -incd casket double 1234.5678" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set -incd casket double 8765.4321" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "get casket mikio" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "get casket ryu" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "import casket resources/numbers.tsv" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "list -des -pv -px casket", "", check_out_file ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "copy casket casket-para" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "dump casket " + check_out_file ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "load -otr casket " + check_out_file ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "defrag -onl casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "setbulk casket aa aaa bb bbb cc ccc dd ddd" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "removebulk casket aa bb zz" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "getbulk casket aa bb cc dd" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "inform -st casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "create -otr -otl -onr -apow 1 -fpow 3 -ts -tl -tc -bnum 1 casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "import casket", "resources/numbers.tsv" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set casket mikio kyotocabinet" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set -app casket tako ikaunini" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set -app casket mikio kyototyrant" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "set -app casket mikio kyotodystopia" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "get -px casket mikio", "", check_out_file ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "list casket", "", check_out_file ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "clear casket" ) == 0 );

        removeCasket();

        assert ( submitArgsToTestFunction ( kctreetest, "order -set -psiz 100 -bnum 5000 -msiz 50000 -pccap 100k casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "order -get -msiz 50000 -pccap 100k casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "order -getw -msiz 5000 -pccap 100k casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "order -rem -msiz 50000 -pccap 100k casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "order -bnum 5000 -psiz 100 -msiz 50000 -pccap 100k casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "order -etc -bnum 5000 -psiz 1000 -msiz 50000 -dfunit 4 -pccap 100k casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "order -th 4 -bnum 5000 -psiz 1000 -msiz 50000 -dfunit 4 -pccap 100k casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "order -th 4 -pccap 100k -rnd -etc -bnum 5000 -psiz 1000 -msiz 50000 -dfunit 4 -pccap 100k -rcd casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "order -th 4 -rnd -etc -tran -bnum 5000 -psiz 1000 -msiz 50000 -dfunit 4 -pccap 100k casket 1000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "order -th 4 -rnd -etc -oat -bnum 5000 -psiz 1000 -msiz 50000 -dfunit 4 -pccap 100k casket 1000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "order -th 4 -rnd -etc -apow 2 -fpow 3 -ts -tl -tc -bnum 5000 -psiz 1000 -msiz 50000 -dfunit 4 casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "queue -bnum 5000 -psiz 500 -msiz 50000 casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "queue -rnd -bnum 5000 -psiz 500 -msiz 50000 casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "queue -th 4 -it 4 -bnum 5000 -psiz 500 -msiz 50000 casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "queue -th 4 -it 4 -rnd -bnum 5000 -psiz 500 -msiz 50000 casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "wicked -bnum 5000 -psiz 1000 -msiz 50000 -pccap 100k casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "wicked -th 4 -it 4 -bnum 5000 -msiz 50000 -dfunit 4 -pccap 100k -rcd casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "wicked -th 4 -it 4 -oat -bnum 5000 -msiz 50000 -dfunit 4 -pccap 100k casket 1000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "wicked -th 4 -it 4 -apow 2 -fpow 3 -ts -tl -tc -bnum 10000 -msiz 50000 -dfunit 4 casket 1000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreemgr, "check -onr casket" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "tran casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "tran -th 2 -it 4 -pccap 100k casket 10000" ) == 0 );
        assert ( submitArgsToTestFunction ( kctreetest, "tran -th 2 -it 4 -apow 2 -fpow 3 -ts -tl -tc -bnum 10000 -msiz 50000 -dfunit 4 -rcd casket 10000" ) == 0 );

        return 0;
}
