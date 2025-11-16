# config.py 

#=========================================
# Configuration setttings
#=========================================

#URL list to download (you can replace these later with real URLs)
DOWNLOAD_URLS = [
   "https://example.com/file1.txt",
   "https://example.com/file2.txt",
   "https://example.com/file3.txt"
]

# Number of threads to use for downloads 
MAX_THREADS = 3 

# Folder where downloaded files will be saved.
DOWNLOAD_FOLDER = "downloads"

#Logging configuration 
LOG_FILE = "app.log"
LOG_LEVEL = "INFO"
