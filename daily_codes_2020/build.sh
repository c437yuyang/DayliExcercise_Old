#!/bin/bash
# set -x
# set -v

if [ $# == 0 ]; then
  echo "build file 00_tmp.cpp"
  g++ 00_tmp.cpp -o app -std=c++11
  exit 1;
fi

while :
do
  [ -z "$1" ] && break;
  case $1 in
    -f|--file)
      echo -e "build file $2";
      g++ $2 -o app -std=c++11; shift 2
      ;;
    -r)
      # echo -e "running app";
      ./app; shift
      ;;
    *)
      echo -e "\033[31mERRO: unkown commond! \033[0m\n]" && exit 1
      ;;
  esac
done