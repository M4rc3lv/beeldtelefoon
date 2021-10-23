#!/bin/bash

#notify-send Test "Hello World"

#Status=`amixer -D pulse sset Capture toggle | gawk 'match($0, /Front Left.*\[(.*)\]/, a) {print a[1]}'`
Status=`amixer -D pulse sset Capture toggle | grep '\[on\]'`
echo $Status
if [ "$Status" ]
then
 amixer -D pulse sset Capture toggle 
fi
