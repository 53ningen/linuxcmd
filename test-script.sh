#!/bin/sh

n_tests=0
failed=0

test_finished() {
    rm -rf tc.*
    echo
    if [ "$failed" = "0" ]
    then
        echo "PASS ($n_tests tests) -- `hostname` / `uname -srm`"
        exit 0
    else
        echo "FAIL ($failed/$n_tests failed) -- `hostname` / `uname -srm`"
        exit 1
    fi
}

print() {
    if [ `/bin/echo -n x` = "-n" ]
    then
        /bin/echo $1'\c'
    else
        /bin/echo -n $1
    fi
}

progress() {
    print '.'
}

begin_test() {
    progress
    n_tests=`expr $n_tests "+" 1`
}

test_failed() {
    failed=`expr $failed "+" 1`
}

assert_equal() {
    begin_test
    _f="no"
    excmd=$1; shift
    mycmd=$1; shift
    eval "$excmd" >tc.out.expected 2>tc.err.expected
    eval "$mycmd" >tc.out.real     2>tc.err.real
    assert_not_coredump || return
    cmp tc.out.real tc.out.expected >/dev/null 2>&1
    if [ "$?" != "0" ]
    then
        echo "stdout differ: \"$excmd\" and \"$mycmd\""
        diff -u tc.out.expected tc.out.real
        echo "----"
        _f="yes"
    fi
    cmp tc.err.real tc.err.expected >/dev/null 2>&1
    if [ "$?" != "0" ]
    then
        echo "stderr differ: \"$excmd\" and \"$mycmd\""
        diff -u tc.err.expected tc.err.real
        echo "----"
        _f="yes"
    fi
    [ "$_f" = "yes" ] && test_failed
}

assert_equal_stdout() {
    begin_test
    _f="no"
    excmd=$1; shift
    mycmd=$1; shift
    eval "$excmd" >tc.out.expected 2>/dev/null
    eval "$mycmd" >tc.out.real     2>/dev/null
    assert_not_coredump || return
    cmp tc.out.real tc.out.expected >/dev/null 2>&1
    if [ "$?" != "0" ]
    then
        echo "stdout differ: \"$excmd\" and \"$mycmd\""
        diff -u tc.out.expected tc.out.real
        echo "----"
        test_failed
    fi
}

assert_stdout() {
    begin_test
    expected=$1; shift
    mycmd=$1; shift
    echo "$expected" > tc.out.expected
    eval "$mycmd" >tc.out.real 2>/dev/null
    assert_not_coredump || return
    cmp tc.out.expected tc.out.real >/dev/null 2>&1
    if [ "$?" != "0" ]
    then
        echo "stdout differ: string \"$expected\" and cmd \"$mycmd\""
        diff -u tc.out.expected tc.out.real
        echo "----"
        test_failed
    fi
}

rm -f core
assert_not_coredump() {
    begin_test
    if [ -f core ]
    then
        echo "core dumped: $mycmd"
        echo "----"
        test_failed
        return 1
    fi
    rm -f core
    return 0
}

assert_not_exist() {
    begin_test
    file=$1; shift
    if [ -f $file ]
    then
        echo "exists: $file"
        echo "----"
        test_failed
        return 1
    fi
}

assert_directory() {
    begin_test
    dir=$1; shift
    if [ ! -d $dir ]
    then
        echo "not directory: $dir"
        echo "----"
        test_failed
        return 1
    fi

}

Head() {
    if [ `uname -s` = "SunOS" ]
    then
        :
    else
        head ${@+"$@"}
    fi
}

uidof() {
    id $1 | sed -e 's/=/ /' -e 's/(/ /' | awk '{print $2}'
}

assert_stdout   "hello, world!" './bin/hello'

assert_stdout   ""              './bin/echo'
assert_stdout   "a"             './bin/echo a'
assert_stdout   "a b c"         './bin/echo a b c'
assert_stdout   "a b c"         './bin/echo a "b c"'
assert_stdout   "a b  c"        './bin/echo a "b  c"'

#assert_equal    'cat ../helpers/cat_helpers.txt'     './bin/cat ../helpers/cat_helpers.txt'

test_finished
