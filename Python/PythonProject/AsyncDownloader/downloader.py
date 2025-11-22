import threading
import requests 
import os 
import config 
from logger import setup_logger 

#============================================
#Downloader class Definition
#============================================

class FileDownloader:
    """Handles threaded downloading of multiple files."""

    def __init__(self):
        self.logger = setup_logger()
        self.download_folder = config.DOWNLOAD_FOLDER
        self.urls = config.DOWNLOAD_URLS

        #Create folder if not exists
        if not os.path.exists(self.download_folder):
            os.makedirs(self.download_folder)

    def download_file(self,url):
        """Downloading a single file"""
        try:
            print("Starting downlaod:", url)
            self.logger.info(f"Starting download: {url}")
            response = requests(url,timeout=10)
            response.raise_for_status() #Raise error for bad responses
            
            filename = os.path.join(self.download.folder,os.path.basename(url))
            with open(filename, 'wb') as f:
                f.write(response.content)

            self.logger.info(f"Completed download : {filename}")    
        except Exception as e:
            self.logger.error(f"Error downloading {url} : {e}")

    def run(self):
        """Start threaded downloads.""" 
        threads = []
        for url in self.urls:
            thread=threading.Thread(target=self.download_file,args=(url,))
            threads.append(thread)
            print("url :",url)
            thread.start()
        
        if len(threads) >= config.MAX_THREADS:
            # Wait for current batch to finish before starting new ones.
            for t in threads:
                t.join()
            threads = []

        #Join any remainuing threads 
        for t in threads:
            t.join()

        self.logger.info("All downloads completed")     

        