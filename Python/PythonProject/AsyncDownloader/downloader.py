import threading
import requests 
import os 
import config 
from logger import setup_logger 

#============================================
#Downloader class Definition
#============================================

class FileDownloader:
    """Handles threaded downloading of multiple files. """

    def __init__(self):
        self.logger = setup_logger()
        self.download_folder = config.DOWNLOAD_FOLDER
        self.urls = config.DOWNLOAD_URLS

        #Create folder if not exists
        if not os.path.exists(self.download_folder):
            os.makedirs(self.download_folder)

        