/*************************************************************************************************
 * The test cases of the utility functions
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
#include "kcutiltest.h"
#include "kcutilmgr.h"

// main routine
int main(int argc, char** argv) {
    std::string test_file = __FILE__;

    removeCasket();

    assert ( submitArgsToTestFunction ( kcutilmgr, "version" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "hex " + test_file, "", check_in_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "hex -d " + check_in_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "enc " + test_file, "", check_in_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "enc -d " + check_in_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "enc -hex " + test_file, "", check_in_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "enc -hex -d " + check_in_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "enc -url " + test_file, "", check_in_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "enc -url -d " + check_in_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "enc -quote " + test_file, "", check_in_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "enc -quote -d " + check_in_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "ciph -key hoge " + test_file, "", check_in_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "ciph -key hoge " + check_in_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "comp -gz " + test_file, "", check_in_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "comp -gz -d " + check_in_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "comp -lzo " + test_file, "", check_in_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "comp -lzo -d " + check_in_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "comp -lzma " + test_file, "", check_in_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "comp -lzma -d " + check_in_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "hash " + test_file, "", check_in_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "hash -fnv " + test_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "hash -path " + test_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "regex mikio " + test_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "regex -alt hirarin mikio " + test_file, "", check_out_file ) == 0 );
    assert ( submitArgsToTestFunction ( kcutilmgr, "conf" ) == 0 );

    removeCasket();

    assert ( submitArgsToTestFunction ( kcutiltest, "mutex -th 4 -iv -1 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "cond -th 4 -iv -1 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "para -th 4 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "para -th 4 -iv -1 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "file -th 4 casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "file -th 4 -rnd -msiz 1m casket 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "lhmap -bnum 1000 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "lhmap -rnd -bnum 1000 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "thmap -bnum 1000 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "thmap -rnd -bnum 1000 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "talist 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "talist -rnd 10000" ) == 0 );
    assert ( submitArgsToTestFunction ( kcutiltest, "misc 10000" ) == 0 );

    return 0;
}
