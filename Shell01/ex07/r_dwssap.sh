cat /etc/passwd | grep -v '^#' | awk 'NR % 2 == 0 {print}' | cut -f 1 -d ':'| rev | sort -r | awk 'NR >='"$FT_LINE1"' && NR <='"$FT_LINE2"' {print}'|tr "\n" "," | sed 's/,/, /g'|sed 's/.\{2\}$/./'| tr -d  "\n"