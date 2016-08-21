from PyQt4 import QtCore, QtGui, uic
import sys
import shutil
i=1
import urllib3
import urllib
urllib3.disable_warnings()
import cStringIO
from subprocess import call
import os
from bs4 import BeautifulSoup
import run2
import os
import subprocess
import check
 
qtCreatorFile = "web.ui" # Enter file here.
 
Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)
 
class MyApp(QtGui.QMainWindow, Ui_MainWindow):
    def getimages(self):
        htt = urllib3.PoolManager()
        urll=str(self.txt.text())
        url=urll
        if urll[4]!=':' and urll[5]!=':':
            url="http://"+urll
        r = htt.request('GET', url)
        soup = BeautifulSoup(r.data,"html.parser")
        im=soup.findAll("img")
        print "No. of images:",len(im)
        lt=str(im)
        ft=open("img.csv","w")
        n=len(lt)
        i=0
        while i<n:
            j=lt.find("src",i,n)
            if j==-1:
                break
            k=j+5
            if lt[k+4]!=':' and lt[k+5]!=':':
                ft.write(url)
                if lt[k]!='/':
                    ft.write('/')
            while lt[k] !='"':
                ft.write(lt[k])
                k=k+1
            ft.write('\n')
            i=k
        ft.close()
        print "Images dumped to img.csv file in your current directory"
        with open('img.csv') as f:
            lines = f.read().splitlines()
        f.close()
        check.dwnldim(lines)
        print "Images dumped to your directory"
    def fetchlink(self):
        htt = urllib3.PoolManager()
        urll=str(self.txt.text())
        if urll[4]!=':' and urll[5]!=':':
            url="http://"+urll
        r = htt.request('GET', url)
        soup = BeautifulSoup(r.data,"html.parser")
       
        links = soup.findAll("a")
        print "Total links in webpage:",len(links)
        lt=str(links)
        #print(lt[0]['values'])
        ft=open("out.csv","w")
        n=len(lt)
        i=0
        while i<n:
            j=lt.find("href",i,n)
            if j==-1:
                break
            k=j+6
            if lt[k+4]!=':' and lt[k+5]!=':':
                ft.write(urll)
                if lt[k]!='/':
                    ft.write('/')
            while lt[k] !='"':
                ft.write(lt[k])
                k=k+1
            ft.write('\n')
            i=k
        ft.close()
        print "URLs dumped to out.csv file in your current directory"
    def source(self):
        htt = urllib3.PoolManager()
        urll=str(self.txt.text())
        if urll[4]!=':' and urll[5]!=':':
            url="http://"+urll
        r = htt.request('GET', url)
        soup = BeautifulSoup(r.data,"html.parser")
        fo=open("source.html","w")
        fo.write(r.data)
        fo.close()
        print "HTML source code dumped to source.html in your directory"
    def bw(self):
        self.hide()
        subprocess.Popen('python run2.py',shell=True);
        print "Thanks for using Web Scrapper"
        #sh("python run2.py")
    def dwn(self):
        self.hide()
        subprocess.Popen('python run3.py',shell=True);
    def eq(self):
        try:
            sys.exit(app.exec_())
            exit()
        except:
            print("Thanks for using Abhi Web Scrapper")
            sys.exit(app.exec_())
            exit()
            
    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)
        self.link.clicked.connect(self.fetchlink)
        self.img.clicked.connect(self.getimages)
        self.html.clicked.connect(self.source)
        self.url.clicked.connect(self.bw)
        self.dwnld.clicked.connect(self.dwn)
        self.ex.clicked.connect(self.eq)
if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())
