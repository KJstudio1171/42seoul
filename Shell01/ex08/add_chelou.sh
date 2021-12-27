#!/bin/bash
c=$(echo "$FT_NBR1+$FT_NBR2" | tr "'\"?\!mrdoc" "023401234" | tr "\\" "1")
echo "obase=13;ibase=5;$c"|bc| tr "0123456789ABC" "gtaio luSnemf"
