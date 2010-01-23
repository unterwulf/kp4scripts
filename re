#!/bin/sh
#
# usage: re [-i] <command> <regexp> args ..
#

if [ $# -lt 3 ]; then
  echo "usage: $(basename $0) [-i] <command> <regexp> args .." >&2
  exit 2
fi

if [ "$1" == '-i' ]; then
  inv=1
  shift
else
  inv=0
fi

command=$1
regex=$2
shift 2

for par; do
  if [ $inv -eq 1 ]; then
    $command "$(echo "$par" | sed -e "$regex")" "$par"
  else
    $command "$par" "$(echo "$par" | sed -e "$regex")"
  fi
done
