from datetime import datetime

class Logger:
    def __init__(self,log_file_path):
        self.log_file_path = log_file_path

    def log(self,message):
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        with open(self.log_file_path,'a') as f:
            f.write(f"[{timestamp}] {message}\n")

            