import sys
from PyQt4 import QtCore, QtGui, uic
import check
qtCreatorFile = "adm.ui" # Enter file here.
 
Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)
 
class Form2(QtGui.QMainWindow, Ui_MainWindow):
    def dwn(self):
        name=str(self.fname.text())
        ur=str(self.url.text())
        check.dwnl(ur,name)
    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)
        self.dwnlde.clicked.connect(self.dwn)
 
if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    window = Form2()
    window.show()
    sys.exit(app.exec_())
