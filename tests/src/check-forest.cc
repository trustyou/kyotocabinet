/*************************************************************************************************
 * The test cases of the directory tree database
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
#include "kcforesttest.h"
#include "kcforestmgr.h"

// main routine
int main(int argc, char** argv) {
    removeCasket();

    assert ( submitArgsToTestFunction (kcforestmgr, "create -otr -bnum 3 casket")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "inform -st casket")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set -add casket duffy 1231")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set -add casket micky 0101")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set casket fal 1007")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set casket mikio 0211")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set casket natsuki 0810")==0);

    // Spaces at the end are intentional (empty parameter)
    assert ( submitArgsToTestFunction (kcforestmgr, "set casket micky  ")==0);

    assert ( submitArgsToTestFunction (kcforestmgr, "set -app casket duffy kukuku")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "remove casket micky")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "list -pv casket", "", check_out_file)==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set casket ryu 1")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set casket ken 2")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "remove casket duffy")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set casket ryu syo-ryu-ken")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set casket ken tatsumaki-senpu-kyaku")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set -inci casket int 1234")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set -inci casket int 5678")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set -incd casket double 1234.5678")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set -incd casket double 8765.4321")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "get casket mikio")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "get casket ryu")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "import casket resources/numbers.tsv")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "list -des -pv -px casket", "", check_out_file)==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "copy casket casket-para")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "dump casket check.out")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "load -otr casket check.out")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "setbulk casket aa aaa bb bbb cc ccc dd ddd")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "removebulk casket aa bb zz")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "getbulk casket aa bb cc dd")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "inform -st casket")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "create -otr -otl -onr -tc -bnum 1 casket")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "import casket", "resources/numbers.tsv")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set casket mikio kyotocabinet")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set -app casket tako ikaunini")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set -app casket mikio kyototyrant")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "set -app casket mikio kyotodystopia")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "get -px casket mikio", "", check_out_file)==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "list casket", "", check_out_file)==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "clear casket")==0);

    removeCasket();

    assert ( submitArgsToTestFunction (kcforesttest, "order -set -psiz 100 -bnum 5000 -pccap 100k casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "order -get -pccap 100k casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "order -getw -pccap 100k casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "order -rem -pccap 100k casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "order -bnum 5000 -psiz 100 -pccap 100k casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "order -etc -bnum 5000 -psiz 1000 -pccap 100k casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "order -th 4 -bnum 5000 -psiz 1000 -pccap 100k casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "order -th 4 -pccap 100k -rnd -etc -bnum 5000 -psiz 1000 -pccap 100k -rcd casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "order -th 4 -rnd -etc -tran -bnum 500 -psiz 1000 -pccap 100k casket 500")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "order -th 4 -rnd -etc -oat -bnum 500 -psiz 1000 -pccap 100k casket 500")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "order -th 4 -rnd -etc -tc -bnum 5000 -psiz 1000 casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "queue -bnum 5000 -psiz 500 casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "queue -rnd -bnum 5000 -psiz 500 casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "queue -th 4 -it 4 -bnum 5000 -psiz 500 casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "queue -th 4 -it 4 -rnd -bnum 5000 -psiz 500 casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "wicked -bnum 5000 -psiz 1000 -pccap 100k casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "wicked -th 4 -it 4 -bnum 5000 -pccap 100k -rcd casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "wicked -th 4 -it 4 -oat -bnum 500 -pccap 100k casket 500")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "wicked -th 4 -it 4 -tc -bnum 500 casket 500")==0);
    assert ( submitArgsToTestFunction (kcforestmgr, "check -onr casket")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "tran casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "tran -th 2 -it 4 -pccap 100k casket 5000")==0);
    assert ( submitArgsToTestFunction (kcforesttest, "tran -th 2 -it 4 -tc -bnum 5000 -rcd casket 5000")==0);

    return 0;
}
