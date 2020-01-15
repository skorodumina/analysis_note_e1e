#!/bin/tcsh -f
rm review_first.pdf
rm review_first.aux

pdflatex review_first
pdflatex review_first
acroread review_first.pdf >& /dev/null
rm review_first.log review_first.aux review_first.toc review_first.out 
