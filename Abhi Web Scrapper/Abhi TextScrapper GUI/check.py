import urllib3
import shutil
import os
import subprocess
import sys
def dwnldim(lines):
    i=0
    for x in (lines):
        i=i+1
        q=str(x[-3:])
                #print(q)
        w=str(i)
        z=w+"."+q
        http = urllib3.PoolManager()

        with http.request('GET', x, preload_content=False) as r, open(z, 'wb') as out_file:       
            shutil.copyfileobj(r, out_file)

def dwnl(url,name):
        q=str(url[-3:])
                #print(q)
        z=name+"."+q
        http = urllib3.PoolManager()
        with http.request('GET', url, preload_content=False) as r, open(z, 'wb') as out_file:       
            shutil.copyfileobj(r, out_file)
        print 'Download Successful!!!'
        d=os.getcwd()
        w=d+'\\'+z
        os.chdir(sys.path[0])
        subprocess.Popen(z,shell=True)
