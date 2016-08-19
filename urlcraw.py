i=1
import urllib3
import urllib
urllib3.disable_warnings()
import cStringIO
from subprocess import call
import os
from bs4 import BeautifulSoup
def getimages(soup):
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
            ft.write(urll)
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
    for x in (lines):
        dwnldimages(x)

def dwnldimages(url):
    global i
    i=i+1
    q=url[-3:]
    w=str(i)
    z=w+"."+q
    urllib.urlretrieve(url,z)
    return

def fetchlink(soup):
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
    
    

htt = urllib3.PoolManager()
urll=raw_input("Abhi Web Scrapper\n\n\nEnter the complete url you wanna crawl starting with https://:")
print(urll)
c=int(input("1:Get links from the webpage     2:Dwnld images from the webpage      3:Dump HTML code of the webpage:"))
r = htt.request('GET', urll)
soup = BeautifulSoup(r.data,"html.parser")
if c==1:
    fetchlink(soup)
elif c==2:
    getimages(soup)
elif c==3:
    fo=open("source.html","w")
    fo.write(r.data)
    fo.close()
    print "HTML dumped to source.html file in your directory"
else:
    print "Invalid input"
