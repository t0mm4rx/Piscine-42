find . -name "*.sh" -type f |sed 's#.*/##' | rev | cut -c 4- | rev
