# logger.py 

import logging
import config
import os 

#======================================
#Setup the logger configuration 
#======================================

def setup_logger():
   """ Configure and return a logger instance """
   
   #Ensure the log directly exists
   log_dir = os.path.dirname(config.LOG_FILE)
   if log_dir and not os.path.exists(log_dir):
      os.makedirs(log_dir)

   #Configure logging format and level
   logging.basicConfig(
      filename=config.LOG_FILE,
      level=getattr(logging,config.LOG_LEVEL),
      format="%(asctime)s" - %(levelname)s - %(message)s",
      datefmt='%Y-%m-%d %H:%M:%S'
   )

   #create and return logger instance 
   logger = logging.getLogger(__name__)
   return logger 



