/*************************************************************************************************
 * The test cases of the polymorphic database
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
#include "kcpolytest.h"
#include "kcpolymgr.h"

// main routine
int main(int argc, char** argv) {
    removeCasket();

    assert ( submitArgsToTestFunction (kcpolymgr, "create -otr casket.kch#apow=1#fpow=2#bnum=3") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "inform -st casket.kch") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set -add casket.kch duffy 1231") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set -add casket.kch micky 0101") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set casket.kch fal 1007") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set casket.kch mikio 0211") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set casket.kch natsuki 0810") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set casket.kch micky  ") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set -app casket.kch duffy kukuku") == 0 );

    // Spaces at the end are intentional (empty parameter)
    assert ( submitArgsToTestFunction (kcpolymgr, "remove casket.kch micky") == 0 );

    assert ( submitArgsToTestFunction (kcpolymgr, "list -pv casket.kch", "", check_out_file) == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "copy casket.kch casket-para") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "dump casket.kch " + check_out_file) == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "load -otr casket.kch " + check_out_file) == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set casket.kch ryu 1") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set casket.kch ken 2") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "remove casket.kch duffy") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set casket.kch ryu syo-ryu-ken") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set casket.kch ken tatsumaki-senpu-kyaku") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set -inci casket.kch int 1234") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set -inci casket.kch int 5678") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set -incd casket.kch double 1234.5678") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set -incd casket.kch double 8765.4321") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "get casket.kch mikio") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "get casket.kch ryu") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "import casket.kch resources/numbers.tsv") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "list -pv -px casket.kch#mode=r", "", check_out_file) == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "setbulk casket.kch aa aaa bb bbb cc ccc dd ddd") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "removebulk casket.kch aa bb zz") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "getbulk casket.kch aa bb cc dd") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kch") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "inform -st casket.kch") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "create -otr -otl -onr casket.kct#apow=1#fpow=3#opts=slc#bnum=1") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "import casket.kct", "resources/numbers.tsv") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set casket.kct mikio kyotocabinet") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set -app casket.kct tako ikaunini") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set -app casket.kct mikio kyototyrant") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "set -app casket.kct mikio kyotodystopia") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "get -px casket.kct mikio", "", check_out_file) == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "list casket.kct", "", check_out_file) == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "clear casket.kct") == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction (kcpolytest, "order -set casket.kct#bnum=5000#msiz=50000 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -get casket.kct#msiz=50000 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -getw casket.kct#msiz=5000 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -rem casket.kct#msiz=50000 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order casket.kct#bnum=5000#msiz=50000 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -etc casket.kct#bnum=5000#msiz=50000#dfunit=4 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -th 4 casket.kct#bnum=5000#msiz=50000#dfunit=4 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -th 4 -rnd -etc casket.kct#bnum=5000#msiz=0#dfunit=1 1000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -th 4 -rnd -etc -tran casket.kct#bnum=5000#msiz=0#dfunit=2 1000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -th 4 -rnd -etc -oat casket.kct#bnum=5000#msiz=0#dfunit=3 1000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -th 4 -rnd -etc casket.kct#apow=2#fpow=3#opts=slc#bnum=5000#msiz=0#dfunit=4 1000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "queue casket.kct#bnum=5000#msiz=0 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "queue -rnd casket.kct#bnum=5000#msiz=0 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "queue -th 4 -it 4 casket.kct#bnum=5000#msiz=0 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "queue -th 4 -it 4 -rnd casket.kct#bnum=5000#msiz=0 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "wicked casket.kct#bnum=5000#msiz=0 1000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "wicked -th 4 -it 4 casket.kct#bnum=5000#msiz=0#dfunit=1 1000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "wicked -th 4 -it 4 -oat casket.kct#bnum=5000#msiz=0#dfunit=1 1000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "wicked -th 4 -it 4 casket.kct#apow=2#fpow=3#opts=slc#bnum=10000#msiz=0#dfunit=1 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "check -onr casket.kct") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "tran casket.kct 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "tran -th 2 -it 4 casket.kct 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "tran -th 2 -it 4 casket.kct#apow=2#fpow=3#opts=slc#bnum=10000#msiz=0#dfunit=1 1000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "mapred -dbnum 2 -clim 10k casket.kct 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "mapred -tmp . -dbnum 2 -clim 10k -xnl -xnc casket.kct 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "mapred -tmp . -dbnum 2 -clim 10k -xpm -xpr -xpf -xnc casket.kct 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "mapred -rnd -dbnum 2 -clim 10k casket.kct 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "index -set casket.kct#idxclim=32k 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "index -get casket.kct 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "index -rem casket.kct 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "index -etc casket.kct#idxclim=32k 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "index -th 4 -rnd -set casket.kct#idxclim=32k#idxdbnum=4 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "index -th 4 -rnd -get casket.kct 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "index -th 4 -rnd -rem casket.kct 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "index -th 4 -rnd -etc casket.kct#idxclim=32k#idxdbnum=4 10000") == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction (kcpolytest, "order -rnd casket.kcx 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -th 4 -rnd casket.kcx 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "wicked casket.kcx 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "wicked -th 4 casket.kcx 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "list -pv casket.kcx", "", check_out_file) == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "list -max 1000 -pv casket.kcx", "", check_out_file) == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "mapred casket.kcx 10000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "mapred -xpm -xpr -xpf casket.kcx 10000") == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction (kcpolytest, "order -rnd casket.kch#opts=s#bnum=256 1000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -rnd casket.kct#opts=l#psiz=256 1000") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -rnd casket.kcd#opts=c#bnum=256 500") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -rnd casket.kcf#opts=c#psiz=256 500") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "order -rnd casket.kcx 500") == 0 );
    assert ( submitArgsToTestFunction (kcpolymgr, "merge -add casket#type=kct casket.kch casket.kct casket.kcd casket.kcf casket.kcx") == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction (kcpolytest, "misc casket#type=-") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "misc casket#type=+") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "misc casket#type=:") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "misc casket#type=*#zcomp=def") == 0 );
    assert ( submitArgsToTestFunction (kcpolytest, "misc casket#type=%#zcomp=gz") == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction (kcpolytest, "misc casket#type=kch#log=-#logkinds=debug#mtrg=-#zcomp=lzocrc") == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction (kcpolytest, "misc casket#type=kct#log=-#logkinds=debug#mtrg=-#zcomp=lzmacrc") == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction (kcpolytest, "misc casket#type=kcd#zcomp=arc#zkey=mikio") == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction (kcpolytest, "misc casket#type=kcf#zcomp=arc#zkey=mikio") == 0 );

    return 0;
}
