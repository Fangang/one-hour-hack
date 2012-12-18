#!/usr/bin/env python2
import sys
from pdfminer.pdfparser import PDFDocument, PDFParser
from pdfminer.pdfinterp import PDFResourceManager, PDFPageInterpreter, process_pdf
from pdfminer.pdfdevice import PDFDevice, TagExtractor
from pdfminer.converter import XMLConverter, HTMLConverter, TextConverter
from pdfminer.cmapdb import CMapDB
from pdfminer.layout import LAParams

# main
def main(argv):
    debug = 0
    password = ''
    pagenos = set()
    maxpages = 0
    outfile = None
    outtype = None
    codec = 'utf-8'
    pageno = 1
    caching = True
    laparams = LAParams()
    CMapDB.debug = debug
    PDFResourceManager.debug = debug
    PDFPageInterpreter.debug = debug
    PDFDevice.debug = debug
    rsrcmgr = PDFResourceManager(caching=caching)
    #outfp = sys.stdout
    test=""
    outfp = test
    device = TextConverter(rsrcmgr, outfp, codec=codec, laparams=laparams)
		
    fname="test.pdf"
    fp = file(fname, 'rb')
    process_pdf(rsrcmgr, device, fp, pagenos, maxpages=maxpages, password=password,caching=caching, check_extractable=True)
    fp.close()
    device.close()
    #outfp.close()
    print test
    return

if __name__ == '__main__': sys.exit(main(sys.argv))
