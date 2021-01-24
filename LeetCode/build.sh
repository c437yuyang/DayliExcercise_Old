if [ -z "$1" ];then
  echo "usage sh build.sh <cpp_file> [out_file]"
  exit -1
fi
cpp_file=$1
out_file="a.out"
if [ -n "$2" ];then
  out_file=$2
fi

CFLAGS="-I../YXPUtility -std=c++11 -g"
set -x
g++ $1 $CFLAGS -o $out_file

