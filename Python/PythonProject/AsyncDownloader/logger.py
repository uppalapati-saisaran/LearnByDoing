# logger.py 

import logging
import config
import os 

#======================================
#Setup the logger configuration 
#======================================

def setup_logger():
   """ Configure and return a logger instance """
   logger = logging.getLogger("downloader_logger")
   logger.setLevel(logging.INFO)

   #Prevent adding handlers multiple times.
   if not logger.handlers:
      #---- FILE HANDLER --------
      file_handler = logging.FileHandler(config.LOG_FILE)
      file_handler.setLevel(logging.INFO)

      #------CONSOLE HANDLER 
      console_handler = logging.StreamHandler()
      console_handler.setLevel(logging.INFO)

      #Formattign for Logs 
      formatter = logging.Formatter("[%(levelname)s] %(message)s")
      file_handler.setFormatter(formatter)
      console_handler.setFormatter(formatter)

      #Add handlers
      logger.addHandler(file_handler)
      logger.addHandler(console_handler)
      
   return logger 



