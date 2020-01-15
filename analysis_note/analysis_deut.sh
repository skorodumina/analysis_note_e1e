#!/bin/tcsh -f
rm analysis_deut.pdf
rm analysis_deut.aux
rm analysis_deut.bbl
rm text/aliases/*.aux text/conclusions/*.aux text/event_selection/*.aux text/motivation/*.aux text/setups/*.aux text/title_page/*.aux text/toc/*.aux text/appendix/*.aux text/rad_corr/rad_corr.aux text/sys_err/*.aux text/bin_corr/*.aux text/cross_sction/*.aux
pdflatex analysis_deut
bibtex analysis_deut
pdflatex analysis_deut
pdflatex analysis_deut
acroread analysis_deut.pdf >& /dev/null
rm analysis_deut.log analysis_deut.aux analysis_deut.toc analysis_deut.out analysis_deut.blg analysis_deut.bbl
