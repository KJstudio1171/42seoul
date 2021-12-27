find . -name "*.sh" | xargs  basename -a | tr "." " " | awk '{print $1}'
